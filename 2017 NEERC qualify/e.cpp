#include<bits/stdc++.h>
#define INF 300005
using namespace std;

int n;
string s;
bool check(int dis) {
    int dot = -1;
    for (int i = 0; i < s.size(); i++) {
        if (dot == -1 && s[i] == '*') {
            dot = i;
        }
        if (s[i] == 'P') {
            if (dot != -1) {
                if (i - dot > dis)   //前面的點吃不到
                    return false;
                else {
                    int endpos, diff = i - dot;
                    if (dis >= 3 * diff) {    //可以先往前吃再跑到後面同等位置甚至更遠
                        endpos = i + dis - 2 * diff;
                    }else {
                        endpos = i + (dis - diff) / 2;
                    }
                    int j;
                    for (j = i + 1; j <= min(n - 1, endpos); j++) {
                        if (s[j] == 'P')    //遇到P就break,後面的P能讓吃的點的數量更大
                            break;
                    }
                    i = j - 1;
                }
                dot = -1;
            }
            else {  //前面沒點
                int j;
                for (j = i + 1; j <= min(n - 1, i + dis); j++) {
                    if (s[j] == 'P')
                        break;
                }
                i = j - 1;
            }
        }
    }
    if (dot != -1)   //有點沒被吃到
        return false;
    return true;
}
int main() {
    cin >> n >> s;
    int l = 0, r = INF, mid, ans;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid, r = mid - 1;
        }else {
            l = mid + 1;
        }
    }
    cout << ans << "\n";
}