#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<ll>> dp(2, vector<ll>(n + 1, 0));
    dp[0][0] = 1, dp[1][0] = 1;
    for (int i = 0; i <= n;i++){
        for (int j = i + 1; j <= min(n, i + b); j++){   //1後面填b個2的方法數
            dp[0][j] = (dp[0][j] + dp[1][i]) % MOD;
        }
        for (int j = i + 1; j <= min(n, i + a);j++){    //2後面填a個1的方法數
            dp[1][j] = (dp[1][j] + dp[0][i]) % MOD;
        }
    }
    /*
    for (int j = 0; j < 2;j++){
        for (int i = 0; i <= n; i++){
            cout << dp[j][i] << " ";
        }
        cout << "\n";
    }*/
    cout << "\n";
    cout << (dp[0][n] + dp[1][n]) % MOD << "\n";
}