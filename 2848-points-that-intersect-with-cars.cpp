// LINK - https://leetcode.com/problems/points-that-intersect-with-cars

// n = size of nums, m = avg difference of nums[i][1]-nums[i][0]

// Solution 1, TC = O(n*m), SC = O(n*m)
class Solution
{
public:
    int numberOfPoints(vector<vector<int>> &nums)
    {
        unordered_set<int> s;
        for (auto &&vec : nums)
        {
            for (int num = vec[0]; num <= vec[1]; num++)
            {
                s.insert(num);
            }
        }
        return s.size();
    }
};

// Solution 2, TC = O(nlogn), SC = O(logn)
class Solution
{
public:
    int numberOfPoints(vector<vector<int>> &nums)
    {
        sort(nums.begin(), nums.end(),
             [](const std::vector<int> &v1, const std::vector<int> &v2)
             {
                 return v1[0] < v2[0];
             });

        int count = nums[0][1] - nums[0][0] + 1, maxi = nums[0][1];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i][0] <= maxi && nums[i][1] > maxi)
            {
                count += nums[i][1] - maxi;
                maxi = nums[i][1];
            }
            else if (nums[i][0] > maxi)
            {
                count += nums[i][1] - nums[i][0] + 1;
                maxi = nums[i][1];
            }
        }
        return count;
    }
};