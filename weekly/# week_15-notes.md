# week_15-notes

## linux command

### process
1. ps -aux | grep ...
2. top -p pid
3. cat /proc/pid/status

### memory
1. free -h
2. cat /proc/meminfo

### cpu
1. cat /proc/cpuinfo
2. vmstat

## tcp head
1. port
2. seq,ack
3. window sz
4. check sum

![](https://img-blog.csdnimg.cn/265c5ca2bf9a409dba3523208a25548f.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAYW5saWFuNTIz,size_20,color_FFFFFF,t_70,g_se,x_16)

## number dedup
1. hash map
2. bitmap

## avoid deadlock
1. timeout
2. banker's theory
3. fine-grained lock

## take book
each turn 1-5 books, how to win?
1. 6 books left=win
2. each turn gurantee 6 books taken
3. 94%6=4,first take 4 books

## process scheduling algorithms
1. first come first served
2. shortest job first
3. highest response ratio next
4. round-robin

## 断点续传
一个下载/上传任务分为几部分，若碰到网络故障，可从断点处继续执行  
using status 206:Partial Content  
status code:200=ok

## plenty of urls deduplicate
1. hash_set:divide and conquer
2. hash_map:in each small file deduplicate

## decltype specifier
Inspects the declared type of an entity or the type and value category of an expression  

## lock
1. unique_lock:write lock
2. shared_lock:read lock

## Resource Acquisition Is Initialization
A c++ programming technique which binds the life cycle of a resource that must be acquired before use(allocated heap memory,locked mutex...anything exists in limited supply)to the lifetime of an object
1. 把资源用类封装起来
2. 对资源操作在类的内部
3. 在析构函数中释放资源
4. 局部变量作用域结束，析构函数自动调用
![](https://miro.medium.com/max/2000/1*RL_89ygWRgJLUgcoqOjPGQ.jpeg)

## Bloom Filters
a data structure that is used to test whether an element is a member of a set  
1. use multiple hash function
2. maintain a bit set
3. if all the bits are turned on, then it probably is in the set  
4. if any of the bits is not turned on, then it is definitely not in the collection

![pic](..\picture\Bloomfilter.png)

## Trie
a trie is typa of search tree, a tree data structure used for locating specific keys from within a set. These keys are most often strings, with links between nodes defined not by the entire key, but by individual characters. In order to access a key(to recover its value, change it, or remove it), the trie is traversed depth-first, following the links between nodes, which represent each character in the key.  

![pic](..\picture\trie.png)

## volatile
A volatile specifier is a hint to a compiler that an object may change its value in ways not specified by the language so that aggressive optimizations must be avoided  
1. 表示变量可能被其他线程，操作系统修改
2. 不进行优化，每次从内存中读取  

## timefd

### timerfd_create
1. CLOCK_REALTIME:time from 1970.1.1, based on system time
2. CLOCK_MONOTONIC:time from reboot to current

### timerfd_settime
1. TFD_TIMER_ABSTIME:call`CLOCK_REALTIME`
2. 0: set by manual

## endian
~~~cpp
int x = 0x12345678;
char* p = (char*)&x;
if (*p == 0x12)
    cout << "big endian";
else if (*p == 0x78)
    cout << "little endian";
~~~

## static cast
1. base-derived class
2. built-in type
3. void* to specified type

## http
1. request line
2. http headers

~~~
GET / HTTP/1.1
Host: www.baidu.com
Connection: keep-alive
Upgrade-Insecure-Requests: 1
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/53.0.2785.143 Safari/537.36
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8
Referer: https://www.baidu.com/s?wd=HTTP%20%E5%8D%8F%E8%AE%AE%E6%9C%89%E5%87%A0%E7%A7%8D%E5%92%8C.....
Accept-Encoding: gzip, deflate, sdch, br
Accept-Language: zh-CN,zh;q=0.8
Cookie: BIDUPSID=670A04B660AAF2716D3120BEAF946A11; BAIDUID=2454D4....
RA-Ver: 3.0.8
RA-Sid: CA623F7A-20150914-060054-2b9722-5fde41
~~~

### http headers
1. 通用头:Connection
2. 请求头:Accept
3. 响应头:Server
4. 实体头:Content-type

