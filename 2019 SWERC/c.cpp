#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define pb push_back
#define ep emplace
#define all(x) x.begin(),x.end()
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long

using namespace std;

signed main(){
    io
    vector<int> a;
    int n,temp;
    cin >> n;
    while(n--){
        string str;
        cin >> str;
        if(str[0]=='-')
            continue;
        if(str.length()<=6){
            a.pb(stoi(str));
        }
            
    }
    sort(all(a));
    int ans=0;
    for(auto x:a){
        if(x==ans){
            ans++;
        }else{
            break;
        }
    }
    cout << ans<<"\n";
}
