#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
//暴力算法

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size() ; i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    return {i , j};
                }
            }
        }
        return {};
    }
//哈希查找
    vector<int>twosum_p(vector<int>& nums, int target) {
       unordered_map<int, int> map; 
        for(int i = 0; i < nums.size(); i++){
            auto iter = map.find(target - nums[i]);
            if(iter != map.end()){
                return {iter->second, i};
            }

            map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
    
};