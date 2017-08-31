//Equal Stacks


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n1;
    int n2;
    int n3;
    int nSum1 = 0, nSum2 = 0, nSum3 = 0;
    int nheight =0;
    cin >> n1 >> n2 >> n3;
    vector<int> h1(n1);
    for(int h1_i = 0;h1_i < n1;h1_i++){
       cin >> h1[h1_i];
       nSum1 += h1[h1_i];
    }
    vector<int> h2(n2);
    for(int h2_i = 0;h2_i < n2;h2_i++){
       cin >> h2[h2_i];
       nSum2 += h2[h2_i];
    }
    vector<int> h3(n3);
    for(int h3_i = 0;h3_i < n3;h3_i++){
       cin >> h3[h3_i];
       nSum3 += h3[h3_i];
    }
    
    // find the maximum height
    // remove max & compare
    bool bBreak=false;
    while(!bBreak)
    {
        if(nSum1 == nSum2 && nSum1 == nSum3)
        {
            nheight = nSum1;
            bBreak = true;
        }
        else if(nSum2 >= nSum3 && nSum2 >= nSum1)
        {
            nheight = nSum2 = nSum2 - h2[0];
            if(!h2.empty())
                h2.erase(h2.begin());
        }
        else if(nSum1 >= nSum3 && nSum1 >= nSum2)
        {
            nheight = nSum1 = nSum1 - h1[0];
            if(!h1.empty())
                h1.erase(h1.begin());
        }
        else
        {
            nheight = nSum3 = nSum3 - h3[0];
            if(!h3.empty())
                h3.erase(h3.begin());
        }
    }
      
   if(h1.empty() && h2.empty() && h3.empty() && nheight > 0)
   {
       nheight = 0;
   }
   cout<<nheight;
   return 0;
}