# ubuntu使用Lightweight Paas功能
**1.安装CLI**

```
$ wget -q -O - https://packages.cloudfoundry.org/debian/cli.cloudfoundry.org.key | sudo apt-key add -
$ echo "deb https://packages.cloudfoundry.org/debian stable main" | sudo tee /etc/apt/sources.list.d/cloudfoundry-cli.list
$ sudo apt-get update
$ sudo apt-get install cf8-cli
```
验证是否安装成功执行：
``` 
$ cf --help
```

**2.安装CF Local**

```
$ cf install-plugin cflocal
Searching CF-Community for plugin cflocal...
Plugin cflocal 0.19.0 found in: CF-Community
Attention: Plugins are binaries written by potentially untrusted authors.
Install and use plugins at your own risk.
Do you want to install the plugin cflocal? [yN]: y
Starting download of plugin binary from repository CF-Community...
 14.35 MiB / 14.35 MiB [=====================================] 100.00% 2s
Installing plugin cflocal...
OK
Plugin cflocal 0.19.0 successfully installed.
```

**3.测试**

``` 
$ git clone https://github.com/cloud-gov/cf-hello-worlds.git
$ cd cf-hello-worlds/go-hello
$ cf local stage go-hello
Buildpack: will detect                                                         
[go-hello] 2023-06-01T05:58:53.769271574Z -----> Go Buildpack version 1.9.5
[go-hello] 2023-06-01T05:58:53.769420352Z        **WARNING** [DEPRECATION WARNING]:
[go-hello] 2023-06-01T05:58:53.769437891Z        **WARNING** Please use AppDynamics extension buildpack for Golang Application instrumentation
[go-hello] 2023-06-01T05:58:53.769446093Z        **WARNING** for more details: https://docs.pivotal.io/partners/appdynamics/multibuildpack.html
[go-hello] 2023-06-01T05:58:53.769981102Z -----> Installing godep 80
[go-hello] 2023-06-01T05:58:53.770170992Z        Download [https://buildpacks.cloudfoundry.org/dependencies/godep/godep-v80-linux-x64-cflinuxfs3-b60ac947.tgz]
[go-hello] 2023-06-01T05:58:58.974221916Z -----> Installing glide 0.13.3
[go-hello] 2023-06-01T05:58:58.974255421Z        Download [https://buildpacks.cloudfoundry.org/dependencies/glide/glide-v0.13.3-linux-x64-cflinuxfs3-ef07acb5.tgz]
[go-hello] 2023-06-01T05:59:03.182754681Z -----> Installing dep 0.5.4
[go-hello] 2023-06-01T05:59:03.185730144Z        Download [https://buildpacks.cloudfoundry.org/dependencies/dep/dep-v0.5.4-linux-x64-cflinuxfs3-79b3ab9e.tgz]
[go-hello] 2023-06-01T05:59:06.508888311Z -----> Installing go 1.13.6
[go-hello] 2023-06-01T05:59:06.509109486Z        Download [https://buildpacks.cloudfoundry.org/dependencies/go/go1.13.6.linux-amd64-cflinuxfs3-56df080c.tgz]
[go-hello] 2023-06-01T05:59:35.684592714Z        **WARNING** go 1.13.x will no longer be available in new buildpacks released after 2020-09-03.
[go-hello] 2023-06-01T05:59:35.684635730Z        See: https://golang.org/doc/devel/release.html
[go-hello] 2023-06-01T05:59:41.567587835Z        **WARNING** Installing package '.' (default)
[go-hello] 2023-06-01T05:59:41.567624172Z -----> Running: go install -tags cloudfoundry -buildmode pie .
Successfully staged: go-hello

$ cf local run go-hello
Running go-hello on port 46069... 

```
此时程序运行，端口为46069

打开另一终端执行
```
$ curl 127.0.0.1:43497
<h1>Hello, World from Go!</h1>
<p>You've requested: /</p>
```