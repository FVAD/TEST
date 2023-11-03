## IP地址格式转换
### 前置知识
#### 多线程
##### `<thread>`头文件
##### 使用方法： `thread <命名关键字>(<执行方法>, <传入参数>)` *（似乎命名关键字不一定一定要相同）*
```cpp
#include <thread>
int output(int i)
{
    std::cout << i << endl;
    return 0;
}
int main()
{
    for (int i=0; i<4; i++)
    {
        std::thread t(output, i);
        t.detach;
    }
}

```

#### 主机字节序
##### 整数在内存中保存的顺序，一般有*Little endian(低字节高地址)* 还有*Big endian(高字节高地址)* 与CPU类型、操作系统有关
#### 网络字节序（采用*Big endian*）
##### TCP/IP中规定好的数据表示格式，与具体的CPU类型、操作系统无关
#### 在使用little endian的系统中 这些函数会把字节序进行转换 在使用big endian类型的系统中这些函数会定义成空宏
### htonl(h to n : l)
#### 主机顺序转换成网络顺序
### ntohl(n to h : l)
#### 网络顺序转换成主机顺序
### inet_addr
#### ip字符串转换成网络字节序的整数值
### inet_ntoa
