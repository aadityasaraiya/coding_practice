///////////////////////
// [1] Two Sum 


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> ans; 
        unordered_map<int, int> m1; 
        
        for(int i=0; i<nums.size(); i++)
        {
            // Insert element into map with its index
            m1.insert({nums[i], i});
            
            if(i == 0 )
            {
                continue; 
            }
            
            // Check for target - element. If you find it, get its index, push both into ans                and break
            auto it= m1.find(target-nums[i]);
            if(it!= m1.end() && it->second!=i)
            {
                ans.push_back(i);
                ans.push_back(it->second);
                break; 
            }
        }
        
        
        return ans; 
        
        
    }
};

///////////////////////
