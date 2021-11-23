# week 12
## MON
### object oriented
1. 封装：数据和方法
2. 继承：扩展和重用
3. 多态：向不同对象发送同一个消息，不同的对象产生不同的行为

### polymorphism
1. 基类指针指向对象调用
2. 是虚函数
对象存储虚函数表的指针，虚函数表存储虚函数的指针(函数实际在代码段)
先从基类复制一份，若overriade则覆盖，可新增

### vector memory allocation
capacity>=size,每次容量不够时，重新申请空间(1.5或2.0倍增长)
将旧数据复制，释放旧空间

### free store and heap
1. 自由存储是c++通过new与delete动态分配和释放对象的抽象概念，而堆是c语言和os的术语，是os维护的一块动态分配内存
2. new所申请的内存区域在c++中为自由存储区。藉由堆实现的自由存储，可以说new申请的内存在堆上。

### 智能指针
1. shared_ptr
2. unique_ptr
3. weak_ptr

### unordered_map and map
1. unordered_map:hash table
2. map:balanced tree

## TUE
### OSI MODEL
1. Application layer(应用层)
2. Presentation layer(表示层)
3. Session layer(会话层)
4. Transport layer(传输层)
5. Network layer(网络层)
6. Data Link layer(数据链路层)
7. Physical layer(物理层)

### TCP
实现可靠传输
1. 检验和
2. 确认重传
3. 滑动窗口
4. 流量与拥塞控制
5. 回退n帧和选择重传

### HTTPS
https相比于http的明文传输，采用了加密的方式
1. 对称加密：加密解密为同一个密匙
2. 非对称加密：服务器私匙，浏览器用公匙
https加密：
1. 浏览器使用url访问服务器，建立SSL链接
2. 服务器明文发送非对称公匙A    
3. 浏览器生成随机数，作为对称密匙X发送
4. 浏览器使用A对B加密，发送
5. 服务器用私匙A'对其解密，得到对称密匙X
6. 使用密匙X进行通信

## WED
### thread
共享：
1. 堆
2. 全局变量
3. 静态变量
4. 打开的文件

独享：
1. 栈
2. 寄存器

线程安全：互斥同步

### stack and heap
1. 堆是运行时动态分配的内存，栈在编译时可确定大小
2. 堆由程序员管理，栈由os管理
3. 堆为线程共享，栈为线程独享
4. 栈在内存中紧挨着存储，分配内存<->移动栈指针，堆为一块块的内存，不一定连续存储

### page replacement
1. FIFO：先进先出
2. OPT：在未来最长时间不使用的换出
3. LRU，访问调到栈顶，栈底换出
4. Clock(NRU)，访问置1。替换时：1->置0,0->换出

### lock
1. 乐观锁
2. 悲观锁：共享锁，排它锁
3. 自旋锁

### virtual function
联编(binding),链接(linking)
静态联编：overload
动态联编：override

一个class，产生一堆指向virtual functions的指针，放于虚函数表
一个object，开头添加vptr指向虚函数表

## TUE
### memory alignment
CPU每次从内存读取固定字节的数据，一般以4字节，8字节存取->内存存取粒度(寄存器宽度)
如果不内存对齐，可能一个int，要读取两次，低效率
结构体要根据对齐值对齐，为了数组访问高效

1. 基本类型对齐值是sizeof值
2. 结构体的对齐值是成员最大对齐值
3. 实际对齐值为min(granularity,type)

### asynchronous
IO比较慢，线程要遇到io时，通知DMA处理，让出cpu，DMA负责与磁盘交互，将数据传输到内存中
当IO完成后，DMA通知cpu造成中断。这样线程可以异步的执行
线程是os级别，有用户态和内核态转换
协程是用户级别

## FRI
### http request
1. 域名解析
2. TCP三次握手
3. 向服务器发起http请求
4. 服务器响应
5. 浏览器解析html代码，并请求资源
6. 渲染页面

## SAT
### hard link and soft link
#### 硬链接
与普通文件没什么不同，inode节点相同，指向同一个文件在硬盘中的区块

#### 软连接
是另外一种文件，保存其代表的文件的绝对路径，在硬盘上有独立的区块，访问时替换自身路径

### SYN flood
A SYN flood is a form of **denial-of-service attack** in which an attacker rapidly initiates a connection to a server **without finalizing the connection**. The server has to spend resources waiting for half-opened connections, which can consume enough resources to make the system unresponsive to legitimate traffic

只有第一次握手，无第三次握手

## SUN
### atomic and mutex
1. 互斥锁是一种数据结构，让线程执行一个程序的关键部分，完成互斥的多个操作
2. 原子操作是针对某个值的单个互斥操作，不能被中断，在cpu级别直接用指令(不可中断)实现(对内存或总线加锁)
3. 互斥锁为悲观锁，假设总是有并发的操作要修改值
4. CAS的做法趋于乐观锁，总是假设值未被修改
5. CAS(compare and swap)，判断addr指向的值是否与old相同，如果true则，替换为new，不一定成功
6. atomic操作更轻量，可不形成临界区和互斥量
7. 都是为了线程安全

### Avoiding Data Race:
1. Use mutex to synchronize data access
2. Never leak a handle of data to outside
3. Design interface appropriately

