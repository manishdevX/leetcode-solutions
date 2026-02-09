// LINK - https://leetcode.com/problems/create-target-array-in-the-given-order/

// n = size of nums

// solution 1, TC = O(n^2), SC = O(1)
class Solution
{
public:
    vector<int> createTargetArray(vector<int> &nums, vector<int> &index)
    {
        vector<int> target_arr;
        for (int i = 0; i < index.size(); i++)
        {
            target_arr.insert(target_arr.begin() + index[i], nums[i]);
        }
        return target_arr;
    }
};