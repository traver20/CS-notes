# week_14-notes

## inline
`inline`向编译器发出请求->在调用处内联展开，省去了调用的开销

## nullptr
1. NULL在c中为void*指针值0，但也允许定义为整常数0 `#define NULL (void*)0  `
2. NULL在c++中被明确定义为常数0 `#define NULL    0 `

c++通过搜索匹配参数的机制实现overload，如果支持void*的隐式转换，会带来syntax ambiguous
~~~c
void foo(int i);  
void foo(char* p)  
  
foo(NULL); // which is called?  
~~~

使用`nullptr`代替`NULL`

## c compile
1. preprocess:`# command`
2. compiler: c file to assembly file(.c -> .s)
3. assembler: .s -> .o (relocatable object file).ie machine instructions
4. linker: .o -> .exe

![](https://img-blog.csdnimg.cn/6059bb480ab046c7b67992680b15cdb3.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMOazoeaenOWltg==,size_20,color_FFFFFF,t_70,g_se,x_16)

gcc默认采用动态链接

### 静态链接
代码直接从静态链接库拷贝到可执行程序中
1. 速度快，可直接打包
2. 占用空间大，更新困难

### 动态链接
代码在动态链接库中(dynamic link library),程序运行时加载dll
1. 性能损失
2. 节省内存，方便更新

## paging and segmentation
1. 页大小不可改变，段大小动态改变
2. 分页是一维地址空间，分段是二维
3. 分页对程序员透明，分段需要显式划分
4. 分页用于虚拟内存，获得更大的地址空间 分段使程序和数据被划分为逻辑上独立的地址空间，利于共享和保护
     
### 段页式
程序地址空间被划分为多个拥有独立地址空间的段  
每个段被划分为大小相同的页  

## 长连接和短连接
1. 短连接：每进行一次请求就建立一次连接，任务结束就中断
2. 长连接：请求完成后，连接不关闭
3. 长连接用于操作频繁，点对点，连接不太多的情况(data base)
4. 连接数很多适合用短连接(web)

## zombie process
父进程通过`wait`得到子进程的`exit`信号  
如果父进程先于子进程退出，子进程结束后，pcb残留于kernel中，变成zombie process  

## big data
10亿个数找出最大的10000个  
1. 建立大小等于m(10000)的小顶堆
2. 每次与堆顶(最小的数)比较，如果大于，则替换，重新建堆

## MyISAM and innoDB index
1. MyISAM 叶节点data域存放数据记录的地址
![](http://blog.codinglabs.org/uploads/pictures/theory-of-mysql-index/8.png)
2. InnoDB数据文件本身就是索引文件，叶节点包含了完整的数据记录
![](http://blog.codinglabs.org/uploads/pictures/theory-of-mysql-index/10.png)
3. InnoDB的辅助索引data域存储主键的值
![](http://blog.codinglabs.org/uploads/pictures/theory-of-mysql-index/11.png)

## &&
1. 变量是左值，只要它有名字，哪怕是右值引用变量，也是左值
2. &&:this只能是右值，&:变量只能是左值

## clustered index
1. 聚簇索引：叶子节点存放的就是整张表的行记录数据
2. 非聚簇索引(辅助索引),建立在聚簇索引之上。叶子节点存放主键值或数据指针  
![](https://img2018.cnblogs.com/i-beta/1464190/201911/1464190-20191106151527647-152458631.png)

## tcp network
1. Server: create-bind-listen-accept-recv/send-close
2. Client: create-connect-send/recv/close
![](https://img-blog.csdnimg.cn/674fda837f7848e281be71c433541f92.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA5ou-54mZ5oWn6ICF,size_20,color_FFFFFF,t_70,g_se,x_16)

## cookie session
http协议是无状态的协议，数据交换完毕，连接关闭，再次交换需建立新的连接  
cookie和session跟踪用户的身份  
1. cookie数据在浏览器，session数据在服务器
2. cookie不安全，session占用浏览器性能
3. session:从broser启动到关闭,cookie:保存于本地

## iterator 失效
1. vector:重新分配内存(全部失效),erase(当前元素之后迭代器失效)
2. list/set/map:insert,不影响 erase:除了当前被删的元素，其他元素迭代器有效

## memcpy strcpy
1. strcpy复制字符串，memcpy复制任意内容
2. strcpy遇到'\0'结束，memcpy指定长度

## mysql isolation level
1. read uncommited
2. read commited
3. repeatable read(mvcc)
4. serializable

## table lock and record lock
1. table lock:开销小，粒度大，并发度低
2. record lock:粒度小，开销大，并发度高
3. innoDB实现record lock，主索引锁一次，辅助索引锁两次，无索引则表锁
![](https://img2020.cnblogs.com/blog/1614350/202011/1614350-20201115221104598-1160606998.png)

## factory pattern
1. 多态继承
2. 使用一个工厂类去产生各种不同的实例对象



