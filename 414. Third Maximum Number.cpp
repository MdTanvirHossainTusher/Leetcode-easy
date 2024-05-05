// TC = O(n*logn), MC = O(n)
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        priority_queue<int> pq;

        int mn = INT_MAX;
        int mx = INT_MIN;
        int i = 0;

        for(auto n: s) {
            pq.push(n);
        }
        while (!pq.empty() && i < 3) {
            i++;
            mn = min(mn, pq.top());
            mx = max(mx, pq.top());
            pq.pop();
        }
        return i == 3? mn : mx;
    }
};


