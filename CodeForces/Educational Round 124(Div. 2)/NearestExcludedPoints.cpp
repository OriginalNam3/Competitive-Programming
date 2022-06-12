#include <bits/stdc++.h>
using namespace std;




int main() {
    int n;
    cin >> n;
    vector <pair<int, int>> a(n);
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    for (int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    
    set <pair<int, int>> b(a.begin(), a.end());
    map <pair<int, int>, pair<int, int>> searched;
    queue<pair<int, int>> q;
    
    for (int i = 0; i < n; i++){
        int x = a[i].first, y = a[i].second;
        for (int j = 0; j < 4; j++){
            int nx = x + dx[j], ny = y + dy[j];
            if (b.count({nx, ny})) continue;
            searched[{x, y}] = {nx, ny};
            q.push({x, y});
            break;
        }
    }
    
    while (!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if (!b.count({nx, ny}) || searched.count({nx, ny})) continue;
            searched[{nx, ny}] = searched[{x, y}];
            q.push({nx, ny});
        }
    }
    
    for (int i = 0; i < n; i++){
        cout << searched[a[i]].first << " " << searched[a[i]].second << endl;
    }
    return 0;
}
