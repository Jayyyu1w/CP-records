#include<bits/stdc++.h>
using namespace std;

int main(){
    int h, m, sum = 0;
    cin >> h >> m;
    sum = h * 60 + m;
    cout << sum - 540 << "\n";
}