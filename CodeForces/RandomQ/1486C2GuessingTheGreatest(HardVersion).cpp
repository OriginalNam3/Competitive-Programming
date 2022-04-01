// Problem: C2. Guessing the Greatest (hard version)
// Contest: Codeforces - Codeforces Round #703 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1486/C2
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

int q(int l, int r){
	if (l >= r) return 0;
	cout << "? " << l << " " << r << "\n";
	cout.flush();
	int i;
	cin >> i;
	return i;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int s = q(1, n);
    if (n == 2){
    	if (s == 1){
    		cout << "! 2";
    	}
    	else{
    		cout << "! 1";
    	}
    	return 0;
    }
	if (q(1, s) == s){
		int l = 1, r = s;
		while (l < r - 1){
			int m = (l + r)/2;
			if (q(m, s) == s){
				l = m;
			}
			else{
				r = m;
			}
		}
		cout << "! " << l;
		return 0;
	}
	else {
		int l = s, r = n;
		while (l < r - 1){
			int m = (l + r)/2;
			if (q(s, m) == s){
				r = m;
			}
			else{
				l = m;
			}
		}
		cout << "! " << r;
	}
}
