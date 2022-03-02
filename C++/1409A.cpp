#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--){
        int a, b;
        cin >> a >> b;
        int d, m;
        d = max(a - b, b - a);
        m = d / 10;
        if (d % 10 > 0) m += 1;
        cout << m << endl;
    }
    return 0;
}
