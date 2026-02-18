// LINK - https://leetcode.com/problems/watering-plants

// n = size of plants

// Solution 1 TC = O(n), SC = O(1)
class Solution
{
public:
    int wateringPlants(vector<int> &plants, int capacity)
    {
        int ans = 0, cur_cap = capacity, n = plants.size();
        for (int i = 0; i < n; i++)
        {
            if (cur_cap < plants[i])
            {
                ans += (2 * i + 1);
                cur_cap = capacity - plants[i];
            }
            else
            {
                ans++;
                cur_cap -= plants[i];
            }
        }
        return ans;
    }
};
