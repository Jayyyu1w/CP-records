#include<bits/stdc++.h>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

signed main() {
    io
    int n, i, j;
    string in, s;
    cin >> n;
    cin >> in;
    vector<vector<int>>p(n, vector<int>(n));
    for (i = 0; i < n; i++) {
        cin >> s;
        for (j = 0; j < s.length(); j++) {
            if (s[j] == '.')
                p[i][j] = 4;
            else if (s[j] == '^')
                p[i][j] = 0;
            else if (s[j] == '>')
                p[i][j] = 1;
            else if (s[j] == 'v')
                p[i][j] = 2;
            else if (s[j] == '<')
                p[i][j] = 3;
        }
    }
    stack<int>stk;
    for (i = 0; i < in.length(); i++) {
        if (in[i] == 'L') {
            if (stk.empty()) {
                stk.push(0);
            }
            else if (stk.top() == 1) {
                stk.pop();
            }
            else if (stk.top() == 0 && stk.size() == 3) {
                stk.pop(); stk.pop(); stk.pop();
            }
            else if (stk.top() == 0 && stk.size() < 3) {
                stk.push(0);
            }
        }
        else {
            if (stk.empty()) {
                stk.push(1);
            }
            else if (stk.top() == 0) {
                stk.pop();
            }
            else if (stk.top() /**/== 1 && stk.size() == 3) {
                stk.pop(); stk.pop(); stk.pop();
            }
            else if (stk.top() == 1 && stk.size() < 3) {
                stk.push(1);
            }
        }
    }
    deque<int>rotate;
    while (!stk.empty()) {
        rotate.push_front(stk.top());
        stk.pop();
    }
    vector<vector<int>>rot(n, vector<int>(n));
    for (int i = 0; i < rotate.size(); i++) {
        if (rotate[i] == 0) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (p[j][n - 1 - i] == 4) {
                        rot[i][j] = p[j][n - 1 - i];
                    }
                    else {
                        rot[i][j] = (p[j][n - 1 - i] + 3) % 4;
                    }
                }
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (p[n - 1 - j][i] == 4) {
                        rot[i][j] = p[n - 1 - j][i];
                    }
                    else {
                        rot[i][j] = (p[n - 1 - j][i] + 1) % 4;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                p[i][j] = rot[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (p[i][j] == 0)
                cout << "^";
            else if (p[i][j] == 1)
                cout << ">";
            else if (p[i][j] == 2)
                cout << "v";
            else if (p[i][j] == 3)
                cout << "<";
            else if (p[i][j] == 4)
                cout << ".";
        }
        cout << "\n";
    }
}