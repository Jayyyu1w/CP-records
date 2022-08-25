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
    int n,mx=0;
    string str,mxstr;map<string,int> cnt;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>str;
        cnt[str]++;
        //cout<<cnt[str]<<"\n";
        if(cnt[str]>mx){
            mx=cnt[str];
            mxstr=str;
        }
    }
    if(cnt[mxstr]>n-(cnt[mxstr]))
        cout<<mxstr<<"\n";
    else
        cout<<"NONE\n";
}