// Problem: D. Circular Spanning Tree
// Contest: Codeforces - Codeforces Round #793 (Div. 2)
// URL: https://codeforces.com/contest/1682/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-22 15:35:11
// 
// Powered by CP Editor (https://cpeditor.org)

// https://codeforces.com/profile/Intellegent <3

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
	str s;
	cin >> s;
	int o = 0, z = 0;
	for (int i = 0; i < n; i++){
		if (s[i] == '1'){
			o++;
		}
		else{
			z++;
		}
	}
	if (o % 2 || o == 0){
		cout << "NO\n";
		return;
	}
	
	cout << "YES\n";
	
	if (z == 0){
		for (int i = 2; i <= n; i++){
			cout << "1 " << i << "\n";
		}
		return;
	}
	
	int f = 0;
	if (!(s[n-1] == '1' && s[0] == '0')) for (int i = 1; i < n; i++){
		if (s[i] == '0' && s[i-1] == '1'){
			f = i;
			break;
		}
	}

	for (int i = f + 1; i < f + n; i++){
		if (s[(i-1) % n] == '1'){
			cout << i % n + 1 << " " << f + 1 << "\n";
		}
		else{
			cout << i % n + 1 << " " << (i - 1) % n + 1 << "\n";
		}
	}
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
