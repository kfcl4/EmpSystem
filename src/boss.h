#include <iostream>
#include <string>
 //头文件只包含函数声明
using namespace std;
#include "worker.h"
#ifndef BOSS_H
#define BOSS_H
class Boss:public Worker{
    public:
        Boss(int id, string name, int dId);
        virtual void showInfo();
        virtual string getDeptName();
};
#endif