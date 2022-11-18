#include<bits/stdc++.h>
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using namespace std;

int main(){
    io
    int t;
    cin >> t;
    while(t--){
        int n, mn = 1000005, sum = 0;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n;i++){
            cin >> a[i];
            mn = min(mn, a[i]);
            sum += a[i];
        }
        if(n & 1){      //每個移除都是奇數，若石頭總和為奇數，每次Yalalov移動時石頭總數都是奇數
            if (sum & 1)
                cout << "Yalalov\n";
            else
                cout << "Shin\n";
        }else{
            if ((mn & 1) || (sum & 1))
                cout << "Yalalov\n";
            else
                cout << "Shin\n";
        }
    }
}