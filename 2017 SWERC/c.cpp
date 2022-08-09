/*矩陣快速冪*/
/*O((2^n)^3*lg(m))*/
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000000
using namespace std;

int n, sz;
ll m;
vector<vector<ll>> base, t;
void dfs(ll p,ll cur,ll to){
    if(p>=n){
        base[to][cur]++;
        return;
    }
    if(cur&(1<<p)){
        dfs(p + 1, cur, to);    //放2*1，所以前一行的同列不能有東西
        dfs(p + 1, cur, to|(1 << p)); //放1*1，所以前一行的同列就必須有東西
        if(p+1<n&&(cur&(1<<(p+1)))){
            dfs(p + 2, cur, to|(1 << p)|(1 << (p + 1))); //放1*2，則p+1行不需考慮(只能放1*1)
        }
    }else{
        dfs(p + 1, cur, to|(1 << p)); //如果這個位置沒有放東西則前面一行必須要有東西(避免未填長度超過2)
    }
}
vector<vector<ll>> mul(vector<vector<ll>>&a,vector<vector<ll>>&b){
    vector<vector<ll>> c(sz, vector<ll>(sz, 0));
    for (int k = 0; k < sz;k++){
        for (int i = 0; i < sz;i++){
            if(a[i][k]){
                for (int j = 0; j < sz;j++){
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j] % MOD) % MOD;
                }
            }
        }
    }
    return c;
}
ll fastpow(ll m){
    t[sz - 1][sz - 1] = 1;
    while(m){
        if(m&1){
            t = mul(t, base);
        }
        m >>= 1;
        base = mul(base, base);
    }
    return t[sz - 1][sz - 1];
}
void solve(){
    cin >> n >> m;
    sz = 1 << n;
    t.resize(sz, vector<ll>(sz, 0));
    base.resize(sz, vector<ll>(sz, 0));
    for (int i = 0; i < sz; i++){
        dfs(0, i, 0);
    }
    cout << fastpow(m) << "\n";
}
int main(){
    solve();
}