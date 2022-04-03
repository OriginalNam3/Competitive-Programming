// Problem: A. Random Mood
// Contest: Codeforces - Matrix Exponentiation
// URL: https://codeforces.com/gym/102644/problem/A
// Memory Limit: 256 MB
// Time Limit: 250 ms
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
    int n;
    cin >> n;
    db p;
    cin >> p;
    cout.precision(17);
    db a = p, res = 1;
    while (n > 0){
    	if (n&1){
    		res = res * (1-a) + (1-res) * a;
    	}
    	a = a * (1-a) * 2;
    	n >>= 1;
    }
    cout << res;
}
