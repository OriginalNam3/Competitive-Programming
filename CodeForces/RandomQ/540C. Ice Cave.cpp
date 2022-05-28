// Problem: C. Ice Cave
// Contest: Codeforces - Codeforces Round #301 (Div. 2)
// URL: https://codeforces.com/problemset/problem/540/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-27 21:34:11
// 
// Powered by CP Editor (https://cpeditor.org)

// https://codeforces.com/profile/Intellegent husbando <3

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

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<bool> > g(n, vector<bool> (m));
    
    for (int i = 0; i < n; i++){
    	str row; cin >> row;
    	for (int j = 0; j < m; j++){
    		if (row[j] == 'X') g[i][j] = 1;
    	}
    }
    
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--; c1--; r2--; c2--;
    
    if (r1 == r2 && c1 == c2){
    	int cnt = 0;
    	for (int i = 0; i < 4; i++){
    		int x = r1 + dx[i], y = c1 + dy[i];
    		if (0 <= x && x < n && 0 <= y && y < m && !g[x][y]){
    			cnt++;
    		}
    	}
    	if (cnt > 0){
    		cout << "YES";
    		return 0;
    	}
    	cout << "NO";
    	return 0;
    }
    
    if (abs(r1 - r2) + abs(c1 - c2) <= 1){
    	if (g[r2][c2]){
    		cout << "YES";
    		return 0;
    	}
    	int cnt = 0;
    	for (int i = 0; i < 4; i++){
    		int x = r2 + dx[i], y = c2 + dy[i];
    		if (0 <= x && x < n && 0 <= y && y < m && !g[x][y]){
    			cnt++;
    		}
    	}
    	if (cnt > 0){
    		cout << "YES";
    		return 0;
    	}
    	cout << "NO";
    	return 0;
    }
    
    vector<vector<bool> > searched(n, vector<bool> (m));
    queue<pair<int, int> > q;
    q.push(mp(r1, c1));
    
    while (!q.empty()){
    	int ox = q.front().f, oy = q.front().s;
    	// debug(ox) debug(oy)
    	q.pop();
    	for (int i = 0; i < 4; i++){
    		int x = ox + dx[i], y = oy + dy[i];
    		if (0 <= x && x < n && 0 <= y && y < m && !searched[x][y]){
    			if (x == r2 && y == c2){
    				if (g[r2][c2]){
			    		cout << "YES";
			    		return 0;
			    	}
			    	int cnt = 0;
			    	for (int i = 0; i < 4; i++){
			    		int nx = r2 + dx[i], ny = c2 + dy[i];
			    		if (0 <= nx && nx < n && 0 <= ny && ny < m && !g[nx][ny]){
			    			cnt++;
			    		}
			    	}
			    	if (cnt > 1){
			    		cout << "YES";
			    		return 0;
			    	}
			    	cout << "NO"; 
			    	return 0;
    			}
    			searched[x][y] = 1;
    			if (!g[x][y]) q.push(mp(x, y));
    		}
    	}
    }
    cout << "NO";
}
