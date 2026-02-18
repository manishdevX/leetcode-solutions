// LINK - https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop

// n = size of prices

// Solution 1 TC = O(n^2), SC = O(1)
class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        int n = prices.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (prices[j] <= prices[i])
                {
                    prices[i] -= prices[j];
                    break;
                }
            }
        }
        return prices;
    }
};

// Solution 2 TC = O(n), SC = O(n)
class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() > prices[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                ans[i] = prices[i];
            }
            else
            {
                ans[i] = prices[i] - st.top();
            }
            st.push(prices[i]);
        }
        return ans;
    }
};
