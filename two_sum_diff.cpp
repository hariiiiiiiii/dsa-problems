#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target){
        unordered_map<int,int> seen;
        for(int i = 0;i < numbers.size(); i++){
            int complement = target - numbers[i];
            if(seen.find(complement) != seen.end()){
                return {seen[complement],i+1};
            }
            seen[numbers[i]] = i+1; 
        }
        return {};
        
    }
};

int main() {
    Solution obj;
    vector<int> nums = {2, 5, 11, 3};
    int target = 9;

    vector<int> ans = obj.twoSum(nums, target);

}