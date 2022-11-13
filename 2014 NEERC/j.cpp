#include<bits/stdc++.h>
using namespace std;

//對不起我真的看不懂題目QQ
int main(){
    int n, sum1 = 0, sum2 = 0;
    cin >> n;
    vector<pair<int, int>> ok(n), ror(n);
    for (int i = 0; i < n;i++){
        cin >> ok[i].first;
        sum1 += ok[i].first;
        ok[i].second = i + 1;
    }
    for (int i = 0; i < n;i++){
        cin >> ror[i].first;
        sum2 += ror[i].first;
        ror[i].second = i + 1;
    }
    //必輸的大到小，必贏的小到大，製造出最懸念的場景
    auto cmpg = [](const pair<int, int> &a, const pair<int, int> &b){
        return a.first > b.first;
    };
    auto cmp = [](const pair<int, int> &a, const pair<int, int> &b){
        return a.first < b.first;
    };
    if (sum1 > sum2){
        sort(ok.begin(), ok.end(), cmp);
        sort(ror.begin(), ror.end(), cmpg);
    }else{
        sort(ok.begin(), ok.end(), cmpg);
        sort(ror.begin(), ror.end(), cmp);
    }
    for (int i = 0; i < n;i++){
        cout << ok[i].second << " " << ror[i].second << "\n";
    }
}