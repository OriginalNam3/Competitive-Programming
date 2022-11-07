// Problem: B. NIT Destroys the Universe
// Contest: Codeforces - Codeforces Global Round 21
// URL: https://codeforces.com/contest/1696/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-25 15:38:24
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

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	
	int i = 0, j = n - 1;
	bool zero = false;
	while (a[i] == 0 && i < n) i++;
	if (i == n){
		cout << "0\n";
		return;
	}
	while (a[j] == 0 && j >= 0) j--;
	for (; i < j; i++){
		if (a[i] == 0) zero = true;
	}
	if (zero){
		cout << "2\n";
	}
	else{
		cout << "1\n";
	}
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; 
    cin >> t;
    while (t--)
    solve();
}
