### OpenSSL Performance On AZB-like Board



#### 1. OpenSSL测试命令

OpenSSL版本：OpenSSL 1.1.1m  14 Dec 2021

我们将会测试md5, sha1, des cbc,  des ede3,  aes-128 cbc, aes-192 cbc, aes-256 cbc, sha256, sha512算法的性能。在OpenWrt上执行下面的脚本：

```
openssl speed md5 sha1 sha256 sha512 des des-ede3 \
    aes-128-cbc aes-192-cbc aes-256-cbc rsa2048 dsa2048 | tee /tmp/sslspeed
. /etc/openwrt_release; echo \
$(awk -v "rev=${DISTRIB_REVISION%%-*}" -v "FS=: " -v "ORS=" -e 'BEGIN \
    {print "|" rev} /(Processor|BogoMIPS|Hardware|machine|cpu model|system type)/ \
    {print "| " $2 " "}' /proc/cpuinfo) \
$(awk -v "ORS=" -e '$1 ~ /OpenSSL/ {print "| " $2 " |"} $1 ~ /(md5|sha)/ \
    {print "  " $5 " |"} $1 ~ /(des|aes)/ {b = b "  " $6 " |"} $1 ~ /(rsa|dsa)/ \
    {print b "  " $6 " | " $7 " | ";b=""}' /tmp/sslspeed \
| sed -e 's/\.\(..\)k/\10/g')
```



#### 2. 测试结果

```
The 'numbers' are in 1000s of bytes per second processed.
type             16 bytes     64 bytes    256 bytes   1024 bytes   8192 bytes  16384 bytes
md5             172233.00k   368652.61k   616264.36k   743024.33k   787092.82k   790609.92k
sha1            306761.65k   809209.37k  1460173.74k  1877378.05k  2050230.95k  2064733.53k
des cbc          79828.63k    85894.93k    86551.13k    86692.52k    86761.47k    86764.20k
des ede3         32443.93k    32822.14k    32924.59k    32900.10k    32918.19k    32920.92k
aes-128 cbc     313196.14k   306038.51k   294329.51k   304238.93k   305586.18k   298855.08k
aes-192 cbc     257813.16k   254565.63k   272277.42k   257782.44k   265753.94k   263372.80k
aes-256 cbc     217759.49k   236704.75k   226716.76k   240953.34k   226929.32k   236022.44k
sha256          294328.21k   785394.28k  1381871.10k  1706296.32k  1832132.61k  1841643.52k
sha512           79068.67k   316323.65k   499098.62k   672873.81k   728793.09k   780670.29k
                  sign    verify    sign/s verify/s
rsa 2048 bits 0.000556s 0.000016s   1799.9  61001.0
                  sign    verify    sign/s verify/s
dsa 2048 bits 0.000230s 0.000213s   4351.5   4701.4
```



#### 3. 性能对比

Intel (R) i5-8250U @ 1.6GHz, Windows 10, OpenSSL v1.02n, done on 20 March, 2018

```
The 'numbers' are in 1000s of bytes per second processed.
type             16 bytes     64 bytes    256 bytes   1024 bytes   8192 bytes
md5              68237.12k   194798.44k   419221.42k   593069.74k   671974.22k
sha1             79453.51k   225723.43k   530520.88k   802999.64k   944201.94k
des cbc          77343.80k    79750.83k    80343.40k    80561.15k    80628.39k
des ede3         29900.29k    30526.66k    30503.944562 2048 bit DSA verify in 10.00s
5k    30686.55k    30679.04k
aes-128 cbc     134577.08k   150465.56k   154372.09k   156139.69k   156898.65k
aes-192 cbc     114858.97k   125527.03k   128568.90k   129967.79k   129629.53k
aes-256 cbc      99963.22k   108251.56k   110185.29k   111000.23k   110801.34k
sha256           83286.34k   181806.75k   331269.37k   409588.39k   441534.71k
sha512           56909.48k   226705.15k   380024.15k   562338.13k   653040.09k
                  sign    verify    sign/s verify/s
rsa 2048 bits 0.000619s 0.000018s   1615.4  55066.8
                  sign    verify    sign/s verify/s
dsa 2048 bits 0.000209s 0.000224s   4794.6   4456.2
```

Intel(R) Atom(TM) CPU D525 @ 1.80GHz , Debian 3.2.68-1+deb7u1 i686 , OpenSSL 1.0.1e 11 Feb 2013

```
The 'numbers' are in 1000s of bytes per second processed.
type             16 bytes     64 bytes    256 bytes   1024 bytes   8192 bytes
md5               8612.44k    32026.79k    96483.33k   196923.73k   282380.97k
sha1              9474.81k    31281.54k    84250.79k   146233.34k   186190.51k
des cbc          28342.85k    29772.23k    30388.74k    30511.45k    30542.51k
des ede3          9999.28k    10214.21k    10270.29k    10287.45k    10291.88k
aes-128 cbc      15720.10k    16385.02k    16805.21k    17142.78k    17167.70k
aes-192 cbc      13503.87k    14302.61k    14590.29k    14665.73k    14688.26k
aes-256 cbc      11513.24k    12065.64k    12243.11k    12291.41k    12304.38k
sha256            9858.68k    22579.31k    39079.77k    48033.45k    51459.41k
sha512            3164.86k    12499.78k    18258.26k    25097.90k    28194.13k
                  sign    verify    sign/s verify/s
rsa 2048 bits 0.042321s 0.001299s     23.6    770.1
                  sign    verify    sign/s verify/s
dsa 2048 bits 0.012883s 0.015480s     77.6     64.6
```

raspberry pi 3 model B, raspian lite 8.1 , openssl OpenSSL 1.0.1k 8 Jan 2015

```
The 'numbers' are in 1000s of bytes per second processed.
type             16 bytes     64 bytes    256 bytes   1024 bytes   8192 bytes
md5               6491.83k    15158.06k    44833.79k   111382.53k    87333.84k
sha1              4822.46k    14773.99k    32323.55k    39425.02k    54804.48k
des cbc          13082.04k    11392.96k    10803.46k    14544.55k    12787.71k
des ede3          3773.94k     3898.99k     4024.83k     5345.96k     4953.43k
aes-128 cbc      20719.11k    33608.64k    30028.37k    24553.47k    26247.17k
aes-192 cbc      25203.35k    24658.75k    20625.32k    25685.33k    22219.43k
aes-256 cbc      19977.37k    18960.96k    18316.03k    28947.80k    21842.60k
sha256            6576.91k    14977.17k    25999.36k    31060.31k    33295.02k
sha512            2061.57k     7991.83k    12406.95k    14139.05k    20108.63k
                  sign    verify    sign/s verify/s
rsa 2048 bits 0.044578s 0.001184s     22.4    844.5
                  sign    verify    sign/s verify/s
dsa 2048 bits 0.012207s 0.015535s     81.9     64.4
```

