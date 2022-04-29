// Problem: B. Make it Divisible by 25
// Contest: Codeforces - Brogrammer Contest #3
// URL: https://codeforces.com/contest/1593/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-04-29 19:30:58
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;
typedef string str;

#define mp make_pair
#define f first
#define s second

typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
typedef vector<pi> vpi;

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsor(x) sort(x.rbegin(), x.rend())
#define pb push_back

#define forn(i,a,b) for (int i = (a); i < (b); ++i)
#define fors(i,a,b,s) for (int i = (a); i < (b); i+=s)
#define rofn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rep(n) for (int _ = 0; _ < n; _++)
#define each(x, a) for (auto& x: a)
#define debug(x) cout << #x << " = " << x << "\n";

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	str s;
	cin >> s;
	int n = s.size();
	bool five = 0, zero = 0;
	rofn(i, 0, n){
		if (s[i] == '5'){
			if (zero){
				cout << n - i - 2 << "\n";
				return;
			}
			five = 1;
			continue;
		}
		if (s[i] == '2'){
			if (five){
				cout << n - i - 2 << "\n";
				return;
			}
			continue;
		}
		if (s[i] == '0'){
			if (zero){
				cout << n - i - 2 << "\n";
				return;
			}
			zero = 1;
			continue;
		}
		if (s[i] == '7'){
			if (five){
				cout << n - i - 2 << "\n";
				return;
			}
			continue;
		}
	}
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
