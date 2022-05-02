### Application Upgrade



#### 1. 说明

openwrt 一个比较重要的特点就是它采用 ipk 包的形式安装软件。只需用简单的命令就可以将 ipk 安装包安装到 openwrt 系统中，非常方便。我们也会使用opkg来实现应用程序的安装，升级。



#### 2. 新建用户程序

```
cd ./package    //进入 package 目录
mkdir hello_world //创建一个名为“hello_world”的文件夹，用于放置安装包源码。
cd hello_world //进入“hello_world”目录
mkdir src //新建一个名为“src”的目录用于放置源码
vi src/hello_world.c //在 src 目录下新建一个名为 hello_world.c 文件
```

hello_world.c文件内容如下所示：

```
#include <stdio.h>
int main(char argc, char *argv[])
{
    int i = 1;
    while(1){
        //1~10 循环
        printf("Hello world!!!%d\n",i); //打印内容
		if (i < 10)
			i++;
		else
			i = 1;		
		sleep(1);
	}
	return 0;
}
```

vim src/Makefile，//在 src 目录下新建一个 Makefile，输入下面内容：

```

all: hello_world
hello_world: hello_world.o
	$(CC) $(LDFLAGS) hello_world.o -o hello_world
helloworld.o: hello_world.c
	$(CC) $(CFLAGS) -c hello_world.c
clean:
	rm *.o hello_world
```

vim Makefile，输入下面内容：

```
include $(TOPDIR)/rules.mk
 
PKG_NAME:=hello_world
PKG_VERSION:=1.0
PKG_BUILD_DIR:= $(BUILD_DIR)/$(PKG_NAME)
 
include $(INCLUDE_DIR)/package.mk
 
define Package/hello_world
	SECTION:=base
	CATEGORY:=Utilities
	TITLE:=Hello world -prints a hello world message
endef
 
define Package/hello_world/description
	If you can't figure out what this program does, you're probably
	brain-dead and need immediate medical attention.
endef
 
define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef
 
define Package/hello_world/install
	$(INSTALL_DIR) $(1)/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/hello_world $(1)/bin/
endef
 
$(eval $(call BuildPackage,hello_world))
```



#### 3. 配置及编译

make menuconfig，选择我们已经加进去的安装包:

```
  Utilities  --->  
	<M> hello_world.................... Hello world -prints a hello world message
```

make package/hello_world/compile V=99

文件：./bin/packages/hello_world_1.0.ipk。

这样的话我们就拥有了ipk文件。

可通过修改打印次数，重新编译生成hello_world_2.0.ipk

#### 4. 安装及更新

将hello_world_1.0.ipk和hello_world_2.0.ipk安装包先放入OpenWrt系统中。

然后执行

```
opkg install hello_world_1.0.ipk
```

此时应用已成功的安装，执行hello_world出现打印。

```
Hello world!!!1
Hello world!!!2
Hello world!!!3
Hello world!!!4
Hello world!!!5
Hello world!!!6
Hello world!!!7
Hello world!!!8
Hello world!!!9
Hello world!!!10
```

此时我们对程序进行更新，执行：

```
opkg install hello_world_2.0.ipk
```

此时应用已成功的安装，执行hello_world出现打印。

```
Hello world!!!1
Hello world!!!2
Hello world!!!3
Hello world!!!4
Hello world!!!5
Hello world!!!6
Hello world!!!7
Hello world!!!8
Hello world!!!9
Hello world!!!10
Hello world!!!11
Hello world!!!12
```

ipk包，是个tar压缩包，安装其实就是通过解压到系统根目录/来完成安装的。所以，ipk的安装是覆盖安装。
也就是说，如果你之前安装过，然后自己有改动程序的话，再次安装会覆盖掉原来的文件，那你的改动就会被覆盖掉了。这就是update的实现。