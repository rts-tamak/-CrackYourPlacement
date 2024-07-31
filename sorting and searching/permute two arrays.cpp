bool solve(vector<int> &a, vector<int> &b, int k) 
{
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());


	for(int i = 0; i < a.size(); i++)
	{
		if(a[i] + b[i] < k) return false;
	}
	return true;
}