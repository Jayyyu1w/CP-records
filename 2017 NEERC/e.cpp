#include<bits/stdc++.h>
#define MXN 1e6+5
using namespace std;

int main(){
    freopen("equal.in", "r", stdin);
    freopen("equal.out", "w", stdout);
    int n, num;
    cin >> n;
    vector<int> a, b, d(MXN, 0);
    for (int i = 0; i < n;i++){
        cin >> num;
        d[num]++;
    }
    for (int i = 1; i <= MXN;i++){
        if(d[i]){
            a.push_back(d[i]);  //每個數字的個數推入
            for (int j = 2 * i; j < MXN;j+=i){  //確認有沒有倍數
                if(d[j]){
                    b.push_back(d[i]);  //有倍數的數字的個數就推入
                    break;
                }
            }
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int q = 0, p = 0, sp = 0, sq = 0;
    for (int i = 0; i <= n;i++){    //步數
        while(p<a.size()&&sp+a[p]<=i){  //改變的個數不超過i
            sp += a[p++];   //加入，然後往下一個移動
        }
        while(q<b.size()&&sq+b[q]<=i){
            sq += b[q++];
        }
        cout << a.size() - max(q, p - 1) << (i == n ? '\n' : ' ');
        //b能保證每次數字個數一定會減少，q不變
        //a在處理沒有倍數的數字的情況下，第一次處理數字個數是不變的，p-1
    }
}