#ifndef UNDO_STACK_H
# define UNDO_STACK_H

#include "EmployeeProject2DLL.h"

struct StackNode
{
	char operation;
	string employee_name;
	string project_name;
	int project_priority;
	StackNode * next;

	StackNode(char operation, string employee_name, string project_name, int project_priority, StackNode *next)
	{
		this->operation = operation;
		this->employee_name = employee_name;
		this->project_name = project_name;
		this->project_priority = project_priority;
		this->next = next;
	}
};

// verdiği operation'a göre logic yazarak ters işlem yapılabilir
// assign undo edilecekse withdraw kullanmak gibi olabilir

class UndoStack
{
	private:
		StackNode *top;
	public:
		UndoStack( void );
		void push(char operation, string employee_name, string project_name, int project_priority);
		void pop(char &operation, string &employee_name, string &project_name, int &project_priority);
		bool isEmpty( void );
		void clear( void );
};

#endif /* end of UNDO_STACK_H */