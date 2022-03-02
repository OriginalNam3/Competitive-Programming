//
//  main.cpp
//  1336ALinovaAndKingdom
//
//  Created by Ming Chau Chan on 01/03/2022.
//

#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char * argv[]) {
    int n, k;
    cin >> n >> k;
    map<int, vector<int>> r;
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        r[u-1].push_back(v-1);
        r[v-1].push_back(u-1);
    }
    queue<int> q;
    int searched[n];
    int parent[n];
    set<pair<int, int>> score;
    map<int, int> scoremap;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        searched[u] = 1;
        for (int v: r[u]) if (!searched[v]) {
            q.push(v);
            parent[v] = u;
            score.insert(pair<int, int>(scoremap[u] + 1, v));
            scoremap[v] = u + 1;
        }
    }
    int c = 0;
    while (k--){
        pair<int, int> maxpair = *(score.rbegin());
        
        int u = maxpair.second, maxscore = maxpair.first;
        if (maxscore != scoremap[u]){
            score.insert(pair<int, int> (scoremap[u], u));
            k++;
            continue;
        }
        c += maxscore;
        scoremap[parent[u]] -= 1;
    }
    return 0;
}
