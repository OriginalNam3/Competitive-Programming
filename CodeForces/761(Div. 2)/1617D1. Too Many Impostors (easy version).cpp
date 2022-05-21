// Problem: D1. Too Many Impostors (easy version)
// Contest: Codeforces - TCP
// URL: https://codeforces.com/contest/1617/problem/D1
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Date & Time: 2022-05-18 18:41:19
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

bool q(int a, int b, int c){
	cout << "? " << a + 1 << " " << b + 1 << " " << c + 1 << "\n";
	cout.flush();
	bool res;
	cin >> res;
	return res;
}

void solve(){
	int n;
	cin >> n;
	int o = -1, z = -1;
	for (int i = 0; i < n; i += 3){
		if (q(i, i + 1, i + 2)) o = i;
		else z = i;
	}
	
	if (q(o, o + 1, z)){
		if (q(o, z, z + 1)){
			z += 2;
		}
		else{
			if (q(o + 1, z, z + 1)){
				z += 2;
				o += 1;
			}
		}
	}
	else{
		o += 2;
	}
	
	vector<int> ans(1, z + 1);
	for (int i = 0; i < n; i++){
		if (i == o || i == z) continue;
		if (!q(i, o, z)){
			ans.pb(i + 1);
		}
	}
	cout << "! " << ans.size() << " ";
	for (int sus: ans) cout << sus << " ";
	cout << "\n";
	cout.flush();
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
