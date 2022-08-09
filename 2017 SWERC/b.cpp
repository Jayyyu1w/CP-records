/*單調隊列*/
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int x, y, n, d, x1, x2, y1, y2, a, b;
    cin >> x >> y >> n >> d;
    vector<vector<int>> graph(x + 1, vector<int>(y + 2, 0)), presum(x + 1, vector<int>(y + 2, 0)), ans(x + 1, vector<int>(y + 2, 0)), rect(x + 1, vector<int>(y + 2, 0));
    for (int i = 0; i < n; i++) {
        cin >> x1 >> x2 >> y1 >> y2;
        x1++, y1++;
        for (int j = x1; j <= x2; j++) {
            for (int k = y1; k <= y2; k++) {
                graph[j][k] = 1;
            }
        }
    }
    for (int i = 1; i <= d; i++) {
        cin >> a >> b;
        rect[a][b] = i;
    }
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            if (!graph[i][j]) {
                presum[i][j] = presum[i - 1][j] + 1;
            }
        }
    }
    for (int i = 1; i <= x; i++) {
        stack<pair<int, int>> stk;
        stk.push(make_pair(0, 0));
        for (int j = 1; j <= y + 1; j++) {
            pair<int, int> cur = make_pair(presum[i][j], j);
            while (cur.first < stk.top().first) {
                cur.second = stk.top().second;
                ans[stk.top().first][j - cur.second]++; //增加矩形個數(要被pop掉的那個矩形)
                stk.pop();
                ans[max(cur.first, stk.top().first)][j - cur.second]--;   //消除重複底的影響
            }
            stk.push(cur);
        }
    }
    vector<int> sum(y + 1, 0), sum2(y + 1, 0), cnt(d + 1, 0);
    for (int i = x; i >= 1; i--) {
        for (int j = y; j >= 1; j--) {
            sum[j] += ans[i][j];
        }
        for (int j = y; j >= 1; j--) {
            sum2[j] = (j == y ? 0 : sum2[j + 1]) + sum[j];  //計算後綴和(當前的貢獻)
        }
        for (int j = y; j >= 1; j--) {
            sum2[j] = (j == y ? 0 : sum2[j + 1]) + sum2[j]; //計算後綴和的後綴和(加上前面的貢獻)
        }
        for (int j = 1; j <= y; j++) {
            if (rect[i][j]) {
                cnt[rect[i][j]] = sum2[j];
            }
        }
    }
    for (int i = 1; i <= d; i++) {
        cout << cnt[i] << "\n";
    }
}
int main() {
    solve();
}