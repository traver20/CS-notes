# Resource Acquisition Is Initialization

cppreference 定义
> RAII is a c++ programming technique which binds the life cycle of a resource that must be acquired before use(allocated heap memory,locked mutex...anything exists in limited supply)to the lifetime of an object

将一些在使用前需要先获取的资源(堆内存，互斥锁，socket)的生命周期绑定到一个局部变量  
防止造成资源泄漏或死锁  

![](https://miro.medium.com/max/2000/1*RL_89ygWRgJLUgcoqOjPGQ.jpeg)

## 具体流程

1. 把资源用类封装起来
2. 对资源操作在类的内部
3. 在析构函数中释放资源
4. 局部变量作用域结束，析构函数自动调用

## example

~~~cpp
mutex mu;
void worker()
{
    unique_lock<mutex> locker(mu);
    /*
    critical section...
    */
    //locker.unlocker 不需要，因为locker是局部变量，离开作用域后自动释放锁资源
}
~~~

![](https://miro.medium.com/max/700/1*sMhY9dDDYP0FRisYTkqPcw.png)