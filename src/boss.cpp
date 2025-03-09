#include "boss.h"
#include <iostream>
#include <string>
using namespace std;
Boss::Boss(int id, string name, int dId ){

    this->m_ID=id;
    this->m_Name=name;
    this->m_DeptID=dId;
}

void Boss::showInfo(){
    cout<<" Employee's ID is "<<this->m_ID
    <<"\t Employee's Name is "<<this->m_Name
    <<"\t Department is "<<this->getDeptName()
    <<" \t duty: manage the company"<<endl;
}
string Boss::getDeptName(){
    return string ("Boss");
}