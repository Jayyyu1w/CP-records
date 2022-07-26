#include<bits/stdc++.h>
using namespace std;

struct times {
    int id, st, ed, w;
    times() {}
    times(int _id, int _st, int _ed, int _w) {
        id = _id, st = _st, ed = _ed, w = _w;
    }
};
int main() {
    int n, s, a, o, t;
    cin >> n;
    vector<vector<times>> stage(n);
    vector<int> disc;
    for (int i = 0; i < n; i++) {
        cin >> t;
        for (int j = 0; j < t; j++) {
            cin >> s >> a >> o;
            stage[i].push_back(times(i, s, a, o));
            disc.push_back(s);
            disc.push_back(a);
        }
    }
    sort(disc.begin(), disc.end());
    int tot = unique(disc.begin(), disc.end()) - disc.begin();
    vector<vector<times>> show(tot);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < stage[i].size(); j++) {
            stage[i][j].st = lower_bound(disc.begin(), disc.begin() + tot, stage[i][j].st) - disc.begin();
            stage[i][j].ed = lower_bound(disc.begin(), disc.begin() + tot, stage[i][j].ed) - disc.begin();
            show[stage[i][j].st].push_back(stage[i][j]);
        }
    }
    vector<vector<int>> dp(tot + 1, vector<int>((1 << n) + 1, -1));
    dp[0][0] = 0;
    for (int i = 0; i < tot; i++) {     //遍歷開始時間
        for (int j = 0; j < (1 << n); j++) {
            dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
        }
        for (int j = 0; j < show[i].size(); j++) {  //遍歷所有在此開始時間的活動
            for (int k = 0; k < (1 << n); k++) {    //窮舉所有舞台狀態(0不選1選)
                if (dp[i][k] == -1)     //代表之前狀態還沒出現過，不能更新(挑選的這些舞台在這個開始時間沒有表演)
                    continue;
                dp[show[i][j].ed][k | (1 << show[i][j].id)] = max(dp[show[i][j].ed][k | (1 << show[i][j].id)], dp[i][k] + show[i][j].w);
                //如果有表演，更新以此為開始時間的每個結束時間的位置的最大值
            }
        }
    }
    cout << dp[tot][(1 << n) - 1] << "\n";
}