#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n;
    while(cin>>t&&t){
        cin>>n;
        vector<vector<int>>traceback(n+1,vector<int>(t+1,0));
        vector<int> dp(t + 1, 0);
        vector<int>cost(n+1);
        for(int i=1;i<=n;i++){
            cin>>cost[i];
        }
        for(int i=n;i>=1;i--){      //由最後更新到最前，讓前面的選擇不會被後面覆蓋
            for(int j=t;j>=cost[i];j--){
                if(dp[j]<=dp[j-cost[i]]+cost[i]){   //<=就要更新，因為越前面優先級越高
                    dp[j]=dp[j-cost[i]]+cost[i];
                    traceback[i][j] = 1;
                }
            }
        }
        for (int i = 1, j = t; i <= n && j > 0;i++){
            if(traceback[i][j]){
                cout << cost[i] << " ";
                j -= cost[i];
            }
        }
        cout << dp[t] << "\n";
    }
}