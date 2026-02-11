// LINK - https://leetcode.com/problems/find-first-palindromic-string-in-the-array/

// n = size of words, m = avg length of words[i]

// Solution 1, TC = O(n*m), SC = O(1)
class Solution
{
public:
    string firstPalindrome(vector<string> &words)
    {
        for (auto &&word : words)
        {
            string new_word = word;
            reverse(new_word.begin(), new_word.end());

            if (new_word == word)
            {
                return word;
            }
        }
        return "";
    }
};