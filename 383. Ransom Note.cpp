// TC = MC : O(m+n)
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int m = ransomNote.size();
        int n = magazine.size();
        unordered_map<char, int> m1, m2;
        /**
        duita map e char gula rkhbo then check kore dkhbo and ekta char check kora hoile count-- krbo
        Complexity- duita diff size er map fill kortesi, so TC = MC : O(m+n)
        */
        for (auto c : ransomNote)
        {
            m1[c]++;
        }
        for (auto c : magazine)
        {
            m2[c]++;
        }
        for (auto c : ransomNote)
        {
            if (m2.count(c) && m1[c] <= m2[c])
            {
                m1[c]--;
                m2[c]--;
            }
            else
                return false;
        }
        return true;
    }
};

// TC = O(n+m), MC = O(n)
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int m = ransomNote.size();
        int n = magazine.size();
        unordered_map<char, int> m2;
        /**
        duita map e char gula rkhbo then check kore dkhbo and ekta char check kora hoile count-- krbo
        Complexity- duita diff size er map fill kortesi, so TC = MC : O(m+n)
        */
        for (auto c : magazine)
        {
            m2[c]++;
        }
        for (auto c : ransomNote)
        {
            if (m2.count(c) && m2[c] > 0)
            {
                m2[c]--;
            }
            else
                return false;
        }
        return true;
    }
};

// TC = MC : O(m+n)
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int m = ransomNote.size();
        int n = magazine.size();
        // array solution. map er motoi just `magazine` er char ke array te rkhbo index hisebe, then cnt++

        vector<int> alphabet(26, 0);
        for (auto c : magazine)
        {
            alphabet[c - 'a']++;
        }
        for (auto c : ransomNote)
        {
            if (alphabet[c - 'a'] == 0)
            { // `c` ransomNote e ase but magazine e nai
                return false;
            }
            else
                alphabet[c - 'a']--;
        }
        return true;
    }
};