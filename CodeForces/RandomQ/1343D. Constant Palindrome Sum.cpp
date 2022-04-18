// Problem: D. Constant Palindrome Sum
// Contest: Codeforces - Codeforces Round #636 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1343/D
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
#define rsor(x) sort(x.rbegin(), x.rend())
#define pb push_back

#define forn(i,a,b) for (int i = (a); i < (b); ++i)
#define fors(i,a,b,s) for (int i = (a); i < (b); i+=s)
#define rofn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rep(n) for (int _ = 0; _ < n; _++)
#define each(x, a) for (auto& x: a)
#define debug(x) cout << #x << " = " << x << "\n";

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n, k;
	cin >> n >> k;
	vi a(n);
	each(x, a) cin >> x;
	vi cnt(2 * k + 2);
	forn(i, 0, n/2){
		if (a[i] > k && a[n - i - 1] > k){
			continue;
		}
		if (a[i] > k && a[n - i - 1] < k){
			cnt[a[n - i - 1] + 1]--;
			cnt[a[n - i - 1] + k + 1]++;
			continue;
		}
		if (a[n - i - 1] > k && a[i] < k){
			cnt[a[i] + 1]--;
			cnt[a[i] + k + 1]++;
			continue;
		}
		cnt[min(a[i], a[n - i - 1]) + 1]--;
		cnt[max(a[i], a[n - i - 1]) + k + 1]++;
		cnt[a[i] + a[n - i - 1]]--;
		cnt[a[i] + a[n - i - 1] + 1]++;
	}
	int ans = INT_MAX;
	forn(i, 1, 2 * k + 2){
		cnt[i] += cnt[i-1];
		ans = min(ans, cnt[i]);
		// cout << cnt[i] << " ";
	}
	cout << n + ans << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
