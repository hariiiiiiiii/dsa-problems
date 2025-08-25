#include <iostream>   // for input/output
#include <vector>     // for vector
#include <string>     // for string
#include <algorithm>  // for algorithms (like find, sort)
using namespace std;

// Class containing our solution
class Solution {
public:
    // Function to find the longest common prefix
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";  // Edge case: empty input array

        string prefix = strs[0];      // Start with the first string as the initial prefix

        // Loop through the rest of the strings
        for(int i = 1; i < strs.size(); i++) {
            // While the current string doesn't start with the prefix
            while(strs[i].find(prefix) != 0) {
                // Reduce the prefix by removing the last character
                prefix = prefix.substr(0, prefix.size() - 1);

                // If prefix becomes empty, no common prefix exists
                if (prefix.empty()) return "";
            }
        }

        return prefix;  // Return the longest common prefix
    }
};

int main() {
    int n;
    cin >> n;  // Read the number of strings

    vector<string> strs(n);          // Create a vector to store the strings
    for(int i = 0; i < n; i++) 
        cin >> strs[i];              // Read each string

    Solution s;                      // Create an object of the Solution class
    string ans = s.longestCommonPrefix(strs);  // Call the method
    cout << ans << "\n";             // Print the answer

    return 0;                        // End of program
}
