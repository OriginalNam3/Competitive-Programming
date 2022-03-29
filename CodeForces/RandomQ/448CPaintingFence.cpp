// Problem: C. Painting Fence
// Contest: Codeforces - Codeforces Round #256 (Div. 2)
// URL: https://codeforces.com/contest/448/problem/C
// Memory Limit: 512 MB
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

int fmin(vi a, int h){
	int width = a.size(), minh = INT_MAX>>1;
	each(x, a){
		if (x < minh) minh = x;
	}
	int ans = minh - h, i = 0;
	while(i < width){
		int j = i;
		while (a[i] > minh && i < width){
			i++;
		}
		if (j != i) {
			ans += fmin(vi (a.begin() + j, a.begin() + i), minh);
		}
		i++;
	}
	return min(ans, width);
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m = 0;
    cin >> n;
    vi a(n);
    each(x, a) cin >> x;
    if (n == 1){
    	cout << 1;
    	return 0;
    }
	cout << fmin(vi (all(a)), 0);
}
