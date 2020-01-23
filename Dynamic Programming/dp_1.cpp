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
///////////////////////////////////////////////////////////////////////////////////////////
// [11] Container with most water 

class Solution {
public:
    
    // Given two indices find the area between themm 
    int areaTwoInd(int idx1, int idx2, vector<int>& height)
    {
        return (abs(idx2 - idx1) * min(height[idx1], height[idx2])); 
    }
    
    int maxArea(vector<int>& height) {
        
        int i = 0;
        int j = height.size()-1; 
        int maxArea = 0; 
        int currArea = 0; 
        
        while(i < j)
        {
            currArea = areaTwoInd(i, j, height); 
            maxArea = max(maxArea, currArea); 
            if(height[i] < height[j]) i++;
            else j--; 
        }
        
        return maxArea; 
    }
};

/* Approach 1: Max Subarray like approach: Good approach, but biased towards the longer windows 
int start = 0;
int end = 1;

int maxArea = areaTwoIndices(end, start, height); 
int area1 = 0;
int area2 = 0; 

for(int i=2; i< height.size(); i++)
{
    area1 = areaTwoIndices(start, i, height);
    area2 = areaTwoIndices(end, i, height);

    if(area2 > area1)
    {
        start = end;
        end = i; 
    }

    else if(area1 > area2)
    {
        end = i; 
    }

    maxArea = max(maxArea, areaTwoIndices(start, end, height)); 

}

*/


/////////////////////////////////////////////////////////////////////////////////
// [55] Jump game [DP solution] 

class Solution {
public:
    
    bool canJumpLoop(vector<int>& nums, int start_idx, vector<int>& visitedFalse)
    {
        
        if(start_idx == nums.size()-1) return true;
        else if(start_idx > nums.size()-1) return false; 
        bool ans = false; 
        
        if(nums[start_idx] == 0) return false; 
                
        for(int i= nums[start_idx]; i>=1 ; i--)
        {
            if((start_idx + i <= nums.size()-1 && visitedFalse[start_idx + i] == 1)) continue; 
            ans = canJumpLoop(nums, start_idx + i, visitedFalse);
            if(ans) return true; 
            if(!ans) 
            {
                if(start_idx + i <= nums.size()-1) visitedFalse[start_idx + i] = 1;
            }
        }        
        return ans;         
    }
    
    bool canJump(vector<int>& nums) {
        vector<int> visitedFalse(nums.size(), 0); 
        bool ans = canJumpLoop(nums, 0, visitedFalse);
        return ans; 
    }
};

////////////////////////////////////////////////////////////////////////////////////////
// [121] Best Time to Buy and Sell Stock 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    
        int local_max = 0; 
        int global_max = 0;
        int min_price = INT_MAX;
        
        for(int i = 0; i < prices.size(); i++)
        {
            // If current price is less than minimum, update minimum 
            if(prices[i] < min_price) min_price = prices[i]; 
            local_max = max(local_max, prices[i]- min_price);
            global_max = max(local_max, global_max);
        }
        
        return global_max;     
    }
};


