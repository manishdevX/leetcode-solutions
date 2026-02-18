// LINK - https://leetcode.com/problems/remove-element

// n = size of nums

// Solution 1 TC = O(n), SC = O(1)
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            if (nums[left] == val)
            {
                swap(nums[left], nums[right]);
                right--;
            }
            else
            {
                left++;
            }
        }
        return left;
    }
};
