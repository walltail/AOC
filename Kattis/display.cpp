#include <bits/stdc++.h>
using namespace std;
string um[7][11] = {
{"+---+",  "    +",  "+---+",  "+---+",  "+   +",  "+---+",  "+---+",  "+---+",  "+---+",  "+---+",  " "},
{"|   |",  "    |",  "    |",  "    |",  "|   |",  "|    ",  "|    ",  "    |",  "|   |",  "|   |",  " "},
{"|   |",  "    |",  "    |",  "    |",  "|   |",  "|    ",  "|    ",  "    |",  "|   |",  "|   |",  "o"},
{"+   +",  "    +",  "+---+",  "+---+",  "+---+",  "+---+",  "+---+",  "    +",  "+---+",  "+---+",  " "},
{"|   |",  "    |",  "|    ",  "    |",  "    |",  "    |",  "|   |",  "    |",  "|   |",  "    |",  "o"},
{"|   |",  "    |",  "|    ",  "    |",  "    |",  "    |",  "|   |",  "    |",  "|   |",  "    |",  " "},
{"+---+",  "    +",  "+---+",  "+---+",  "    +",  "+---+",  "+---+",  "    +",  "+---+",  "+---+",  " "},
};
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("display.in", "r", stdin);

	string s; bool foo;
	while (getline(cin,s), s[0]!='e') {
		for (int i = 0; i < 7; ++i) {
			foo=0;
			for (char &c:s) {
				if (foo) cout << "  ";
				foo = 1;
				cout << um[i][(c==':') ? 10 : (c-'0')];
			}
			cout << "\n";
		}
		cout << "\n\n";
	}
	cout<<"end\n";

	return 0;
}