///////////////////////////////////////////////////////////////////////////////////////////
// [63] Unique Paths II 

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGridOld) {
       
        int num_rows = obstacleGridOld.size();
        int num_cols = obstacleGridOld[0].size(); 
        
        vector<vector<long>> obstacleGrid(num_rows, vector<long>(num_cols, 0)); 
        
        for(int r=0; r < num_rows; r++)
        {
            for(int c = 0; c < num_cols; c++)
            {
                obstacleGrid[r][c]= obstacleGridOld[r][c]; 
            }
        }
        
        // Key step. Convert the grid of obstacles into a matrix which has path infomration 
        // Obstacle at 0,0. Hence, there is no way for us to traverse 
        if(obstacleGrid[0][0]) return 0; 
        // One way to traverse 
        obstacleGrid[0][0] = 1;
        
        // Set obstacles to 0. If any obstacle comes in the path, the whole row/ column after that becomes 0 (aka it does not contribute to the final path)
        
        // First column . Making actual obstacles 
        for(int r = 1; r < num_rows; r++)
        {
            if(obstacleGrid[r][0] == 1) obstacleGrid[r][0] = 0;
            else obstacleGrid[r][0] = obstacleGrid[r-1][0]; 
        }

        // First Row: Making actual obstacles 
        for(int c = 1; c < num_cols; c++)
        {
            if(obstacleGrid[0][c] == 1) obstacleGrid[0][c] = 0;
            else obstacleGrid[0][c] = obstacleGrid[0][c-1]; 
        }
        
        for(int r = 1; r < num_rows; r++)
        {
            for(int c= 1; c < num_cols; c++)
            {
                // If the current grid value is not an obstacle 
                if(obstacleGrid[r][c]!= 1) obstacleGrid[r][c] = obstacleGrid[r-1][c]+ obstacleGrid[r][c-1];
                else obstacleGrid[r][c]= 0; 
            }
        }
        
        
        return (obstacleGrid[num_rows-1][num_cols-1]);
        
    }
};


/////////////////////////////////////////////////////////////////////////////////////////////
// [62] Unique Paths 

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        // Create an m x n grid. Fill the top row and bottom column with 1 
        // Keep adding and solving till you reach your end goal 
        
        // Create an n x m grid of zeros 
        vector<vector<int>> grid(n, vector<int>(m, 0)); 
        
        // Fill the top row and bottom column with 0s 
        int r = 0; 
        for(int c = 0; c < m; c++)
        {
            grid[r][c] = 1; 
        }
        
        int c = 0; 
        for(int r = 0; r < n; r++)
        {
            grid[r][c] = 1; 
        }
                
        for(int r = 1; r < n; r++)
        {
            for(int c = 1; c< m; c++)
            {
                grid[r][c]= grid[r-1][c] + grid[r][c-1]; 
            }
        }       
        
        return (grid[n-1][m-1]); 
    }
};


////////////////////////////////////////////////////////////////////////////////////////////
// [70] Climbing stairs (Using memoization)
/* This method can be thought of as thinking in reverse. If we have already computed result for a position before, we just return the result. The result is incrementally added. As we recursively get out, we are at pos = 0, in the last return call and that has the value of how many possible paths are there 
*/

    // int numWaysClimb(int pos, int n, vector<bool>& isPosVec)
    int numWaysClimb(int pos, int n, vector<int>& memo)
    {
        if(pos == n)  return 1;
        else if (pos > n) return 0; 
        
        // If we have already computed result. Return the pre-computed result 
        if(memo[pos] > 0) return memo[pos];
        
        memo[pos] = numWaysClimb(pos+1, n, memo) + numWaysClimb(pos+2, n, memo);
        
        return memo[pos]; 
    }
    
    
    
    
    int climbStairs(int n) {
        
        vector<int> memo(n+1, 0);
        int ans= numWaysClimb(0, n, memo);
        return ans;
    }
};

// [70] Climb stairs  (Using DP)

    // Dynamic programming based method (bottom up) 
    int climbStairs(int n) {
        
        if(n ==1) return 1; 
        
        // Key part of the solution. We know how many ways are to reach step 1 and step 2 
        vector<int> dp(n+1, 0);
        // We can reach step 1 in only one way 
        dp[1] = 1;
        // We can reach step 2 in two ways 
        dp[2] = 2; 
        
        
        for(int i=3; i<=n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2]; 
        }
        
        return dp[n]; 
    }
};

//////////////////////////////////////////////////////////////////////////////////
// [152] Max product subarray 

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int current_max = 1;
        int current_min = 1;
        int prev_max = 1;
        int prev_min = 1;
        
        int maximum = INT_MIN; 
        
        for(int curr: nums)
        {
           // Maintain a current max. Which uses the prev_max and prev_min
           // Reason we keep both max and min is that it can also be that the prev. min was -ve and multiplication leads to a positive number 
            current_max = max(curr, max(curr*prev_max, curr* prev_min));
            current_min = min(curr, min(curr*prev_max, curr* prev_min));
            
            // Update the global max 
            maximum = max(current_max, maximum);
            // Update previous max and previous minimum to be used for the next loop 
            prev_max = current_max;
            prev_min = current_min;             
            
        }
        
        
        return maximum; 
    }
};



