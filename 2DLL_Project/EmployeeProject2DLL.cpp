#include "EmployeeProject2DLL.h"
// priorities are ascending
// Useful functions to write
// 0. reOrder the list
// 1. addInOrder

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

void EmployeeProject2DLL::deleteProjectByName(EmployeeNode *employee, string project_name)
{
	// some cases // []<->[]<->[] // []<->[] // [] // NULL
	ProjectNode *temp = getProjectByName(employee, project_name);
	if (temp == NULL)
		return ;
	else if (temp->prev == NULL && temp->next == NULL)
	{
		// we need to delete employee and project
	}
	else if (temp->next == NULL)
	{
		ProjectNode *temp2 = temp;
		temp->prev->next = NULL;
		temp2->prev = NULL; // may be not required
		delete temp2;
	}
	else if (temp->prev == NULL)
	{
		ProjectNode *temp2 = temp;
		employee->head = temp->next;
		temp->prev = NULL;
		delete temp2;
	}
	else
	{

	}
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

bool EmployeeProject2DLL::isProjectsSorted(ProjectNode *head)
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

	if (temp == NULL)
	{
		this->top = new EmployeeNode(employee_name, NULL, NULL, this->top);
		return (this->top);
	}
	else if (employee_name.compare(temp->employee_name) > 0)
	{
		this->top = new EmployeeNode(employee_name, NULL, NULL, this->top);
		return (this->top);
	}
	while (temp->down != NULL && employee_name.compare(temp->employee_name) > 0) // while newName is greater
		temp = temp->down;
	temp->down = new EmployeeNode(employee_name, NULL, NULL, temp->down);
	return (temp->down);
}


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
	
	tProject = temp->head;
	while (isProjectsSorted(temp->head) == false)
	{
		if (tProject->project_priority > tProject->next->project_priority)
		{
			// prev[tProject]next <-> prev[next]next
			ProjectNode *next = tProject->next;
			next->prev = tProject->prev;
			tProject->next = next->next;
			next->next = tProject;
		}
		tProject = tProject->next;
		if (tProject == NULL)
			tProject = temp->head;
	}

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
	EmployeeNode *temp = this->top;
	while (temp->employee_name != employee_name)
		temp = temp->down;
	// deleteProject
}

// Employee name yok ise yeni employee oluşturmak gerekiyor olabilir