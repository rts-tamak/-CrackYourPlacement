class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        vector<int> temp;

        int i = 0, j = 0;

        while(i < n && j < m)
        {
            if(nums1[i] <= nums2[j])
            {
                temp.push_back(nums1[i]);
                i++;
            }
            else
            {
                temp.push_back(nums2[j]);
                j++;
            }
        }

        while(i < n)
        {
            temp.push_back(nums1[i]);
            i++;
        }

        while(j < m)
        {
            temp.push_back(nums2[j]);
            j++;
        }

        for(int i = 0; i < nums1.size(); i++)
        {
            nums1[i] = temp[i];
        }

        return;
    }
};