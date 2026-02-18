// LINK - https://leetcode.com/problems/reverse-vowels-of-a-string

// n = length of s

// Solution 1 TC = O(n), SC = O(n)
class Solution
{
public:
    string reverseVowels(string s)
    {
        stack<char> st;
        string v = "AaEeIiOoUu";
        for (auto &&ch : s)
        {
            if (v.find(ch) != v.npos)
            {
                st.push(ch);
            }
        }
        for (auto &&ch : s)
        {
            if (v.find(ch) != v.npos)
            {
                ch = st.top();
                st.pop();
            }
        }
        return s;
    }
};

// Solution 2 TC = O(n), SC = O(1)

class Solution
{
public:
    bool isVowel(char c)
    {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string reverseVowels(string s)
    {
        int lo = 0, hi = s.length() - 1;
        while (lo < hi)
        {
            if (isVowel(s[lo]) && isVowel(s[hi]))
            {
                swap(s[lo++], s[hi--]);
            }
            else if (!isVowel(s[lo]))
            {
                lo++;
            }
            else if (!isVowel(s[hi]))
            {
                hi--;
            }
        }
        return s;
    }
};