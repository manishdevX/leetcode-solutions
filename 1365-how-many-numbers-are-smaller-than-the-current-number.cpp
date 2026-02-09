// LINK - https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

// n = size of nums

// solution 1, TC = O(n^2), SC = O(1)
class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (nums[i] > nums[j])
                {
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};