// Problem: Concert Tickets
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1091
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-03 00:05:56
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

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    set<int> a;
    map<int, int> cnt;
    forn(i, 0, n){
    	int x; cin >> x;
    	if (cnt[x] == 0) a.insert(x);
    	cnt[x]++;
    }
    forn(i, 0, min(n, m)){
    	int x; cin >> x;
    	auto it = upper_bound(all(a), x);
    	if (it == a.begin()){
    		cout << "-1\n";
    	}
    	else{
    		it--;
    		int h = *it;
    		cout << h << "\n";
    		if (--cnt[h] == 0) a.erase(it);
    	}
    }
}