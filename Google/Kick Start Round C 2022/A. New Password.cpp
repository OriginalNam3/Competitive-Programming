// Problem: New Password
// Contest: Google Coding Competitions - Round C 2022 - Kick Start 2022
// URL: https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb4d1/0000000000b20f15
// Memory Limit: 1024 MB
// Time Limit: 20000 ms
// Date & Time: 2022-05-22 12:20:24
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
	str p;
	cin >> p;
	bool upper = false, lower = false, digit = false, special = false;
	for (int i = 0; i < n; i++){
		if (p[i] == '@' || p[i] == '#' || p[i] == '*' || p[i] == '&') special = true;
		if (p[i] - 'A' >= 0 && p[i] - 'A' < 26) upper = true;
		if (p[i] - 'a' >= 0 && p[i] - 'a' < 26) lower = true;
		if (p[i] - '0' >= 0 && p[i] - '0' < 10) digit = true;
	}
	if (!upper) p += 'A';
	if (!lower) p += 'a';
	if (!digit) p += '1';
	if (!special) p += '@';
	for (int i = p.size(); i < 7; i++){
		p += 'a';
	}
	cout << p << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++){
    	cout << "Case #" << i << ": ";
    	solve();
    }
}
