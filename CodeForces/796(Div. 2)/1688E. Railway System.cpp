// Problem: E. Railway System
// Contest: Codeforces - Codeforces Round #796 (Div. 2)
// URL: https://codeforces.com/contest/1688/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-06-03 15:35:12
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
#define pb push_back

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

const int mod = 1e9+7;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n, m;
	cin >> n >> m;
	
	vector<pair<int, int> > a(m);
	
	str q = "";
	for (int i = 0; i < m; i++){
		q += "0";
	}
	q += "\n";
	
	for (int i = 0; i < m; i++){
		q[i] = '1';
		cout << "? " << q;
		q[i] = '0';
		cout.flush();
		cin >> a[i].f;
		a[i].s = i;
	}
	
	sor(a);
	q[a[0].s] = '1';
	int cur = a[0].f, res, ans = a[0].f;
	for (int i = 1; i < m; i++){
		q[a[i].s] = '1';
		cout << "? " << q;
		cout.flush();
		cin >> res;
		if (res == cur + a[i].f){
			ans += a[i].f;
		}
		cur = res;
	}
	
	cout << "! " << ans;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
