int findDuplicate(int* nums, int numsSize) {
    // since this is a linked list problem, we will solve it the linked list way
    // since there are n + 1 numbers and n places where only one appears multiple times, this can be thought of as a linked list with a cycle, where the repeating numbers form a cycle
    // this only works because there are n+1 places, where n is the largest number in the array, and all nums are positive
    int slow = 0;
    int fast = 0;
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    slow = 0;
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}
