// Problem: D. Cyclic Rotation
// Contest: Codeforces - Codeforces Global Round 20
// URL: https://codeforces.com/problemset/problem/1672/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-04-24 15:59:51
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
template<class T> using V = vector<T>;
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
	int n;
	cin >> n;
	vi a(n), b(n);
	each(x, a) cin >> x;
	each(x, b) cin >> x;
	
	if (a[n-1] != b[n-1]){
		cout << "NO\n"; return;
	}
	
	map<int, int> cnt, used;
	forn(i, 0, n-1){
		cnt[a[i]]++;
	}
	int j = n-2, prev = a[n-1];
	rofn(i, 0, n-1){
		while (j >= 0 && cnt[a[j]] == 0) j--;
		// debug(j);
		// debug(a[j]);
		// debug(cnt[a[j]]);
		if (b[i] == a[j]) {
			cnt[b[i]]--;
			j--;
			prev = b[i];
			// cout << "Equal\n";
		}
		else {
			if (b[i] == prev && cnt[prev] > 0){
				cnt[prev]--;
				used[prev]++;
				continue;
			}
			if (used[a[j]] > 0){
				used[a[j]]--;
				j--;
				i++;
				continue;
			}
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
