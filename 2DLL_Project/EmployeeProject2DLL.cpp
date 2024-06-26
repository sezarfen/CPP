#include "EmployeeProject2DLL.h"
// priorities are ascending
// Useful functions to write
// 0. reOrder the x
// 1. addInOrder

// Bazı özel caseler mevcut gibi, sample runlar kontrol edilebilir

ProjectNode *getNewProjectNode(string project_name, int project_priority, ProjectNode *prev, ProjectNode *next)
{
	ProjectNode *projectNode = new ProjectNode;
	projectNode->project_name = project_name;
	projectNode->project_priority = project_priority;
	projectNode->prev = prev;
	projectNode->next = next;
	return (projectNode);
}

// I THINK NOT COMPLETED, WE MIGHT NEED TO CHECK AGAIN

void EmployeeProject2DLL::addProjectInOrder(EmployeeNode *employee, string project_name, int project_priority)
{
	// it assumes, employee already exists, and that also means, it has at least 1 project
	ProjectNode *curr = employee->head;

	if (project_priority < curr->project_priority)
	{
		ProjectNode *newNode = new ProjectNode(project_name, project_priority, curr, NULL);
		curr->prev = newNode;
		employee->head = newNode;
		return ;
	}

	ProjectNode *next = curr->next;
	while (next != NULL && project_priority > next->project_priority)
	{
		curr = curr->next;
		next = next->next;
	}
	if (next == NULL)
	{
		curr->next = new ProjectNode(project_name, project_priority, NULL, curr);
		employee->tail = curr->next;
	}
	else // []<-(we need to insert here in the middle)->[]
	{
		ProjectNode *newNode = new ProjectNode(project_name, project_priority, next, curr);
		curr->next = newNode;
		next->prev = newNode;
	}
}

// IT SEEMS NOT COMPLETED
void EmployeeProject2DLL::deleteProjectByName(EmployeeNode *emp, string project_name)
{
	if (emp->head == NULL)
		return ;
	if (emp->head != NULL && emp->head == emp->tail)
	{
		delete emp->head;
		emp->head = NULL;
		emp->tail = NULL;
	}

	if (project_name == head->project_name)
	{
		ProjectNode *next = head->next;
		delete emp->head;
		emp->head = next;
		return ;
	}
	
	ProjectNode *temp = emp->head;
	

	// first we need to find the project
	while (temp != NULL && temp->next->project_name != project_name)
	{
		temp = temp->next;
	}
	if (temp == NULL)
		return ;
	ProjectNode *newNode = temp->next->next;
	delete temp->next;
	temp->next = newNode;
}


// 2. is_there_duplicates

EmployeeNode *EmployeeProject2DLL::getEmployee(string employee_name)
{
	EmployeeNode *temp = this->top;

	while (temp != NULL && temp->employee_name != employee_name)
		temp = temp->down;
	return (temp);
}

ProjectNode *EmployeeProject2DLL::getProjectByName(EmployeeNode *employee, string project_name)
{
	ProjectNode *tProject = employee->head;
	while (tProject != NULL && tProject->project_name != project_name)
		tProject = tProject->next;
	return (tProject);
}

ProjectNode *EmployeeProject2DLL::getProjectByPriority(EmployeeNode *employee, int project_priority)
{
	ProjectNode *tProject = employee->head;
	while (tProject != NULL && tProject->project_priority != project_priority)
		tProject = tProject->next;
	return (tProject);
}

bool EmployeeProject2DLL::isProjectsAreSorted(ProjectNode *head)
{
	while (head->next != NULL)
	{
		if (head->project_priority > head->next->project_priority)
			return (false);
		head = head->next;
	}
	return (true);
}

// NOT SURE IF IT IS CORRECT, CAN BE CHECKED AGAIN
EmployeeNode *EmployeeProject2DLL::addNewEmployee(string employee_name)
{
	EmployeeNode *temp = this->top;

	if (temp == NULL || employee_name.compare(temp->employee_name) < 0)
	{
		this->top = new EmployeeNode(employee_name, NULL, NULL, this->top);
		return (this->top);
	}
	while (temp->down != NULL && employee_name.compare(temp->employee_name) < 0) // while newName is greater
		temp = temp->down;
	temp->down = new EmployeeNode(employee_name, NULL, NULL, temp->down);
	return (temp->down);
}

void EmployeeProject2DLL::reOrderProjects(EmployeeNode *employee)
{

	ProjectNode *tProject = employee->head;
	while (isProjectsAreSorted(employee->head) == false)
	{
		if (tProject->project_priority > tProject->next->project_priority)
		{
			// prev[tProject]next <-> prev[next]next->
			ProjectNode *next = tProject->next;
			
			next->prev = tProject->prev;
			tProject->next = next->next;
			
			if (tProject->next != NULL)
				tProject->next->prev = tProject;
			
			next->next = tProject;

			if (tProject->prev != NULL)
				tProject->prev->next = next;
			
			tProject->prev = next;
		}
		tProject = tProject->next;
		if (tProject == NULL)
			tProject = employee->head;
	}
}

void EmployeeProject2DLL::deleteEmployeeByName(string employee_name)
{
	EmployeeNode *temp = this->top;

	while (temp->down != NULL && temp->down->employee_name != employee_name)
		temp = temp->down;
	
	EmployeeNode *toBeDeleted = temp->down;
	temp->down = temp->down->down;
	delete toBeDeleted;
}

