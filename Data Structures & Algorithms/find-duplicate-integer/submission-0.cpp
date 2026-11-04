class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Step 1: Initialize slow and fast pointers
        int slow = nums[0];
        int fast = nums[0];

        // Step 2: Find the intersection point in the cycle
        do {
            slow = nums[slow];          // Move 1 step
            fast = nums[nums[fast]];    // Move 2 steps
        } while (slow != fast);

        // Step 3: Find the entrance to the cycle (the duplicate number)
        slow = nums[0]; // Reset slow pointer to start
        while (slow != fast) {
            slow = nums[slow]; // Move 1 step
            fast = nums[fast]; // Move 1 step
        }

        return slow; // Or fast, both point to the cycle entry
    }
};