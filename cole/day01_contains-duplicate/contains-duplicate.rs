use std::collections::HashSet;

impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        if nums.len() < 2 {
            return false;
        }
        let mut seen = HashSet::new();
        for &num in nums.iter() {
            if !seen.insert(num) {
                return true;
            }
        }
        return false;
    }
}
