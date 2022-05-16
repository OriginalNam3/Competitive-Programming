// Problem: C. Detective Task
// Contest: Codeforces - Codeforces Round #787 (Div. 3)
// URL: https://codeforces.com/contest/1675/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-15 20:05:43
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
	str s;
	cin >> s;
	int n = s.size();
	vector<int> o(n+1), z(n+1);
	for (int i = n-1; i >= 0; i--){
		o[i] += o[i+1];
		if (s[i] == '1' && i > 0) o[i-1]++;
	}
	for (int i = 0; i < n; i++){
		z[i+1] += z[i];
		if (s[i] == '0') z[i+1]++;
	}
	// vdebug(o) vdebug(z)
	
	int ans = 0;
	for (int i = 0; i < n; i++){
		if (o[i] == 0 && z[i] == 0){
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
