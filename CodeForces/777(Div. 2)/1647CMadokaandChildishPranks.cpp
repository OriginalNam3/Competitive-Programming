#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int> (m));
        for (int i = 0; i < n; i++){
            string row;
            cin >> row;
            for (int j = 0; j < m; j++){
                if (row[j] == '1') a[i][j] = 1;
            }
        }
        if (a[0][0] == 1){
            cout << -1 << endl;
            continue;
        }
        vector<pair<pair<int, int>, pair<int, int>>> c;
        int q = 0;
        for (int i = n - 1; i >= 0; i --){
            for (int j = m - 1; j > 0; j--){
                if (a[i][j] == 1){
                    c.push_back(make_pair(make_pair(i + 1, j), make_pair(i + 1, j + 1)));
                    q++;
                }
            }
            if (a[i][0] == 1){
                c.push_back(make_pair(make_pair(i, 1), make_pair(i + 1, 1)));
                q++;
            }
        }
        cout << q << endl;
        for (int i = 0; i < q; i++){
            cout << c[i].first.first << " " << c[i].first.second << " " << c[i].second.first << " " << c[i].second.second << endl;
        }
    }
    return 0;
}
