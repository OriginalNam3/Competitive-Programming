// Problem: C. 3SUM Closure
// Contest: Codeforces - Codeforces Round #803 (Div. 2)
// URL: https://codeforces.com/contest/1698/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-07-02 16:49:13
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

void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for (ll &x: a) cin >> x;
	
	sor(a);
	int i = 0, j = n - 1;
	bool ok = true;
	while (i < n && a[i] < 0) i++;
	while (j >= 0 && a[j] > 0) j--;
	
	if (i > 2 || j < n - 3){
		cout << "NO\n"; return;
	}
	
	vector<int> b;
	for (int x = 0; x < i; x++) b.pb(a[x]);
	if (i <= j) b.pb(0);
	for (int x = j + 1; x < n; x++) b.pb(a[x]);
	dbg(b);
	for (int i = 0; i < b.size(); i++){
		for (int j = i + 1; j < b.size(); j++){
			for (int k = j + 1; k < b.size(); k++){
				ll sum = b[i] + b[j] + b[k];
				bool in = false;
				for (int l = 0; l < b.size(); l++){
					if (b[l] == sum) in = true;
				}
				if (!in) {
					cout << "NO\n"; return;
				}
			}
		}
	}
	
	cout << "YES\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; 
    cin >> t;
    while (t--)
    solve();
}
