edgex需要Openwrt提前安装docker, dockerd,docker-compose,python3等等。

#### 1. 下载配置文件

执行：

```
release="main" # or "jakarta" for latest
wget https://raw.githubusercontent.com/edgexfoundry/edgex-compose/${release}/docker-compose.yml
docker-compose up -d
```

我用的是jakarta。



#### 2. 安装过程

```
/edgex# docker-compose up -d
Creating network "edgex_edgex-network" with driver "bridge"
Creating volume "edgex_consul-acl-token" with default driver
Creating volume "edgex_consul-config" with default driver
Creating volume "edgex_consul-data" with default driver
Creating volume "edgex_db-data" with default driver
Creating volume "edgex_edgex-init" with default driver
Creating volume "edgex_kong" with default driver
Creating volume "edgex_kuiper-connections" with default driver
Creating volume "edgex_kuiper-data" with default driver
Creating volume "edgex_kuiper-sources" with default driver
Creating volume "edgex_postgres-config" with default driver
Creating volume "edgex_postgres-data" with default driver
Creating volume "edgex_redis-config" with default driver
Creating volume "edgex_vault-config" with default driver
Creating volume "edgex_vault-file" with default driver
Creating volume "edgex_vault-logs" with default driver
Pulling security-bootstrapper (edgexfoundry/security-bootstrapper:2.1.1)...
```

这里看网速需要等待，这里会自动的下载各种镜像。



#### 3. 运行

浏览器输入http://[IP]:8500/可以浏览到edgeX的功能界面。

类似：

![](https://picx.zhimg.com/v2-c46844fc2ac9048a290706bbeebedafe_1440w.jpg?source=172ae18b)