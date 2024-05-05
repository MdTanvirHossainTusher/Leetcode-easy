// TC = O(n), MC = O(1)
class Solution {
public:
    int countSegments(string s) {
        bool hitAnyCharYet = false; // s="   Hello, my name is John"; ei case e first er space gula ignore kora lgbe. tai space paile seta kon space(surur space naki word er majher space) bujhar jonno ei variable declare korsi
        int cnt = 0;
        int n = s.size();

        if (n == 0) return 0; // s=""; `s` jokhn empty string
        for(auto c: s) {
            if (c != ' ') hitAnyCharYet = true;
            if (c == ' ' && hitAnyCharYet) {
                hitAnyCharYet = false;
                cnt++;
            }
        }
        // s = "Hello, my name is John" ==> ei case e last e kno space nai so cnt er value 1 kom asbe. tai (cnt+1) korsi
        // s = "Hello, my name is John " ==> ei case e last e space thakay loop er 2nd if e hit korbe and cnt er value +1 korbe. tai ekhetre just cnt return korbo
        return s[n-1] != ' ' ? (cnt+1) : cnt;
    }
};