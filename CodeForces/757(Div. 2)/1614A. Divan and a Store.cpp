// Problem: A. Divan and a Store
// Contest: Codeforces - Brogrammer contest #something (I forgor)
// URL: https://codeforces.com/contest/1614/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-23 18:55:31
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
#define pb push_back

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n, l, r, k;
	cin >> n >> l >> r >> k;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	
	sor(a);
	int ans = 0;
	for (int i = 0; i < n; i++){
		if (a[i] >= l && a[i] <= r){
			if (a[i] > k) break;
			k -= a[i];
			ans++;
		}
	}
	cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
