#include <iostream>
using namespace std;
#include "workerManager.hpp"

WorkerManager::WorkerManager(){
    this->m_EmpNum=0;
    this->m_EmpArray=NULL;

}
WorkerManager::~WorkerManager(){

}
void WorkerManager::Show_menu(){
    cout<<"*********************"<<endl;
    
    cout<<"****** 0.exit ********"<<endl;
    cout<<"****** 1.add information ********"<<endl;
    cout<<"****** 2.show information ********"<<endl;
    cout<<"****** 3.delete information ********"<<endl;
    cout<<"****** 4.edit information ********"<<endl;
    cout<<"****** 5.look up for information ********"<<endl;
    cout<<"****** 6.sort by order ********"<<endl;
    cout<<"****** 7.delete all ********"<<endl;
    cout<<"*********************"<<endl;
    cout<<endl;
}
void WorkerManager::exitSystem(){
    cout<<"goodbye"<<endl;
    system("pause");
    exit(0);
}
void WorkerManager::Add_Emp(){
    cout<<"input how many employees you want to add"<<endl;
    int addNum=0;
    cin>>addNum;
    if (addNum>=0){
        int newSize=this->m_EmpNum+addNum;
        Worker ** newSpace = new Worker*[newSize];//开辟新空间

        //将原空间下内容放到新空间
        if (this->m_EmpArray !=NULL){
            for (int i=0;i<this->m_EmpNum;i++){
                newSpace[i]=this->m_EmpArray[i];
            }
        }
        

        //输入新数据
        for (int i=0;i<addNum;i++){
            int id;
            string name;
            int dSelect;
            cout<<"input the "<<i+1 << "employee 's id"<<endl;
            cin>>id;
            cout<<"input the "<<i+1 << "employee 's name"<<endl;
            cin>>name;

            cout<<"input the employee 's department. 1 for employee, 2 for manager, 3 for boss"<<endl;
            cin>>dSelect ;

            Worker* worker=NULL;
            switch (dSelect){
                case 1:
                    worker = new Employee(id, name,1);
                    break;
                case 2:
                    worker = new Manager(id, name,2);
                    break;
                case 3:
                    worker = new Boss(id, name,3);
                    break;
                default:
                    break;
            }
            newSpace[this->m_EmpNum+i]=worker;//插入新位置
            
        }
        delete [] this->m_EmpArray;//释放原有空间
        this->m_EmpArray=newSpace;
        this->m_EmpNum=newSize;
        cout<<"you have added " <<addNum<<"Employees"<<endl;

    }
    else{
        cout<<"wrong data"<<endl;
    }
    system("pause");
    system("cls");//清空控制台窗口的内容

}