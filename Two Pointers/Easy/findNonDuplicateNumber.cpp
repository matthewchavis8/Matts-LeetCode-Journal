/*
Given an array of sorted numbers, move all non-duplicate number instances at the beginning of the array in-place. 
The non-duplicate numbers should be sorted and you should not use any extra space so that the solution has constant space complexity i.e., .
Move all the unique number instances at the beginning of the array and after moving return the length of the subarray that has no duplicate in it.

Example 1:

Input: [2, 3, 3, 3, 6, 9, 9]
Output: 4
Explanation: The first four elements after moving element will be [2, 3, 6, 9].
Example 2:

Input: [2, 2, 2, 11]
Output: 2
Explanation: The first two elements after moving elements will be [2, 11].
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int moveElements (vector<int> &nums) {
            int n = nums.size();
            vector<int> subArr;

            for (int i{1}; i <= n; i++) {
                if (nums[i] != nums[i-1]) subArr.push_back(nums[i]);
            }
            return subArr.size();
        }
};

int main () {
    Solution test;
    vector<int> arr{2, 3, 3, 3, 6, 9, 9};

    cout << "The original Size of the array is: " << arr.size() << '\n';

    int res = test.moveElements(arr);
    cout << "The new size of the array is: " << res << '\n';

    return 0;
}