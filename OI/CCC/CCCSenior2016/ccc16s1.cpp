// Problem: S1 - Ragaman
// Contest: DMOJ - CCC '16
// URL: https://dmoj.ca/problem/ccc16s1
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-11-02 19:08:24
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
	str a, b;
	cin >> a >> b;
	
	int n = a.size();
	vector<int> c(26), d(26);
	for (int i = 0; i < n; i++){
		c[a[i] - 'a']++;
		if (b[i] == '*') continue;
		d[b[i] - 'a']++;
	}
	
	for (int i = 0; i < 26; i++){
		if (c[i] < d[i]){
			cout << "N\n";
			return;
		}
	}
	cout << "A\n";
}

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
}
