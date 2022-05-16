// Problem: Counting Rooms
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1192
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-13 11:20:35
// 
// Powered by CP Editor (https://cpeditor.org)

// You either sink in the coom, or coom in the sink.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;
typedef string str;

#define mp make_pair
#define f first
#define s second

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsor(x) sort(x.rbegin(), x.rend())
#define pb push_back

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<bool> > g(n, vector<bool> (m));
    
    for (int i = 0; i < n; i++){
    	str row; cin >> row;
    	for (int j = 0; j < m; j++){
    		if (row[j] == '.'){
    			g[i][j] = 1;
    		}
    	}
    }
    
    vector<vector<bool> > s(n, vector<bool> (m));
    queue<pair<int, int> > q;
    int cnt = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){
    	if (g[i][j] && !s[i][j]) {
    		q.push(mp(i, j));
    		s[i][j] = 1;
    		cnt++;
    		while (!q.empty()){
    			int x = q.front().f, y = q.front().s;
    			q.pop();
    			for (int i = 0; i < 4; i++){
    				int nx = x + dx[i], ny = y + dy[i];
    				if (0 <= nx && nx < n && 0 <= ny && ny < m && g[nx][ny] && !s[nx][ny]){
    					q.push(mp(nx, ny));
    					s[nx][ny] = 1;
    				}
    			}
    		}
    	}
    }
    cout << cnt;
}
