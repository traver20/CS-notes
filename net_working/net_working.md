# TCP and UDP

## TCP(Transmission Control Protocol)
TCP是面向连接的通信方式，数据通信可靠性更高

## UDP(User Data Protocol)
UDP是面向报文的通信方式

## 区别
1. 系统资源要求TCP更多
2. UDP程序结构更简单
3. TCP保证数据顺序和正确性
4. TCP面向字节流，UDP面向报文(即应用层给UDP多长的报文，UDP照样发送，一次发送一个报文)
5. TCP点对点，UDP一对多

## 折中
UDP实现可靠性传输：RUDP

## TCP拥塞控制
1. 慢开始：每次*2
2. 拥塞避免：每次+1
3. 超时重传： ssthresh/=2 cwnd=1
4. 快速重传：收到三个重复确认，立即重传
5. 快恢复：cwnd=ssthresh=cwnd/2

# url resolution

1. 通过DNS域名解析获取ip地址
2. 建立TCP连接
3. 发送HTTP请求
4. 服务器响应HTTP请求
5. 浏览器解析html代码，请求对应资源
6. 断开TCP连接
7. 渲染页面

# 网络字节序和主机字节序

## 大端和小端

### Little endinan
数据低位存储在内存的低地址，数据高位存储在内存的高地址

### Big endian
数据高位存储在内存的低地址，低位存储在内存的高地址

## 主机字节序
CPU存储数据的字节顺序，不同的CPU的字节序不同。intel系列采用小端
PowerPC采用大端。

### 判断本机字节序
~~~c
int dGetHostByteOrder()
{
    uint32_t a=0x12345678;
    uint8_t *p=(uint8_t *)(&a);
    if(*p==0x78)
        return 0;
    else
        return 1;
}
~~~
## 网络字节序
TCP/IP规定好的一种数据表示格式，使用big endian

## 主机字节序和网络字节序的相互转换
linux socket网络编程中，提供c标准函数进行转换

    #incude<arpa/inet.h>

    uint32_t htonl(uint32_t hostlong);
    uint16_t htons(uint16_t hostshort);
    uint32_t ntohl(uint32_t netlong);
    uint16_t ntohs(uint16_t netlong);

## 64位数值的转换
可以使用移位
~~~c
if(__BYTE_ORDER==__LITTLE_ENDIAN)
    return (((unsigned long long)htol((int)((val<<32)>>32))<<32) | (unsigned int)htonl((int)(val >> 32)));
~~~

# HTTP(HyperText Transfer Protocol) and HTTPS
1. HTTP明文传输，HTTPS使用SSL加密
2. HTTPS需要到CA(Certificate Authority)申请证书
3. http端口：80，https端口：443