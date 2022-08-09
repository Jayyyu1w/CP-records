#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define pb push_back
#define ep emplace
#define all(x) x.begin,x.end
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// #define int long long

using namespace std;

signed main(){
    io
    int n,m;
    ll tmp,mx=0,ans=0;
    map<ll,ll> cnt;
    vector<ll> in,out;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>tmp;
        in.push_back(tmp);
    }
    for(int i=0;i<m;i++){
        cin>>tmp;
        out.push_back(tmp);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(out[j]>in[i]){
                ll diff=out[j]-in[i];
                cnt[diff]++;
                //cout<<diff<<"/"<<cnt[diff]<<"/"<<mx<<"\n";
                if(cnt[diff]>mx){
                    ans=diff;
                    mx=cnt[diff];
                }else if(cnt[diff]==mx&&diff<ans){
                    ans=diff;
                }
            }
        }
    }
    cout<<ans<<"\n";
}