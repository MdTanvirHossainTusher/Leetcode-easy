// TC = O(logn), MC = O(logn)
class Solution {
public:
    string toHex(int n) {       
        string ans = "";
        string hexNum = "0123456789abcdef";
        unsigned int num = n;
        if (num == 0) return "0";
        while (num > 0) {
            int rem = num % 16;
            num = num / 16;
            ans.push_back(hexNum[rem]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

