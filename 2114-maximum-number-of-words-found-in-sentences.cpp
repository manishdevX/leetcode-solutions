// LINK - https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/

// TC = solution 1, O(n^2), SC = O(1)

class Solution
{
public:
    int mostWordsFound(vector<string> &sentences)
    {
        int max_words_count = 0;
        for (string st : sentences)
        {
            int count = 0;
            for (char ch : st)
            {
                if (ch == ' ')
                {
                    count++;
                }
            }
            max_words_count = max(max_words_count, count);
        }
        return max_words_count + 1;
    }
};