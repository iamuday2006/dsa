class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int low = 0, unique = 1, curr = 1;

        while (curr < nums.size()) {
            if (nums[low] != nums[curr]) {
                nums[low + 1] = nums[curr];
                curr++;
                unique++;
                low++;
            }else{
                curr++;
            }
        }

        return unique;
    }
};