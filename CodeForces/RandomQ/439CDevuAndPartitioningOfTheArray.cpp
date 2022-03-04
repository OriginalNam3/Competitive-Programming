// https://codeforces.com/problemset/problem/439/C

#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, const char * argv[]) {
    int k, n, p;
    cin >> n >> k >> p;
    int np = k - p;
    vector<vector<long long>> a(2);
    vector<long long> b(n+1, 0);
    vector<int> c(2, 0);
    for (int i = 0; i < n; i++){
        int d;
        cin >> d;
        a[d % 2].push_back(d);
        c[d % 2] += 1;
    }
    if (c[1] - (2 * max(p - c[0], 0)) >= k - p & c[1] % 2 == (k - p) % 2){
        cout << "YES" << endl;
        int oi = 0, ei = 0;
        while (p--){
            if (ei < a[0].size()){
                if (p == 0){
                    cout << a[0].size() - ei + a[1].size() - np << " ";
                    for (ei = ei; ei < a[0].size(); ei++) cout << a[0][ei] << " ";
                    for(oi = oi; oi < a[1].size() - np; oi++) cout << a[1][oi] << " ";
                    cout << endl;
                    break;
                }
                cout << 1 << " " << a[0][ei] << endl;
                ei += 1;
            }
            else {
                if (p == 0){
                    cout << a[1].size() - oi - np << " ";
                    for (oi = oi; oi < a[1].size() - np; oi++) cout << a[1][oi] << " ";
                    cout << endl;
                    break;
                }
                cout << 2 << " " << a[1][oi] << " " << a[1][oi+1] << endl;
                oi += 2;
            }
        }
        while (np--){
            if (np == 0){
                cout << a[1].size() - oi + a[0].size() - ei << " ";
                for (oi = oi; oi < a[1].size(); oi++) cout << a[1][oi] << " ";
                for (ei = ei; ei < a[0].size(); ei++) cout << a[0][ei] << " ";
                cout << endl;
                break;
            }
            cout << 1 << " " << a[1][oi] << endl;
            oi += 1;
        }
    }
    else cout << "NO" << endl;
    return 0;
}
