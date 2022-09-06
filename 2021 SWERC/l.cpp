#include<bits/stdc++.h>
#define int long long
#define MXN 200005
using namespace std;

signed main(){
    int n, v, p;
    int kick[MXN];
    vector<pair<int,int>> pos;
    cin >> n >> v;
    for (int i = 0; i < n;i++){
        cin >> kick[i];
    }
    for (int i = 0; i < n;i++){
        cin >> p;
        if (kick[i] * v >= abs(p)){
            pos.push_back(make_pair(kick[i] * v - p, kick[i] * v + p));
        }
    }
    sort(pos.begin(), pos.end());
    vector<int> lis;
    for(auto it:pos){
        if (lis.empty() || lis.back() <= it.second){
            lis.push_back(it.second);
        }else{
            p = upper_bound(lis.begin(), lis.end(), it.second) - lis.begin();
            lis[p] = it.second;
        }
    }
    cout << lis.size() << "\n";
}