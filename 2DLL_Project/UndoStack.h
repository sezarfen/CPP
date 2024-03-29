#ifndef UNDO_STACK_H
# define UNDO_STACK_H

class UndoStack
{

	public:
		UndoStack();
		void push();
		/* some type */ void pop();
		bool isEmpty();
		void clear();
};

#endif /* end of UNDO_STACK_H */