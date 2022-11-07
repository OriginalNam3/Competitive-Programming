// Problem: E. Cactus Wall
// Contest: Codeforces - Educational Codeforces Round 138 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1749/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-11-04 10:54:09
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
#define pb emplace_back

#ifdef ORIGINAL_LOCAL
#include <bits/debug.h>
#else
#define dbg(...) 42
#endif

const int mod = 1e9+7;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n, m;
	cin >> n >> m;
	
	vector<vector<bool> > f(n, vector<bool> (m));
	
	for (int i = 0; i < n; i++){
		str s;
		cin >> s;
		for (int j = 0; j < m; j++) if (s[j] == '#') f[i][j] = 1;
	}
	
	int d2[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	vector<vector<bool> > ok(n, vector<bool> (m, 1));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (f[i][j]) for (int k = 0; k < 4; k++){
				int x = i + d2[k][0], y = j + d2[k][1];
				if (x >= n || x < 0 || y >= m || y < 0) continue;
				ok[x][y] = 0;
			}
		}
	}
	
	set<pair<int, pair<int, int> > > q;
	vector<vector<int> > dist(n, vector<int> (m, INT_MAX));
	
	for (int i = 0; i < n; i++){
		if (!ok[i][0]) continue;
		if (f[i][0]) {
			dist[i][0] = 1;
			q.insert(mp(1, mp(i, 0)));
		}
		else {
			dist[i][0] = 1000;
			q.insert(mp(1000, mp(i, 0)));
		}
	}
	
	
	int d[4][2] = {{1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
	while (!q.empty()){
		int w = q.begin()->f, x = q.begin()->s.f, y = q.begin()->s.s;
		q.erase(q.begin());
		for (int i = 0; i < 4; i++){
			int nx = x + d[i][0], ny = y + d[i][1];
			if (nx >= n || nx < 0 || ny >= m || ny < 0 || !ok[nx][ny]) continue;
			int nw = w;
			if (!f[nx][ny]) nw += 1000;
			else nw += 1;
			if (nw < dist[nx][ny]){
				auto it = q.find(mp(dist[nx][ny], mp(nx, ny)));
				if (it != q.end()){
					q.erase(it);
				}
				dist[nx][ny] = nw;
				q.insert(mp(nw, mp(nx, ny)));
			}
		}
	}
	dbg(dist);
	int mn = INT_MAX, x = 0;
	for (int i = 0; i < n; i++){
		if (dist[i][m - 1] < mn){
			mn = dist[i][m-1];
			x = i;
		}
	}
	if (mn == INT_MAX){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	
	int y = m - 1;
	vector<pair<int, int> > changes;
	while (y != 0){
		dbg(x, y);
		if (!f[x][y]) mn -= 1000;
		else mn--;
		changes.pb(mp(x, y));
		for (int i = 0; i < 4; i++){
			int nx = x + d[i][0], ny = y + d[i][1];
			if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
			if (dist[nx][ny] == mn){
				x = nx;
				y = ny;
				break;
			}
		}
	}
	changes.pb(mp(x, y));
	
	for (auto p : changes){
		f[p.f][p.s] = 1;
	}
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (f[i][j]) cout << "#";
			else cout << ".";
		}
		cout << "\n";
	}
}

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; 
	cin >> t;
	while (t--)
	solve();
}
