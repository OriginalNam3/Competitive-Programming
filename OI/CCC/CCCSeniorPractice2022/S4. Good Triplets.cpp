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
	int n, c;
	cin >> n >> c;
	
	int h = c / 2 + c % 2;
	
	vector<int> a(c);
	for (int i = 0; i < n; i++){
		int x; cin >> x;
		a[x]++;
	}
	
	// if (n < 100){
		// int nans = 0;
		// for (int i = 0; i < h; i++){
			// for (int j = i + 1; j < c; j++){
				// for (int k = j + 1; k < c; k++){
					// if (i != j && j != k && k != i && j - i < h && k - j < h && abs(i + c - k) < h) nans += a[i] * a[j] * a[k];
				// }
			// }
		// }
		// cout << nans;
		// return;
	// }
	
	vector<int> pref(2 * c);
	pref[0] = a[0];
	for (int i = 1; i < 2 * c; i++){
		pref[i] += pref[i-1] + a[i % c];
	}
	dbg(pref);

	ll sum = 0;
	for (int i = 1; i < h; i++){
		sum += 1LL * a[i] * (pref[i + h - 1] - pref[c - h]);
		dbg(i, a[i], pref[i + h - 1] - pref[c-h]);
	}
	dbg(sum);
	ll ans = sum * a[0];
	for (int i = 1; i < c; i++){
		// transition to i, new possible vertices are i + h - 1 and i + c - h, need to remove current vertex as well
		sum -= 1LL * a[i] * (pref[i + h - 1] - pref[i - 1 + c - h]);  // removing current vertex from j and k
		sum -= 1LL * a[(i + c - h) % c] * (pref[i - 1 + h - 1] - pref[max(i, i + c - h - h)]);  // removing i + c - h
		sum += 1LL * a[(i + h - 1) % c] * (pref[i + h - 1 + h - 1] - pref[i + c - h]);
		ans += 1LL * sum * a[i];
		dbg(ans, sum);
	}
	// int nans = 0;
	// for (int i = 0; i < h; i++){
		// for (int j = i + 1; j < c; j++){
			// for (int k = j + 1; k < c; k++){
				// if (i != j && j != k && k != i && j - i < h && k - j < h && abs(i + c - k) < h) nans += a[i] * a[j] * a[k];
			// }
		// }
	// }
	// dbg(ans);
	// cout << nans << "\n";
	ans /= 3;
	cout << ans << "\n";
}
// 0 0 2 6 2 6 8 7

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
