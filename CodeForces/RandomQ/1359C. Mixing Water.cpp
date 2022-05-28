// Problem: C. Mixing Water
// Contest: Codeforces - Educational Codeforces Round 88 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1359/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-27 22:42:43
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
	db h, c, t;
	cin >> h >> c >> t;
	if (t <= (h + c) / 2){
		cout << "2\n";
		return;
	}
	int l = 1, r = 1e9;
	while (l < r){
		int m = l + (r - l)/2;
		// debug((((m+1) * h) + (m * c))/(2*m + 1))
		if ((((m+1) * h) + (m * c))/(2*m + 1) >= t) l = m + 1;
		else r = m;
	}
	if (abs((((l+1) * h) + (l * c))/(2*l + 1) - t) < abs((((l) * h) + ((l-1) * c))/(2*l - 1) - t))
		cout << 2 * l + 1 << "\n";
	else cout << 2 * l - 1 << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
