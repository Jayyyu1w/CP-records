#include<bits/stdc++.h>
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define int long long
using namespace std;

signed main(){
    io
    int t;
    cin >> t;
    while(t--){
        int n, x, y, num, ans = 0, gd = 0, lm = 0;
        cin >> n >> x >> y;
        for (int i = 0; i < n;i++){
            cin >> num;
            if (num % x != 0 || y % num != 0){
                ans++;
            }else{
                if(gd == 0 && lm == 0)
                    lm = gd = num;
                else{
                    lm = lm * num / __gcd(lm, num);
                    gd = __gcd(gd, num);
                }
            }
        }
        if (y % x != 0 || (n == 1 && x != y)){  //錯誤
            cout << "-1\n";
        }else if((gd == 0 && lm == 0) || (gd == x && lm == y)){     //全改或不改
            cout << ans << "\n";
        }else{      //改一半
        //gcd(a1,a2,a3,...) = ∏ pj^(min(cj))
        //lcm(a1,a2,a3,...) = ∏ pj^(max(cj))
            int a = x / gd, b = lm / y;     //與目標差值
            if(__gcd(a,b) == 1){            //可以藉由修改一個數字到達目標
                cout << max(1ll, ans) << "\n";
            }else{                          //必須修改兩個數字，因為一定由兩個數字的質因數貢獻gcd與lcm
                cout << max(2ll, ans) << "\n";
            }
        }
    }
}