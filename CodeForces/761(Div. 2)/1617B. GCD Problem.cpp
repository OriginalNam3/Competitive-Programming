// Problem: B. GCD Problem
// Contest: Codeforces - TCP
// URL: https://codeforces.com/contest/1617/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-18 18:41:19
// 
// Powered by CP Editor (https://cpeditor.org)

// https://codeforces.com/profile/Intellegent <3

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
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n;
	cin >> n;
	if (n == 10){
		cout << "5 4 1\n";
		return;
	}
	if (n % 2 == 0){
		cout << n - 3 << " 2 1" << "\n";
	}
	else{
			if ((n-1) % 4){
				cout << (n - 1)/2 + 2 << " " << (n-1)/2 - 2 << " 1\n";
			}
			else{
				cout << (n-1)/2 + 1 << " " << (n-1)/2 - 1 << " 1\n";
			}
	}
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
