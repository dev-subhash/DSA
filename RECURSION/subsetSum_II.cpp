#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> current_subset;
        
        // 1. Sort the array so that duplicate elements are adjacent
        std::sort(nums.begin(), nums.end());
        
        backtrack(0, nums, current_subset, res);
        return res;
    }

private:
    void backtrack(int start, const std::vector<int>& nums, std::vector<int>& current_subset, std::vector<std::vector<int>>& res) {
        // Add the current subset to our result list
        res.push_back(current_subset);
        
        for (int i = start; i < nums.size(); ++i) {
            // 2. Skip duplicates: If the current element is the same as the 
            // previous one, AND we are not at the 'start' pointer of this level.
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            
            // Include the element
            current_subset.push_back(nums[i]);
            
            // Move to the next element
            backtrack(i + 1, nums, current_subset, res);
            
            // Backtrack (remove the element)
            current_subset.pop_back();
        }
    }
};

// Example usage:
int main() {
    Solution sol;
    std::vector<int> nums = {1, 2, 2};
    std::vector<std::vector<int>> result = sol.subsetsWithDup(nums);
    
    // Printing the subsets
    for (const auto& subset : result) {
        std::cout << "[";
        for (size_t i = 0; i < subset.size(); ++i) {
            std::cout << subset[i] << (i + 1 < subset.size() ? ", " : "");
        }
        std::cout << "]\n";
    }
    return 0;
}