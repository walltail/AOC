#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (a)-1; i >= (b); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define FORr(a, x) for (auto& a : x)
#define LSOne(S) ((S) & -(S))

typedef long long ll;
typedef tuple<int,int> ii;
typedef tuple<int,int,int> iii;
typedef tuple<ll,ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpll;
typedef tuple<int,ll,ll> edge;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vdit;
const ll INF = 1e18;

int n;
const int MAX_N = 3e5;
const int Z=2, M[]={2147482921, 2147480507}, p=31;
int Pow[Z][MAX_N];                                  // to store p^i % M

inline void processPow() {
	for (int j = 0; j < Z; ++j) {
		auto &P = Pow[j];
		P[0] = 1;                                    // compute p^i % M
		for (int i = 1; i < MAX_N; ++i)                    // O(n)
			P[i] = ((ll)P[i-1] * p) % M[j];
	}
}

inline vi computeRollingHash(string &T, int z) {                      // Overall: O(n)
  vi h(T.size(), 0);
  for (int i = 0; i < T.size(); ++i) {                  // O(n)
    if (i != 0) h[i] = h[i-1];                   // rolling hash
    h[i] = (h[i] + ((ll)(T[i] - 'a' + 1)*Pow[z][i]) % M[z]) % M[z];
  }
  return h;
}

int extEuclid(int a, int b, int &x, int &y) {    // pass x and y by ref
  int xx = y = 0;
  int yy = x = 1;
  while (b) {                                    // repeats until b == 0
    int q = a/b;
    tie(a, b) = tuple(b, a%b);
    tie(x, xx) = tuple(xx, x-q*xx);
    tie(y, yy) = tuple(yy, y-q*yy);
  }
  return a;                                      // returns gcd(a, b)
}

int modInverse(int b, int m) {                   // returns b^(-1) (mod m)
  int x, y;
  int d = extEuclid(b, m, x, y);                 // to get b*x + m*y == d
  if (d != 1) return -1;                         // to indicate failure
  // b*x + m*y == 1, now apply (mod m) to get b*x == 1 (mod m)
  return ((ll)x+m)%m;                                // this is the answer
}

int hash_fast(const vi &h, int L, int R, int z) {                    // O(1) hash of any substr
  if (L == 0) return h[R];                       // h is the prefix hashes
  int ans = 0;
  ans = ((h[R] - h[L-1]) % M[z] + (ll)M[z]) % M[z];           // compute differences
  ans = ((ll)ans * modInverse(Pow[z][L], M[z])) % M[z];   // remove P[L]^-1 (mod M)
  // cout<<h[R]<<' '<<h[L-1]<<' '<<ans<<'\n';
  return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("hashing.in", "r", stdin);

	processPow();
	string T; cin>>T;
	const auto &h = computeRollingHash(T, 0);
	const auto &h2 = computeRollingHash(T, 1);
	int q; cin>>q;
	while (q--) {
		int L,R; cin>>L>>R; --R;
		// cout << hash_fast(h,L,R,0) << ' ' << hash_fast(h2,L,R,1) << "\n";
		cout << (ll)(1e9) * hash_fast(h,L,R,0) + hash_fast(h2,L,R,1) << "\n";
	}

	return 0;
}