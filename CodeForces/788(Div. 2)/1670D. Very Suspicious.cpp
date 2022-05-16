// Problem: D. Very Suspicious
// Contest: Codeforces - Codeforces Round #788 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1670/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-16 11:33:49
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
	n = (n + 1) / 2;
	ll l = 0, r = INT_MAX;
	while (l < r){
		ll m = (l + r)/2;
		ll cur = ((m + 1) / 3) * 2;
		ll sum = cur * (cur + 1) / 2 + (m/3) * ((m/3) * 2 + 2) / 2;
		if (m % 3 == 1){
			sum += cur + 1;
		}
		if (sum >= n){
			r = m;
		}
		else{
			l = m+1;
		}
	}
	cout << l + 1 << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
