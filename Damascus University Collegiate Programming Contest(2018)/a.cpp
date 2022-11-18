#include<bits/stdc++.h>
#define ll long long
using namespace std;
signed main(){
    int t;
    ll r1,r2;
    cin>>t;
    while(t--){
        cin>>r1>>r2;
        if(r1*r1>r2*r2*2){
            cout<<"1\n";
        }else{
            cout<<"2\n";
        }
    }
}