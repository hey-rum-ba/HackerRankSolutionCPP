#include <math.h>
#include<iostream>


using namespace std;

void catsandmouse()
{
    int x,y,z,a,b;
    cin>>x>>y>>z;
    a = abs(z-x);
    b = abs(z-y);
    if(a>b)cout<<"Cat B"<<endl;
    else if(b>a)cout<<"Cat A"<<endl;
    else cout<<"Mouse C"<<endl;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {catsandmouse();};
    return 0;
}