// Problem: C. Recover an RBS
// Contest: Codeforces - Educational Codeforces Round 132 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1709/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-07-24 01:10:46
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
	str s;
	cin >> s;
	int n = s.length(), o = 0, c = 0;
	for (int i = 0; i < n; i++){
		if (s[i] == '(') o++;
		if (s[i] == ')') c++;
	}
	
	if (o == n/2 || c == n/2){
		cout << "YES\n"; return;
	}
	
	o = n/2 - o;
	
	int ocnt = 0, ccnt = 0;
	dbg(s);
	bool ok = true;
	for (int i = 0; i < n; i++){
		if (s[i] == '(') ocnt++;
		if (s[i] == ')') ccnt++;
		if (s[i] == '?'){
			if (o-- > 1){
				ocnt++;
			}
			else {
				if (o == 0){
					ccnt++;
				}
				if (o == -1){
					ocnt++;
				}
				if (o < -1){
					ccnt++;
				}
			}
		}
		if (ocnt < ccnt){
			ok = false;
		}
	}
	cout << (ok ? "NO\n": "YES\n");
}

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; 
	cin >> t;
	while (t--)
	solve();
}
