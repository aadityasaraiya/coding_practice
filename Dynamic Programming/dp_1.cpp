#include<iostream>

int main()
{
    int maxN= 100; 
    int dp[maxN];

    // base case : Factorial of 0 is 1 
    dp[0]= 1;

    int n= 3; 
    for (int i= 1; i<=n; i++)
    {
        dp[i]= dp[i-1]*i;
    }

    std::cout << "Factorial for: "<< n << " is: "<< dp[n] << std::endl;  
}


------------------------------------------------------------
//// [198] House Robber 

class Solution {
public:
    
    int maxSumFunc(int ind, vector<int>& nums, vector<int>& maxSumVals)
    {
        if(maxSumVals[ind]!= -1)
        {
            return maxSumVals[ind]; 
        }
        
        int currSum= nums[ind]; 

        
        if(ind +2 >= nums.size())
        {
            return currSum; 
        }
        
        int maxSum = currSum; 
        int temp = 0; 
        int ind_new = ind + 2; 
        
        for(int i= ind_new; i< nums.size(); i++)
        {
            
            temp = maxSumFunc(i, nums, maxSumVals);
            maxSumVals[i]= temp; 
            currSum+= temp; 
            maxSum= max(maxSum, currSum); 
            currSum= nums[ind];
        }
        
        return maxSum; 
    }
    
    
    int rob(vector<int>& nums) {
        
        // Set size of vector as member value 
        int vec_size = nums.size(); 
        
        if(vec_size == 0) return 0; 
        if(vec_size == 1) return nums[0]; 
        if(vec_size == 2) return max(nums[0], nums[1]);
        
        // Initialize a vector of zeros 
        vector<int> maxSumVals(nums.size(), -1);
        
        int maxVal= 0; 
        for(int i=0; i<2; i++)
        {
            maxVal= max(maxVal, maxSumFunc(i, nums, maxSumVals));
        }

    return maxVal; 
    
    
    }
};

///////////////////////////////////////////////////////////////////////////////////
// [39] Combination Sum 

class Solution {
public:
       
    void search(vector<int>& num, int next, vector<int>& pSol, int target, vector<vector<int> >& ans)
    {
        if(target == 0)
        {
            ans.push_back(pSol);
            return; 
        }
        
        if(next == num.size() || target- num[next] < 0) return; 
                
        pSol.push_back(num[next]); 
        search(num, next, pSol, target- num[next], ans);
        pSol.pop_back(); 
        search(num, next+1, pSol, target, ans); 
    }

    

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;  
        vector<int> pSol; 
        sort(candidates.begin(), candidates.end()); 
        search(candidates, 0, pSol, target, ans);
        return ans; 
    }
};


///////////////////////////////////////////////////////////////////////////////////
// [252] Meeting rooms 

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        
        if(intervals.size() == 0) return true; 
        
        // Sort the start and end times for the meetings. If for any case, start[i+1] > end[i] return false
        
        vector<int> start_times(intervals.size(), 0); 
        vector<int> end_times(intervals.size(), 0); 
        
        
        int i=0; 
        for(auto const& x: intervals)
        {
            start_times[i] = x[0];
            end_times[i] = x[1];
            i++; 
        }
        
        // Sort the start times and end times vectors 
        sort(start_times.begin(), start_times.end());
        sort(end_times.begin(),   end_times.end());
        
        for(int i=0; i< start_times.size()-1; i++)
        {
            if(start_times[i+1] < end_times[i]) return false; 
        }
        
        return true; 
        
        
        
    }
};

/*  Approach 1: Naive approach using maps 
// Approach does not work as we may have some intervals which start at the exact same time 


        map<int,int> map1;
        
        // Added in ordered map, so it will be sorted according to start  
        for(auto const& vec: intervals)
        {
            // Insert all the start and end intervals in map
            map1.insert({vec[0], vec[1]}); 
        }
        
        int curr_start = 0;
        int curr_end = 0;
        int prev_end = INT_MIN; 
        
        for(auto const& x: map1)
        {
            curr_start = x.first;
            curr_end = x.second; 
            
            cout << curr_start << " " << curr_end << endl; 
            
            if(curr_start < prev_end) return false; 
            // Updating the prev end as the current end for the next iteration
            prev_end = curr_end; 
        }
        
        return true; 





*/

///////////////////////////////////////////////////////////////////////////////////
// [253] Meeting rooms II 


    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0; 
        
        // Sorting a vector of vectors with a custom sorting function 
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>&a, const vector<int>& b){return a[0]< b[0]; });
        
        // Initialize min heap 
        priority_queue<int, vector<int>, greater<int>> minH; 
        
        // Add first elements end time in min heap 
        minH.push(intervals[0][1]); 
        
        for(int end_idx = 1; end_idx < intervals.size(); end_idx++)
        {
            // End time is after the min end time
            // 
            if(minH.top() <= intervals[end_idx][0])
            {
                minH.pop();
                minH.push(intervals[end_idx][1]); 
            }
            // These two meeting times are clashing, we need another room
            else minH.push(intervals[end_idx][1]); 
        }
        
        return minH.size(); 
       
    }
