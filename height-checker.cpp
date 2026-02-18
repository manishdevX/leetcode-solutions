// LINK - https://leetcode.com/problems/height-checker

// n = size of heights

// Solution 1 TC = O(nlogn), SC = O(n)
class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        int ans = 0;
        vector<int> vec(heights);
        sort(vec.begin(), vec.end());
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] != heights[i])
            {
                ans++;
            }
        }
        return ans;
    }
};
