// LINK - https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

// n = size of nums

// Solution 1 TC = O(n), SC = O(1)
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int pos = 0, n = nums.size();

        for (int i = 1; i < n; i++)
        {
            if (nums[pos] != nums[i])
            {
                nums[++pos] = nums[i];
            }
        }
        return pos + 1;
    }
};