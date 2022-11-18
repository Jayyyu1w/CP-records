#include<bits/stdc++.h>
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define MOD 1000000007
#define MOD2 1000000009
#define p1 75577
#define p2 12721
#define ll long long
using namespace std;

int main(){
    io
    vector<ll> pow1(4500, 0), pow2(4500, 0);
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i < 4500;i++){
        pow1[i] = (pow1[i - 1] * p1) % MOD;
        pow2[i] = (pow2[i - 1] * p2) % MOD2;
    }
    int t;
    cin >> t;
    while(t--){
        int n, u, v, idx = 1;
        cin >> n;
        vector<ll> vec(n);
        map<pair<int,int>, int> mp;
        map<pair<ll, ll>, ll> hmp[4500];    //儲存使用編號i~j的邊的數量
        for (int i = 0; i < n;i++){
            cin >> u >> v;
            if (u > v)
                swap(u, v);
            if(!mp.count(make_pair(u, v)))
                mp[make_pair(u, v)] = idx++;
            vec[i] = mp[make_pair(u, v)];   //同一個編號組合使用同一個id
        }
        ll hash1, hash2, ans = 0;
        for (int i = 0; i < n;i++){
            hash1 = 0, hash2 = 0;
            for (int j = i; j < n;j++){     //窮舉編號組合
                hash1 = (hash1 + pow1[vec[j]]) % MOD;
                hash2 = (hash2 + pow2[vec[j]]) % MOD2;
                ans += hmp[j - i][make_pair(hash1, hash2)];     //加上重複數量
                hmp[j - i][make_pair(hash1, hash2)]++;          //存入map
            }
        }
        cout << ans << "\n";
    }
}