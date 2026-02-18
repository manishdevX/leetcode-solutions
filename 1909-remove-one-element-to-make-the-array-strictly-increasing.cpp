// LINK - https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing

// n = size of nums

// Solution 1, TC = O(n*2), SC = O(n)
class Solution
{
public:
    bool canBeIncreasing(vector<int> &nums)
    {
        bool ans;
        vector<int> vec;
        for (int i = 0; i < nums.size(); i++)
        {
            vec.assign(nums.begin(), nums.end());
            vec.erase(vec.begin() + i);
            ans = true;
            for (int j = 0; j < vec.size() - 1; j++)
            {
                if (vec[j] >= vec[j + 1])
                {
                    ans = false;
                    break;
                }
            }
            if (ans)
            {
                return true;
            }
        }
        return false;
    }
};
