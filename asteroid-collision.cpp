// LINK - https://leetcode.com/problems/asteroid-collision/description/

// n = size of asteroids

// Solution 1 TC = O(n), SC = O(n)
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> ans;
        stack<int> st;
        for (auto &&ast : asteroids)
        {
            if (st.empty() || st.top() < 0 || ast > 0)
            {
                st.push(ast);
            }
            else
            {
                int val = ast;
                while (!st.empty() && st.top() > 0 && val < 0)
                {
                    if (abs(st.top()) < abs(val))
                    {
                        st.pop();
                    }
                    else if (abs(st.top()) > abs(val))
                    {
                        val = st.top();
                    }
                    else
                    {
                        val = 0;
                        st.pop();
                        break;
                    }
                }
                if (val == ast)
                {
                    st.push(val);
                }
            }
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