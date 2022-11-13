#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, m, s1, s2, s3, s4, a, b, c, d, x, y, x1, y1, treasure;
    cin >> t;
    while(t--){
        cin >> n >> m;
        cout << "SCAN 1 1" << endl;
        cin >> s1;  // (x1 − 1) + (x2 − 1) + (y1 − 1) + (y2 − 1) 
        cout << "SCAN " << 1 << " " << m << endl;
        cin >> s2;  //(x1 − 1) + (x2 − 1) + (m − y1) + (m − y2) 
        //搜出x1+x2,y1+y2 使用數學解
        a = (s1 + s2 + 6 - 2 * m) / 2;
        b = (s1 - s2 + 2 + 2 * m) / 2;
        cout << "SCAN " << a / 2 << " " << 1 << endl;
        cin >> s3;
        cout << "SCAN " << 1 << " " << b / 2 << endl;
        cin >> s4;
        //搜出x2-x1,y2-y1 使用數學解
        c = s3 - s1 - 2 + a;    //(x2 - x1) + (y1 - 1) + (y2 - 1) - (x1 - 1) - (x2 - 1) - (y1 - 1) - (y2 - 1) = x2 - x1
        d = s4 - s2 + 2 * m - b;
        x = (a - c) / 2;
        y = (b - d) / 2;
        x1 = a - x;
        y1 = b - y;
        //先查(x1,y1)如果沒有寶藏就查(x1,y2),(x2,y1),如果有寶藏就查(x2,y2)
        cout << "DIG " << x << " " << y << endl;
        cin >> treasure;
        if(treasure){
            cout << "DIG " << x1 << " " << y1 << endl;
        }else{
            cout << "DIG " << x << " " << y1 << endl;
            cout << "DIG " << x1 << " " << y << endl;
        }
    }
}