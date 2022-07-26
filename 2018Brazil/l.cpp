/*L. Subway Lines 樹鏈剖分 or LCA*/
/*樹鏈剖分版*/
#include<bits/stdc++.h>
#define MAX 150005
#define cl(x) (x<<1)
#define cr(x) (x<<1|1)
#define INF 1e9+5
using namespace std;

int n, q;
vector<vector<int>>edge(MAX);
vector<vector<int>>tree(MAX), tag(MAX);
int sz[MAX], father[MAX], heavy[MAX], root[MAX], len[MAX], dep[MAX];
vector<pair<int, int>> arr;
void init() {
	for (int i = 1; i <= n; i++) {
		edge[i].clear();
		tree[i].clear();
		heavy[i] = 0;
		len[i] = 0;
	}
}
void dfs_1(int rt, int f, int d) {
	dep[rt] = d;
	father[rt] = f;
	sz[rt] = 1;
	for (auto i : edge[rt]) {
		if (i == f)continue;
		dfs_1(i, rt, d + 1);
		sz[rt] += sz[i];
		if (sz[i] > sz[heavy[rt]]) {
			heavy[rt] = i;
		}
	}
}
void dfs_2(int rt, int f) {
	for (auto i : edge[rt]) {
		if (i == f)continue;
		if (i == heavy[rt])
			root[i] = root[rt];  //併到根節點，因為整棵樹的root必定為重鏈的root
		else
			root[i] = i;   //根節點當成自己
		dfs_2(i, rt);
	}
	len[root[rt]]++;  //最後在回朔時增加(根節點的child跑完之後就會上一層，鏈長度+1)
}
void buildsegtree(int idx, int i, int l, int r) {
	if (l == r) {
		tree[idx][i] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	buildsegtree(idx, cl(i), l, mid);
	buildsegtree(idx, cr(i), mid + 1, r);
	tree[idx][i] = tree[idx][cl(i)] + tree[idx][cr(i)];
}
void build() {
	for (int i = 1; i <= n; i++) {
		if (root[i] == i) {  //樹鏈根節點
			tree[i].resize(len[i] << 2, 0);
			tag[i].resize(len[i] << 2, 0);
			buildsegtree(i, 1, 0, len[i] - 1);
		}
	}
}
void push(int idx, int i, int l, int r) {
	if (tag[idx][i] != 0) { // 判斷是否有打標記
		tree[idx][i] += tag[idx][i] * (r - l + 1);
		if (l != r) {  // 如果有左右子節點把標記往下打
			tag[idx][cl(i)] += tag[idx][i];
			tag[idx][cr(i)] += tag[idx][i];
		}
		tag[idx][i] = 0; // 更新後把標記消掉
	}
}
void pull(int idx, int i, int l, int r) {
	int mid = (l + r) / 2;
	push(idx, cl(i), l, mid);
	push(idx, cr(i), mid + 1, r);
	tree[idx][i] = tree[idx][cl(i)] + tree[idx][cr(i)];
}
void updatepoi(int idx, int i, int l, int r, int ql, int qr, int val) {
	push(idx, i, l, r);
	if (ql <= l && qr >= r) {
		tag[idx][i] += val;
		return;
	}
	int mid = (l + r) >> 1;
	if (ql <= mid)
		updatepoi(idx, cl(i), l, mid, ql, qr, val);
	if (qr > mid)
		updatepoi(idx, cr(i), mid + 1, r, ql, qr, val);
	pull(idx, i, l, r);
}
int query(int idx, int i, int l, int r, int ql, int qr) {
	push(idx, i, l, r);
	if (l >= ql && r <= qr) {
		return tree[idx][i];
	}
	int mid = (l + r) >> 1, ret = 0;
	if (ql <= mid) {
		ret += query(idx, cl(i), l, mid, ql, qr);
	}
	if (qr > mid) {
		ret += query(idx, cr(i), mid + 1, r, ql, qr);
	}
	return ret;
}
void updatePath(int x, int y, int v) {
	while (root[x] != root[y]) {        //若不在同一條鏈上
		if (dep[root[x]] > dep[root[y]]) {      //優先更新深度深的鏈
			updatepoi(root[x], 1, 0, len[root[x]] - 1, 0, dep[x] - dep[root[x]], v);
			x = father[root[x]];
		}
		else {
			updatepoi(root[y], 1, 0, len[root[y]] - 1, 0, dep[y] - dep[root[y]], v);
			y = father[root[y]];
		}
	}
	if (dep[x] > dep[y]) {
		swap(x, y);
	}
	//更新第treeID[i]樹從mn~mx的範圍加值v
	updatepoi(root[x], 1, 0, len[root[x]] - 1, dep[x] - dep[root[x]], dep[y] - dep[root[y]], v); //最後會連至同一條鏈上，更新範圍
}
void solve() {
	int u, v, a, b, c, d;
	cin >> n >> q;
	init();
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs_1(1, 1, 0);
	root[1] = 1;
	dfs_2(1, 1);
	build();
	for (int i = 0; i < q; i++) {
		cin >> a >> b >> c >> d;
		updatePath(a, b, 1);
		int ans = 0;
		while (root[c] != root[d]) {  //先將一邊更新到根節點
			if (dep[root[c]] < dep[root[d]]) {  //詢問深度較深的
				swap(c, d);
			}
			ans += query(root[c], 1, 0, len[root[c]] - 1, 0, dep[c] - dep[root[c]]);
			c = father[root[c]];  //往上跳(小鏈根節點跳到大鏈節點)
		}
		if (dep[c] > dep[d]) {
			swap(c, d);
		}
		ans += query(root[c], 1, 0, len[root[c]] - 1, dep[c] - dep[root[c]], dep[d] - dep[root[d]]);
		cout << ans << "\n";
		updatePath(a, b, -1);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}