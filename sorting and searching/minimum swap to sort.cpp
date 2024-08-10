class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<int> temp = nums;
	    sort(temp.begin(), temp.end());
	    map<int, int> m;
	    int i = 0;
	    for(auto it: nums)
	    {
	        m[it] = i;
	        i++;
	    }
	    int ans = 0; 
	    for(int i = 0; i < nums.size(); i++)
	    {
	        if(nums[i] != temp[i])
	        {
	            int index = m[temp[i]];
	            swap(nums[i], nums[index]);
	            m[nums[index]] = index;
	            m[nums[i]] = i;
	                       
	            ans++;
	        }
	    }
	    return ans;
	   
	    
	}
};