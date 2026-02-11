// LINK - https://leetcode.com/problems/find-words-containing-character/

// m = size of words, n = avg length of words[i]

// Solution 1, TC = O(m*n), SC = O(1)
class Solution
{
public:
    vector<int> findWordsContaining(vector<string> &words, char x)
    {
        vector<int> indices;
        for (int i = 0; i < words.size(); i++)
        {
            if (words[i].find(x) != string::npos)
            {
                indices.push_back(i);
            }
        }

        return indices;
    }
};
