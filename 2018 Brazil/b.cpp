#include<bits/stdc++.h>
using namespace std;

int n;
int sg[101][101] = {};
int mex(int i,int j){
    vector<int> exist(1001, 0);
    for (int m = 0; m < i;m++){
        exist[sg[m][j]] = 1;
    }
    for (int m = 0; m < j;m++){
        exist[sg[i][m]] = 1;
    }
    for (int m = 1; m <= min(i, j);m++){
        exist[sg[i - m][j - m]] = 1;
    }
    for (int i = 0; i <= 1000;i++){
        if(!exist[i])
            return i;
    }
}
void solve(){
    cin >> n;
    for (int i = 0; i <= 100;i++){
        sg[i][0] = sg[0][i] = sg[i][i] = 999;
    }
        for (int i = 1; i <= 100; i++){
            for (int j = 1; j <= 100; j++){
                if (i == j) //對角線為必贏態(x=0與y=0也是)
                    continue;
                sg[i][j] = mex(i, j); //找三個方向的mex
            }
        }
    int a, b, nim = 0;
    for (int i = 0; i < n;i++){
        cin >> a >> b;
        if(a==b){   //起始狀態為必贏態
            cout << "Y\n";
            return;
        }
        nim ^= sg[a][b];
    }
    nim ? cout << "Y\n" : cout << "N\n";
}
int main(){
    solve();
}
