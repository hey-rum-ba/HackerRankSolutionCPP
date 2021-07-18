#include<bits/stdc++.h>
using namespace std;

int main(){

    unsigned long long T,b,w,x,y,z,ans;
    cin >> T;
    for(int i = 1; i <= T; i++){
        cin >> b >> w;
        cin >> x >> y >> z;
        ans = (b * min(x,y+z)) + (w * min(y,x+z));
        cout << ans << endl;
    }
    return 0;
}