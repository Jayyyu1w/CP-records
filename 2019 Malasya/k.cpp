#include<bits/stdc++.h>
#define ll long long
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main(){
    io
    int t;
    int cas = 1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        ll sum=0,ans=0;
        for(int i=0;i<n;i++){
            if(sum+v[i]<=2*v[i]){
                ans++;
                sum+=v[i];
            }
        }
        cout <<"Case #"<<cas++<<": ";
        cout<<ans<<"\n";
    }
}