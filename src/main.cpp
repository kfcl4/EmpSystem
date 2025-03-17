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
            case 2:
                wm.Show_Emp();
            case 3:
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
                system("cls");
                break;
    }
    }



    return 0;

}
