// Problem: D. Flowers
// Contest: Codeforces - Codeforces Round #271 (Div. 2)
// URL: https://codeforces.com/problemset/problem/474/D
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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


#define MAXN 100005
const int mod = 1e9 + 7;
int ans[MAXN], sum[MAXN];

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ans[0] = 1;
    sum[0] = 1;
    int t, k;
    cin >> t >> k;
    fr(i, 1, MAXN) {
    	if (i >= k) ans[i] = (1LL * ans[i-1] + ans[i-k]) % mod;
    	else ans[i] = 1;
    	sum[i] = (1LL * sum[i-1] + ans[i]) % mod;
    	// cout << i << " " << ans[i] << " " << sum[i] << "\n";
    }
    while (t--) {
    	int a, b;
    	cin >> a >> b;
    	cout << (1LL * sum[b] + mod - sum[a - 1]) % mod << "\n";
    }
}
