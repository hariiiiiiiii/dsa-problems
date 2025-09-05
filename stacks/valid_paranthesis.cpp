#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>   

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;   

        for (char ch : s) {   
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);   
            } else {
                if (st.empty()) {
                    return false;   
                }

                char top = st.top();   
                st.pop();              

               
                if (ch == ')' && top != '(') return false;
                if (ch == ']' && top != '[') return false;
                if (ch == '}' && top != '{') return false;
            }
        }

        return st.empty();  
    }
};

int main() {
    Solution sol;

    string s = "[{}]";   
    bool result = sol.isValid(s);   

    cout << result << endl;   

    return 0;
}
