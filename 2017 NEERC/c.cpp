/*狀態壓縮、枚舉*/
//O(2^19*19^2)
#include<bits/stdc++.h>
using namespace std;

string s;
int consocnt[26] = {0, 1, 2, 3, 0, 4, 5, 6, 0, 7, 8, 9, 10, 11, 0, 12, 13, 14, 15, 16, 0, 17, 0, 18, 0, 19}; //子音新編號
void solve(){
    vector<vector<int>> con(20, vector<int>(20, 0));
    for (int i = 0; i < s.length() - 1;i++){
        con[consocnt[s[i] - 'a']][consocnt[s[i + 1] - 'a']]++;  //代表他可貢獻一個consonant fencity
    }
    int maxi = 0, upper;
    for (int i = 1; i < (1 << 19);i++){
        int sum = 0;
        for (int j = 1; j <= 19;j++){
            for (int k = 1; k <= 19;k++){
                if ((i & (1 << (j - 1))) && (!(i & (1 << (k - 1))))||(!(i & (1 << (j - 1)))) && (i & (1 << (k - 1)))){   //必須為一大寫一小寫
                    sum += con[j][k];
                }
            }
        }
        if(sum>maxi){   //大於當前最大值則更新最大值及須轉大寫的字母
            upper = i;
            maxi = sum;
        }
    }
    for (int i = 0; i < s.length();i++){
        if (upper & (1 << (consocnt[s[i] - 'a'] - 1))){
            s[i] -= 32;
        }
    }
    cout << s << "\n";
}
int main(){
    //freopen("consonant.in","r",stdin);    // 讀 file.in 檔
    //freopen("consonant.out","w",stdout);  // 寫入 file.out 檔
    while(cin>>s){
        solve();
    }
}