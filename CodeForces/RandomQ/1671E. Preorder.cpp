// Problem: E. Preorder
// Contest: Codeforces - Educational Codeforces Round 127 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1671/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-11 14:33:31
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define mp make_pair
#define f first
#define s second

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsor(x) sort(x.rbegin(), x.rend())
#define pb push_back

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

const int mod = 998244353;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

int qpow(int a, int b){  // returns a^b % mod
	int res = 1;
	while (b > 0){
		if (b & 1) res = (1LL * res * a) % mod;
		b >>= 1;
		a = (1LL * a * a) % mod;
	}
	return res;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
	string s;
	cin >> s;
	s = "#" + s;
	vector<pair<int, int> > seg(1 << n + 1);
	vector<int> ord(1 << n + 1);
	
	for (int i = (1 << n) - 1; i >= (1 << (n - 1)); i--){
		seg[i].f = 1;
		seg[i].s = s[i] - 'A' + 1;
	}
	
	for (int i = (1 << (n - 1)) - 1; i > 0; i--){
		// debug(seg[i*2].s) debug(seg[i*2+1].s)
		ord[i] = ord[i * 2] * 2 + 1;
		if (seg[i*2].s == seg[i*2+1].s){
			seg[i].f = mul(seg[i*2].f, seg[i*2].f);
		}
		else{
			seg[i].f = mul(2, mul(seg[i*2].f, seg[i*2+1].f));
		}
		seg[i].s = add((s[i] - 'A') + 1, mul(31, add(min(seg[i*2].s, seg[i*2+1].s), mul(qpow(31, ord[i]), max(seg[i*2].s, seg[i*2+1].s)))));
		// debug(seg[i].f) debug(seg[i].s)
	}
	
	cout << seg[1].f;
}

