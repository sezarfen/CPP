#include "UndoStack.h"

UndoStack::UndoStack( void )
{
	this->top = NULL;
}

void UndoStack::push(char operation, string employee_name, string project_name, int project_priority)
{
	if (this->top == NULL)
	{
		this->top = new StackNode(operation, employee_name, project_name, project_priority, NULL);
	}
	else
	{
		StackNode *temp = this->top;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new StackNode(operation, employee_name, project_name, project_priority, NULL);
	}
}

void UndoStack::pop(char &operation, string &employee_name, string &project_name, int &project_priority)
{
	if (isEmpty())
	{
		cout << "The undo stack is empty." << endl;
		return ;
	}
	StackNode *temp = this->top;
	operation = temp->operation;
	employee_name = temp->employee_name;
	project_name = temp->project_name;
	project_priority = temp->project_priority;
	this->top = this->top->next;
}

bool UndoStack::isEmpty( void )
{
	return (this->top == NULL);
}

void UndoStack::clear( void )
{
	StackNode *curr = this->top;
	StackNode *next = this->top->next;

	while (next != NULL)
	{
		next = curr->next;
		delete curr;
		curr = next;
	}
	if (curr != NULL) // if there is only one node
	{
		delete curr;
		curr = NULL;
	}
}