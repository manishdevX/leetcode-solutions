// LINK - https://leetcode.com/problems/reveal-cards-in-increasing-order/description/

// n = size of deck

// Solution 1 TC = O(nlogn), SC = O(n)
class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        int n = deck.size(), ind = 0;
        sort(deck.begin(), deck.end());
        queue<int> q;
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            q.push(i);
        }
        while (q.size())
        {
            ans[q.front()] = deck[ind++];
            q.pop();
            q.push(q.front());
            q.pop();
        }
        return ans;
    }
};

// Solution 2 TC = O(nlogn), SC = O(n)
class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        int n = deck.size(), deck_ind = 0, ans_ind = 0;
        sort(deck.begin(), deck.end());
        vector<int> ans(n);
        bool skip = false;
        while (deck_ind < n)
        {
            if (ans[ans_ind] == 0)
            {
                if (!skip)
                {
                    ans[ans_ind] = deck[deck_ind++];
                }

                skip = !skip;
            }
            ans_ind = (ans_ind + 1) % n;
        }
        return ans;
    }
};
