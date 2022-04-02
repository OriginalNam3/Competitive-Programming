// Problem: A. Two Substrings
// Contest: Codeforces - Codeforces Round #306 (Div. 2)
// URL: https://codeforces.com/problemset/problem/550/A
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
typedef array<int, 3> qq;

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back

#define forn(i,a,b) for (int i = (a); i < (b); ++i)
#define rofn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rep(n) for (int _ = 0; _ < n; _++)
#define each(x, a) for (auto& x: a)

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    str s;
    cin >> s;
    int i1 = -10, i2 = -10, n = s.size();
    n--;
    forn(i, 0, n){
    	if (s[i] == 'A' && s[i+1] == 'B' && (i1 == -10)){
    		i1 = i;
    	}
    	if (s[i] == 'B' && s[i+1] == 'A' && (i2 == -10)){
    		i2 = i;
    	}
    }
    if (i1 == -10 || i2 == -10){
    	cout << "NO";
    	return 0;
    }
    int j1 = -10, j2 = -10;
    rofn(i, 0, n){
    	if (s[i] == 'A' && s[i+1] == 'B' && (j1 == -10)){
    		j1 = i;
    	}
    	if (s[i] == 'B' && s[i+1] == 'A' && (j2 == -10)){
    		j2 = i;
    	}
    }
    cout << ((abs(j2 - i1) > 1 || abs(j1 - i2) > 1) ? "YES": "NO");
}
