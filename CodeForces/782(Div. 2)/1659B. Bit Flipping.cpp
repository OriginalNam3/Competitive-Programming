// Problem: B. Bit Flipping
// Contest: Codeforces - Codeforces Round #782 (Div. 2)
// URL: https://codeforces.com/contest/1659/problem/B
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
	str s;
	cin >> s;
	bool cur = 0;
	if (k % 2 == 1){
		cur = 1;
	}
	vi ans(n);
	int cnt = k;
	forn(i, 0, n){
		if (cnt == 0) break;
		if (((s[i]-'0') ^ (k%2)) == 0){
			ans[i]++;
			cnt--;
		}
	}
	if (k > 0){
		ans[n-1] += cnt;
	}
	forn(i, 0, n){
		bool a = (bool)(s[i]-'0') ^ ((k-ans[i]) % 2);
		cout << a;
	}
	cout << "\n";
	forn(i, 0, n){
		cout << ans[i] << " ";
	}
	cout << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
    	solve();
    }
}
