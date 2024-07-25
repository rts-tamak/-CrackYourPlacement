#include <bits/stdc++.h>

using namespace std;

int main()
{

	string s;
	cin >> s;
	map<char, int> m;

	for(auto it: s)
	{
		m[it]++;
	}


	for(auto it: m)
	{
		if(it.second > 1)
		{
			cout << it.first << " ";
		}
	}

	return 0;
}

