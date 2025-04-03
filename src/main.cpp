#include <iostream>
using namespace std;
#include "workerManager.hpp"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"


void test(){
    Worker * worker =NULL;
    worker = new Boss(1,"lily",1);
    worker->showInfo();
    delete worker;
}
int main()
{   
    // test();
    
    WorkerManager wm;
    while (true){
        wm.Show_menu();
        cout<<"input your choice"<<endl;
        int choice;
        cin>>choice;
        switch(choice){
            case 0:
                wm.exitSystem();
                
            case 1:
                wm.Add_Emp();
                break;
            case 2:
                wm.Show_Emp();
                break;
            case 3:
                wm.Del_Emp();
                break;
                
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            default:
                system("pause");
                break;
    }
    }



    return 0;

}
