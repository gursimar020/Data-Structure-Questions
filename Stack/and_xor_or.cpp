//AND xor OR

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<stack>
using namespace std;


int main() {
    int n,x,max=0;
    cin>>n;
    stack<int> mystack;
    while(n--){
        cin>>x;
        while(!mystack.empty()){
            if((x^mystack.top())>max)
                max=x^mystack.top();
            if(x<mystack.top())
                mystack.pop();
            else
                break;
        }
        mystack.push(x);
    }
    cout<<max;
    return 0;
}
