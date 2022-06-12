// Problem: D. Guess The String
// Contest: Codeforces - Educational Codeforces Round 130 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1697/problem/D
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// Date & Time: 2022-06-12 18:17:26
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
	int n;
	cin >> n;
	vector<char> ans(n), in;
	map<char, int> ind;
	cout << "? 1 1\n";
	cout.flush();
	cin >> ans[0];
	in.pb(ans[0]);
	ind[ans[0]] = 1;
	for (int i = 1; i < n; i++){
		cout << "? 2 1 " << i + 1 << "\n";
		cout.flush();
		int x; cin >> x;
		if (x > in.size()){
			cout << "? 1 " << i + 1 << "\n";
			cout.flush();
			cin >> ans[i];
			in.pb(ans[i]);
			ind[ans[i]] = i + 1;
			continue;
		}
		in.clear();
		for (char c = 'a'; c <= 'z'; c++){
			ind[c] = -1;
		}
		for (int j = i-1; j >= 0; j--){
			if (ind[ans[j]] == -1){
				in.pb(ans[j]);
				ind[ans[j]] = j + 1;
			}
		}
		int l = 0, r = in.size() - 1;
		while (l < r){
			int m = (l + r)/2;
			cout << "? 2 " << ind[in[m]] << " " << i + 1 << "\n";
			cout.flush();
			int x; cin >> x;
			dbg(x, m, in);
			if (x == m + 1){
				r = m;
			}
			else{
				l = m + 1;
			}
		}
		ans[i] = in[l];
	}
	cout << "! ";
	for (char c: ans) cout << c;
	cout << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
