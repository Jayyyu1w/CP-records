#include<bits/stdc++.h>
using namespace std;

bool vis[505][5005] = {};
struct bit{
    int mod, sum;
    string s;
};
int main(){
    int d, s, flag = 0;
    cin >> d >> s;
    queue<bit> q;
    bit now, nxt;
    now.mod = 0, now.sum = 0, now.s = "";
    q.push(now);
    vis[0][0] = 1;
    while(!q.empty()){
        now = q.front();
        q.pop();
        if (now.sum > s) //總和已超過
            continue;
        if(now.mod==0&&now.sum==s){
            flag = 1;
            break;
        }
        for (int i = 0; i <= 9;i++){
            nxt.mod = (now.mod * 10 + i) % d;
            nxt.sum = now.sum + i;
            if(!vis[nxt.mod][nxt.sum]){
                nxt.s = now.s + to_string(i);
                q.push(nxt);
                vis[nxt.mod][nxt.sum] = 1;
            }
        }
    }
    flag ? cout << now.s << "\n" : cout << "-1\n";
}