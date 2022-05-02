// Problem: E. Breaking the Wall
// Contest: Codeforces - Codeforces Round #786 (Div. 3)
// URL: https://codeforces.com/contest/1674/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-02 15:35:10
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
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vi a(n);
    each(x, a) cin >> x;
    if (n == 1){
    	cout << (a[0] + 1) / 2;
    	return 0;
    }
    int ans = INT_MAX;
    
    forn(i, 0, n-1){
    	if (a[i] >= 2 * a[i + 1]){
    		ans = min(ans, (a[i] + 1)/2);
    	}
    	else if (a[i] >= a[i + 1]){
    		int nxt = a[i] - a[i + 1], cur = a[i] - 2 * nxt;
    		ans = min(ans, (cur / 3) * 2 + cur % 3 + nxt);
    		// debug(cur) debug(nxt)
    	}
    	// debug(i) debug(ans)
    }
    forn(i, 1, n){
    	if (a[i] >= 2 * a[i - 1]){
    		ans = min(ans, (a[i] + 1)/ 2);
    	}
    	else if (a[i] > a[i-1]){
    		int nxt = a[i] - a[i - 1], cur = a[i] - 2 * nxt;
    		ans = min(ans, (cur / 3) * 2 + cur % 3 + nxt);
    	}
    	// debug(i) debug(ans)
    }
    forn(i, 1, n-1){
    	ans = min(ans, max(a[i-1], a[i+1]));
    	ans = min(ans, min(a[i-1], a[i+1]) + (abs(a[i+1] - a[i-1]) + 1)/2);
    }
    
    int mn = INT_MAX, smn = INT_MAX;
    forn(i, 0, n){
    	if (a[i] < mn){
    		smn= mn;
    		mn = a[i];
    	}
    	else if (a[i] < smn){
    		smn = a[i];
    	}
    }
    ans = min(ans, ((mn + 1) / 2) + ((smn + 1) / 2));
    cout << ans;
}
