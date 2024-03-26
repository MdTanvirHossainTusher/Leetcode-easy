// TC=O(n+m), O(3*n)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end()), intermediate;
        // vector<int> ans;
        for(int i = 0; i < nums2.size(); i++) {
            if(s1.count(nums2[i])) {
                intermediate.insert(nums2[i]);
            }
        }
        // ans(intermediate.begin(), intermediate.end()); // evabe initialize kora jay na
        vector<int> ans(intermediate.begin(), intermediate.end()); // direct evabe declare and initialize kora lgbe
        return ans;
    }
};

// TC=O(n+m), O(3*n)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end()), intermediate;
        vector<int> ans;
        
        for(auto num: nums2) {
            if(s1.count(num) && !intermediate.count(num)) {
                intermediate.insert(num);
                ans.push_back(num);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        vector<int> ans;

        for(auto num: nums1) {
            m[num]++;
        }
        for(auto num: nums2) {
            if(m.count(num)) {
                ans.push_back(num);
                m.erase(num); // `nums1` ta `map` theke delete kore dibo jate ekta value multiple bar na count hoy
            }
        }
        return ans;
    }
};