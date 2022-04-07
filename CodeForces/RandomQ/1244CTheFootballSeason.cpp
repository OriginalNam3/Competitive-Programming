// Problem: C. The Football Season
// Contest: Codeforces - Codeforces Round #592 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1244/C
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

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n, p, w, d;
    cin >> n >> p >> w >> d;
    if (p == 0){
    	cout << "0 0 " << n;
    	return 0;
    }
    ll x = -1, y = -1;
    forn(i, 0, w){
    	if ((p - (i * d)) % w == 0){
    		y = i;
    		x = (p-(i*d))/w;
    		break;
    	}
    }
    if (x + y > n || x < 0){
    	cout << -1;
    	return 0;
    }
    cout << x << " " << y << " " << n - x - y;
}
