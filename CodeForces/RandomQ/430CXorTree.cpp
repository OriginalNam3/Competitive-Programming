#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
    vector<int> changed(n, 0);
    vector<int> searched(n, 0);
    vector<int> operations;
    vector<int> init(n);
    for (int i = 0; i < n; i ++){
        cin >> init[i];
    }
    vector<int> goal(n);
    for (int i = 0; i < n; i ++){
        cin >> goal[i];
    }
    queue<int> q;
    q.push(0);
    int c = 0;
    while (!q.empty()){
        int u = q.front();
        q.pop();
//        cout << u << " searched" << endl;
        init[u] = init[u] ^ changed[u];
        if (init[u] != goal[u]){
//            cout << u << " changed" << endl;
            changed[u] = !changed[u];
            c += 1;
            operations.push_back(u+1);
        }
        if (changed[u]) for (int v: graph[u]) for (int w : graph[v]) if (!searched[v] & !searched[w]) changed[w] = changed[u];
        for (int v : graph[u]) if (!searched[v]) q.push(v);
        searched[u] = 1;
    }
    cout << c << endl;
    for (int v: operations) cout << v << endl;
    return 0;
}
