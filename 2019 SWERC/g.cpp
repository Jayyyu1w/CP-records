#include<bits/stdc++.h>
#define MXN 205
#define MAX 100005
using namespace std;

int s, l, n;
int id[MAX], deg[MAX] = {}, last[MXN], rel[MXN][MXN] = {};
vector<int> tp;
vector<vector<int>> edge(MAX);
vector<string> v;
map<string, int> mp;
void topo(){
    tp.clear();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= n;i++){
        if(deg[i]==0){
            pq.emplace(make_pair(id[i], i));
        }
    }
    while(!pq.empty()){
        pair<int, int> tmp = pq.top();
        pq.pop();
        tp.push_back(tmp.first);
        for(int it:edge[tmp.second]){
            deg[it]--;
            if (deg[it] == 0){
                pq.emplace(make_pair(id[it], it));
            }
        }
    }
}
int main(){
    string str, a, b;
    cin >> s >> l >> n;
    for (int i = 0; i < s;i++){
        cin >> str;
        v.push_back(str);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < s;i++){
        mp[v[i]] = i + 1;
    }
    for (int i = 1; i <= l; i++){
        cin >> a >> b;
        rel[mp[a]][mp[b]] = rel[mp[b]][mp[a]] = 1;
    }
    /*窮舉所有組合*/
    for (int i = 1; i <= n;i++){
        cin >> str;
        id[i] = mp[str];
        for (int j = 1; j <= s;j++){
            if (rel[id[i]][j] || !last[j]){
                continue;
            }
            edge[last[j]].push_back(i); //無法互換的建邊
            deg[i]++;
        }
        last[id[i]] = i;
    }
    topo();
    for (int i = 0; i < tp.size();i++){
        if(i!=0)
            cout << " ";
        cout << v[tp[i] - 1];
    }
    cout << "\n";
}