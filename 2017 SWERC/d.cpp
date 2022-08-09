/*dp+trie*/
#include<bits/stdc++.h>
#define MXN 55
#define LEN 2*50*200+10     //正反*最大長度*最大字串數量
using namespace std;

//dp[i][j] 將[i,j]的字元全部消除所得到的最大價值
//g[i][j][k] 將[i,j]中的字元全部消除，且最後消除位置在trie中為第k個

int tot = 0;    //總節點數量
int ans[MXN], val[LEN], ch[30][LEN];
int dp[MXN][MXN], g[MXN][MXN][LEN];
void add(string& s, int v) {
    int now = 0;
    for (auto i : s) {
        if (!ch[i - 'a' + 1][now]) {    //如果沒有節點，就添加節點
            ch[i - 'a' + 1][now] = ++tot;
        }
        now = ch[i - 'a' + 1][now];
    }
    val[now] = max(val[now], v);
}
void solve() {
    int c, v, len;
    string candy, s;
    vector<int> cost;
    cin >> candy;
    cin >> c;
    len = candy.length();
    memset(val, -1, sizeof(val));
    for (int i = 0; i < c; i++) {
        cin >> s >> v;
        if (s.length() > candy.length())
            continue;
        add(s, v);
        reverse(s.begin(), s.end());
        add(s, v);
    }
    candy = " " + candy;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= len; i++) {
        for (int j = 0; j <= len; j++) {
            for (int k = 0; k <= tot; k++) {
                g[i][j][k] = -1;
            }
        }
        g[i][i - 1][0] = 0;
    }
    for (int l = len; l > 0; l--) {
        for (int r = l - 1; r <= len; r++) {  //枚舉[l,r]區間
            for (int k = 0; k <= tot; k++) {
                if (g[l][r][k] == -1)
                    continue;
                //將前面區段全部更新一遍
                for (int x = r + 1; x <= len; x++) {
                    if (dp[r + 1][x] != -1) {   //這個區間可被全部消除
                        g[l][x][k] = max(g[l][x][k], g[l][r][k] + dp[r + 1][x]);    //兩個取最大值
                    }
                }
                if (r >= len)
                    continue;
                //區段更新完後再添加新字元
                int nxt = ch[candy[r + 1] - 'a' + 1][k];
                if (!nxt)
                    continue;
                g[l][r + 1][nxt] = max(g[l][r + 1][nxt], g[l][r][k]);
                if (val[nxt] != -1)   //該字元是結尾//g[i][j][0]紀錄g[i][j]的最大值
                    g[l][r + 1][0] = max(g[l][r + 1][0], g[l][r][k] + val[nxt]);
            }
            dp[l][r] = g[l][r][0];
        }
    }
    for (int i = 1; i <= len; i++) {    //以i為結尾所能得到的最大價值
        ans[i] = ans[i - 1];
        for (int j = 0; j < i; j++) {   //窮舉以i為結尾的所有子字串，取最大值
            ans[i] = max(ans[i], ans[j] + dp[j + 1][i]);
        }
    }
    cout << ans[len] << "\n";
}
int main() {
    solve();
}