#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define int long long
#define pb push_back
#define ep emplace
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mp make_pair
using namespace std;

signed main(){
    io
    int n,car,cnt=0;
    cin >> n;
    while(n--){
        cin>>car;
        if(car==2||car==3)cnt++;
    }
    cout<<cnt<<"\n";
}