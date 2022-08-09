#include<bits/stdc++.h>
#define ll long long
#define MXN 2005
#define MAX 5005
#define MOD 1000000007
using namespace std;

int main() {
    int n, e, k, u, v;
    cin >> n >> e >> k;
    vector<vector<int>> edge(MXN, vector<int>(MXN, 0));
    for (int i = 0; i < k; i++) {
        cin >> u >> v;
        edge[u][v] = 1;
    }
    vector<vector<ll>> dp(MXN, vector<ll>(MAX, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (1 << (2 * e + 1)); j++) {     //窮舉上一個的所有選擇
            for (int k = -e; k <= e; k++) {
                if (i + k<1 || i + k>n)   //越界
                    continue;
                if ((j >> 1) & (1 << (k + e)))   //如果這個人已被挑過(撞車)，k+e讓他不為負，j>>1移動到下一個人
                    continue;
                if (edge[i][i + k])    //兩人不能相連
                    continue;
                dp[i][(j >> 1) | (1 << (k + e))] += dp[i - 1][j];
                dp[i][(j >> 1) | (1 << (k + e))] %= MOD;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < (1 << (2 * e + 1)); i++) {
        ans = (ans + dp[n][i]) % MOD;
    }
    cout << ans << "\n";
}