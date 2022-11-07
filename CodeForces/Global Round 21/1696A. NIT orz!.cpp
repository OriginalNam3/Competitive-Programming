// Problem: A. NIT orz!
// Contest: Codeforces - Codeforces Global Round 21
// URL: https://codeforces.com/contest/1696/problem/A
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Date & Time: 2022-06-25 15:35:11
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
	int n, z;
	cin >> n >> z;
	vector<int> a(n);
	int mx = 0;
	for (int &x: a){
		cin >> x;
		mx = max(mx, x | z);
	}
	
	cout << mx << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; 
    cin >> t;
    while (t--)
    solve();
}
