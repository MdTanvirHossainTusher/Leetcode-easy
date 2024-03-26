class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m1, m2;
        vector<int> ans;

        for(auto num: nums1) {
            m1[num]++;
        }
        for(auto num: nums2) {
            m2[num]++;
        }

        for(auto num: nums2) {
            if(m1.count(num) && m2.count(num)) {
                int cmnAppearTimes = min(m1[num], m2[num]);
                for(int i = 0; i < cmnAppearTimes; i++) {
                    ans.push_back(num);
                }
                m2.erase(num); // O(n) in worst case
            }
        }
        return ans;
    }
};


// https://leetcode.com/problems/intersection-of-two-arrays-ii/solutions/282372/java-solution-with-all-3-follow-up-questions/
// TC = O(n+m), MC = O(n)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m1;
        vector<int> ans;

        for(auto num: nums1) {
            m1[num]++;
        }
        for(auto num: nums2) {
            if(m1.count(num) && m1[num] > 0) {
                m1[num]--;
                ans.push_back(num);
            }
        }
        return ans;
    }
};


// https://leetcode.com/problems/intersection-of-two-arrays-ii/solutions/282372/java-solution-with-all-3-follow-up-questions/
// TC = O(nlogn), MC = O(n)
// but jodi dhore nei je, input array already sorted, taile, TC = O(max(n, m))
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end()); // O(nlogn)
        sort(nums2.begin(), nums2.end());
        int m = nums1.size(), n = nums2.size();
        vector<int> ans;
        int i = 0, j = 0;
        
        while(i < m && j < n) { // O(max(n, m))
            if(nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] > nums2[j]) { // jodi eta hoy, taile `intersection` ber korar jonno nums2 er pointer samne barabo cz ami nums1 er soman value paite chai jate `intersection` value khuje pai
                j++;
            }
            else {
                i++;
            }
        }
        return ans;        
    }
};