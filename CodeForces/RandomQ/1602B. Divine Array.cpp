// Problem: B. Divine Array
// Contest: Codeforces - 11-5-2022 Evening
// URL: https://codeforces.com/problemset/problem/1602/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-11 18:48:18
// 
// Powered by CP Editor (https://cpeditor.org)

// You either sink in the coom, or coom in the sink.

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

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	vector<vector<int> > cnt(n+1, vector<int>(n + 1));
	for (int i = 0; i < n; i++){
		cnt[0][a[i]]++;
	}
	vector<vector<int> > state(n+1, vector<int>(n));
	for (int i = 0; i < n; i++){
		state[0][i] = a[i];
	}
	for (int i = 0; i < n; i++){
		for (int j = 1; j <= n; j++){
			cnt[i+1][cnt[i][j]] += cnt[i][j];
		}
		for (int j = 0; j < n; j++){
			state[i+1][j] = cnt[i][state[i][j]];
		}
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++){
		int x, k;
		cin >> x >> k;
		cout << state[min(n, k)][x - 1];
		cout << "\n";
	}
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
