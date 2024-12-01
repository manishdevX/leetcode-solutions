// LINK - https://leetcode.com/problems/container-with-most-water/description/

// n = size of height

// Solution 1 TC = O(n^2), SC = O(1) TLE
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int ans = 0, n = height.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int new_area = (j - i) * min(height[i], height[j]);
                ans = max(ans, new_area);
            }
        }
        return ans;
    }
};

// Solution 2 TC = O(n), SC = O(1)
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int ans = 0, left = 0, right = height.size() - 1;
        while (left < right)
        {
            int area = (right - left) * min(height[left], height[right]);
            ans = max(ans, area);
            height[left] < height[right] ? left++ : right--;
        }
        return ans;
    }
};