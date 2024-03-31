#ifndef EMPLOYEE_PROJECT_2DLL_H
# define EMPLOYEE_PROJECT_2DLL_H

# include <iostream>
using namespace std;

// For both node structs, you may add constructors.

struct ProjectNode
{
	string project_name;
	int project_priority;
	ProjectNode * next;
	ProjectNode * prev;

	ProjectNode(){}

	ProjectNode(string project_name, int project_priority, ProjectNode *next, ProjectNode *prev)
	{
		this->project_name = project_name;
		this->project_priority = project_priority;
		this->next = next;
		this->prev = prev;
	}
};

struct EmployeeNode
{
	string employee_name;
	ProjectNode * head;
	ProjectNode * tail;
	EmployeeNode * down;

	EmployeeNode(){}

	EmployeeNode(string employee_name, ProjectNode *head, ProjectNode *tail, EmployeeNode *down)
	{
		this->employee_name = employee_name;
		this->head = head;
		this->tail = tail;
		this->down = down;
	}
};

/*
Feel free to 
implement other private member functions for the sake of modularity (to be used in the 
implementation of the required public member functions), but you are not allowed to implement 
extra public ones.
*/

class EmployeeProject2DLL
{
	private:
		EmployeeNode *top;

		// useful private functions
		EmployeeNode *getEmployee(string employee_name);
		ProjectNode *getProjectByName(EmployeeNode *employee, string project_name);
		ProjectNode *getProjectByPriority(EmployeeNode *employee, int project_priority);
		void deleteProjectByName(EmployeeNode *employee, string project_name);
		bool isProjectsAreSorted(ProjectNode *head);
		void addProjectInOrder(EmployeeNode *employee, string project_name, int project_priority);
		EmployeeNode *addNewEmployee(string employee_name);
		void reOrderProjects(EmployeeNode *employee);
		void deleteEmployeeByName(string employee_name);
		void printTheProjects(EmployeeNode *employee, int mode);

	public:
		EmployeeProject2DLL( void );
		bool isEmployeeAssignedToProject(string employee_name, string project_name);
		bool updateProjectPriority(string employee_name, string project_name, int project_priority);
		bool assignEmployeeToProject(string employee_name, string project_name, int project_priority);
		void withdrawEmployeeFromProject(string employee_name, string project_name, int &project_priority);
		void printTheEntireList( void );
		void printEmployeeProjects(string employee_name, int mode);
		void undo( char type, string employee_name, string project_name, int project_priority );
		void clear( void );
};

/**
 
   Default constructor: Creates an empty object with no employee. 
 
● isEmployeeAssignedToProject: This function takes two parameters, an employee name 
and a project name. It returns true/false depending on whether the employee is assigned 
to the project or not. 

● updateProjectPriority: This function takes three parameters; an employee name, a 
project name, and a project priority. It does not change anything and returns false, if there 
is another project in the list of projects of that employee with the same priority as the 
parameter priority. Otherwise, it updates the priority of the project of that employee as the 
parameter priority, reorders the list (if needed) and then returns true. 

● assignEmployeeToProject: This function takes three parameters; an employee name, a 
project name and a project priority. The aim of this function is to assign the project to the 
employee, if possible. If the project cannot be added to the employee’s project list due to 
having another project with the same priority, then the structure does not change and the 
function returns false. Otherwise, the function returns true and assigns the project to the 
employee by observing the ordering rules and if needed by adding a new employee row. 

● withdrawEmployeeFromProject: This function takes three parameters, an employee 
name, a project name and project priority (the last one is a reference parameter). This 
function assumes that there exists such an employee-project pair in the data structure and 
priority is not a criterion for selection. The function simply deletes the project node from 
the employee list and returns its priority as the reference parameter. The function itself 
does not return anything. Be aware that you cannot have employees with no projects 
assigned. If the project to be deleted is the only project that employee has, then the 
employee node has to be deleted as well.

● printTheEntireList: This function prints the content of the entire 2DHLL structure in a 
predefined format (employees in ascending alphabetical order; projects per employee are 
in ascending priority order). If the list is empty, it prints a specific message indicating that. 
Please refer to sample runs for the output format, and specific message.

● printEmployeeProjects: This function takes two parameters, an employee name, and an 
integer value indicating whether to print the projects of that employee in an ascending (1) 
or descending (0) order according to the priorities of the projects.

● undo: This function takes four parameters: (i) a char type indicating the type of the 
operation, (ii) an employee name, (iii) a project name, and (iv) project priority. It recognizes 
the operation type and based on that, it performs an action that reverses that operation. 
There are three types of operations: ‘a’ for assigning a project; ‘w’ for withdrawing a 
project; ‘u’ for updating the priority of an existing project.

● clear: This function takes no parameters, and is responsible for deallocating the 
dynamically-allocated memory of the entire 2DHLL structure.
 * 
*/

#endif /* end of EMPLOYEE_PROJECT_2DLL_H */