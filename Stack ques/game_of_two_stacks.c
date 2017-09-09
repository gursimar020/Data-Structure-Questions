//Game of Two Stacks


#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int g; 
    scanf("%d",&g);
    for(int a0 = 0; a0 < g; a0++){
        int n; 
        int m; 
        int x; 
        scanf("%d %d %d",&n,&m,&x);
        int *a = malloc(sizeof(int) * n);
        for(int i = 0; i < n; i++){
           scanf("%d",&a[i]);
        }
        int *b = malloc(sizeof(int) * m);
        for(int i = 0; i < m; i++){
           scanf("%d",&b[i]);
        }
        
        
         int sum=0,count=0,temp=0,i=0,j=0;        
        while(i<n && sum+a[i]<=x)
        {    
            sum+=a[i];
            i++;
        }
        count=i;        
        
        while(j<m && i>=0){             
            sum+=b[j];             
            j++;
            while(sum>x && i>0){
                i--;
                sum-=a[i];
            }
            if(sum<=x && i+j>count)
                count=i+j;
        }
       printf("%d\n",count);
    } 
    return 0;
    }
    
