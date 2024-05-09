// Has KMP solution

// TC = O(n^2), MC = O(1)
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        int subStrLen = n/2;
        while (subStrLen >= 1) {
            string subString = s.substr(0, subStrLen);
            string ans = subString;
            while (ans.size() < n) {
                ans += subString;
                if (ans == s) {
                    return true;
                }
            }
            subStrLen = subStrLen - 1;
        }
        return false;
    }
};


// TC = O(n^2), MC = O(1)
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        int subStrLen = n/2;
        while (subStrLen >= 1) {
            if (n % subStrLen == 0) { // sudhu je sb substr diye `s` banano possible tader consider korchi
                string subString = s.substr(0, subStrLen);
                string ans = subString;
                while (ans.size() < n) {
                    ans += subString;
                    if (ans == s) {
                        return true;
                    }
                }
            }
            subStrLen = subStrLen - 1;
        }
        return false;
    }
};

// https://youtu.be/cRcdmmR5nBo?si=AyOtnuDNOubw1NBP