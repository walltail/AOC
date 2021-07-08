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

ll ans=0;
void mergeSort(vector<char> &a, int l, int r) {
	if (l>=r) return;
	int m = (l+r)>>1;
	mergeSort(a,l,m);
	mergeSort(a,m+1,r);
	vector<char> b; b.reserve(r-1+1);
	int i=l, j=m+1;
	while (i<=m and j<=r) {
		if (a[i]<=a[j]) b.pb(a[i++]);
		else { b.pb(a[j++]); ans+=m-i+1; }
	}
	while (i<=m) b.pb(a[i++]);
	while (j<=r) b.pb(a[j++]);
	F0R(i,r-l+1) a[i+l]=b[i];
	// cout<<l<<" "<<r<<" ans "<<ans<<"\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("excursion.in", "r", stdin);

	vector<char> a; char c;
	while (cin>>c) a.pb(c);
	mergeSort(a,0,a.size()-1);
	// FORr(i,a) cout<<i; cout<<"\n";
	cout<<ans;

	return 0;
}

/*
102 10
(10 2) 1 0 --> 1+1
012 01 --> 2+1+
*/