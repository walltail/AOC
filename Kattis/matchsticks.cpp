#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;

string hz[] = {
"1 1",
"7 7",
"4 11",
"2 71",
"6 111",
"8 711",
"10 1111",
"18 7111",
"22 11111",
"20 71111",
"28 111111",
"68 711111",
"88 1111111",
"108 7111111",
"188 11111111",
"200 71111111",
"208 111111111",
"288 711111111",
"688 1111111111",
"888 7111111111",
"1088 11111111111",
"1888 71111111111",
"2008 111111111111",
"2088 711111111111",
"2888 1111111111111",
"6888 7111111111111",
"8888 11111111111111",
"10888 71111111111111",
"18888 111111111111111",
"20088 711111111111111",
"20888 1111111111111111",
"28888 7111111111111111",
"68888 11111111111111111",
"88888 71111111111111111",
"108888 111111111111111111",
"188888 711111111111111111",
"200888 1111111111111111111",
"208888 7111111111111111111",
"288888 11111111111111111111",
"688888 71111111111111111111",
"888888 111111111111111111111",
"1088888 711111111111111111111",
"1888888 1111111111111111111111",
"2008888 7111111111111111111111",
"2088888 11111111111111111111111",
"2888888 71111111111111111111111",
"6888888 111111111111111111111111",
"8888888 711111111111111111111111",
"10888888 1111111111111111111111111",
"18888888 7111111111111111111111111",
"20088888 11111111111111111111111111",
"20888888 71111111111111111111111111",
"28888888 111111111111111111111111111",
"68888888 711111111111111111111111111",
"88888888 1111111111111111111111111111",
"108888888 7111111111111111111111111111",
"188888888 11111111111111111111111111111",
"200888888 71111111111111111111111111111",
"208888888 111111111111111111111111111111",
"288888888 711111111111111111111111111111",
"688888888 1111111111111111111111111111111",
"888888888 7111111111111111111111111111111",
"1088888888 11111111111111111111111111111111",
"1888888888 71111111111111111111111111111111",
"2008888888 111111111111111111111111111111111",
"2088888888 711111111111111111111111111111111",
"2888888888 1111111111111111111111111111111111",
"6888888888 7111111111111111111111111111111111",
"8888888888 11111111111111111111111111111111111",
"10888888888 71111111111111111111111111111111111",
"18888888888 111111111111111111111111111111111111",
"20088888888 711111111111111111111111111111111111",
"20888888888 1111111111111111111111111111111111111",
"28888888888 7111111111111111111111111111111111111",
"68888888888 11111111111111111111111111111111111111",
"88888888888 71111111111111111111111111111111111111",
"108888888888 111111111111111111111111111111111111111",
"188888888888 711111111111111111111111111111111111111",
"200888888888 1111111111111111111111111111111111111111",
"208888888888 7111111111111111111111111111111111111111",
"288888888888 11111111111111111111111111111111111111111",
"688888888888 71111111111111111111111111111111111111111",
"888888888888 111111111111111111111111111111111111111111",
"1088888888888 711111111111111111111111111111111111111111",
"1888888888888 1111111111111111111111111111111111111111111",
"2008888888888 7111111111111111111111111111111111111111111",
"2088888888888 11111111111111111111111111111111111111111111",
"2888888888888 71111111111111111111111111111111111111111111",
"6888888888888 111111111111111111111111111111111111111111111",
"8888888888888 711111111111111111111111111111111111111111111",
"10888888888888 1111111111111111111111111111111111111111111111",
"18888888888888 7111111111111111111111111111111111111111111111",
"20088888888888 11111111111111111111111111111111111111111111111",
"20888888888888 71111111111111111111111111111111111111111111111",
"28888888888888 111111111111111111111111111111111111111111111111",
"68888888888888 711111111111111111111111111111111111111111111111",
"88888888888888 1111111111111111111111111111111111111111111111111",
"108888888888888 7111111111111111111111111111111111111111111111111",
"188888888888888 11111111111111111111111111111111111111111111111111",
};
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("matchsticks.in", "r", stdin);

	int n; cin>>n;
	while (n--) {
		int i; cin>>i;
		cout<<hz[i-2]<<'\n';
	}

	return 0;
}