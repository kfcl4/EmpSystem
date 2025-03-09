#include <iostream>
#include <string>
 //头文件只包含函数声明
using namespace std;
#include "worker.h"
#include "employee.h"
#include "boss.h"
#include "manager.h"
#ifndef WORKERMANAGER_HPP
#define WORKERMANAGER_HPP

class WorkerManager{
    public:
        WorkerManager();
        ~WorkerManager();
        void Show_menu();//展示界面
        void exitSystem();
        int m_EmpNum; //记录文件中人数个数
        Worker ** m_EmpArray;//员工数组的指针
        void Add_Emp();
};



#endif