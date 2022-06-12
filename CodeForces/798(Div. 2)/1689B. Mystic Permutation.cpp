// Problem: B. Mystic Permutation
// Contest: Codeforces - Codeforces Round #798 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1689/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-10 21:14:44
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
	if (n == 1){
		int x; cin >> x;
		cout << "-1\n"; return;
	}
	vector<int> a(n), b(n);
	for (int &x: a) cin >> x;
	for (int i = 0; i < n; i++) b[i] = i + 1;
	
	for (int i = 0; i < n - 1; i++){
		if (b[i] == a[i]) swap(b[i], b[i+1]);
	}
	if (b[n-1] == a[n-1]){
		swap(b[n-1], b[n-2]);
	}
	
	for (int x: b) cout << x << " ";
	cout << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
