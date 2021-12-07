# week_13-notes
## c++ memory layout
1. 栈：局部变量，参数，局部常量
2. 堆：动态分配内存
3. 静态存储区：虚函数，静态变量
4. 常量存储区：全局常量，函数指针
5. 代码区：text

## thread safety
Lock
: 悲观锁(mutex, spinlock:based on CAS)
: 乐观锁(compare and swap)

Atomic:
: based on CAS

## 互斥锁与自旋锁
当加锁失败:
互斥锁使用线程切换应对，有用户态内核态转换和上下文切换
自旋锁使用忙等待，循环获取直到拿到锁

## get and post
1. get获取数据，post修改服务器数据
2. get将数据放在URL中，post，将数据放在request body中
3. get有长度限制(url)
4. get可以被缓冲，post比get更慢

## https
1. over ssl
2. 可能会有中间人攻击(替换公匙)
3. 使用ca保证收到的公匙是服务器的

## ctor and dtor virtual
1. 有类继承时，dtor应为virtual
2. ctor不能为virtual

原因
: 虚函数表指针存放在对象的内存空间中，构造时还未初始化。
: 创建对象时主动调用，不能通过父类指针调用。只初始化一次，不是动态行为

## polymorphism
1. static:overload
2. dynamic:overrride,相同的消息给不同的对象引起不同的动作

## extern c
1. c++支持重载，符号表函数名有所不同
2. extern c 让g++以c的风格去编译
3. 可以使用第三方写好的库

## c++ callable object
1. 函数指针
2. 仿函数：类内重载operator()
### Lambda表达式 
1. 可方便地创造一个“函数对象”，比函数多了捕获列表
2. 可按引用捕获或按值捕获
3. 相当于匿名内联函数

## network transport
1. pc封装:传输层-报文段(端口号)，网络层-包(ip地址),数据链路层-帧(mac)
2. 路由器处理到网络层，转发。
3. 路由器需要解封装和再封装
4. 路由器首先根据ip地址查询路由表，得到端口后确定源mac，通过arp确定目的mac
5. 交换机根据mac地址转发

## arp
1. 完成ip地址向mac的转换
2. 静态映射：手动关联
3. 动态映射：请求和回应
4. 请求(广播),回应(单播)

arp报文格式
![](https://img-blog.csdn.net/20180419180040413?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2V2ZXJfcGVuZw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

在arp请求中，arp是最高层，之上没有传输层和应用层
arp报文封装在帧中传输
![](https://img-blog.csdn.net/20180419180050187?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2V2ZXJfcGVuZw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)
帧总长度=帧头+ARP包=14+28=42bytes
以太网帧最小帧长为64bytes，所以有padding


