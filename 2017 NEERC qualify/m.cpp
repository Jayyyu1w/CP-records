#include<bits/stdc++.h>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

signed main(){
    io    
    int n;
    cin >> n;
    vector<int> a(n+5);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int diff = a[2]-a[1], fail=false;
    for(int i = 2;i<n;i++){
        if(a[i+1]-a[i]!=diff){
            fail=true;
            break;
        }
    }
    if(fail)cout<<a[n]<<"\n";
    else cout<<a[n]+diff<<"\n";
}