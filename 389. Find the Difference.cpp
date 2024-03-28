class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        vector<int> v(26, 0);
        for (auto c : s)
        {
            v[c - 'a']++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            if (v[t[i] - 'a'] == 0)
                return t[i];
            else
                v[t[i] - 'a']--; // s="a", t="aa" ==> output="a"
        }
        return ' ';
    }
};

// TC = O(n+m), MC = O(k) where k = 26
class Solution
{
public:
    // set/multiset diye hbe na. cz set e no duplicate r multiset e erase krle sb occurance delete korbe oi char er
    char findTheDifference(string s, string t)
    {
        unordered_map<char, int> m;
        for (auto c : s)
        {
            m[c]++;
        }
        for (auto c : t)
        {
            if (m.count(c) && m[c] != 0)
                m[c]--; // s="a", t="aa" ==> output="a", eta na dile ei case er jnno wrong dibe
            else
                return c;
        }
        return ' ';
    }
};