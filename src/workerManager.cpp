#include <iostream>
using namespace std;
#include <fstream>
#include "workerManager.hpp"

WorkerManager::WorkerManager(){
    

    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    if (!ifs.is_open()){
        cout<<"no such file"<<endl;
        this->m_EmpNum=0;
        this->m_FileIsEmpty=true;
        this->m_EmpArray=NULL;
        ifs.close();
        return;
    }


    //文件存在但是没有记录
    char ch;
    ifs>>ch;
    if (ifs.eof()){//ifs.eof() 用于检查文件输入流是否到达文件末尾。
        cout<<"file is empty"<<endl;
        this->m_EmpNum=0;
        this->m_FileIsEmpty=true;
        this->m_EmpArray=NULL;
        ifs.close();
        return;
    }

    //文件存在并且有记录人数
    int num=this->get_EmpNum();
    cout<<"the number of employees is "<<num<<endl;
    
    
	this->m_EmpNum = num;
    this->m_FileIsEmpty=false;
	this->m_EmpArray = new Worker * [this->m_EmpNum]; //先开辟空间，然后初始化数组
	this->init_Emp();
    for (int i=0;i<this->m_EmpNum;i++){
        cout<<"id: "<<this->m_EmpArray[i]->m_ID<<"name: "<<this->m_EmpArray[i]->m_Name<<endl;
    }

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
            cin.ignore();//清除输入缓冲区中的换行符
            cout<<"input the "<<i+1 << "employee 's name"<<endl;
            getline(cin,name);//使用getline读取包含空格的名字

            cout<<"input the employee 's department. 1 for employee, 2 for manager, 3 for boss"<<endl;
            cin>>dSelect ;
            cin.ignore();

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
        this->m_FileIsEmpty=false;
        cout<<"you have added " <<addNum<<"Employees"<<endl;
        this->save();
        cout<<"new input has been saved in file"<<endl;

    }
    else{
        cout<<"wrong data"<<endl;
    }
    system("pause");
    // system("cls");//清空控制台窗口的内容

}
WorkerManager::~WorkerManager(){
    if (this->m_EmpArray!=NULL){
        delete [] this->m_EmpArray;
        this->m_EmpArray=NULL;
    }
}
void WorkerManager::save(){
    ofstream ofs;
    ofs.open(FILENAME,ios::out);
    for (int i=0;i<this->m_EmpNum;i++){
        ofs<<this->m_EmpArray[i]->m_ID<<" "
        <<this->m_EmpArray[i]->m_Name<<" "
        <<this->m_EmpArray[i]->m_DeptID<<endl;
    }
    ofs.close();
}

int WorkerManager:: get_EmpNum(){
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int id;
    string name;
    int dId;
    int num=0;
    while (ifs>>id && ifs >>name && ifs>>dId){
        num++;//统计人数变量
    }
    return num;
}
void WorkerManager::init_Emp(){
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int id;
    string name;
    int dId;
    int index=0;
    while (ifs >>id  && ifs >> name && ifs >> dId)//读取数据
	{
		Worker* worker = NULL;
		//根据不同的部门id创建不同对象
		if (dId == 1)//1普通职工
		{
			worker = new Employee(id, name, 1);
		}
		else if(dId==2)//2经理
		{
			worker = new Manager(id, name, 2);
		}
		else//3老板
		{
			worker = new Boss(id, name, 3);
		}
		//存放在数组中
		this->m_EmpArray[index] = worker;
		index++;
	}
	//关闭文件
	ifs.close();
}

void WorkerManager::Show_Emp(){
    if (this->m_FileIsEmpty){
        cout<<"no records!"<<endl;
    }else{
        for (int i=0;i<m_EmpNum;i++){
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("pause");
    
}