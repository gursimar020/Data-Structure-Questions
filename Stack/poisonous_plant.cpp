//poisonous plant using stack

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<stack>
using namespace std;


int main() {
       int n;
    cin >> n;
    int *p = new int [n];
    for(int i=0;i<n;i++)
        cin >> p[i];
    
    stack<int> st;
    int *killer = new int [n];//which killed i
    int *daycount = new int [n];//how long i can exist
    int *killcount = new int [n];//how many i killed
    for(int i=0;i<n;i++)
    {
        daycount[i] = 0;
        killcount[i] = 0;
    }
    
    for(int i=0;i<n;i++)
     {        
        while(!st.empty() && p[i]<=p[st.top()])
            st.pop();
        
        if(st.empty())
        {
            killer[i] = -1;
            daycount[i] = -1;
        }
        else
        {
            killer[i] = st.top();
            killcount[killer[i]]++;
            daycount[i] += killcount[killer[i]];
            daycount[st.top()]--;
            if(killer[st.top()]>=0 && daycount[st.top()]<=0)
                st.pop();
        }
        
        st.push(i);       
    }
   
    int max = -1;
    for(int i=0;i<n;i++)
        if(max<killcount[i])
            max = killcount[i];
    
    cout << max << endl;
    
   
    return 0;
}
