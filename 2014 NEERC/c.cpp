#include<bits/stdc++.h>
#define cl(i) i<<1
#define cr(i) i<<1|1
#define ll long long
#define MXN 100005
using namespace std;

ll tree[MXN << 2] = {}, tag[MXN << 2] = {};
int mday[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
struct times {
    int cost, sumt, id;
    times() {}
    times(int _cost, int _sumt) {
        cost = _cost, sumt = _sumt;
    }
};

void push(int i, int l, int r) {
    if (tag[i]) {
        tree[cl(i)] += tag[i];
        tree[cr(i)] += tag[i];
        tag[cl(i)] += tag[i];
        tag[cr(i)] += tag[i];
        tag[i] = 0;
    }
}
void pull(int i, int l, int r) {
    int mid = (l + r) >> 1;
    push(cl(i), l, mid);
    push(cr(i), mid + 1, r);
    tree[i] = min(tree[cl(i)], tree[cr(i)]);
}
void update(int i, int l, int r, int ul, int ur, int val) {
    if (ul <= l && r <= ur) {
        tree[i] += val;
        tag[i] += val;
        return;
    }
    push(i, l, r);
    int mid = (l + r) >> 1;
    if (ul <= mid)
        update(cl(i), l, mid, ul, ur, val);
    if (ur > mid)
        update(cr(i), mid + 1, r, ul, ur, val);
    tree[i] = min(tree[cl(i)], tree[cr(i)]);
}
ll query(int i, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return tree[i];
    }
    int mid = (l + r) >> 1, ret = 0;
    if (ql <= mid)
        ret = query(cl(i), l, mid, ql, qr);
    if (qr > mid)
        ret = query(cr(i), mid + 1, r, ql, qr);
    return ret;
}
int main() {
    int n;
    cin >> n;
    vector<times> mail;
    vector<int> dis;
    for (int i = 0; i < n; i++) {
        int c;
        string date, time, d1, d2, t1, t2;
        cin >> c >> date >> time;
        auto pos = date.find('.');
        d1 = date.substr(0, pos);
        d2 = date.substr(pos + 1, date.size() - pos);
        pos = time.find(':');
        t1 = time.substr(0, pos);
        t2 = time.substr(pos + 1, time.size() - pos);
        mail.push_back(times(c, ((mday[stoi(d2) - 1] + stoi(d1)) * 24 + stoi(t1)) * 60 + stoi(t2)));
        dis.push_back(mail[i].sumt);
    }
    auto cmp = [](const int& a, const int& b) {
        return a < b;
    };
    sort(dis.begin(), dis.end(), cmp);
    for (int i = 0; i < n; i++) {
        mail[i].id = lower_bound(dis.begin(), dis.end(), mail[i].sumt) - dis.begin() + 1;
        update(1, 1, n, mail[i].id, n, mail[i].cost);
        cout << min(0ll, tree[1]) << "\n";
    }
}