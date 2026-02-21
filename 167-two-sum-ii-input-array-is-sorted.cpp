// LINK - https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

// n = size of numbers

// Solution 1, TC = O(n), SC = O(1)
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> ans;
        int left = 0, right = numbers.size() - 1;
        while (left < right)
        {
            if (numbers[left] + numbers[right] < target)
            {
                left++;
            }
            else if (numbers[left] + numbers[right] > target)
            {
                right--;
            }
            else
            {
                ans.assign({left + 1, right + 1});
                return ans;
            }
        }
        return ans;
    }
};

// Solution 2, TC = O(nlogn), SC = O(1)
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> ans;
        int n = numbers.size();
        for (int i = 0; i < n; i++)
        {
            int l = i + 1, r = n - 1, num = target - numbers[i];
            while (l <= r)
            {
                int m = (r - l) / 2 + l;
                if (numbers[m] == num)
                {
                    ans.assign({i + 1, m + 1});
                    return ans;
                }
                else if (numbers[m] < num)
                {
                    l = m + 1;
                }
                else
                {
                    r = m - 1;
                }
            }
        }
        return ans;
    }
};