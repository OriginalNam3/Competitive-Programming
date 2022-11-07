// Problem: C. Swap Game
// Contest: Codeforces - Codeforces Round #832 (Div. 2)
// URL: https://codeforces.com/contest/1747/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-11-05 12:24:18
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
	
	vector<int> a(n);
	
	for (int &x: a) cin >> x;
	
	int mn = INT_MAX;
	for (int i = 1; i < n; i++){
		mn = min(mn, a[i]);
	}
	
	if (mn <= a[0] - 1){
		cout << "Alice\n";
	}
	else cout << "Bob\n";
}

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; 
	cin >> t;
	while (t--)
	solve();
}
