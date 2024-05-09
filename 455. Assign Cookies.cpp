// TC = O(n*lonn), MC = O(logn)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size();
        int n = s.size();
        int i = 0, j = 0, cnt = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        // g = 10 9 8 7 -> 7' 8' 9 10
        // s = 5 6 7 8  -> 5 6 7' 8'
        while (i < m && j < n) {
            if (s[j] >= g[i]) {
                cnt++;
                i++;
                j++;
            }
            else {
                j++;
            }
            
        }
        return cnt;
    }
};