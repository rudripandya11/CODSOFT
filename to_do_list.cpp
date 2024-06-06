#include <iostream>
#include <string>
#include <list>
using namespace std;

list<string> tasks;

void createTask();
void showTasks();
void completeTask();
void deleteTask();

int main(){
    int choice = -1;
    cout << "       TO-DO LIST      " <<endl;
     cout << "_______________________"<<endl;
    cout << "1. Create a new task\n2.Show all tasks\n3.Complete a task\n4.Delete a task\n5.Exit the list" << endl;
    cout << "_______________________"<<endl;
    while(choice!=5){
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                createTask();
                break;
            case 2:
                showTasks();
                break;
            case 3:
                completeTask();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                cout << "Exit";
                break;
        }
    }
    return 0;
}

void createTask(){
    string task;
    cout << "Enter task: ";
    cin.ignore(); 
    getline(cin, task);
    tasks.push_back(task);
}

void showTasks(){
    int id = 1;
    cout << "_______________________"<<endl;
    if(tasks.empty()){
        cout << "No tasks in the list" << endl;
    }else{
        cout << "TASKS: " << endl;
        for (const string& task: tasks)
        {
            if (task.find(" [COMPLETED]") != string::npos) {
                cout << id++ << ": "<< task << endl;
            } else {
                cout << id++ << ": "<< task << " [INCOMPLETE]" << endl;
            }
        }
    }
    cout << "_______________________"<< endl;
}

void completeTask() {
    int taskNumber;
    list<string>::iterator it;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        int i = 1;
        for (it = tasks.begin(); it != tasks.end(); it++) {
            if (i == taskNumber) {
                if ((*it).find(" [COMPLETED]") != string::npos) {
                    cout << "Task is already completed." << endl;
                } else {
                    *it += " [COMPLETED]";
                }
                break;
            }
            i++;
        }
    } else {
        cout << "Invalid task number." << endl;
    }
}

void deleteTask(){
    int taskNumber,currentTaskNumber=1;
    list <string>:: iterator it;
    cout << "Enter task number to be deleted: ";
    cin >> taskNumber;
    if(taskNumber>0 && taskNumber <= tasks.size()){
        for(it = tasks.begin(); it !=tasks.end(); it++){
            if(currentTaskNumber == taskNumber){
                tasks.erase(it);
                return;
            }
            currentTaskNumber++;
        }
    }else{
        cout << "Invalid task number";
    }
}