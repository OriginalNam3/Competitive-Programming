// Problem: C. Zero Path
// Contest: Codeforces - Codeforces Round #801 (Div. 2) and EPIC Institute of Technology Round
// URL: https://codeforces.com/contest/1695/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-18 15:59:55
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

typedef array<int, 3> qq;
qq mt(int a, int b, int c){
	qq e = {a, b, c};
	return e;
}

void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > a(n, vector<int>(m));

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		cin >> a[i][j];
	}
	if (((n + m - 1) % 2)){
		cout << "NO\n";
		return;
	}
	
	vector<vector<pair<int, int> > > dp(n, vector<pair<int, int> > (m));
	dp[0][0].f = a[0][0], dp[0][0].s = a[0][0];
	
	for (int i = 1; i < m; i++){
		dp[0][i].f = dp[0][i-1].f + a[0][i], dp[0][i].s = dp[0][i-1].s + a[0][i];
	}
	for (int i = 1; i < n; i++){
		dp[i][0].f = dp[i-1][0].f + a[i][0], dp[i][0].s = dp[i-1][0].s + a[i][0];
		for (int j = 1; j < m; j++){
			dp[i][j].f = min(dp[i-1][j].f, dp[i][j-1].f) + a[i][j], dp[i][j].s = max(dp[i-1][j].s, dp[i][j-1].s) + a[i][j];
		}
	}
	
	// int cur = 0;
	// for (int i = 0; i < n; i++){
		// cur += a[i][0];
	// }
	// for (int j = 1; j < m; j++){
		// cur += a[n-1][j];
	// }
	
	// queue<pair<int, int> > add, sub, stay;
	// if (n > 1 && m > 1){
		// if (a[n-2][1] - a[n - 1][0] > 0){
			// add.push(mp(n-1, 0));
		// }
		// if (a[n-2][1] - a[n-1][0] < 0){
			// sub.push(mp(n-1, 0));
		// }
		// if (a[n-2][1] == a[n-1][0]){
			// stay.push(mp(n-1, 0));
		// }
	// }
	// while (cur != 0 && (!add.empty() || !sub.empty() || !stay.empty())){
		// if (cur > 0){
			// if (!sub.empty()) while (!sub.empty() && cur > 0){
				// int x = sub.front().f, y = sub.front().s;
				// sub.pop();
				// cur -= 2;
				// int nx = x - 1, ny = y;
				// if (nx != 0 && ny != m - 1){
					// if (a[nx - 1][ny + 1] > a[nx][ny]){
						// add.push(mp(nx, ny));
					// }
					// if (a[nx - 1][ny + 1] < a[nx][ny]){
						// sub.push(mp(nx, ny));
					// }
					// if (a[nx - 1][ny + 1] == a[nx][ny]){
						// stay.push(mp(nx, ny));
					// }
				// }
				// nx = x, ny = y - 1;
				// if (nx != 0 && ny != m - 1){
					// if (a[nx - 1][ny + 1] > a[nx][ny]){
						// add.push(mp(nx, ny));
					// }
					// if (a[nx - 1][ny + 1] < a[nx][ny]){
						// sub.push(mp(nx, ny));
					// }
					// if (a[nx - 1][ny + 1] == a[nx][ny]){
						// stay.push(mp(nx, ny));
					// }
				// }
			// }
			// if (cur == 0) break;
			// else{
				// if (!stay.empty()) while (!stay.empty()){
					// int x = stay.front().f, y = stay.front().s;
					// stay.pop();
					// int nx = x - 1, ny = y;
					// if (nx != 0 && ny != m - 1){
						// if (a[nx - 1][ny + 1] > a[nx][ny]){
							// add.push(mp(nx, ny));
						// }
						// if (a[nx - 1][ny + 1] < a[nx][ny]){
							// sub.push(mp(nx, ny));
						// }
						// if (a[nx - 1][ny + 1] == a[nx][ny]){
							// stay.push(mp(nx, ny));
						// }
					// }
					// nx = x, ny = y - 1;
					// if (nx != 0 && ny != m - 1){
						// if (a[nx - 1][ny + 1] > a[nx][ny]){
							// add.push(mp(nx, ny));
						// }
						// if (a[nx - 1][ny + 1] < a[nx][ny]){
							// sub.push(mp(nx, ny));
						// }
						// if (a[nx - 1][ny + 1] == a[nx][ny]){
							// stay.push(mp(nx, ny));
						// }
					// }
				// }
				// else{
					// if (!add.empty()){
						// int x = add.front().f, y = add.front().s;
						// add.pop();
						// cur += 2;
						// int nx = x - 1, ny = y;
						// if (nx != 0 && ny != m - 1){
							// if (a[nx - 1][ny + 1] > a[nx][ny]){
								// add.push(mp(nx, ny));
							// }
							// if (a[nx - 1][ny + 1] < a[nx][ny]){
								// sub.push(mp(nx, ny));
							// }
							// if (a[nx - 1][ny + 1] == a[nx][ny]){
								// stay.push(mp(nx, ny));
							// }
						// }
						// nx = x, ny = y - 1;
						// if (nx != 0 && ny != m - 1){
							// if (a[nx - 1][ny + 1] > a[nx][ny]){
								// add.push(mp(nx, ny));
							// }
							// if (a[nx - 1][ny + 1] < a[nx][ny]){
								// sub.push(mp(nx, ny));
							// }
							// if (a[nx - 1][ny + 1] == a[nx][ny]){
								// stay.push(mp(nx, ny));
							// }
						// }
					// }
				// }
			// }
		// }
	// }
	cout << (dp[n-1][m-1].f <= 0 && dp[n-1][m-1].s >= 0 ? "YES\n": "NO\n");
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; 
    cin >> t;
    while (t--)
    solve();
}
