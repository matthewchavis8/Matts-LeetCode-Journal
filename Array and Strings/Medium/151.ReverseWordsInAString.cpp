/*
151. Reverse Words in a String

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. 
The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
 

    **Inution**

    So basically the strategy goes as follows so you make a vector of the words
    the reason being is because you are going to take that input string and chop it
    you chop it using stringstream as it handles all white spaces and also separates them
    into their own string
        ex: "Matthew is a 5'11 manlet" -> after string stream and vector
        ex: {"Matthew", "is", "a", "5'11", "manlet"}
    Don't you see how much easier that is for us to handles
    Now we can reverse our string 
        ex: {"Matthew", "is", "a", "5'11", "manlet"} -> reverse
        ex: {"manlet", "5'11", "a", "is", "Matthew",}
    wow wollah we are almost there now we need to append it to our res string
    so we loop through our vector and append 
        ex: res += words[i]
        after appending we then add a space as long as we are not on our last word
    That is how to solve the problem
*/
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


class Solution {
public:
    string reverseWords(string &s) {
        vector<string> words;
        string word{""};
        string res{""};
        int n = s.size();

        stringstream ss(s);
        while (ss >> word) {
            words.push_back(word);
        }
        reverse(words.begin(), words.end());

        for (int i{}; i < words.size(); i++) {
            res += words[i];

            if (i != words.size() - 1) res += " ";
        }
        return res;
    }
};

int main () {
    Solution test;
    string s{"the sky is blue"};

    cout << "The original String is: " << s << '\n';
    cout << "The Reversed words in the string is: "
         << test.reverseWords(s) << '\n';

    return 0;
}