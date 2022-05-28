// Problem: Range Partition
// Contest: Google Coding Competitions - Round C 2022 - Kick Start 2022
// URL: https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb4d1/0000000000b20deb
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
// Date & Time: 2022-05-22 12:26:25
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
	ll n, x, y;
	cin >> n >> x >> y;
	ll total = (n * (n + 1))/ 2;
	if (total % (x + y) == 0 && (x + y) <= total){
		cout << "POSSIBLE\n";
		ll m = total / (x + y);
		x *= m;
		vector<int> ans;
		for (int i = n; i >= 1 && x > 0; i--){
			if (i <= x){
				x -= i;
				ans.pb(i);
			}
		}
		cout << ans.size() << "\n";
		for (int x: ans) cout << x << " ";
		cout << "\n";
	}
	else{
		cout << "IMPOSSIBLE\n";
	}
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++){
    	cout << "Case #" << i << ": ";
    	solve();
    }
}