////////////////////////////////////////////////////////////////////////////////////////
// [300] Longest increasing subsequence 

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        if(nums.empty()) return 0; 
        
        // Ans of longest consecutive susequence from this given index 
        unordered_map<int, int> umap; 
        // Insert the last element into the map 
        umap.insert({nums.size()-1, 1});
        // Store the current index which has max length  
        int currMaxIdx = nums.size()-1; 
        // Stores max Length which will be returned as answer 
        int maxLen = 1; 
        
        for(int i = nums.size()-2; i>= 0; i--)
        {
            // Max amount which can be added in the j loop 
            int max_add_len = 0; 

            for(int j = i+1; j< nums.size(); j++)
            {
                // Amount added for the current j 
                int curr_add_len = 0;                 
                // If we have reached an index which has maxLen till now, we put its length to max_add_len and break. we don't need to go any ahead. 
                
                if(nums[i] < nums[j])
                {
                  if(j == currMaxIdx)  
                  {
                    max_add_len = umap[j];
                    break;                       
                   }
                    else
                    {
                    curr_add_len = umap[j];
                    max_add_len = max(curr_add_len, max_add_len);                         
                    }
                }
            }
            
            // Current length is the length of max subsequence 
            int currLen = max_add_len + 1; 
            // Add for storing in the map 
            umap.insert({i, currLen});
            // If the new length we found is max, update currMaxIdx and currLen          
             if(currLen >= maxLen)
             {
                 // Update maxlen 
                 maxLen= max(currLen, maxLen); 
                 currMaxIdx = i; 
             }
        }
        
        return maxLen; 
     }
};
    


////////////////////////////////////////////////////////////////////////////////////////////
// [128] Longest consecutive subsequence 

class Solution {
public:

    int maxLenSeq = 0; 
    int lenSeq = 1; 
        
    void recurNeg(int currElem, unordered_set<int>& s)
    {
        // If set is empty, return 
        if(s.empty()) return; 
        // Find if current element exists 
        auto it = s.find(currElem);
        // If element not found, return 
        if(it == s.end()) return; 
        else 
        {
            lenSeq++;
            //cout << "Erasing: "<< currElem << endl; 
            s.erase(currElem);
        }
        
        recurNeg(currElem-1, s);
        return; 
    }
    
    void recurPos(int currElem, unordered_set<int>& s)
    {
        // If set is empty, return 
        if(s.empty()) return; 
        // Find if current element exists 
        auto it = s.find(currElem);
        // If element not found, return 
        if(it == s.end()) return; 
        else 
        {
            lenSeq++;
            //cout << "Erasing: "<< currElem << endl; 
            s.erase(currElem);
        }
        
        recurPos(currElem+1, s);
        return; 
    }
    
    
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.empty()) return 0; 
        
        unordered_set<int> s; 
        
        // Insert all the elements into a set 
        for(int i: nums) s.insert(i);

        // Iterate through the entire set 
        auto it= s.begin(); 
        // Initialize current element to first element 
        int currElem = *it; 
        
        //cout << currElem << endl; 
        
        while(!s.empty() && it!=s.end())
        {    
            // Check in negative direction, check in positive direction 
            recurPos(currElem+1, s);
            recurNeg(currElem-1, s);
            
            //cout << "Done with recursions" << endl; 
            
            // Update maxLenSeq
            maxLenSeq = max(maxLenSeq, lenSeq);
            // Set lenSeq to 0 
            lenSeq = 1; 
            // Remove current element from set 
            s.erase(currElem);
            //cout << "Erasing: "<< currElem << endl; 
            // Go to next element 
            it= s.begin();
            if(it == s.end()) break; 
            else currElem = *it; 
            
            //cout << "Size of set: " << s.size() << endl; 
        }
        
        return maxLenSeq; 
    }
};


