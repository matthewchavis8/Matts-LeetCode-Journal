/*
There are n kids with candies. You are given an integer array candies, 
where each candies[i] represents the number of candies the ith kid has, 
and an integer extraCandies, denoting the number of extra candies that you have.

Return a boolean array result of length n, where result[i] is true if, 
after giving the ith kid all the extraCandies, they will have the greatest number of candies among all the kids, or false otherwise.

Note that multiple kids can have the greatest number of candies.

 

Example 1:

Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true] 
Explanation: If you give all extraCandies to:
- Kid 1, they will have 2 + 3 = 5 candies, which is the greatest among the kids.
- Kid 2, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
- Kid 3, they will have 5 + 3 = 8 candies, which is the greatest among the kids.
- Kid 4, they will have 1 + 3 = 4 candies, which is not the greatest among the kids.
- Kid 5, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
Example 2:

Input: candies = [4,2,1,1,2], extraCandies = 1
Output: [true,false,false,false,false] 
Explanation: There is only 1 extra candy.
Kid 1 will always have the greatest number of candies, even if a different kid is given the extra candy.
Example 3:

Input: candies = [12,1,12], extraCandies = 10
Output: [true,false,true]

INTUITIONL:
    So basically we look for the greatest element
    so kid with the most candies so far
    then we loop through and give the kid the extra candies
    if he is greater then or equal to the current greatest element
    then we append true to our boolean vector
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
            int n = candies.size();
            vector<bool> res;
            auto kidWithMost = *max_element(candies.begin(), candies.end());

            for (int i{}; i < n; i++) {
                candies[i] + extraCandies >= kidWithMost ? res.push_back(true) : res.push_back(false);
            }
            return res;
        }
};

int main () {
    Solution test;
    vector<int> candies{2,3,5,1,3};
    int extraCandies{3};

    vector<bool> res = test.kidsWithCandies(candies, extraCandies);

    for (int i{}; i < res.size(); i++) {
        cout << res[i] << ',';
    }
    

    return 0;
}