// LINK - https://leetcode.com/problems/rotate-array/description/

// n = size of nums, lim = k % n

// Solution 1 TC = O(n*lim), SC = O(1) TLE
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size(), lim = k % n;
        for (int i = 0; i < lim; i++)
        {
            int num = nums[n - 1];
            for (int j = n - 1; j > 0; j--)
            {
                nums[j] = nums[j - 1];
            }
            nums[0] = num;
        }
    }
};

// Solution 2 TC = O(n), SC = O(1)
class Solution
{
private:
    void reverse(vector<int> &nums, int i, int j)
    {
        while (i < j)
        {
            swap(nums[i++], nums[j--]);
        }
    }

public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size(), lim = k % n, ind = n - lim - 1;
        reverse(nums, 0, ind);
        reverse(nums, ind + 1, n - 1);
        reverse(nums, 0, n - 1);
    }
};

// Solution 3 TC = O(n), SC = O(n)
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size(), lim = k % n;
        vector<int> temp(n);
        for (int i = 0; i < n; i++)
        {
            if (i < lim)
            {
                temp[i] = nums[n - lim + i];
            }
            else
            {
                temp[i] = nums[i - lim];
            }
        }
        nums = temp;
    }
};