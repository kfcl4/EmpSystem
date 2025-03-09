//普通员工
#include <iostream>
#include <string>
 //头文件只包含函数声明
using namespace std;
#include "worker.h"
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee: public  Worker{

public:
    Employee(int id,string name, int dId);
    virtual void showInfo();
    virtual string getDeptName();


};

#endif