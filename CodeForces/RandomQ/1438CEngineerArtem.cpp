// Problem: C. Engineer Artem
// Contest: Codeforces - Codeforces Round #682 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1438/C
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

// const int INF = INT_MAX>>1;
// const int MOD = 998244353;


int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	int n, m;
    	cin >> n >> m;
    	vector<vi> a(n, vi(m));
    	fr(i, 0, n){
    		fr(j, 0, m){
    			cin >> a[i][j];
    		}
    	}
    	fr(i, 0, n){
    		fr(j, 0, m){
    			a[i][j] += a[i][j] % 2 ^ ((i + j) % 2);
    			cout << a[i][j] << " ";
    		}
    		cout << "\n";
    	}
    }
}
