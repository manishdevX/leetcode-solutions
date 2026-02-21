// LINK - https://leetcode.com/problems/baseball-game

// n = size of operations, m = avg length of operations[i]

// Solution 1, TC = O(n*m), SC = O(n)
class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        vector<int> arr;
        for (auto &&op : operations)
        {
            int s = arr.size();
            if (op == "+")
            {
                arr.push_back(arr[s - 1] + arr[s - 2]);
            }
            else if (op == "D")
            {
                arr.push_back(2 * arr[s - 1]);
            }
            else if (op == "C")
            {
                arr.pop_back();
            }
            else
            {
                arr.push_back(stoi(op));
            }
        }
        return accumulate(arr.begin(), arr.end(), 0);
    }
};

// Solution 2, TC = O(n*m), SC = O(n)
class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        stack<int> st;
        int sum = 0;

        for (auto &&op : operations)
        {
            if (op == "+")
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.push(num1);
                st.push(num1 + num2);
            }
            else if (op == "D")
            {
                st.push(2 * st.top());
            }
            else if (op == "C")
            {
                st.pop();
            }
            else
            {
                st.push(stoi(op));
            }
        }
        while (!st.empty())
        {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};