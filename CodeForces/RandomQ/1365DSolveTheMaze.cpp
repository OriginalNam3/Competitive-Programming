// Problem: D. Solve The Maze
// Contest: Codeforces - Codeforces Round #648 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1365/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;
typedef string str;

#define mp make_pair
#define f first
#define s second

typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
typedef vector<pi> vpi;
typedef array<int, 3> qq;

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back

#define fr(i,a,b) for (int i = (a); i < (b); ++i)
#define rf(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define each(x, a) for (auto& x: a)

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve(){
	int n, m;
	cin >> n >> m;
	vector<vi> g(n, vi(m));
	fr(i, 0, n){
		str row;
		cin >> row;
		fr(j, 0, m){
			if (row[j] == '.'){
				g[i][j] = 0;
			}
			if (row[j] == '#'){
				g[i][j] = 2;
			}
			if (row[j] == 'G'){
				g[i][j] = 1;
			}
			if (row[j] == 'B'){
				g[i][j] = 3;
			}
		}
	}
	int cnt = 0;
	int sx = n-1, sy = m-1;
	fr(i, 0, n){
		fr(j, 0, m){
			if (g[i][j] == 1) {
				cnt++;
				sx = i; sy = j;
			}
			if (g[i][j] == 3){
				fr(k, 0, 4){
					int x = i + dx[k], y = j + dy[k];
					if (((0 <= x) && (x < n)) && ((0 <= y) && (y < m))){
						if (g[x][y] == 1) {
							// cout << x << " " << y << "\n";
							cout << "No\n";
							return;
						}
						if (g[x][y] == 3){
							continue;
						}
						g[x][y] = 2;
					}
				}
			}
		}
	}
	queue<pi> q;
	q.push(mp(n-1, m-1));
	int ans = 0;
	vector<vb> searched(n, vb(m));
	searched[n-1][m-1] = 1;
	while (!q.empty()){
		int i = q.front().f, j = q.front().s;
		q.pop();
		if (g[i][j] == 1){
			ans++;
			// cout << i << " " << j << "\n";
		}
		if (g[i][j] == 2){
			break;
		}
		if (g[i][j] == 3){
			cout << "No\n";
			return;
		}
		fr(k, 0, 4){
			int x = i + dx[k], y = j + dy[k];
			if (((0 <= x) && (x < n)) && ((0 <= y) && (y < m))){
				if (!searched[x][y] && g[x][y] != 2){
					searched[x][y] = 1;
					q.push(mp(x, y));
				}
			}
		}
	}
	// fr(i, 0, n){
		// fr(j, 0, m){
			// cout << g[i][j] << " ";
		// }
		// cout << "\n";
	// }
	cout << ((ans == cnt) ? "Yes\n": "No\n");
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
    	// cout << t << "\n";
    	solve();
    }
}
