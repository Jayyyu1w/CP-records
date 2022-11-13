#include<bits/stdc++.h>
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int ans = 0;
    for (int l = 0; l < n; l++) {
        for (int len = 1; len <= n; len++) {
            int val = 0;
            priority_queue<pair<int, int>> pq;
            for (int i = l; i < l + len;i++){
                pq.push(make_pair(a[i % n], i % n));
            }
            int rem = m - min({l, n - l, (l + len - 1) % n, n - ((l + len - 1) % n)}) - (len - 1);
            while(rem-- > 0){   //要加限制，不然<0還會一直跑
                pair<int, int> tp = pq.top();
                pq.pop();
                val += tp.first;
                pq.push(make_pair(max(tp.first - b[tp.second], 0), tp.second));
            }
            // cerr << val << "\n";
            ans = max(ans, val);
        }
    }
    cout << ans << "\n";
}