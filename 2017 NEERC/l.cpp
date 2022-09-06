/*將n拆解成 x^k1 * (x+1)^k2 或 x^k*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct times{
    ll n1, t1, n2, t2;
    times(){}
    times(ll _n1, ll _t1, ll _n2, ll _t2){
        n1 = _n1, t1 = _t1, n2 = _n2, t2 = _t2;
    }
};
ll n1;
vector<times> ans;
bool factof2(ll n){
    while(!(n&1)){
        n >>= 1;
    }
    return n == 1 ? true : false;
}
pair<int,int> factory(ll a,ll b,ll n){
    int fact1 = 0, fact2 = 0;
    while(n % a == 0){
        fact1++;
        n /= a;
    }
    while (n % b == 0){
        fact2++;
        n /= b;
    }
    return n == 1 ? make_pair(fact1, fact2) : make_pair(0, 0);  //無法整除回傳0
}
void divide1(ll n){
    ll fact1 = sqrt(n);
    ll fact2 = (-1 + sqrt(1 + 4 * n)) / 2;
    if(fact1 * fact1 == n){
        ans.push_back(times(fact1, 2, 0, 0));
    }
    if (fact2 * (fact2 + 1) == n){
        ans.push_back(times(fact2, 1, fact2 + 1, 1));
    }
}
void divide2(ll n){
    ans.push_back(times(n, 1, 0, 0));
    for (ll i = 2; i <= min(1000000ll, n);i++){     //窮舉所有因數，最多只會有1e6個
        pair<int, int> p = factory(i, i + 1, n);
        if(p.first==0)  //不判斷second，因為下一個for迴圈就會判斷了
            continue;
        if(p.first==1&&p.second==0) //就是 1 n，上面已推過
            continue;
        if(p.first==1&p.second==1)
            continue;
        if(p.first==2&&p.second==0)
            continue;
        ans.push_back(times(i, p.first, i + 1, p.second));
    }
}
void solve(){
    ans.clear();
    if(factof2(n1)){    //若為2^x則為-1
        cout << "-1\n";
    }else{
        divide1(n1);    //找k=2 or k1=1 and k2=1 的解
        divide2(n1);    //找k>=3 or k1+k2>=3 的解
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size();i++){
            cout << ans[i].t1 + ans[i].t2;
            for (int j = 0; j < ans[i].t1;j++){
                cout << " " << ans[i].n1;
            }
            for (int j = 0; j < ans[i].t2;j++){
                cout << " " << ans[i].n2;
            }
            cout << "\n";
        }
    }
}
int main(){
    /*
    freopen("little.in", "r", stdin);
    freopen("little.out", "w", stdout);
    */
    while(cin>>n1)
        solve();
}