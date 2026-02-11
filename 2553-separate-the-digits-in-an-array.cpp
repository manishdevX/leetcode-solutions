// LINK - https://leetcode.com/problems/separate-the-digits-in-an-array/

// n = size of nums, d = avg no of digits in nums[i] 

// Solution 1, TC = O(n*d), SC = O(1)
class Solution
{
public:
    vector<int> separateDigits(vector<int> &nums)
    {
        vector<int> answer;
        for (auto num : nums)
        {
            int dig = floor(log10(num)) + 1;
            int div = pow(10, dig - 1);
            while (div > 0)
            {
                int d = num / div;
                num %= div;
                div /= 10;
                answer.push_back(d);
            }
        }
        return answer;
    }
};

// Solution 2, TC = O(n*d), SC = O(1)
class Solution
{
public:
    vector<int> separateDigits(vector<int> &nums)
    {
        vector<int> answer;
        for (auto num : nums)
        {
            string str = to_string(num);
            for (auto &&c : str)
            {
                answer.push_back(c - '0');
            }
        }
        return answer;
    }
};

// Solution 3, TC = O(n*d), SC = O(d)
class Solution
{
public:
    vector<int> separateDigits(vector<int> &nums)
    {
        vector<int> answer;
        stack<int> st;
        for (auto num : nums)
        {
            while (num > 0)
            {
                st.push(num % 10);
                num /= 10;
            }
            while (!st.empty())
            {
                answer.push_back(st.top());
                st.pop();
            }
        }
        return answer;
    }
};