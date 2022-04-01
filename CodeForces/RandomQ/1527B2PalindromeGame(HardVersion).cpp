// Problem: B2. Palindrome Game (hard version)
// Contest: Codeforces - Codeforces Round #721 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1527/B2
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

void solve(){
	int n;
	cin >> n;
	str s;
	cin >> s;
	int a = 0, c = 0;
	fr(i, 0, n){
		if (s[i] == '0') c++;
	}
	fr(i, 0, n/2){
		if (s[i] != s[n-1-i]){
			a++;
		}
	}
	if (a == 0){
		if (c == 1){
			cout << "BOB\n";
			return;
		}
		if (c % 2){
			cout << "ALICE\n";
			return;
		}
		cout << "BOB\n";
		return;
	}
	if (c == 2 && a == 1){
		cout << "DRAW\n";
		return;
	}
	cout << "ALICE\n";
	return;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
    	solve();
    }
}
