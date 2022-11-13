#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using namespace std;

//題解不會過你要先講
int n, m;
vector<int> a, b;
vector<vector<int>> getdp(){
    vector<vector<int>> dp(n, vector<int>(m + 1, -INF));
    dp[0][0] = 0;
    for (int i = 1; i <= m;i++){
        dp[0][i] = dp[0][i - 1] + max(0, a[0] - (i - 1) * b[0]);
    }
    for (int i = 1; i < n;i++){
        for (int j = 0; j <= m;j++){
            int sum = 0;
            for (int k = 0; k < j;k++){     //dp[i][j]由i-1的前j-1個轉移
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k - 1] + sum);
                sum += max(0, a[i] - k * b[i]);     //增加獲得的coin
            }
        }
    }
    return dp;
}
int main(){
    io
    int num;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num;
        a.push_back(num);
    }
    for (int i = 0; i < n; i++) {
        cin >> num;
        b.push_back(num);
    }
    vector<vector<int>> dp = getdp();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vector<vector<int>> dp1 = getdp();
    int ans = 0;
    for (int i = 0; i < n;i++){
        ans = max({ans, dp[i][m], dp1[i][m - 1]});
    }
    
    for (int r = 0; r < n; r++){    //l,r = 從0往左/右走的距離
        for (int l = 0; l < n; l++){
            if (r >= n - l - 1) //l不超過r
                continue;
            for (int i = r; i <= m;i++){    //右邊先走
                if (i + r + 1 > m){
                    continue;
                }
                ans = max(ans, dp[r][i] + dp1[l][m - (i + r + 1)]);     
            }
            for (int i = l; i <= m;i++){    //左邊先走
                if (i + l + 2 > m){
                    continue;
                }
                ans = max(ans, dp[r][m - (i + l + 2)] + dp1[l][i]);
            }
        }
    }

    cout << ans << "\n";
}