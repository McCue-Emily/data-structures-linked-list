#include <string>
#include <iostream>
using namespace std;

#include "LinkedList.h"
#include "node.h"

int main() {

    bool exit = false;

    int command;
    LinkedList<string>* linkedlist = new LinkedList<string>();

    while(exit == false) {
        cout << endl << "TODO LIST" << endl << "1. Add Task" << endl <<
        "2. Complete Task" << endl << "3. Display List" << endl <<
        "4. Complete List" << endl << "0. Exit" << endl;    
        cin >> command;

        switch(command) {
            case 1: {
                if (linkedlist->isEmpty() == true) {
                    cout << "No tasks currently!" << endl;

                } else {
                    for (int i = 0; i < linkedlist->getLength(); i++) {
                        cout << i + 1 << ": " <<linkedlist->getEntry(i) << endl;
                    }
                }

                cout << endl <<  "What is the priority of your new task?" << endl;
                int priority;
                cin >> priority;
                priority--;

                if (priority >= 0 && priority <= linkedlist->getLength()) {
                    string newTask;
                    cout << "What is your new task?" << endl;
                    cin.ignore();
                    getline(cin, newTask);

                    linkedlist->insert(priority, newTask); 
                } else {
                    cout << "Invalid priority" << endl;
                }

                break;
            }  
            case 2: {
                if (linkedlist->isEmpty() == true) {
                    cout << "No tasks currently!" << endl;

                } else {
                    for (int i = 0; i < linkedlist->getLength(); i++) {
                        cout << i + 1 << ": " <<linkedlist->getEntry(i) << endl;
                    }
                    cout << "Please select which task you've completed:" << endl;
                    int itemToRemove;
                    cin >> itemToRemove;
                    itemToRemove--;

                    cout << endl << "Completed: " << linkedlist->getEntry(itemToRemove) << endl;
                    linkedlist->remove(itemToRemove);
                }               
                break;
            }
            case 3: {
                if (linkedlist->isEmpty() == true) {
                    cout << "No tasks currently!" << endl;

                } else {
                    for (int i = 0; i < linkedlist->getLength(); i++) {
                        cout << i + 1 << ": " <<linkedlist->getEntry(i) << endl;
                    }
                }
                break;
            }
            case 4: {
                if (linkedlist->isEmpty() == true) {
                    cout << "No tasks currently!" << endl;

                } else {
                    for (int i = 0; i < linkedlist->getLength(); i++) {
                        cout << i + 1 << ": " <<linkedlist->getEntry(i) << endl;
                    }
                    linkedlist->clear();

                    cout << endl << "Congratulations! List complete!" << endl;
                    
                }
                break;
            }
            case 0: {
                if (linkedlist->isEmpty() == true) {
                    cout << "No tasks currently!" << endl;

                } else {
                    for (int i = 0; i < linkedlist->getLength(); i++) {
                        cout << i + 1 << ": " <<linkedlist->getEntry(i) << endl;
                    }
                }
                exit = true;
                break;
            }
            default: {
                cout << "Invalid Command" << endl;
            }

        }
        
    }
    return 0;
}
