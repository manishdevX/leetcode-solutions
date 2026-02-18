// LINK - https://leetcode.com/problems/find-the-duplicate-number

// n = size of nums

// Solution 1 TC = O(nlogn), SC = O(1)
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                return nums[i];
            }
        }
        return -1;
    }
};

// Solution 2 TC = O(n), SC = O(1)
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        for (auto &&num : nums)
        {
            int ind = abs(num);
            if (nums[ind] < 0)
            {
                return ind;
            }
            nums[ind] *= -1;
        }
        return -1;
    }
};

// Solution 3 TC = O(n), SC = O(1)
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = 0, fast = 0, n = nums.size();
        while (!slow || slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

// Solution 4 TC = O(nlogn), SC = O(1)
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = (left + right) >> 1;
            int cnt = 0;
            for (auto &&num : nums)
            {
                if (num <= mid)
                {
                    cnt++;
                }
            }
            if (cnt > mid)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};