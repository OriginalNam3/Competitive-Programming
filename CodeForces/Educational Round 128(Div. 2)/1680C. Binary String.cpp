// Problem: C. Binary String
// Contest: Codeforces - Educational Codeforces Round 128 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1680/problem/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-13 15:45:26
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
	string s;
	cin >> s;
	int n = s.size();
	vector<int> pre(n);
	if (s[0] == '0') pre[0]++;
	for (int i = 1; i < n; i++){
		pre[i] += pre[i-1];
		if (s[i] == '0'){
			pre[i]++;
		}
	}
	if (pre[n-1] == n){
		cout << "0\n"; return;
	}
	
	int ans = n - pre[n-1];
	for (int i = 0; i < n; i++){
		if (s[i] == '1'){
			int l = i, r = n-1, cur = i - pre[i];
			while (l < r){
				int m = (l + r)/2;
				if ((n - 1 - m) - (pre[n-1] - pre[m]) + cur <= pre[m] - pre[i]){
					r = m;
				}
				else{
					l = m+1;
				}
			}
			// debug(l)
			int nans = max((n - 1 - l) - (pre[n-1] - pre[l]) + cur, pre[l] - pre[i]);
			// debug(nans)
			ans = min(ans, nans);
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
