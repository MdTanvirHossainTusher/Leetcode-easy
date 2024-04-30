// TC: O(n+m), MC: O(1)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        int sz = s.size();
        int tz = t.size();
        // `i` baire asa mane `s` er sob char `t` te ase, tai true return korbo
        while (i < sz && j < tz) {
            if (s[i] == t[j]) {
                i++;
                j++;
            }
            else {
                j++;
            }
        }
        return i == sz; // `i` baire asa mane i r s er value soman hbe, tai true return korbo
    }
};