// LINK - https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length

// n = length of s

// Solution 1, TC = O(n), SC = O(1)
class Solution
{
public:
    bool isVowel(string &s, int i)
    {
        return s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
               s[i] == 'u';
    }
    int maxVowels(string s, int k)
    {
        int cur_count = 0, max_count = 0, j = 0;
        for (int i = 0; i < s.length(); i++)
        {
            isVowel(s, i) ? cur_count++ : cur_count;
            if (i >= k)
            {
                isVowel(s, j) ? cur_count-- : cur_count;
                j++;
            }
            max_count = max(max_count, cur_count);
        }
        return max_count;
    }
};