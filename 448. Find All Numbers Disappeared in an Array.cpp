// TC = O(n), MC = O(1) without considering the output array
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // nums[i] thkbe i-1 position e. amra ekta ekta kore num check krbo and jodi nums[i], i-1 position e na thke taile value duita swap korbo. direct bosay dibo na cause taile i-1 position er value ta haray jabe. er fole ekta position e right value bosbe but ekhn i-1 th position e abr correct value nao baste pare. tai ei process ta chalaite thkbo. tai `if` na hoye `while` hbe
        // 0 1 2 3 4 5 6 7 8 -> idx
        // 1 2 3 4 5 6 7 8 9 -> value

        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            while (nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
            } 
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i+1) {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};

