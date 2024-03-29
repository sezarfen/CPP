#include <iostream>
#include <string>
#include "EmployeeProject2DLL.h"
#include "UndoStack.h"

using namespace std;

void printMenu(bool first_time)
{
    if (!first_time)
    {
        cout << "Please enter option number:" << endl;
        return;
    }
    cout << "Hello! Welcome to the Employees-Projects Management System."<<endl;
    cout << "Below is the list of options that the system supports at the moment." << endl;
    cout << "Please choose the number corresponding to the option,\nand then enter the necessary information to execute the option." << endl;
    cout << "1. is_assigned_to" << endl;
    cout << "2. is_withdrawn_from" << endl;
    cout << "3. print_the_entire_list" << endl;
    cout << "4. print_employee_projects" << endl;
    cout << "5. undo" << endl;
    cout << "6. exit" << endl;
    cout << "Please enter option number:" << endl;
}

int main() {

    EmployeeProject2DLL list;
    UndoStack  stack;

    printMenu(true);

    int option;
    cin >> option;

    while (option != 6)
    {
        if (option == 1) // an employee is assigned to a project
        {
            string emp_name, proj_name;
            int proj_priority;
            cout<< "Please enter the employee name:"<<endl;
            cin >> emp_name;
            cout<< "Please enter the project name:"<<endl;
            cin >> proj_name;
            cout<< "Please enter the project priority:"<<endl;
            cin >> proj_priority;

            if (list.isEmployeeAssignedToProject(emp_name, proj_name)) // this means that the employee is in the list and already has this specific project in their list of projects, thus we will update the priority of the project
            {
                if (list.updateProjectPriority(emp_name, proj_name, proj_priority)) // update the priority of the project 'proj_name' of the employee 'emp_name' to 'proj_priority'
                {
                    stack.push('u', emp_name, proj_name, proj_priority); // push the operation to the undo stack where the operation is 'u' for updating the priority of the project 'proj_name' of the employee 'emp_name' to 'proj_priority'
                }
            }
            else // this means that either the employee is not in the list or is indeed in the list but does not have that specific project in their list of projects, thus we will add the project to the employee's list of projects
            {
                if (list.assignEmployeeToProject(emp_name, proj_name, proj_priority)) // assign the project 'proj_name' to the employee 'emp_name' with the priority 'proj_priority'
                {
                    stack.push('a', emp_name, proj_name, proj_priority); // push the operation to the undo stack where the operation is 'a' for assigning the project 'proj_name' to the employee 'emp_name' with the priority 'proj_priority'
                }
            }
        }
        else if (option == 2) // an employee is being withdrawn from a project
        {
            string emp_name;
            string proj_name;
            cout << "Please enter the employee name:"<<endl;
            cin >> emp_name;
            cout << "Please enter the project name:"<<endl;
            cin >> proj_name;

            if (list.isEmployeeAssignedToProject(emp_name, proj_name)) // this means that the employee is in the list and has this specific project in their list of projects
            {
                int proj_priority = -1;// this is a dummy value that will be updated by the withdrawEmployeeFromProject function
                list.withdrawEmployeeFromProject(emp_name, proj_name, proj_priority);
                stack.push('w', emp_name, proj_name, proj_priority); // push the operation to the undo stack where the operation is 'w' for withdrawing the project 'proj_name' from the employee 'emp_name' with the priority 'proj_priority'
            }
            else
            {
                cout << "Either the employee is not in the list or is in the list but is not assigned to that project." << endl;
            }
        }
        else if (option == 3) // print the entire list of employees and their projects in the format as in the sample runs section in HW3 document
        {
            list.printTheEntireList();
        }
        else if (option == 4) // print the projects of a specific employee in ascending or descending order
        {
            cout << "Please enter 1 for ascending order, or 0 for descending order:"<<endl;
            int order;
            cin >> order;
            if (order != 1 && order != 0)
            {
                cout << "Invalid input." << endl;
            }
            else
            {
                string emp_name;
                cout << "Please enter the employee name:"<<endl;
                cin >> emp_name;
                list.printEmployeeProjects(emp_name, order);
            }
        }
        else if (option == 5)// the undo
        {
            // in order to undo, we need to pop the last operation from the undo stack, and then use the undo member function to recognize and undo that operation
            if (stack.isEmpty())
            {
                cout << "The undo stack is empty." << endl;
            }
            else
            {
                char operation;
                string emp_name, proj_name;
                int proj_priority;
                stack.pop(operation, emp_name, proj_name, proj_priority);
                list.undo(operation, emp_name, proj_name, proj_priority);
            }
        }
        else
        {
            cout << "Invalid option." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }

        printMenu(false);
        cin >> option;
    }

    cout << "Deallocating the 2DHLL and the undo stack and terminating the program." << endl;
    stack.clear();// clear the undo stack
    list.clear();// clear the 2D-LL list
    return 0;
}