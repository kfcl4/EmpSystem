#include "manager.h"
#include <iostream>
#include <string>
using namespace std;
Manager::Manager(int id, string name, int dId ){

    this->m_ID=id;
    this->m_Name=name;
    this->m_DeptID=dId;
}

void Manager::showInfo(){
    cout<<" Employee's ID is "<<this->m_ID
    <<"\t Employee's Name is "<<this->m_Name
    <<"\t Department is "<<this->getDeptName()
    <<" \t duty: do whatever by Boss and assign work to employee"<<endl;
}
string Manager::getDeptName(){
    return string ("Manager");
}