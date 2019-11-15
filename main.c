#include <stdio.h>
#include <stdlib.h>

typedef int StackValue;

typedef struct Stack
{
	size_t size;
	void *stack_head;
} Stack;

typedef Stack *StackP;

StackP mainStack;

void CreateStack();
StackValue *ExpandStack();
void AddStack(StackValue value);
void PrintStack();
StackValue *GetOnStack(size_t index);
StackValue GetValueOnStack(size_t index);
void ChangeValueOnStack(size_t index, StackValue value);
void ClearStack();

int main(int argc, char const *argv[])
{
	CreateStack();

	AddStack(5);
	AddStack(15);
	AddStack(25);
	AddStack(35);
	AddStack(45);

	ChangeValueOnStack(2, 55);

	int c = GetValueOnStack(2);

	PrintStack();

	ClearStack();

	c = GetValueOnStack(2);

	return 0;
}

void CreateStack(){
	StackP newStack = (StackP) malloc(sizeof(Stack));

	newStack->size = 0;
	newStack->stack_head = (void *) malloc(sizeof(StackValue)*0);

	mainStack = newStack;
}

StackValue *ExpandStack(){
	mainStack->stack_head = realloc(mainStack->stack_head, sizeof(StackValue)*(++(mainStack->size)));

	return ((StackValue *)(mainStack->stack_head) + (mainStack->size) - 1);
}

void AddStack(StackValue value){
	*ExpandStack() = value;
}

void PrintStack(){
	int val = -1;
	for (size_t i = 0; i < mainStack->size; i++)
	{
		val = GetValueOnStack(i);
		printf("%d ", val);
	}
	
}

StackValue *GetOnStack(size_t index){
	return ((StackValue *)(mainStack->stack_head)+index);
}

StackValue GetValueOnStack(size_t index){
	return *(GetOnStack(index));
}

void ChangeValueOnStack(size_t index, StackValue value){
	*GetOnStack(index) = value;
}

void ClearStack(){
	mainStack->size = 0;
	free(mainStack->stack_head);
}
