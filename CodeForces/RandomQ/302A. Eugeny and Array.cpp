// Problem: A. Eugeny and Array
// Contest: Codeforces - Codeforces Round #182 (Div. 2)
// URL: https://codeforces.com/contest/302/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-04 11:18:20
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
    int n, m;
    cin >> n >> m;
    int a = 0, b = 0;
    
    forn(i, 0, n){
    	int x; cin >> x;
    	if (x == 1) a++;
    	else b++;
    }
    // debug(a) debug(b)
    rep(m){
    	int l, r;
    	cin >> l >> r;
    	if ((r - l + 1) % 2 == 1){
    		cout << "0\n";
    	}
    	else{
    		if ((r - l + 1) / 2 <= min(a, b)){
    			cout << "1\n";
    		}
    		else{
    			cout << "0\n";
    		}
    	}
    }
}
