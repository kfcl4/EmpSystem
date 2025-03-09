#include <iostream>
#include <string>
 //头文件只包含函数声明
using namespace std;
#include "employee.h"

Employee::Employee(int id, string name,int dId){
    this->m_ID=id;
    this->m_Name=name;
    this->m_DeptID=dId;
}
void Employee::showInfo(){
    cout<<" Employee's ID is "<<this->m_ID
    <<"\t Employee's Name is "<<this->m_Name
    <<"\t Department is "<<this->getDeptName()
    <<" \t duty: do whatever"<<endl;
}
string Employee::getDeptName(){
    return string ("Employee");
}
