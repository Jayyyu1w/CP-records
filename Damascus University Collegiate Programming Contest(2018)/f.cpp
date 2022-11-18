#include<bits/stdc++.h>
#define ll long long
#define MOD 7901
using namespace std;
signed main(){
    int t,n,num;
    cin>>t;
    while(t--){
        cin>>n;
        set<int> s;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            cin>>num;
            mp[num]++;
            s.insert(num);
        }
        ll ans=1;
        for(auto x:s){
            for(int i=1;i<=mp[x];i++){
                ans*=i;
                ans%=MOD;
            }
        }
        cout<<ans<<"\n";
    }
}