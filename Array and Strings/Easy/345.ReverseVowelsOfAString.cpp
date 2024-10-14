/*
345. Reverse Vowels of a String

Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

Example 1:

Input: s = "IceCreAm"

Output: "AceCreIm"

Explanation:

The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

Example 2:

Input: s = "leetcode"

Output: "leotcede"

INTUITION:
    So basically this is a two pointer strategy where we go from left and right. 
    When you hit a vowel you pause one pointer and until both pointers are a vowel
    if both pointers are on a vowel swap
    Done
*/
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    public:
        string reverseVowels(string &s) {
            int n = s.length();
            int left{};
            int right{n-1};

            while (left < right) {
                if (!isVowel(s[left])) left++;
                if (!isVowel(s[right])) right--;

                if (isVowel(s[left]) == isVowel(s[right])) {
                    swap(s[left], s[right]);
                    left++;
                    right--;
                }
            }

            return s;
        }
        bool isVowel(char &c) {
            return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                    c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') 
                    ? true : false;
        }
};

int main () {
    Solution test;

    string str{"IceCreAm"};

    cout << "Original String: " << str << '\n';
    cout << "New String is: " << test.reverseVowels(str) << '\n';

    return 0;
}