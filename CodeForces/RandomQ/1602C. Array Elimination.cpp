// Problem: C. Array Elimination
// Contest: Codeforces - 11-5-2022 Evening
// URL: https://codeforces.com/problemset/problem/1602/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-11 18:48:18
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
	vector<int> a(n);
	for (int &x: a) cin >> x;
	
	vector<int> cnt(31);
	for (int i = 0; i < n; i++){
		int j = a[i];
		for (int p = 0; p < 31; p++){
			if (j & 1) cnt[p]++;
			j >>= 1;
		}
	}
	
	int ans = -1;
	for (int i = 0; i < 31; i++){
		if (cnt[i] == 0) continue;
		if (ans == -1){
			ans = cnt[i];
			continue;
		}
		ans = gcd(ans, cnt[i]);
	}
	if (ans == -1){
		for (int i = 1; i <= n; i++) cout << i << " ";
	}
	else{
		for (int i = 1; i <= ans; i++){
			if (ans % i == 0) cout << i << " ";
		}
	}
	cout << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
