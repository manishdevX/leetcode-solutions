// LINK - https://leetcode.com/problems/string-compression

// n = size of chars

// Solution 1 TC = O(n), SC = O(n)
class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int n = chars.size(), count = 1;
        string s = "";
        s += chars[0];
        for (int i = 1; i < n; i++)
        {
            if (chars[i] == chars[i - 1])
            {
                count++;
            }
            else
            {
                s = count > 1 ? s + to_string(count) : s;
                s = s + chars[i];
                count = 1;
            }
        }
        s = count > 1 ? s + to_string(count) : s;
        int sz = s.length();
        chars.resize(sz);
        for (int i = 0; i < sz; i++)
        {
            chars[i] = s[i];
        }
        return sz;
    }
};

// Solution 2 TC = O(n), SC = O(1)

class Solution
{
public:
    void addCounts(vector<char> &chars, int n, int &ind)
    {
        int a = (int)log10(n);
        int div = (int)(pow(10, a) + 0.5);
        while (div)
        {
            int d = n / div;
            chars[ind++] = '0' + d;
            n %= div;
            div /= 10;
        }
    }

    int compress(vector<char> &chars)
    {
        int n = chars.size(), count = 1, ind = 1;
        for (int i = 1; i < n; i++)
        {
            if (chars[i] == chars[i - 1])
            {
                count++;
            }
            else
            {
                if (count > 1)
                {
                    addCounts(chars, count, ind);
                }
                chars[ind++] = chars[i];
                count = 1;
            }
        }
        if (count > 1)
        {
            addCounts(chars, count, ind);
        }
        chars.resize(ind);
        return ind;
    }
};