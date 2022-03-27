// Problem: C. Celex Update
// Contest: Codeforces - Codeforces Round #645 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1358/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
#define pb push_back

#define fr(i,a,b) for (int i = (a); i < (b); ++i)
#define rf(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define each(x, a) for (auto& x: a)

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	ll x, y, x2, y2;
    	cin >> x >> y >> x2 >> y2;
    	x = abs(x - x2);
    	y = abs(y - y2);
    	ll ans = x * y + 1;
    	cout << ans << "\n";
    }
}
