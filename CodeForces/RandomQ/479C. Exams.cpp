// Problem: C. Exams
// Contest: Codeforces - Codeforces Round #274 (Div. 2)
// URL: https://codeforces.com/problemset/problem/479/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-21 22:21:53
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
	vector<pair<int, int> > e(n);
	for (int i = 0; i < n; i++){
		cin >> e[i].f >> e[i].s;
	}
	
	int cur = 0;
	sor(e);
	for (int i = 0; i < n; i++){
		if (e[i].s >= cur){
			cur = e[i].s;
		}
		else{
			cur = e[i].f;
		}
	}
	cout << cur;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
