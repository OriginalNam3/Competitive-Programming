// Problem: D. 1-2-K Game
// Contest: Codeforces - Educational Codeforces Round 68 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1194/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-12 19:08:19
// 
// Powered by CP Editor (https://cpeditor.org)

// You either sink in the coom, or coom in the sink.

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
	int n, k;
	cin >> n >> k;
	if (k % 3 != 0){
		if (n % 3 == 0 && n != k){
			cout << "Bob\n";
		}
		else{
			cout << "Alice\n";
		}
	}
	else{
		n = n % (k + 1);
		if (n % 3 == 0 && n != k){
			cout << "Bob\n";
		}
		else{
			cout << "Alice\n";
		}
	}
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
