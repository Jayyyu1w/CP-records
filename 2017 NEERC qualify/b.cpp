#include<bits/stdc++.h>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MXN 200005
using namespace std;

vector<int>v(MXN);
vector<vector<int>>ans(MXN);
vector<int>endval(MXN, 0);
signed main(){
    io    
    int n;
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        auto pos = lower_bound(endval.rbegin(),endval.rend(),v[i]) - endval.rbegin();
        pos--;
        endval[MXN - 1 - pos]=v[i];
        ans[MXN - 1 - pos].push_back(v[i]);
    }
    for(int i=0;endval[i]!=0;i++){
        for(auto it:ans[i]){
            cout<<it<<" ";
        }
        cout<<"\n";
    }
}