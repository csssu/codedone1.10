#include <stdio.h>
 
// int MAX_SIZE = 100;
 
int stackSize = 0;
int STACK_CAPACITY = 100;
int top = -1;
 
char stack[100];
 
void stackPush(char newValue)
{
    if(stackSize == STACK_CAPACITY) return;
    else
    {
        stack[++top] = newValue;
        stackSize++;
    }
}
 
void stackPop()
{
    top--;
    stackSize--;
}
 
int queueSize = 0;
int QUEUE_CAPACITY = 100;
int front = -1;
int rear = -1;
 
char queue[100];
 
void queuePush(char newValue)
{
    if(queueSize == QUEUE_CAPACITY) return;
    else
    {
        queue[++rear] = newValue;
        queueSize++;
    }
}
 
void queuePop()
{
    front++;
    queueSize--;
}
 
int main()
{
    int sSize = 0;
    char s[100];
 
    scanf("%s", s);
		
		for(int i = 0; i < 100; i++)
		{
			if(s[i] == '\0')
			{
				sSize = i;
				break;
			}
		}
 
    for(int i = 0; i < sSize; i++)
    {
        if(s[i] == '\\' && i + 1 < sSize)
        {
            while(stack[top] != '/')
            {
                char c = stack[top];
                queuePush(c);
                stackPop();
            }
 
            stackPop();
 
            while(queueSize != -1)
            {
                char c = queue[front + 1];
                stackPush(c);
                queuePop();
            }
        }
        else
        {
            stackPush(s[i]);
        }
    }
 
    stackPop();    
 
	while(stackSize != 1)
	{
		printf("%c", stack[top]);
		stackPop();
		
		if(stackSize == 0) break;
	}
 
    return 0;
 
}
Language: C