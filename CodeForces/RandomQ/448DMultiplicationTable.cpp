// Problem: D. Multiplication Table
// Contest: Codeforces - Codeforces Round #256 (Div. 2)
// URL: https://codeforces.com/problemset/problem/448/D
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

#define fr(i,a,b) for (int i = (a); i < (b); ++i)
#define rf(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define each(x, a) for (auto& x: a)

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    ll l = 1, r = 1LL * n * m + 1;
    
    while (r > l){
    	ll t = (l+r)/2, sum = 0;
    	// cout << t << " " << l << " " << r << "\n";
    	fr(i, 1, n+1){
    		sum += min((t-1)/i, m);
    	}
    	// cout << sum << "\n";
    	if (sum < k){
    		l = t + 1;
    	}
    	else{
    		r = t;
    	}
    }
    cout << l - 1;
}
