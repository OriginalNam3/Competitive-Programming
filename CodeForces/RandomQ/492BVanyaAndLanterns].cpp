// Problem: B. Vanya and Lanterns
// Contest: Codeforces - Codeforces Round #280 (Div. 2)
// URL: https://codeforces.com/problemset/problem/492/B
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
    int n, l;
    cin >> n >> l;
    vector<db> a(n);
    each(x, a) cin >> x;
    sor(a);
    db m = max(a[0], l - a[n-1]);
    fr(i, 1, n){
    	m = max(m, (a[i] - a[i-1])/2);
    }
    cout.precision(32);
    cout << m;
}
