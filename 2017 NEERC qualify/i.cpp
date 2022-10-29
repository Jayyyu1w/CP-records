#include<bits/stdc++.h>
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using namespace std;

int n, m, q, p;
vector<vector<int>> maze, val, vis;
pair<int, int> dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main(){
    string s;
    cin >> n >> m >> q >> p;
    maze.resize(n + 2, vector<int>(m + 2, 1));
    val.resize(n + 2, vector<int>(m + 2, 0));
    vis.resize(n + 2, vector<int>(m + 2));
    vector<tuple<int, int, int>> st;
    for (int i = 1; i <= n;i++){
        cin >> s;
        for (int j = 1; j <= m;j++){
            if(s[j - 1] == '*'){
                maze[i][j] = 1;
            }else{
                if (s[j - 1] != '.'){
                    st.push_back({i, j, (s[j - 1] - 'A' + 1) * q});
                }
                maze[i][j] = 0;
            }
        }
    }
    for(auto it:st){
        for (int i = 1; i <= n;i++){
            for (int j = 1; j <= m;j++){
                vis[i][j] = 0;
            }
        }
        queue<tuple<int, int, int>> q;
        q.push({get<0>(it), get<1>(it), get<2>(it)});
        while(!q.empty()){
            auto tmp = q.front();
            q.pop();
            vis[get<0>(tmp)][get<1>(tmp)] = 1;
            val[get<0>(tmp)][get<1>(tmp)] += get<2>(tmp);
            for (int i = 0; i < 4;i++){
                int nxtx = get<0>(tmp) + dir[i].first, nxty = get<1>(tmp) + dir[i].second;
                if(!vis[nxtx][nxty] && !maze[nxtx][nxty] && get<2>(tmp) / 2 > 0){
                    vis[nxtx][nxty] = 1;
                    q.push({nxtx, nxty, get<2>(tmp) / 2});
                }
            }
        }
    }
    /*
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cout << val[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";*/
    int ans = 0;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            if (val[i][j] > p){
                ans++;
            }
        }
    }
    cout << ans << "\n";
}