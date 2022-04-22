// Problem: Pseudo Sorted Array
// Contest: CodeChef - April Long Two 2022 Division 3 (Rated)
// URL: https://www.codechef.com/APRIL222C/problems/PSEUDOSORT
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-04-22 11:15:20
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
template<class T> using V = vector<T>;
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
#define debug(x) cout << #x << " = " << x << "\n";

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n;
	cin >> n;
	vi a(n);
	forn(i, 0, n){
		cin >> a[i];
	}
	forn(i, 0, n-1){
		// debug(i); debug(a[i]);
		if (a[i] > a[i+1]){
			swap(a[i], a[i+1]);
			break;
		}
	}
	forn(i, 0, n-1){
		if (a[i] > a[i+1]){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
    	solve();
    }
}
