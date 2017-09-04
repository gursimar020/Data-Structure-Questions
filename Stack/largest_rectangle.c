//WAP to find largest rectangle


#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

long int largestRectangle(int N, int* h) {
    int prev,next,s;
    long int max=0;
    
    for(int i=0;i<N;i++)
    {
        s=h[i];
        prev=i-1;
        while(prev>=0 && h[prev]>=h[i])
        {
            s+=h[i];
            prev--;
        }
        next=i+1;
        while(next<N && h[next]>=h[i])
        {
            s+=h[i];
           next++;
        }
        if(s>max)
        max=s;
     }
    return max;
}


int main() {
    int n; 
    scanf("%d", &n);
    int *h = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
       scanf("%i",&h[i]);
    }
    
    long int result = largestRectangle(n,h);
    printf("%ld\n", result);
    return 0;
}
