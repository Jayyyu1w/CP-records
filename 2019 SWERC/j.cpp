/*單調隊列+卡塔蘭數*/
#include<bits/stdc++.h>
#define MOD 1000000007
#define MXN 1000005
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(MXN), lmin(MXN);
    vector<ll> catalan(MXN), inv(MXN);
    catalan[0] = catalan[1] = 1, inv[1] = 1;
    for (int i = 2; i <= n + 1;i++){
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    }
    for (int i = 2; i <= n + 1; i++){
        catalan[i] = catalan[i - 1] * inv[i] % MOD;
        catalan[i] = ((catalan[i] * (2 * i - 1) % MOD) * (2 * i) % MOD) * inv[i + 1] % MOD;
    }
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    stack<int> stk;
    v[0] = -1;
    stk.push(0);
    for (int i = 1; i <= n; i++) {
        while (v[stk.top()] > v[i]) {
            stk.pop();
        }
        lmin[i] = stk.top();    //左邊最靠近v[i]的小於等於v[i]的值的位置
        stk.push(i);
    }
    ll ans = 1;
    vector<int> cnt(MXN, 0);
    for (int i = 1; i <= n; i++) {
        if (v[lmin[i]] < v[i]) {                    //如果當前值超過，代表該值被分割
            ans = ans * catalan[cnt[v[i]]] % MOD;   //乘入答案
            cnt[v[i]] = 1;                          //重新計數v[i]
        }else {                                     //當前值未超過
            cnt[v[i]]++;                            //增加v[i]數量
        }
    }
    for (int i = 1; i <= n; i++) {
        ans = ans * catalan[cnt[i]] % MOD;          //乘入剩下未計算之v[i]
    }
    cout << ans << "\n";
}