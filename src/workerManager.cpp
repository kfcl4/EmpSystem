#include <iostream>
using namespace std;
#include "workerManager.hpp"

WorkerManager::WorkerManager(){

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