#include<bits/stdc++.h>
#define INF 1e8
using namespace std;

int main() {
    int n, st, sub = 0, rangesum = 0, tsum = 0, msum = 0;
    string tm, trav;
    cin >> n;
    vector<pair<string, int>>v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> tm >> trav;
        int tot = 0;
        tot = stoi(tm.substr(0, 2)) * 60 + stoi(tm.substr(3, 2));
        v[i] = make_pair(trav, tot);
        if (i == 1) {
            st = tot;
            if (trav == "S")rangesum += 26;
            else sub++, rangesum += 28;
        }
        else {
            if (tot - st <= 90) {
                if (trav == "S")rangesum += 26;
                else if (trav == "U") {
                    sub++;
                    if (sub == 2) {
                        st = tot;
                        sub = 1;
                        tsum += (rangesum > 44 ? 44 : rangesum);
                        rangesum = 28;
                    }
                    else
                        rangesum += 28;
                }
            }
            else {
                st = tot;
                tsum += (rangesum > 44 ? 44 : rangesum);
                if (trav == "S")sub = 0, rangesum = 26;
                else sub = 1, rangesum = 28;
            }
        }
    }
    tsum += (rangesum > 44 ? 44 : rangesum);
    vector<int>dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        rangesum = 0, sub = 0;
        int r = i, st = v[i].second;
        while (r <= n && v[r].second - st <= 90) {
            if (v[r].first == "U")sub++;
            if (sub == 2) {
                break;
            }
            rangesum += (v[r].first == "U" ? 28 : 26);
            dp[r] = min(dp[r], dp[i - 1] + (rangesum > 44 ? 44 : rangesum));
            r++;
        }
    }
    cout << tsum << " " << dp[n] << "\n";
}