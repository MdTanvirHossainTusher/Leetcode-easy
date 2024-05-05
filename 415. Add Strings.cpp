// TC = MC: O(max(n,m))
class Solution {
public:
    string addStrings(string num1, string num2) {
        int s1 = num1.size();
        int s2 = num2.size();
        int i = s1-1, j = s2-1;
        int carry = 0;
        string ans = "";
        // khatay jevabe number jog kori sei process e agabo
        // number duitar size different hole jei position e kono value thkbe na sekhne `0` bosay kaj korbo
        while(i >= 0 || j >= 0 || carry) {
            int x1 = i >= 0? num1[i]-'0' : 0;
            int x2 = j >= 0? num2[j]-'0' : 0;
            int sum = (x1 + x2 + carry) % 10;
            carry = (x1 + x2 + carry) / 10;
            ans.push_back(sum+'0');
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};