#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    cin >> n >> t;
    int wait[n + 2];
    memset(wait, 0, sizeof(wait));
    for (int i = 1; i <= n;i++){
        cin >> wait[i];
    }
    int ans = 0;
    priority_queue<int>pq;
    for (int i = 1; i <= min(t - 1, n);i++){    //窮舉所有可走到位置
        int rem = t - i;    //剩下可等待時間
        while(!pq.empty() && pq.top() >= rem){  //>=可等時間就刪除
            pq.pop();
        }
        if (wait[i] < t)   //等待時間跟位置必須小於總時間
            pq.push(wait[i] - i);
        ans = max(ans, (int)pq.size());
    }
    cout << ans << "\n";
}