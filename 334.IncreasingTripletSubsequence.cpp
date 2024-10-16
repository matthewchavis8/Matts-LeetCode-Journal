/*
    Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k 
    and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

Example 1:

Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
Example 2:

Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.
Example 3:

Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.

Inution:
    So this strategy is very clever I would have never came up with myself. 
    I did come up with the right Solution although very brute force it got the job.
    But it did not fall into the time constraint o(n)

    Anyway the strategy is to make two variables that will store the first two min values
        ex: int min1{INT_MAX}, min2{INT_MAX}
    we then loop through our array and we assign our min values to a num if it is less than it
    if we cannot assign any values then we know the third value is greater then the first two
    make it true
    
    ex:
        int min1{INT_MAX}, min2{INT_MAX};
        [2,1,5,0,4,6]
        if (num <= min1) 
        if (num <= min2)
        min1{2->5->4}, min2{1->0}

        return true because none of the numbers got reassigned this is it. 
        This has been solved as you can see it is now 0, 4, 6
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min1{INT_MAX};
        int min2{INT_MAX};
        
        for (int &num : nums) {
            if (num <= min1) min1 = num;
            else if (num <= min2) min2 = num;
            else return true;
        }
        return false;
    }

    string printNums (vector<int> &nums) {
        string res{""};

        for (int &num : nums) {
            res += to_string(num) + " ";
        }
        return res;
    }
};

int main () {
    Solution test;
    vector<int> nums{1,2,3,4,5};

    cout << "The Numbers are: " << test.printNums(nums) << '\n';

    cout << "Does a triplet exit?: " 
         << ((test.increasingTriplet(nums) == true) ? 
    "True" : "False") << '\n';

    return 0;
} 