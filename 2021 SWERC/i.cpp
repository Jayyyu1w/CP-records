#include<bits/stdc++.h>
#define io ios::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define int long long
using namespace std;

signed main() {
    io
        int m, n;
    ll num;
    cin >> n >> m;
    vector<ll>ice(m+2), house;
    for (int i = 0; i < n; i++) {
        cin >> num;
        house.push_back(num);
    }
    for (int i = 1; i <= m; i++) {
        cin >> ice[i];
    }
    sort(ice.begin() + 1, ice.begin() + 1 + m);
    ice[0] = -200, ice[m + 1] = 2e9;
    map<ll, ll> mp;
    for (int i = 0; i < n;i++){
        int meter = i * 100;
        int pos = lower_bound(ice.begin(), ice.end(), meter) - ice.begin(); //找到第一個大於房屋的冰淇淋店
        int r = pos, l = pos - 1;   //房屋兩側最近的冰淇淋店
        ll dist = min(ice[r] - meter, meter - ice[l]);  //取到兩邊冰淇淋店最小值
        mp[meter - dist] += house[i], mp[meter + dist] -= house[i]; //距離差在+-dist內均可以獲得該房子的客人
    }
    ll ans = 0, temp = 0;
    for(auto it:mp){
        temp += it.second;
        ans = max(ans, temp);
    }
    cout << ans << "\n";
}