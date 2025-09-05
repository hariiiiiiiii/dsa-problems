#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> product_except_self(vector<int>& nums){
        int n = nums.size();
        vector<int> answer(n,1);

        int prefix = 1;
        for(int i = 0; i < n; i++){
            answer[i] = prefix;
            prefix *= nums[i];
        }
        int suffix = 1;
        for(int i = n - 1; i >= 0; i--){
            answer[i] *= suffix;
            suffix *= nums[i];
        }
        return answer;

    }
};

int main() {
    Solution sol;
    vector<int> a = {2,3,5,6,7};
    vector<int> result = sol.product_except_self(a);
    for(int x: result){
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}