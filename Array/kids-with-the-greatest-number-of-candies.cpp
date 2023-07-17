// TC = O(n), SC = O(n)

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        vector<bool> result;
        int max_candies = candies[0];
        int n = candies.size();

        for (int i = 1; i < n; i++)
        {
            if (candies[i] > max_candies)
            {
                max_candies = candies[i];
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (candies[i] + extraCandies >= max_candies)
            {
                result.push_back(true);
            }
            else
            {
                result.push_back(false);
            }
        }
        return result;
    }
};