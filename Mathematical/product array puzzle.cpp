class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here
        vector<long long int> ans;
        
        long long prod = 1;
        int zero = 0;
        for(auto it: nums)
        {
            if(it == 0)
            {
                zero++;
                continue;
            }
            prod *= it;
        }
        
        for(auto it: nums)
        {
            if(zero == 1)
            {
                if(it == 0)
                {
                    ans.push_back(prod);
                }
                else
                {
                    ans.push_back(0);
                }
            }
            else if(zero >= 2)
            {
                ans.push_back(0);
            }
            else  ans.push_back(prod/it);
            
        }
        return ans;
    }
};