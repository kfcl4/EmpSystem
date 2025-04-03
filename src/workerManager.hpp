#include <iostream>
#include <string>
#include <fstream>
#define FILENAME "empFile.txt"//如果不添加文件 就只是将员工数据添加到内存中 程序结束了就无法保存了
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
        void save();//保存文件
        bool m_FileIsEmpty;//判断现在文件是否为空
        int get_EmpNum();
        void init_Emp();
        void Show_Emp();
        void Del_Emp();
        int IsExist(int id);
        void Mod_Emp();
        void Find_Emp();
};



#endif