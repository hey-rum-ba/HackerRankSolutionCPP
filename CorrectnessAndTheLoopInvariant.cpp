#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
using namespace std;

void merge(int p[], int m, int q[], int n, int r[]){
    for(int rb=0, pf=0,qf=0;rb<m+n;rb++){
        if(pf<m&&qf<n){
            if(p[pf]<=q[qf]){
                r[rb]=p[pf];
                pf++;
            }
            else{
                r[rb]=q[qf];
                qf++;
            }
        }
        else if(pf<m){
            r[rb]=p[pf];
            pf++;
        }
        else{
            r[rb]=q[qf];
            qf++;
        }
    }
}

void mergesort(int*r,int n){
    if(n>1){
        int p[n/2],q[n-n/2];
        for(int i=0;i<n/2;i++)p[i]=r[i];
        for(int i=n/2;i<n;i++)q[i-n/2]=r[i];
        mergesort(p,n/2);
        mergesort(q,n-n/2);
        merge(p,n/2,q,n-n/2,r);
    }
}

int main(void) {
   
   int _ar_size;
cin>>_ar_size;
int _ar[_ar_size], _ar_i;
for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
   cin>>_ar[_ar_i];
}

mergesort(_ar,_ar_size);
   
    for(int i=0;i<_ar_size;i++)cout<<_ar[i]<<" ";
    cout<<endl;
   return 0;
}