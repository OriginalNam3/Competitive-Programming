// Problem: B. 3-Coloring
// Contest: Codeforces - Codeforces Round #712 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1503/B
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Date & Time: 2022-06-06 20:25:49
// 
// Powered by CP Editor (https://cpeditor.org)

// https://codeforces.com/profile/Intellegent husbando <3

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;
typedef string str;

#define mp make_pair
#define f first
#define s second

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsor(x) sort(x.rbegin(), x.rend())
#define pb push_back

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

const int mod = 1e9+7;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n;
	cin >> n;
	
	int cur, a = 0, b = 1, ac = 1, bc = 1; 
	for (int i = 0; i < n * n; i++){
		if (a >= n){
			a %= 2;
			a ^= 1;
			ac++;
		}
		if (b >= n){
			b %= 2;
			b ^= 1;
			bc++;
		}
		cin >> cur;
		if (cur == 1){
			if (bc > n){
				cout << 3 << " " << ac << " " << a + 1 << "\n";
				a += 2;
			}
			else{
				cout << 2 << " " << bc << " " << b + 1 << "\n";
				b += 2;
			}
		}
		if (cur == 2){
			if (ac > n){
				cout << 3 << " " << bc << " " << b + 1 << "\n";
				b += 2;
			}
			else{
				cout << 1 << " " << ac << " " << a + 1 << "\n";
				a += 2;
			}
		}
		if (cur == 3){
			if (ac > n){
				cout << 2 << " " << bc << " " << b + 1 << "\n";
				b += 2;
			}
			else{
				cout << 1 << " " << ac << " " << a + 1 << "\n";
				a += 2;
			}
		}
		cout.flush();
	}
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
