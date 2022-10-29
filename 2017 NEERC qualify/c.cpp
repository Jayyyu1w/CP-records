#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> p(n + 1, 0);
    for (int i = 1; i <= n;i++){
        p[i] = p[i - 1] + i - 1;
    }
    if (n * (n - 1) < 2 * k){
        cout << "Impossible\n";
    }else{
        auto pos = lower_bound(p.begin(), p.end(), k);
        if(*pos == k){  //可以剛好由n個嵌套()組成
            int loc = pos - p.begin();
            for (int i = 0; i < loc;i++){
                cout << "(";
            }
            for (int i = 0; i < loc;i++){
                cout << ")";
            }
            for (int i = 0; i < n - loc;i++){
                cout << "()";
            }
        }else{
            pos--;
            int loc = pos - p.begin();
            ll rem = k - *pos;
            ll prt = loc - rem;
            for (int i = 0; i < loc;i++){
                cout << "(";
            }
            for (int i = 0; i < prt;i++){
                cout << ")";
            }
            cout << "()";
            for (int i = 0; i < rem;i++){
                cout << ")";
            }
            for (int i = 0; i < n - loc - 1;i++){
                cout << "()";
            }
        }
    }
}