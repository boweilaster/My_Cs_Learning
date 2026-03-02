#include <iostream>
#include<unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maioritpyElement(vector<int>& nums){
      unordered_map<int, int> count;
      int n = nums.size() / 2;

      for(int num : nums){
        count[num]++;

        if(count[num] > n){
            return num;
        }
      }
      return -1;
    }
};