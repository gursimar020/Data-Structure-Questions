#include<stdio.h>
#define N 10
struct stack
   {
    int a[N];
    int top;
   };
typedef struct stack STACK;
STACK s;
   void push(int i)
   {
     if(s.top==N)
       printf("overflow");
     else
       s.a[++s.top]=i;
   }
   int pop()
   {
     if(s.top==-1)
       printf("underflow");
     else
       return s.a[s.top--];
   }
void display()
{
	int i=0;
	if(s.top==-1)
	printf("stack is empty");
	for(i=s.top;i>=0;i--)
	printf("%d",s.a[i]);
}
int main()
{
  s.top = -1;
  push(10);
  pop();

  display();
}
