// Problem: Ants on a Stick
// Contest: Google Coding Competitions - Round C 2022 - Kick Start 2022
// URL: https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb4d1/0000000000b209bc
// Memory Limit: 1024 MB
// Time Limit: 20000 ms
// Date & Time: 2022-05-22 12:38:59
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
	int n, L;
	cin >> n >> L;
	
	vector<int > l, r;
	vector<pair<int, int> > ants;
	
	for (int i = 1; i <= n; i++){
		int p; cin >> p;
		bool x; cin >> x;
		if (x) r.pb(p);
		else l.pb(p);
		ants.pb(mp(p, i));
	}
	sor(ants);
	sor(l); sor(r);
	int i = 0, j = r.size()-1;
	while (i < l.size() && j >= 0){
		// debug(i) debug(j)
		if (L - r[j] == l[i]){
			cout << min(ants[i].s, ants[j + l.size()].s) << " " << max(ants[i].s, ants[j + l.size()].s) << " ";
			i++;
			j--;
			continue;
		}
		if (L - r[j] < l[i]){
			cout << ants[j + l.size()].s << " ";
			j--;
		}
		else{
			cout << ants[i].s << " ";
			i++;
		}
		
	}
	for (int k = i; k < l.size(); k++){
		cout << ants[k].s << " ";
	}
	for (int k = j; k >= 0; k--){
		cout << ants[l.size() + k].s << " ";
	}
	cout << "\n";
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
