#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define pb push_back
#define ep emplace
#define all(x) x.begin,x.end
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long

using namespace std;

signed main(){
    io
    int n,m,i,j,sum,a,b;
    cin >> n;
    cin >> m;
    sum = 0;
    for(i=0;i<m;i++){
        cin >> a >> b;
        sum+=(a*b);
    }
    sum /= n;
    cout << sum <<"\n";
}