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

