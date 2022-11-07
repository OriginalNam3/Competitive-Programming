// Problem: D. Fixed Point Guessing
// Contest: Codeforces - Codeforces Round #803 (Div. 2)
// URL: https://codeforces.com/contest/1698/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-07-02 18:41:38
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

vector<int> q(int l, int r){
	cout << "? " << l << " " << r << "\n";
	cout.flush();
	
	vector<int> res(r - l + 1);
	for (int &x: res) cin >> x;
	
	return res;
}

void solve(){
	int n;
	cin >> n;
	
	int l = 1, r = n;
	while (l < r){
		int m = (l + r)/ 2;
		vector<int> res(r - l + 1);
		res = q(l, m);
		int cnt = 0;
		for (int x: res){
			if (l <= x && x <= m){
				cnt++;
			}
		}
		if (cnt % 2) r = m;
		else l = m + 1;
	}
	cout << "! " << l << "\n";
	cout.flush();
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    solve();
}
// 5
// 3 4 1 2 5