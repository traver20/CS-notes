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