class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        	    int ans = 0;
    
    //XOR ing all array elements
    for(int i = 0; i<nums.size(); i++ ) {
    	ans = ans^nums[i];
    }
	
    //XOR [1, n-1]
    for(int i = 1; i<nums.size();i++ ) {
    	ans = ans^i;
    }
    return ans;
    }
};