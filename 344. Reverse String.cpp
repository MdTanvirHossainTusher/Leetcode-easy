// TC=O(n), MC=O(1)
class Solution {
public:
    void reverseString(vector<char>& s) {
        /**
            `in-place` modifies the input in place, without creating a separate copy of the data structure. An algorithm which is not in-place is sometimes called not-in-place or out-of-place.
        */
        int l = 0, r = s.size()-1;
        while(l <= r) {
            char c = s[l];
            s[l] = s[r];
            s[r] = c;
            l++;
            r--;
        }
        return;
    }
};