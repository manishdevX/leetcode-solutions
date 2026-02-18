// LINK - https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations

// n = size of nums, m = avg no. of digits in nums[i]

// Solution 1 TC = O(nlogm), SC = O(n)
class Solution
{
public:
    int reverseHelper(int num)
    {
        int reverse = 0;
        while (num)
        {
            reverse = reverse * 10 + num % 10;
            num /= 10;
        }
        return reverse;
    }

    int countDistinctIntegers(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int rev_num = reverseHelper(nums[i]);
            nums.push_back(rev_num);
        }
        unordered_set<int> s(nums.begin(), nums.end());
        return s.size();
    }
};