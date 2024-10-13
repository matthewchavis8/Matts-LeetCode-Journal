/*
1768. Merge Strings Alternately

You are given two strings word1 and word2. 
Merge the strings by adding letters in alternating order, 
starting with word1. If a string is longer than the other,
append the additional letters onto the end of the merged string.

Return the merged string.

Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s
Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d
 
Constraints:

1 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.
*/

/*INTUITION Explained
    -So this question is similar to merge sorted List 
    We use a one pointer to move across both strings and append it Alternately
    once the pointer runs out on one string we will only append that.
*/
#include<iostream>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        int left{};
        string res{""};
        
        while (left < n || left < m) {
            if (left < n) res += word1[left];
            if (left < m) res += word2[left];
            left++;
        }

        return res;
    }
};

int main () {
    Solution test;
    string str1{"Matthew"};
    string str2{"Chavis"};

    cout << "string 1 is: " << str1 << '\n';
    cout << "string 2 is: " << str2 << '\n';
    
    cout << "New string is: " << test.mergeAlternately(str1, str2) << '\n';

    return 0;
}