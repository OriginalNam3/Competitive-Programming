// Problem: E. notepad.exe
// Contest: Codeforces - Codeforces Global Round 20
// URL: https://codeforces.com/contest/1672/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-04-25 21:39:31
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
	
}

int q(int w){
	cout << "? " << w << "\n";
	cout.flush();
	int h;
	cin >> h;
	return h;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int l = 1, r = 4000000, h;
    while (l < r){
    	int m = (l + r)/2;
    	// if (l == r - 1) m++;
    	h = q(m);
    	if (h != 1){
    		l = m+1;
    	}
    	else{
    		r = m;
    	}
    }
    int ans = r;
    forn(i, 2, n+1){
    	int w = r/i;
		h = q(w);
		if (h > 0) ans = min(ans, h * w);
    }
    cout << "! " << ans << "\n";
}
