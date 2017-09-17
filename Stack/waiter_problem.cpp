//waiter problem


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int pri[100000]={0};

void prime()
{

    int count=1;
    int flag=0;
    for(int i=2;i<=10000;i++)
    {
        for(int j=2;j<=i/2;j++)
        {
            if(i%j==0)
            {
               flag=1;
                break;
            }

        }
        if(flag==0)
        {
        pri[count++]=i;
            //cout<<count-1<<" -> : "<<i<<"\n";
        }
        
        flag=0;
        
    }
    
}

struct stack
{
    int top;
    int items[60000];
};
typedef struct stack stk;

int pop(stk *s)
{
    if(s->top==-1)
        return -1;
    int so=s->items[s->top];
    s->top--;
    return so;
}

void push(stk *s,int x)
{
    if(s->top==49999)
        return;
    s->top++;
    s->items[s->top]=x;
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    prime();
    stk s,a,b;
    s.top=-1;
    a.top=-1;
    b.top=-1;
    int flag=0;
    int n,q,x;
    int p;
    cin>>n>>q;
    while(n--)
    {
        cin>>x;
        push(&s,x);
    }
    for(int i=1;i<=q;i++)
    {
        if(a.top==-1)
        {
            p=pop(&s);
            while(p!=-1)
            {
                if(p%pri[i]==0)
                    push(&b,p);
                else
                    push(&a,p);
                p=pop(&s);
            }
            p=pop(&b);
            while(p!=-1)
            {
                cout<<p<<"\n";
                p=pop(&b);
            }
            b.top=-1;
        }
        else
        {
            p=pop(&a);
            while(p!=-1)
            {
                if(p%pri[i]==0)
                    push(&b,p);
                else
                    push(&s,p);
                p=pop(&a);
            }
            p=pop(&b);
            while(p!=-1)
            {
                cout<<p<<"\n";
                p=pop(&b);
            }
            b.top=-1;
        }
    }
    p=pop(&s);
    while(p!=-1)
    {
        cout<<p<<"\n";
        p=pop(&s);
    }
    p=pop(&a);
    while(p!=-1)
    {
        cout<<p<<"\n";
        p=pop(&a);
    }
}
        
   