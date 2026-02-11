// LINK - https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/

// n = size of nums

// Solution 1, TC = O(n^2), SC = O(1)
class Solution
{
public:
    int countPairs(vector<int> &nums, int k)
    {
        int count = 0, n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] == nums[j] && (i * j) % k == 0)
                {
                    count++;
                }
            }
        }
        return count;
    }
};

// Solution 2, TC = O(n^2), SC = O(n)
class Solution
{
public:
    int countPairs(vector<int> &nums, int k)
    {
        unordered_map<int, vector<int>> umap;
        int count = 0, n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (umap.find(nums[i]) != umap.end())
            {
                for (auto &&x : umap[nums[i]])
                {
                    if ((x * i) % k == 0)
                    {
                        count++;
                    }
                }
            }

            umap[nums[i]].push_back(i);
        }

        return count;
    }
};