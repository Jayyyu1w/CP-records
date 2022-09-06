#include<bits/stdc++.h>
using namespace std;

int ans, maze[42][720];
void dfs(int x,int y){
    if(ans)
        return;
    if (x == 41){
        ans = 1;
        return;
    }
    if (!maze[x + 1][y]){
        maze[x + 1][y] = 1;
        dfs(x + 1, y);
    }
    if (!maze[x][(y + 1) % 720]){
        maze[x][(y + 1) % 720] = 1;
        dfs(x, (y + 1) % 720);
    }
    if (!maze[x][(y + 719) % 720]){
        maze[x][(y + 719) % 720] = 1;
        dfs(x, (y + 719) % 720);
    }
    if (x > 0 && !maze[x - 1][y]){
        maze[x - 1][y] = 1;
        dfs(x - 1, y);
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        ans = 0;
        memset(maze, 0, sizeof(maze));
        int n, r1, r2, ang1, ang2;
        string type;
        cin >> n;
        for (int i = 0; i < n;i++){
            cin >> type;
            if(type=="C"){
                cin >> r1 >> ang1 >> ang2;
                r1 *= 2;
                if (ang2 < ang1)
                    ang2 += 360;
                for (int j = ang1 * 2; j <= ang2 * 2;j++){  //開*2讓中間至少會有一條路可走
                    maze[r1][j % 720] = 1;
                }
            }
            if(type=="S"){
                cin >> r1 >> r2 >> ang1;
                r1 *= 2, r2 *= 2, ang1 *= 2;
                for (int j = r1; j <= r2;j++){
                    maze[j][ang1] = 1;
                }
            }
        }
        dfs(1, 0);
        ans ? cout << "YES\n" : cout << "NO\n";
    }
}