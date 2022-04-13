// Problem: C. Wrong Addition
// Contest: Codeforces - Late night coding Pepega
// URL: https://codeforces.com/problemset/problem/1619/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
typedef array<int, 3> qq;

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsor(x) sort(x.rbegin(), x.rend())
#define pb push_back

#define forn(i,a,b) for (int i = (a); i < (b); ++i)
#define fors(i,a,b,s) for (int i = (a); i < (b); i+=s)
#define rofn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rep(n) for (int _ = 0; _ < n; _++)
#define each(x, a) for (auto& x: a)

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	str a; ll s;
	cin >> a >> s;
	int n = a.size();
	vi b(n);
	bool ok = true;
	forn(i, 0, n){
		if (s%10 >= a[n-1-i] - '0'){
			b[i] = s %10 - (a[n-1-i]-'0');
			s /= 10;
			continue;
		}
		if (s < 10 || (s % 100 - (a[n-i-1] - '0')) > 9 || (s % 100 - (a[n-i-1] - '0')) < 0) {
			ok = false;
			break;
		}
		b[i] = (s % 100 - (a[n-i-1] - '0'));
		s /= 100;
	}
	if (!ok) {
		cout << "-1\n";
		return;
	}
	bool lead = true;
	if (s > 0) {
		cout << s;
		lead = false;
	}
	rofn(i, 0, n){
		if (lead && b[i] == 0) continue;
		lead = false;
		cout << b[i];
	}
	cout << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
    	solve();
    }
}
