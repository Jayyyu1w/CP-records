#include<bits/stdc++.h>
#define io ios::sync_with_stdio(false);cin.tie(0);
#define ll long long
using namespace std;

int main() {
    io
    int n,k;
    vector<int> arr;
    cin>>n>>k;
    for(int i=0,tmp;i<n;i++){
        cin>>tmp;
        arr.push_back(tmp);
    }
    arr.push_back(0);
    ll ans=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0)continue;
        if(arr[i]>=k){
            ans+=(arr[i]/k);
            arr[i]=arr[i]%k;
        }
        if(arr[i]==0)continue;
        ans++;
        if(arr[i]+arr[i+1]<=k)
            arr[i+1]=0;
        else
            arr[i+1]-=(k-arr[i]);
    }
    cout<<ans<<"\n";
}