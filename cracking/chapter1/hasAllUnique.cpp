#include <iostream>
#include <ostream>
#include <string>

using namespace std;

/*
 * Implement a method to determine if a string has all unique characters.
 * Assume ASCII char set and that case matters.
 */
 bool hasAllUnique(string str)
 {
     // Assuming 128 char ASCII
     if (str.length() > 128) 
     {
         return false;
     }

     bool charSet[128] = {false};
     for (string::iterator it = str.begin(); it != str.end(); ++it)
     {
         int charIndex = *it;
         if (charSet[charIndex]) 
         {
             return false;
         }
         charSet[charIndex] = true;
     }

     return true;
 }

 int main()
 {
    cout << hasAllUnique("abcd") << std::endl;
    cout << hasAllUnique("abca") << std::endl;
    cout << hasAllUnique("aAbc") << std::endl;
    cout << hasAllUnique("a c") << std::endl;
 }