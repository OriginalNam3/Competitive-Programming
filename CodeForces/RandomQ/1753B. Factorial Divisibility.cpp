// Problem: B. Factorial Divisibility
// Contest: Codeforces - Codeforces Round #829 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1753/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-11-02 14:21:45
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
	int n, x;
	cin >> n >> x;
	vector<int> a(x + 1);
	
	for (int i = 0; i < n; i++){
		int e;
		cin >> e;
		a[e]++;
	}
	
	for (int i = 1; i < x; i++){
		if (a[i] % (i + 1)){
			cout << "No\n";
			return;
		}
		a[i + 1] += a[i]/ (i + 1);
	}
	
	cout << "Yes\n";
}

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
}
