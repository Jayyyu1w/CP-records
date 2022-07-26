// https://codeforces.com/gym/101908/problem/J
// SteinerTree變化題
#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

// Minimum Steiner Tree 重要點的mst
// O(V 3^T + V^2 2^T)
struct SteinerTree
{
#define V 105
#define T 15
#define INF 4000005
    int n, k;
    double dst[V][V], dp[1 << T][V], tdst[V];
    void init(int _n, int _k){
        n = _n;
        k = _k;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++)
                dst[i][j] = INF;
            dst[i][i] = 0;
        }
    }
    void add_edge(int ui, int vi, double wi){
        dst[ui][vi] = min(dst[ui][vi], wi);
        dst[vi][ui] = min(dst[vi][ui], wi);
    }
    void shortest_path(){ // using spfa may faster
        for (int l = 0; l < n; l++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    dst[i][j] = min(dst[i][j],dst[i][l] + dst[l][j]);
    } // call shorest_path before solve
    double solve(const vector<int> &ter){
        int t = (int)ter.size();
        for (int i = 0; i < (1 << t); i++)
            for (int j = 0; j < n; j++)
                dp[i][j] = INF;
        for (int i = 0; i < n; i++)
            dp[0][i] = 0;
        for (int msk = 1; msk < (1 << t); msk++){
            if (msk == (msk & (-msk))){
                int who = __lg(msk);
                for (int i = 0; i < n; i++)
                    dp[msk][i] = dst[ter[who]][i];
                continue;
            }
            // 接下來都從k開始轉移(因為Capitals為前k項)
            for (int i = k; i < n; i++)
                for (int submsk = (msk - 1) & msk; submsk;submsk = (submsk - 1) & msk)
                    dp[msk][i] = min(dp[msk][i],dp[submsk][i] + dp[msk ^ submsk][i]);
            for (int i = k; i < n; i++){
                tdst[i] = INF;
                for (int j = k; j < n; j++)
                    tdst[i] = min(tdst[i],dp[msk][j] + dst[j][i]);
            }
            for (int i = k; i < n; i++)
                dp[msk][i] = tdst[i];
        }
        double ans = INF;
        for (int i = k; i < n; i++)
            ans = min(ans, dp[(1 << t) - 1][i]);
        return ans;
    }
} solver;

struct node{
    int x, y;
};

double dist(node a, node b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

signed main(){
    int n, k, i, j;
    cin >> n >> k;
    vector<node> graph;
    vector<int> ter;
    solver.init(n, k);
    for (i = 0; i < n; i++){
        node temp;
        cin >> temp.x >> temp.y;
        graph.pb(temp);
        if (i < k)
            ter.pb(i); // Capitals
    }
    for (i = 0; i < n; i++){
        for (j = i + 1; j < n; j++){
            solver.add_edge(i, j, dist(graph[i], graph[j]));
        }
    }
    solver.shortest_path();
    cout << fixed << setprecision(5) << solver.solve(ter);
}