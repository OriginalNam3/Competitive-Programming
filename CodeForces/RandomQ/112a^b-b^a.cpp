// Problem: 112. ab-ba
// Contest: Codeforces - acm.sgu.ru archive
// URL: https://codeforces.com/problemsets/acmsguru/problem/99999/112
// Memory Limit: 4 MB
// Time Limit: 250 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double; // or double if tight TL
using str = string;

using pi = pair<int,int>;
#define mp make_pair
#define f first
#define s second

using pqi = priority_queue<int>;
using pqll = priority_queue<long long>;
using qi = queue<int>;
using qll = queue<long long>;
using vi = vector<int>;
using vb = vector<bool>;
using vpi = vector<pi>;

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back

#define fr(i,a,b) for (int i = (a); i < (b); ++i)
#define rf(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define fe(x, a) for (auto &x: a)

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    if (a == b){
    	cout << 0; return 0;
    }
    long long ab = 1;
    long long ba = 1;
    fr(i, 0, b) ab *= a;
    fr(i, 0, a) ba *= b;
    cout << ab - ba;
}
