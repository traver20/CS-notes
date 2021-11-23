# function call
程序经过编译生成可执行文件，这些指令在虚拟内存空间中，位于代码段

## 栈帧
当函数执行所需要的存储空间超出寄存器能够存放的大小时，就会借助栈上的存储空间，成为栈帧
函数执行需要有内存空间存放局部变量，参数等数据，这段空间对应到虚拟地址空间的栈
栈在高地址向下增长，分配给函数的栈空间叫stack frame
栈底一般叫栈基bp,栈顶又叫栈指针sp
布局为：
1. caller's bp
2. local variables
3. return value
4. parameters

## 执行过程(golang)
### param and return
1. 分配return value
2. 参数压栈，从右到左

### call做两件事：
1. 将下一条指令的地址，即返回地址入栈
2. 跳转到指定函数入口地址

### 接着进入函数运行
1. 首先修改sp分配栈帧(golang)
2. 将caller's bp 保存入栈
3. 修改bp寄存器为本身的bp
4. 执行自身指令

### 在ret前，有两条指令
1. 恢复caller's bp
2. 修改sp，释放栈帧空间

### 执行ret指令
1. 弹出call指令压栈的返回地址
2. 跳转到返回地址，修改pc

## C++_version

1. 参数压栈
2. call指令将下一条指令的地址压栈，并调用函数
3. 函数开始执行，ebp压栈
4. ebp变为当前esp
5. 分配栈帧
6. 函数执行完毕，准备return value
7. esp变为ebp回收栈帧
8. pop ebp回到caller栈底
9. ret 将ESP指向的return address弹出，存储到EIP，调用结束
10. caller清理参数，接收返回值