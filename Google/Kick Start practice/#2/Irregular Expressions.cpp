// Problem: Irregular Expressions
// Contest: Google Coding Competitions - Coding Practice with Kick Start Session #2 - Kick Start 2022
// URL: https://codingcompetitions.withgoogle.com/kickstart/round/00000000008f4a94/0000000000b55464
// Memory Limit: 1024 MB
// Time Limit: 30000 ms
// Date & Time: 2022-07-02 21:38:06
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
#define pb emplace_back

#ifdef ORIGINAL_LOCAL
#include <bits/debug.h>
#else
#define dbg(...) 42
#endif

const int mod = 1e9+7;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

vector<int> z(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = (n + 1)/2, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

void solve(){
	str s;
	cin >> s;
	
	int n = s.length();
	vector<int> cnt(n);
	for (int i = 0; i < n; i++){
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') cnt[i]++;
		if (i > 0) cnt[i] += cnt[i - 1];
	}
	
	for (int i = 0; i < n; i++){
		for (int j = i + 2; j < n; j++){
			if ((i != 0 && cnt[j] - cnt[i - 1] <= 4) || (i == 0 && cnt[j] <= 4)) continue;
			str cur = s.substr(i, j - i + 1);
			vector<int> res(j - i + 1);
			res = z(cur);
			dbg(res);
			bool ok = false;
			for (int x = j - i; x > (j - i + 1)/ 2; x--){
				if (res[x] == j - i + 1 - x && cnt[j] - cnt[i + x - 1] >= 2){
					ok = true;
				}
			}
			if (ok){
				cout << "Spell!\n";
				return;
			}
		}
	}
	cout << "Nothing.\n";
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