void printTheProjects(EmployeeNode *employee, int mode)
{
	// mode 1 indicates asc, mode 0 indicates desc
	if (mode == 1)
	{
		ProjectNode *temp = employee->head;
		while (temp != NULL)
		{
			cout << "(" << temp->project_name << ", " << temp->project_priority << ") ";
			temp = temp->next;
		}
		cout << endl;
	}
	else if (mode == 0)
	{
		ProjectNode *temp = employee->tail;
		while (temp != NULL)
		{
			cout << "(" << temp->project_name << ", " << temp->project_priority << ") ";
			temp = temp->prev;
		}
		cout << endl;
	}
}


// PUBLIC FUNCTIONS

EmployeeProject2DLL::EmployeeProject2DLL( void )
{
	this->top = NULL;
}

// DONE ELHAMDULILLAH
bool EmployeeProject2DLL::isEmployeeAssignedToProject(string employee_name, string project_name)
{
	EmployeeNode *temp = getEmployee(employee_name);
	if (temp == NULL)
		return (false);
	// employee is found, now it is time to find project
	ProjectNode *tProject = getProjectByName(temp, project_name);
	if (tProject == NULL)
		return (false);
	// project found
	return (true);
}

bool EmployeeProject2DLL::updateProjectPriority(string employee_name, string project_name, int project_priority)
{
	// first, check if there is a project with same priority
	
	EmployeeNode *temp = getEmployee(employee_name);
	if (temp == NULL)
		return (false);

	// employee is found, now it is time to find project

	ProjectNode *tProject = getProjectByPriority(temp, project_priority);
	if (tProject != NULL) // that means, there is project with project_priority, duplicate!
		return (false);

	// no priority duplicates, and we found the project, so we are good to go

	tProject->project_priority = project_priority;
	
	// tProject = temp->head;
	// Check the order
	// We could use bubble-sort

	reOrderProjects(temp);

	// Above Loop might solve the problem, otherwise this type of method might be used
	// deleteProjectByPriority(temp->head ,tProject->project_priority);
	// addInOrder(temp->head, tProject->project_name, project_priority);//with new project_priority
	// or delete the node first and then addInOrder again
}

// the function returns true and assigns the project to the 
// 	employee by observing the ordering rules and if needed by adding a new employee row.
bool EmployeeProject2DLL::assignEmployeeToProject(string employee_name, string project_name, int project_priority)
{
	// first, check if there is a project with same priority
	EmployeeNode *temp = getEmployee(employee_name);
	
	// TODO: If temp is null that means this is new employee, generate new employee and add in alphabetical order
	
	if (temp == NULL)
		temp = addNewEmployee(employee_name); 

	// employee is found, now it is time to check duplicates
	
	ProjectNode *tProject = getProjectByPriority(temp, project_priority);
	if (tProject != NULL) // that means, there is a duplicate
		return (false);

	// no duplicates found, lets add in order
	addProjectInOrder(temp, project_name, project_priority);
}

void EmployeeProject2DLL::withdrawEmployeeFromProject(string employee_name, string project_name, int &project_priority)
{
	/*
		This
		function assumes that there exists such an employee-project
		pair in the data structure and 
		priority is not a criterion for selection.
	*/
	EmployeeNode *emp = getEmployee(employee_name);
	// assuming that employee is not empty
	ProjectNode *project = getProjectByName(emp, project_name);
	project_priority = project->project_priority;
	deleteProjectByName(emp, project_name);
	if (emp->head == NULL) // if there are no projects left
		deleteEmployeeByName(emp->employee_name);
}

// Employee name yok ise yeni employee oluşturmak gerekiyor olabilir

/*
Please enter option number:
3
cem: (ai, 4) 

The list is empty
*/

void EmployeeProject2DLL::printTheEntireList( void )
{
	EmployeeNode *temp = this->top;

	while (temp != NULL)
	{
		cout << temp->employee_name << ": ";
		printTheProjects(temp, 1); // mode 1 by default
		temp = temp->down;
	}
}

void EmployeeProject2DLL::printEmployeeProjects(string employee_name, int mode)
{
	// "The employee is not in the list."
	EmployeeNode* emp = getEmployee(employee_name);
	if (emp == NULL)
	{
		cout << "The employee is not in the list." << endl;
		return ;
	}
	printTheProjects(emp, mode);
}

void EmployeeProject2DLL::undo(char type, string employee_name, string project_name, int project_priority)
{

}

/*
This function takes no parameters, and is responsible for deallocating the
dynamically-allocated memory of the entire 2DHLL structure.
*/
void EmployeeProject2DLL::clear( void )
{

}



function()
{

	while (isOrdered)
	{
		ProjectNode *head = temp->head;
		while (head->next != null)
		{
			if (head->pri > head->next->pri)
			{
				// [] <-> [ head ] <-> [ 2 ] <-> []
				head->prev->next = head->next;
				ProjectNode *prev = head->prev;
				head->next->prev = prev;
				head->next->next = head;
				prev->next = head->next;
				head->next = head->next->next;

			}
		}
	}


}


temp = emphead;

while (temp != null)
	cout << temp->name << ": ";
	ProjectNode *protemp = temp->head;
	while (protemp != null)
	{
		cout << protemp->project_name << ", " 
	}