// Problem: B. Counting Rectangles is Fun
// Contest: Codeforces - Codeforces Round #219 (Div. 1)
// URL: https://codeforces.com/problemset/problem/372/B
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Date & Time: 2022-05-26 21:20:22
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





// this question lowkey dogwater ong no cap frfr





int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<bool> > g(n, vector<bool> (m));
    for (int i = 0; i < n; i++){
    	str row;
    	cin >> row;
    	for (int j = 0; j < m; j++){
    		g[i][j] = row[j] == '1';
    	}
    	// vdebug(g[i])
    }
    
    
    int cnt[n][m][n][m];
    memset(cnt, 0, sizeof cnt);
    
    for (int a = 0; a < n; a++) for (int b = 0; b < m; b++){
    	int mnj = m;
		for (int c = a; c < n; c++){
			for (int d = b; d < mnj; d++){
				if (g[c][d]){
					mnj = d;
					break;
				}
				cnt[a][b][c][d]++;
				// debug(cnt[a][b][c][d])
			}
		}
    }
    
    
    int dp[n + 1][m + 1][n + 1][m + 1];
    memset(dp, 0, sizeof dp);

    for (int a = 1; a <= n; a++) for (int b = 1; b <= m; b++){
    	for (int c = a; c <= n; c++) for (int d = b; d <= m; d++){
    		dp[a][b][c][d] += dp[a][b][c-1][d] + dp[a][b][c][d-1] - dp[a][b][c-1][d-1] + cnt[a-1][b-1][c-1][d-1];
    	}
    }
    
    
    int ans[n + 2][m + 2][n + 2][m + 2];
    memset(ans, 0, sizeof ans);
    
    for (int c = n; c >= 1; c--) for (int d = m; d >= 1; d--){
    	for (int a = c; a >= 1; a--) for (int b = d; b >= 1; b--){
    		ans[a][b][c][d] += ans[a + 1][b][c][d] + ans[a][b + 1][c][d] - ans[a + 1][b + 1][c][d] + dp[a][b][c][d];
    	}
    }
    

    while (q--){
    	int a, b, c, d;
    	cin >> a >> b >> c >> d;
    	cout << ans[a][b][c][d] << "\n";
    }
}
