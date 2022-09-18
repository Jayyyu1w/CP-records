#include<bits/stdc++.h>
#define int long long
#define MXN 1e6
using namespace std;

int n, m, t;
vector<int> v(MXN);
bool check(int mid, int d){
    int sum = 0, cur = 0, brk = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] > d)
            continue;
        sum += v[i], cur++, brk += v[i];
        if(cur==mid){
            if(sum<=t)  //完成指定件數且時間未超過
                return true;
            else
                return false;
        }
        if(cur%m==0){
            sum += brk;
            brk = 0;
        }
        if (sum > t)
            return false;
    }
    return false;
}
signed main() {
    int c;
    cin >> c;
    while (c--) {
        cin >> n >> m >> t;
        vector<int> s(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            s[i] = v[i];
        }
        sort(s.begin() + 1, s.begin() + 1 + n);     //用於查詢最大時間
        int l = 1, r = n, mid, sum = 0, ans = 0;
        while (l <= r) {    //用完成件數做二分
            mid = (l + r) >> 1;
            if(check(mid,s[mid])){
                ans = mid, l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        cout << ans << " " << (ans <= 0 ? 1 : s[ans]) << "\n";
    }
}