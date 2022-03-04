#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int c = 0, a = 0, m = 0;
        for (int i = 0; i < n; i++){
            int p;
            cin >> p;
            if (p > m) {
                a = p - m + a - 1;
                m = p;
            }
            if (p < m) a -= 1;
            if (a == 0) c += 1;
        }
        cout << c << endl;
    }
    return 0;
}
