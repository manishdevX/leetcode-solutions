// LINK - https://leetcode.com/problems/removing-stars-from-a-string

// n = length of s

// Solution 1, TC = O(n^2), SC = O(n), MLE
class Solution
{
public:
    string removeStars(string s)
    {
        stack<char> st;
        for (auto &&ch : s)
        {
            ch != '*' ? st.push(ch) : st.pop();
        }
        string ans = "";
        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};

// Solution 2, TC = O(n), SC = O(n)
class Solution
{
public:
    string removeStars(string s)
    {
        string ans = "";
        for (auto &&ch : s)
        {
            ch != '*' ? ans.push_back(ch) : ans.pop_back();
        }
        return ans;
    }
};

// Solution 3, TC = O(n), SC = O(n)
class Solution
{
public:
    string removeStars(string s)
    {
        stack<char> st;
        string ans;
        for (auto &&ch : s)
        {
            ch != '*' ? st.push(ch) : st.pop();
        }

        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
