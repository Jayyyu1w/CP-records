#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b, k, f;
    string s1, s2, ps1 = "", ps2 = "";
    cin >> n >> a >> b >> k >> f;
    map<pair<string, string>, int> mp;
    for (int i = 0; i < n;i++){
        cin >> s1 >> s2;
        if (s1 == ps2){     //是轉運
            mp[make_pair(min(s1, s2), max(s1, s2))] += b;
        }else{              //非轉運
            mp[make_pair(min(s1, s2), max(s1, s2))] += a;
        }
        ps1 = s1, ps2 = s2;
    }
    int ans = 0;
    vector<pair<pair<string, string>, int>> v;
    for (auto it : mp){
        v.push_back({it.first, it.second});
    }
    auto cmp = [](const pair<pair<string, string>, int> &a, const pair<pair<string, string>, int> &b) -> bool{
        return a.second > b.second;
    };
    sort(v.begin(), v.end(), cmp);
    for(auto it:v){
        if (k > 0 && it.second > f){
            it.second = f;
            k--;
        }
        ans += it.second;
    }
    cout << ans << "\n";
}