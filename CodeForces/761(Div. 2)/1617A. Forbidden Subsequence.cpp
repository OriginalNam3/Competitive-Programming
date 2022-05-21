// Problem: A. Forbidden Subsequence
// Contest: Codeforces - TCP
// URL: https://codeforces.com/contest/1617/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	str s;
	cin >> s;
	str t;
	cin >> t;
	int n = s.size();
	vector<int> cnt(26);
	
	for (int i = 0; i < n; i++){
		cnt[s[i] - 'a']++;
	}
	bool ok = false;
	for (int i = 0; i < 2; i++){
		if (t[i+1] < t[i]) ok = true;
	}
	if (n < 3) ok = true;

	if (ok || cnt[0] == 0 || cnt[1] == 0 || cnt[2] == 0){
		for (int i = 0; i < 26; i++){
			char x = 'a' + i;
			for (int j = 0; j < cnt[i]; j++){
				cout << x;
			}
		}
	}
	else{
		for (int i = 0; i < cnt[0]; i++){
			cout << 'a';
		}
		for (int i = 0; i < cnt[2]; i++){
			cout << 'c';
		}
		for (int i = 0; i < cnt[1]; i++){
			cout << 'b';
		}
		for (int i = 3; i < 26; i++){
			char x = 'a' + i;
			for (int j = 0; j < cnt[i]; j++){
				cout << x;
			}
		}
	}
	cout << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
