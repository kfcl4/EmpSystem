#include <iostream>
#include <string>
 //头文件只包含函数声明
using namespace std;
#include "worker.h"
#ifndef MANAGER_H
#define MANAGER_H

class Manager:public Worker{
    public:
        Manager(int id, string name, int dId);
        virtual void showInfo();
        virtual string getDeptName();
};

#endif