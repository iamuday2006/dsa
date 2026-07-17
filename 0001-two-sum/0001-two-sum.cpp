#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Map to store: Key = number value, Value = its index
        std::unordered_map<int, int> numMap;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Check if the complement already exists in the map
            if (numMap.find(complement) != numMap.end()) {
                // Return the index of the complement and the current index
                return {numMap[complement], i};
            }
            
            // If not found, insert the current number and its index into the map
            numMap[nums[i]] = i;
        }
        
        // Return empty vector if no solution is found (though the problem guarantees one)
        return {};
    }
};
