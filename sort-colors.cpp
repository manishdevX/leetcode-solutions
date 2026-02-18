// LINK - https://leetcode.com/problems/sort-colors

// n = size of nums

// Solution 1 TC = O(n^2), SC = O(1)
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        bool flag;
        for (int i = 0; i < n - 1; i++)
        {
            flag = false;
            for (int j = 0; j < n - i - 1; j++)
            {
                if (nums[j] > nums[j + 1])
                {
                    swap(nums[j], nums[j + 1]);
                    flag = true;
                }
            }
            if (!flag)
            {
                break;
            }
        }
    }
};

// Solution 2 TC = O(n), SC = O(1)
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int i = 0, j = nums.size() - 1, k = 0;
        while (k <= j)
        {
            if (nums[k] == 0)
            {
                swap(nums[i++], nums[k++]);
            }
            else if (nums[k] == 2)
            {
                swap(nums[j--], nums[k]);
            }
            else
            {
                k++;
            }
        }
    }
};