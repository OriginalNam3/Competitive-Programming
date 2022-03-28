// Problem: A. Maze
// Contest: Codeforces - Codeforces Round #222 (Div. 1)
// URL: https://codeforces.com/problemset/problem/377/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back

#define fr(i,a,b) for (int i = (a); i < (b); ++i)
#define rf(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define each(x, a) for (auto& x: a)

#define MAXN 503

int maze[MAXN][MAXN], searched[MAXN][MAXN], dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n, m, k, cnt = 0;

void dfs (int x, int y) {
	searched[x][y] = 1;
	cnt--;
	// cout << x << " " << y << " " << cnt << "\n";
	if (cnt < k) maze[x][y] = 2;
	fr(i, 0, 4){
		int nx = x + dx[i], ny = y + dy[i];
		if ((0 <= nx && nx < n) && (0 <= ny && ny < m) && !searched[nx][ny]) {
			dfs(nx, ny);
		}
	}
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    int x, y;
    fr(i, 0, n){
    	str row;
    	cin >> row;
    	fr(j, 0, m) {
    		maze[i][j] = searched[i][j] = row[j] == '#';
    		if (!maze[i][j]) {
    			x = i;
    			y = j;
    			cnt++;
    		}
    	}
    }
    // cout << cnt << "\n";
    dfs(x, y);
    fr(i, 0, n){
    	fr(j, 0, m){
    		if (maze[i][j] == 0) cout << '.';
    		if (maze[i][j] == 1) cout << '#';
    		if (maze[i][j] == 2) cout << 'X';
    	}
    	cout << "\n";
    }
}
