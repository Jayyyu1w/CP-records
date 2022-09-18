#include<bits/stdc++.h>
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define cl(i) i<<1
#define cr(i) i<<1|1
#define MXN 1000005
#define ll long long
using namespace std;

struct core{
    ll cnt, sum;
};
core tree[4 * MXN] = {};
void build(int i,int l,int r){
    if(l==r){
        tree[i].cnt = 0, tree[i].sum = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(cl(i), l, mid);
    build(cr(i), mid + 1, r);
}
void update(int i,int l,int r,int q,ll v){
    if(l==q&&r==q){
        tree[i].cnt += v;
        tree[i].sum += (v * r);
        return;
    }
    int mid = (l + r) >> 1;
    if(q<=mid){
        update(cl(i), l, mid, q, v);
    }else{
        update(cr(i), mid + 1, r, q, v);
    }
    tree[i].cnt = tree[cl(i)].cnt + tree[cr(i)].cnt;
    tree[i].sum = tree[cl(i)].sum + tree[cr(i)].sum;
}
ll query(int i,int l,int r,ll k){
    if(tree[i].cnt<=k){
        return tree[i].sum;
    }
    if(l==r){
        return min(k, tree[i].cnt) * r;
    }
    int mid = (l + r) >> 1;
    if(tree[cl(i)].cnt>k){
        return query(cl(i), l, mid, k);
    }
    return query(cl(i), l, mid, tree[cl(i)].cnt) + query(cr(i), mid + 1, r, k - tree[cl(i)].cnt);//左邊挑多一點
}
int main(){
    io
    int n, m, k, l, r, c, p;
    ll ans = 0;
    cin >> n >> k >> m;
    vector<vector<pair<int, int>>> v(MXN);
    for (int i = 0; i < m;i++){
        cin >> l >> r >> c >> p;
        v[l].push_back(make_pair(c, p));
        v[r + 1].push_back(make_pair(c * (-1), p));
    }
    build(1, 1, MXN - 1);
    for (int i = 1; i <= n;i++){
        for(auto it:v[i]){
            update(1, 1, MXN - 1, it.second, it.first);
        }
        ans += query(1, 1, MXN - 1, k);
    }
    cout << ans << "\n";
}