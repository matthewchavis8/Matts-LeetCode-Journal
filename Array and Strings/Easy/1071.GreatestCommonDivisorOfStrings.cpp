/*
1071. Greatest Common Divisor of Strings

For two strings s and t, we say "t divides s" if and 
only if s = t + t + t + ... + t + t (i.e., t 
is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""
*/

/*  INTUITION
    Basically there is a fancy mathmatical algorithm of this
    so if you add both strings Alternately like str1 + str2 or str2 + str1
    they have to be the same if they are not the same there is no greateest common Divisor.
    If they are the same then it will be from 0, to the gcd of both strings

    ex:
        s1:ABCBAB s2: ABAB
        gcd(6,4): we get 2
        s1.substr(0,2): we get our answer AB
*/
#include <iostream>
#include <numeric>
using namespace std;

class Solution {
    public:
        string gcdOfStrings(string str1, string str2) {
            return str1 + str2 == str2 + str1 ? str1.substr(0, gcd(str1.size(), str2.size())) : "";
        }
};

int main () {
    Solution test;

    string str1{"ABCABC"};
    string str2{"ABC"};

    cout << "String 1 is: " << str1 << '\n';
    cout << "String 2 is: " << str2 << '\n';
    cout << "Greatest Common Divisor of both strings is: " << test.gcdOfStrings(str1, str2) << '\n';
  
    return 0;
}