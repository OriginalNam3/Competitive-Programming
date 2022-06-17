// Problem: G. 2^Sort
// Contest: Codeforces - Codeforces Round #799 (Div. 4)
// URL: https://codeforces.com/contest/1692/problem/G
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-06-14 17:15:28
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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	int i = 0, j = 0;
	vector<int> suf(n, INT_MAX);
	for (int i = 1; i < n; i++){
		if (a[i] * 2 <= a[i-1]){
			suf[i-1] = i;
		}
	}
	dbg(suf);
	
	int cnt = 0;
	for (int i = n - 2; i >= 0; i--){
		suf[i] = min(suf[i], suf[i+1]);
		if (suf[i] > i + k && i < n - k){
			cnt++;
		}
	}
	dbg(suf);
	
	cout << cnt << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; 
    cin >> t;
    while (t--)
    solve();
}
