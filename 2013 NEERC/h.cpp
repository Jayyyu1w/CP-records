#include<bits/stdc++.h>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

signed main(){
    io
    int xa,ya,xs,ys,xb,yb;
    cin >> xa >> ya >> xs >> ys;
    cin >> xb >> yb;
    int xl=min(xa,xs),xr=max(xa,xs),yu=min(ya,ys),yd=max(ya,ys);
    if(xr>=xb && xb>=xl && yd>=yb && yb>=yu ){
        cout << "Yes\n"; 
    }else{
        cout << "No\n";
    }
}