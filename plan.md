# 10/31 学习目标
## 前置知识学习--了解响应http报文和响应字符串
## C++ 如何去写一个基本的网络后端：实现socket通信和 接收发送的http报文
## C++ 11 以后的特性有什么？ 怎么用？

## 开始学习

### Http报文格式： 请求报文/响应报文
### 请求报文
#### 请求行
##### 请求方法 + space + 请求URL + HTTP协议及其版本
##### Eg `POST /xxx/xxxx/xxxxx.html HTTP/1.1`
#### 请求头
##### 主要是GET 或者 POST ，还有一些如`DELETE,HEAD,OPTIONS,PUT,TRACE`(这些方法大多是通过“_method”参数模拟出HEEP方法，一般还是借助了POST用于提交表单)
#### 