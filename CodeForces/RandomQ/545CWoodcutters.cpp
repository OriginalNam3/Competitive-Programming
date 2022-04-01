// Problem: C. Woodcutters
// Contest: Codeforces - Codeforces Round #303 (Div. 2)
// URL: https://codeforces.com/problemset/problem/545/C
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

// void solve(){
// 	
// }

struct tree{
	int x, h;
};

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<tree> a(n);
    fr(i, 0, n){
    	cin >> a[i].x >> a[i].h;
    }
    vi s(n+1), l(n+1), r(n+1);
    l[0] = 1;
    if (a[1].x > a[0].x + a[0].h) r[0] = 1;
    fr(i, 1, n){
    	s[i] = max(s[i-1], max(l[i-1], r[i-1]));

    	if (a[i].x - a[i].h > a[i-1].x){
    		l[i] = max(l[i-1], s[i-1]) + 1;
    		
    		if (a[i].x - a[i].h > a[i-1].x + a[i-1].h){
    			l[i] = max(l[i], r[i-1] + 1);
    		}
    	}
    	
    	if (i == n-1){
    		r[i] = max(s[i-1], max(l[i-1], r[i-1])) + 1;
    		continue;
    	}
		if (a[i].x+a[i].h < a[i+1].x){
			r[i] = max(s[i-1], max(l[i-1], r[i-1])) + 1;
		}
    }
    cout << max(s[n-1], max(r[n-1], l[n-1]));
}
