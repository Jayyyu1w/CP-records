#include<bits/stdc++.h>
#define ll long long
#define INF (ll)1e15
using namespace std;

//我真的好爛喔
int main(){
    int n;
    cin >> n;
    vector<ll> v(n + 1, 0), f(n + 1, 0), b(n + 1, 0);
    for (int i = 1; i <= n;i++){
        cin >> v[i];
    }
    for (int i = 1; i <= n;i++){
        f[i] = max(v[i], f[i - 1] + 1);
    }
    b[n] = v[n];
    for (int i = n - 1; i >= 1;i--){
        b[i] = max(v[i], b[i + 1] + 1);
    }
    ll peek = INF, tmp;
    int pos = -1;
    for (int i = 1; i <= n;i++){    //f嚴格遞增, b嚴格遞減，所以可以找到一個交點使得三角型面積為最小
        tmp = max(f[i], b[i]);
        if (tmp < peek){
            peek = tmp;
            pos = i;
        }
    }
    ll ans = 0;
    for (int i = 1; i < pos;i++){
        ans += f[i] - v[i];
    }
    for (int i = pos + 1; i <= n;i++){
        ans += b[i] - v[i];
    }
    ans += peek - v[pos];
    cout << ans << "\n";
}