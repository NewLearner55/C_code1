#define _CRT_SECURE_NO_WARNINGS 1

assert(ps);
typedef char STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;
	int _capacity;
}Stack;

void StackInit(Stack* ps, int n)
{
	assert(ps);
	ps->_a = (STDataType*)malloc(sizeof(STDataType)*n);
	ps->_top = 0;
	ps->_capacity = n;
}

void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		ps->_a = (STDataType*)realloc(ps->_a, ps->_capacity * 2 * sizeof(STDataType));
		ps->_capacity *= 2;
	}

	ps->_a[ps->_top] = x;
	ps->_top++;
}

void StackPop(Stack* ps)
{
	assert(ps);
	if (ps->_top > 0)
	{
		ps->_top--;
	}
}

STDataType StackTop(Stack* ps)
{
	assert(ps);

	return ps->_a[ps->_top - 1];
}

int StackSize(Stack* ps)
return ps->_top;
}

int StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->_top == 0 ? 0 : 1;
}

bool isValid(char* s)
{
	struct Stack st;
	StackInit(&st, 10);
	char symbols[][2] = {
		{ '(', ')' },
		{ '[', ']' },
		{ '{', '}' },
	};
	while (*s)
	{
		int i = 0;
		for (; i < 3; ++i)
		{
			if (*s == symbols[i][0])
			{
				StackPush(&st, *s);
				++s;
				break;
			}
		}

		if (i == 3)
		{
			// 走到这里说明*s不是左括号
			char top = StackTop(&st);
			for (int j = 0; j < 3; ++j)
			{
				if (*s == symbols[j][1])
				{
					if (top == symbols[j][0])
					{
						++s;
						StackPop(&st);
						break;
					}
					else
					{
						return false;
					}
				}
			}
		}


	}

	if (StackEmpty(&st) == 0)
		return true;
	else
		return false;
}
