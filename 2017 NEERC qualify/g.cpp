#include<bits/stdc++.h>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

signed main(){
    io    
    int n;
    string s;
    cin >> n;
    vector<string>v;
    for(int i=0;i<n;i++){
        cin>>s;
        v.push_back(s);
    }
    int cnt = 0,mx = 0;
    for(int i=0;i<7;i++){
        cnt=0;
        for(int j=0;j<n;j++){
            if(v[j][i] == '1'){
                cnt++;
            }
        }
        mx=max(mx,cnt);
    }
    cout<<mx<<"\n";
}