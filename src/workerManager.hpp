#include <iostream>
#include <string>
 //头文件只包含函数声明
using namespace std;
#ifndef WORKERMANAGER_HPP
#define WORKERMANAGER_HPP

class WorkerManager{
    public:
        WorkerManager();
        ~WorkerManager();
        void Show_menu();//展示界面
        void exitSystem();
};



#endif