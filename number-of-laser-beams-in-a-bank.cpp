// LINK - https://leetcode.com/problems/number-of-laser-beams-in-a-bank

// m = size of bank, n = avg length of bank[i]

// Solution 1 TC = O(m*n), SC = O(1)
class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int ans = 0, devices = 0;
        for (auto &&row : bank)
        {
            int rd = count(row.begin(), row.end(), '1');
            ans += devices * rd;
            devices = rd ? rd : devices;
        }
        return ans;
    }
};