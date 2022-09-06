#include <bits/stdc++.h>
#define MAX_V 1010
#define MAXN 105
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define ld long double
#define pb push_back
#define ep emplace
#define all(x) x.begin(),x.end()
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

#define int long long

using namespace std;
signed main() {
    io
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        int max_w=0,max_r=0,r,w;
        for(int i=0;i<m;i++){
            cin>>r>>w;
            max_r=max(max_r,r);
            max_w=max(max_w,w);
        }
        if(max_r+max_w>n){
            cout<<"IMPOSSIBLE\n";
        }else{
            for(int i=0;i<max_r;i++){
                cout<<"R";
            }
            for(int i=0;i<n-max_r;i++){
                cout<<"W";
            }
            cout<<"\n";
        }
    }
}