// Problem: C. Barcode
// Contest: Codeforces - Codeforces Round #139 (Div. 2)
// URL: https://codeforces.com/problemset/problem/225/C
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
typedef array<int, 3> qq;

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back

#define forn(i,a,b) for (int i = (a); i < (b); ++i)
#define rofn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rep(n) for (int _ = 0; _ < n; _++)
#define each(x, a) for (auto& x: a)

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, x, y;
    cin>>n>>m>>x>>y;
    y++;
    vi cnt(m);
    forn(i, 0, n){
    	str row;
    	cin >> row;
    	forn(j, 0, m){
    		cnt[j] += row[j]=='#';
    	}
    }
    // forn(i, 0, m){
    	// cout << cnt[i] << " ";
    // }
    // cout << "\n";
    vi wsums(m+1), bsums(m+1);
    wsums[1] = n - cnt[0]; bsums[1] = cnt[0];
    forn(i, 2, m+1){
    	wsums[i] = wsums[i-1] + n - cnt[i-1];
    	bsums[i] = bsums[i-1] + cnt[i-1];
    	// cout << wsums[i] << " " << bsums[i] << " " << cnt[i] << "\n";
    }
    
    vector<vll> dp(m+1, vll(2, INT_MAX));
    dp[0][0] = dp[0][1] = 0;
    forn(i, 1, m+1){
    	// if (i+1 < y){
    		// dp[i+1][0] = bsums[i];
    		// dp[i+1][1] = wsums[i];
    	// }
    	forn(j, x, y){
    		if (i - j < 0) break;
    		dp[i][0] = min(dp[i][0], dp[i-j][1] + bsums[i] - bsums[i-j]);
    		dp[i][1] = min(dp[i][1], dp[i-j][0] + wsums[i] - wsums[i-j]);
    	}
    	// cout << dp[i][0] << " " << dp[i][1] << "\n";
    }
    cout << min(dp[m][0], dp[m][1]);
}
