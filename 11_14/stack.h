#include"common.h"
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;
	int _capacity;
}Stack;
void StackInit(Stack* ps, int n);
void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);
STDataType StackTop(Stack* s);
int StakcSize(Stack* ps);
int StackEmpty(Stack* ps);
void StackTest();