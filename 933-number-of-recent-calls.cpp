// LINK - https://leetcode.com/problems/number-of-recent-calls

// n = size of q

// Solution 1, TC = O(n), SC = O(n)
class RecentCounter
{
private:
    queue<int> q;
    int size;

public:
    RecentCounter() { size = 0; }

    int ping(int t)
    {
        int tf = t - 3000;
        while (q.size() && q.front() < tf)
        {
            q.pop();
            size--;
        }
        q.push(t);
        size++;
        return size;
    }
};
