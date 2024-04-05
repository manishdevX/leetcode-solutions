// LINK - https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/

// Solution 1 TC = O(size of rectangles), SC = O(size of rectangles)
class Solution
{
public:
    int countGoodRectangles(vector<vector<int>> &rectangles)
    {
        vector<int> arr;
        for (auto &&rec : rectangles)
        {
            arr.push_back(min(rec[0], rec[1]));
        }
        return count(arr.begin(), arr.end(), *max_element(arr.begin(), arr.end()));
    }
};

// Solution 2 TC = O(size of rectangles), SC = O(1)
class Solution
{
public:
    int countGoodRectangles(vector<vector<int>> &rectangles)
    {
        int count = 0;
        int cur_max = INT16_MIN;
        for (auto &&rec : rectangles)
        {
            int new_max = min(rec[0], rec[1]);
            if (new_max == cur_max)
            {
                count++;
            }
            else if (new_max > cur_max)
            {
                cur_max = new_max;
                count = 1;
            }
        }
        return count;
    }
};