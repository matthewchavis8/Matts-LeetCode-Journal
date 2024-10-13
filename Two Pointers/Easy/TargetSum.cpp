#include <iostream>
#include <vector>
#include <unordered_map>
/*
Given an array of numbers sorted in ascending order and a target sum, find a pair in the array whose sum is equal to the given target.

Write a function to return the indices of the two numbers (i.e. the pair) such that they add up to the given target. If no such pair exists return [-1, -1].

Example 1:
Input: [1, 2, 3, 4, 6], target=6
Output: [1, 3]
Explanation: The numbers at index 1 and 3 add up to 6: 2+4=6
Example 2:

Input: [2, 5, 9, 11], target=11
Output: [0, 2]
Explanation: The numbers at index 0 and 2 add up to 11: 2+9=11
*/
using namespace std;
class Solution {
    public:
        vector<int> search(vector<int> &nums, int target) {
            int n = nums.size();
            unordered_map<int,int> map;
            vector<int> res;

            for (int i{}; i < n; i++) {
                int complacent = target - nums[i];

                if (map.find(complacent) != map.end()) {
                    return {map[complacent], i};
                }

                else map.insert({nums[i], i});
            }
            
            return {-1,-1};
        }
};

int main () {
    Solution test;

    vector<int> arr{1, 2, 3, 4, 6};
    int target{6};

    vector<int> res = test.search(arr, target);

    cout << "Target was found " << res[0] << ',' << res[1] << '\n';
    
    return 0;
}