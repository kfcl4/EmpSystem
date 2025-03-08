#include <iostream>
using namespace std;
#include "workerManager.hpp"


int main()
{   
    
    WorkerManager wm;
    wm.Show_menu();
    cout<<"input your choice"<<endl;
    int choice;
    cin>>choice;
    switch(choice){
        case 0:
            wm.exitSystem();
        case 1:
            break;
        case 2:
            break;
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




    return 0;

}
