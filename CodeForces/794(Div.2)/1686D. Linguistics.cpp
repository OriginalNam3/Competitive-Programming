// Problem: D. Linguistics
// Contest: Codeforces - Codeforces Round #794 (Div. 2)
// URL: https://codeforces.com/contest/1686/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-25 18:35:31
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
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	str s;
	cin >> s;
	int n = s.size();
	s += s[s.size()-1];
	
	vector<int> cnt(2);
	for (int i = 0; i < n; i++){
		cnt[s[i] - 'A']++;
	}
	
	n++;
	if (cnt[0] == a + c + d && cnt[1] == b + c + d){
		cnt.assign(3, 0);
		priority_queue<int> A, B;
		int j = 0, total = 0, As = 0, Bs = 0;
		for (int i = 1; i < n; i++){
			if (s[i] == s[i-1]){
				int len = i - j;
				if (len > 1){
					if (len % 2 == 0){
						if (s[j] == 'A') {
							As += len/2;
							A.push(len/2);
						}
						else{
							Bs += len/2;
							B.push(len/2);
						}
					}
					else{
						total += len/2;
					}
				}
				j = i;
			}
		}
		if (As + Bs + total >= c + d){
			if (As + total >= c && Bs + total >= d){
				cout << "YES\n";
				return;
			}
			if (Bs + total >= d){
				while (!B.empty()){
					int diff = min(Bs + total - d, B.top());
					B.pop();
					if (diff == 1) break;
					Bs -= diff;
					As += diff - 1;
					if (As + Bs + total < c + d) {
						cout << "NO\n";
						return;
					}
					if (As + total >= c && Bs + total >= d){
						cout << "YES\n";
						return;
					}
				}
			}
			else{
				while (!A.empty()){
					int diff = min(As + total - c, A.top());
					A.pop();
					if (diff == 1) break;
					As -= diff;
					Bs += diff - 1;
					if (As + Bs + total < c + d) {
						cout << "NO\n";
						return;
					}
					if (As + total >= c && Bs + total >= d){
						cout << "YES\n";
						return;
					}
				}
			}
		}
		cout << "NO\n";	
	}
	else{
		cout << "NO\n";
	}
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
