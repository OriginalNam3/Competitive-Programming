#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, k;
    cin >> n >> l >> k;
    vector<int> d(n + 1);
    d[n] = l;
    for (int i = 0; i < n; i++) cin >> d[i];
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> p(n + 1, vector<int> (k+1, INT_MAX));
    p[0][0] = 0;
    for (int i = 1; i <= n; i++) p[i][0] = p[i-1][0] + (a[i-1] * (d[i] - d[i-1]));
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= k; j++){
            for (int x = i + 1; x <= n; x++){
                if ((p[i][j] < 2147483647) & (j + x - i - 1 <= k)) {
                    p[x][j + x - i - 1] = min(p[i][j] + a[i] * (d[x] - d[i]), p[x][j + x - i - 1]);
                }
            }
        }
    }
    cout << *min_element(p[n].begin(), p[n].end());
    return 0;
}
