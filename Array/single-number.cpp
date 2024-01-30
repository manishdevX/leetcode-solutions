// LINK - https://leetcode.com/problems/single-number/description/

// n = size of nums

// Solution 1 TC = O(n), SC = O(1)
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int number = 0;
        for (auto &&num : nums)
        {
            number = num ^ number;
        }
        return number;
    }
};