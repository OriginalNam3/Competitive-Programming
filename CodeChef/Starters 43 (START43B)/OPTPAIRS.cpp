// Problem: The Optimal Pairs
// Contest: CodeChef - START43
// URL: https://www.codechef.com/submit-v2/OPTPAIRS
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-06-15 20:44:16
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
	ll n;
	cin >> n;
	vector<int> cnt(1e5);
	// for (int i = 1; i < n; i++){
		// if (gcd(i, n - i) + (i * (n - i))/ gcd(i, n - i) == n){
			// cout << i << " " << n - i << "\n";
		// }
	// }
	int i = 2, x = n;
	bool square = 0;
	while (i * i <= n){
		while (x % i == 0){
			x /= i;
			cnt[i]++;
		}
		i++;
	}
	
	ll res = 1; // number of factors
	if (x > 1){
		res = 2;
	}
	for (int x: cnt) res *= x + 1;
	dbg(res);
	res -= 1;
	res *= 2;
	if (n % 2 == 0) res -= 1;
	cout << res << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; 
    cin >> t;
    while (t--)
    solve();
}
