// Problem: D. Colored Rectangles
// Contest: Codeforces - Educational Codeforces Round 93 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1398/D
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

bool cmp(int a, int b) {return a > b;}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int R, G, B;
    cin >> R >> G >> B;
    vector<vi> a(3, vi(max(max(R, G), B)));
    fr(i, 0, R) cin >> a[0][i];
    fr(i, 0, G) cin >> a[1][i];
    fr(i, 0, B) cin >> a[2][i];
	sort(all(a[0]), cmp); sort(all(a[1]), cmp); sort(all(a[2]), cmp);
    int area = 0;
    vector<vector<vi> > dp(R + 1, vector<vi>(G + 1, vi(B + 1)));
    fr(i, 0, R + 1) {
    	fr (j, 0, G + 1) {
    		fr (k, 0, B + 1) {
    			if (i < R && j < G) dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + a[0][i] * a[1][j]);
    			if (j < G && k < B) dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1], dp[i][j][k] + a[1][j] * a[2][k]);
    			if (i < R && k < B) dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + a[0][i] * a[2][k]);
    			area = max(area, dp[i][j][k]);
    		}
    	}
    }

    
    cout << area;
}
