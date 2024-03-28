class Solution
{
public:
    int firstUniqChar(string s)
    {
        // loveleetcode
        // 01234567891011 --> indices
        /**
            map(char, indices) ==>
            l = 0, 4
            o = 1, 9
            v = 2
            e = 3, 5, 6, 11
            t = 7
            c = 8
            d = 10
        jesb vector er size=1 tader moddhe jar index sb theke kom seta ans        */
        unordered_map<char, vector<int>> letters;
        int minIdx = INT_MAX;
        char c;
        for (int i = 0; i < s.size(); i++)
        {
            letters[s[i]].push_back(i);
        }
        for (auto letter : letters)
        {
            if (letter.second.size() == 1 && letter.second[0] < minIdx)
            {
                minIdx = letter.second[0];
                // c = letter.first;
            }
        }
        return minIdx == INT_MAX ? -1 : minIdx;
    }
};

// TC = MC: O(n)
class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> m;
        for (auto c : s)
        {
            m[c]++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (m[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};