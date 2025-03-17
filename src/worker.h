#include <iostream>
#include <string>
 //头文件只包含函数声明
using namespace std;
#ifndef WORKER_H
#define WORKER_H

//抽象基类
class Worker{
    public:
        virtual void showInfo()=0;
        virtual string getDeptName()=0;
        int m_ID;
        string m_Name;
        int m_DeptID;
        

};

#endif