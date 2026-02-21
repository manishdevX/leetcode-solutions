// LINK - https://leetcode.com/problems/sort-array-by-parity

// n = size of nums

// Solution 1, TC = O(n), SC = O(1)
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
            {
                swap(nums[i], nums[j]);
                j++;
            }
        }
        return nums;
    }
};
