////////////////////////////////////////////////////////////////
// [21] Merge two sorted lists 
class Solution {
public:
    
    ListNode* compareNodes(ListNode* temp1, ListNode* temp2)
    {
        if(temp1->val > temp2->val)
        {
            return temp2;
        }
        
        else
        {
            return temp1;
        }
        
        return temp1; 
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* head= NULL; 
        
        // If both are NULL, return NULL 
        if(l1== NULL && l2== NULL)
        {
            return NULL; 
        }
        
        if(l1== NULL && l2!= NULL)
        {
            head= l2; 
            l2= l2->next; 
        }
        
        if(l1!= NULL && l2== NULL)
        {
            head= l1; 
            l1= l1->next; 
        }  
        
        if(l1!= NULL && l2!= NULL)
        {
            head= compareNodes(l1, l2);
            if(l1== head && l1!= NULL)
            {
                l1= l1->next; 
            }

            else if(l2== head && l2!= NULL)
            {
                l2= l2->next; 
            }
        }
        
        auto temp= head; 
        auto tempHead= temp; 
        
        while(l1!= NULL || l2!= NULL)
        {
            
            if(l1!= NULL && l2!=NULL)
            {
                
                temp->next= compareNodes(l1, l2);
                
                if(l1== temp->next)
                {
                    l1= l1->next; 
                }

                else if(l2= temp->next)
                {
                    l2= l2->next; 
                }                
                
                temp= temp->next; 
            }
            
            else if(l1== NULL && l2!= NULL)
            {
                temp->next= l2;
                l2= l2->next; 
                temp= temp->next; 
            }
            
            else if(l1!= NULL && l2== NULL)
            {
                temp->next= l1;
                l1= l1->next; 
                temp= temp->next; 
            }            
        }
        
        return tempHead; 
        
    }
};


///////////////////////////////////////////////////////////
[23] Merge K sorted Lists 


public:
    
    // The reason we had to use first ind and stuff was because we had to loop through the whole thing for comparison 
    int findMinIndexTraditional(vector<ListNode*>& lists)
    {
        // Store index to first non NULL element 
        int firstInd = -1;
        // Store index to minimum element 
        int minInd = -1; 
        
        for(int i=0; i<lists.size(); i++)
        {
            // If node is NULL, we can't use for comparison 
            if(lists[i] == NULL) continue; 
            
            // If node is not NULL check 
            else
            {
                // This is not our first valid element
                if (firstInd!= -1)
                {
                    // Update minInd as we have found a smaller element 
                    if(lists[i]->val < lists[minInd]->val) minInd = i; 
                    else continue; 
                }
                
                // This the first valid element we have found 
                else 
                {
                    firstInd = i;
                    minInd = i; 
                    continue; 
                }
            }
        }
        return minInd; 
    }
    
//     // Using priority queues 
//     int findMinIndexFast(vector<ListNode*>& lists, priority_queue<pi, vector<pi>, greater<pi> > &pq)
//     {
        
//         int i=0; 
//         // Store index to first non NULL element 
//         int firstInd = -1;
//         int minInd = -1; 
        
//         for(auto node:lists)
//         {
//           // If list is valid 
//           if(node) 
//           {
//               firstInd = i; 
//               minInd = i; 
//               pq.push(make_pair(node->val, i)); 
//           }
//           i++; 
//         }
        
//         if(minInd == -1); 
//         else minInd = pq.top().second; 
//         return minInd; 
//     }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        
        //typedef pair<int, int> pi; 
        //priority_queue<pi, vector<pi>, greater<pi> > pq; 
        
        
        // Set head of list 
        int head_ind = findMinIndexTraditional(lists);
        
        // All lists are NULL 
        if(head_ind == -1) return NULL; 
        
        // Set head to the given pointer, store temporary head 
        auto head= lists[head_ind]; 
        auto temp= head; 
        
        // Update chosen pointer to next inside list 
        lists[head_ind]= lists[head_ind]->next; 
        
        int temp_ind = -1; 
        
        while(temp!= NULL)
        {
            // Find min Ind from vector of lists 
            temp_ind = findMinIndexTraditional(lists); 
            // All pointer have become NULL, we need to exit
            if(temp_ind == -1)
            {
                temp = NULL;
                continue; 
            }
            
            else
            {
                // Update temp 
                temp->next = lists[temp_ind]; 
                // Update chosen pointer to next inside list 
                lists[temp_ind]= lists[temp_ind]->next; 
                // Move temp to new location 
                temp = temp->next; 
            }
            
        }
        
        return head; 
    }
};


//////////////////////////////////////////////////////////////////
// [189] Rotate an array 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        // If size of array if 1, return it back 
        if(nums.size() == 1) return; 
        
        // Initialize a vector of zeros 
        vector<int> rot_nums(nums.size(), 0);
                
        for(int i=0; i< nums.size(); i++)
        {
            rot_nums[(i+k) % nums.size()]= nums[i];
        }
        
        for(int i=0; i<nums.size(); i++)
        {
            nums[i]= rot_nums[i];
        }        
        
        return; 
    }
    
};


//////////////////////////////////////////////////
// [69] Sqrt of x

    int mySqrt(int x) {
        long int start = 1; 
        long int end = x; 
        long int mid = 0; 
        
        long int ans = 0; 
        
        while(start<= end)
        {
            mid = (start+ end)/2;
            
            if(mid*mid == x) return mid;
            
            else
            {
                // We need to go on the left side of mid 
                if(mid*mid > x) 
                {
                    end= mid-1;
                }
                // We need to go on right side 
                if(mid* mid < x) 
                {
                    start = mid+1;
                    ans= mid; 

                }
            }
        }
        
        return ans; 

////////////////////////////////////////////
// [704] Binary search 

    int search(vector<int>& nums, int target) {
        
        int start_ind = 0; 
        int end_ind = nums.size()-1;
        int mid_ind = 0; 
        
        while(start_ind <= end_ind)
        {
            // Find middle index 
            mid_ind = (start_ind + end_ind)/2;
            if(nums[mid_ind]== target) return mid_ind;
            // Move to right 
            else if(nums[mid_ind]> target) end_ind= mid_ind-1; 
            // Move to left 
            else if(nums[mid_ind] < target) start_ind= mid_ind+1; 
        }
        
        return -1; 
    }

/////////////////////////////////
// [702] Search in a sorted array with no end 

// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        
        int left =0;
        int right = 1;
        
        // While the right is less than target, keep moving the right 
        while(reader.get(right) < target)
        {
            left= right; 
            right= right << 1;
            if(reader.get(right) == target) return right;
            else if(reader.get(left) == target) return left; 
        }
        
        // Perform binary search to get target 
        int mid = 0; 
        while(left<= right)
        {
            //mid= (right+ left)/2
            mid = left + ((right- left) >> 1);
            
            if(reader.get(mid)== target) return mid;
            else if(reader.get(mid)< target) left= mid+1;
            else if(reader.get(mid)> target) right = mid-1; 
        }
        
        return -1;         
  }
};

////////////////////////////////////////////
// [33] Search in Rotated Sorted Array 

    int search(vector<int>& vec, int target) {
        int start =0; 
        int end= vec.size()-1; 
        int mid = 0; 
         
        while(start<= end)
        {
            mid= (start+ end)/2;
            if(target == vec[mid]) return mid; 
            // Right side is sorted 
            if(vec[end]> vec[mid])
            {
                if(target> vec[mid] && target<= vec[end]) start = mid+1;
                else end= mid-1; 
            }
            // Left side is sorted 
            else
            {
                if(target >= vec[start] && target< vec[mid]) end= mid-1; 
                else start = mid+1; 
            }
        }
        
        return -1; 
    }
//////////////////////////////////////////////////
// [49] Group anagrams

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    
        vector<vector<string>> ans; 
        unordered_map<string, vector<string>> m;  
        
        for (const auto s:strs)
        {
            // Create a temporary string 
            string t= s;
            // Sort the string
            sort(t.begin(), t.end());
            // Push the string into a map 
            m[t].push_back(s);
        }
        // Push answer into the map         
        for(auto x: m) ans.push_back(x.second);
        return ans;  
    }

};

////////////////////////////////////////////////////
// [74] Search a 2D matrix 

class Solution {
public:
    
    inline int getRowInd(int i, int num_cols) 
    {
        return (i / num_cols);
    }
    inline int getColInd(int i, int num_cols)
    {
        return (i % num_cols);
    }
      
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = 0;
        if(matrix.size() == 0) return false; 
        
        // If we flatten the matrix, what will be the last index
        int num_cols = matrix[0].size();
        int num_rows = matrix.size();       
        
        int end = (num_rows * num_cols) - 1; 
        int mid = 0;
        int mid_val = 0;
        
        while(start<= end)
        {
            // Calculate mid for binary search 
            mid = (end+ start) / 2 ;
            mid_val = matrix[getRowInd(mid, num_cols)][getColInd(mid, num_cols)];
            if( mid_val == target) return true;
            // Move right 
            else if(mid_val > target) end = mid - 1;
            // Move left 
            else if(mid_val < target) start = mid + 1;  
        }
        
        return false; 
    }
};

////////////////////////////////////////////////////////////
// [240] Search a 2D matrix II

class Solution {
public:
    

//     inline int getRowInd(int i, int num_cols) 
//     {
//         return (i / num_cols);
//     }
    
//     inline int getColInd(int i, int num_cols)
//     {
//         return (i % num_cols);
//     }
    
    // inline int getLinearInd(int r, int c, int num_cols)
    // {
    //     return (r*num_cols) + c; 
    // }
      
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // Case for empty matrix 
        if(matrix.size() ==  0 || matrix[0].size() == 0) return false; 
        
        int num_rows = matrix.size(); 
        int num_cols = matrix[0].size(); 
        
        // Index from which we start search
        int q_row = num_rows -1; 
        int q_col = 0; 
        int q_val = matrix[q_row][q_col];
        // int q_ind = getLinearInd(start_row, start_col, num_cols); 
           
        while(q_row >= 0 && q_col <= num_cols - 1)
        {
            q_val = matrix[q_row][q_col]; 
            // If target has been found 
            if(q_val == target) return true;
            // Move up 
            else if(target < q_val) q_row--; 
            // Move right 
            else if(target > q_val) q_col++; 
        }
        
        return false; 
    }
};

//////////////////////////////////////////////////////////////////////
// [867] Transpose of a matrix 

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int num_rows = A.size();
        int num_cols = A[0].size(); 
        
        // If matrix is square, we have a faster routine where we can just exchange 
        bool isSquare = num_rows == num_cols; 
        
        if (isSquare)
        {
            for(int i = 0; i < num_rows; i++)
            {
                for (int j = i+1; j < num_cols; j++)
                {
                    swap(A[j][i], A[i][j]);
                }
            }  
            
            return A; 
        }

        
        vector<vector<int>> A_trans(num_cols, vector<int> (num_rows));

        for(int i=0; i< num_rows; i++)
        {
            for( int j=0; j < num_cols; j++)
            {
                A_trans[j][i] = A[i][j];
            }
        }
        
        return A_trans; 
    }
};


//////////////////////////////////////////////////////////////////////////
// [566] Reshape a matrix 

class Solution {
public:
    
    inline int getRowInd(int i, int num_cols)
    {
        return (i / num_cols); 
    }
    
    inline int getColInd(int i, int num_cols)
    {
        return (i % num_cols ); 
    }
    
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
               
        
        int num_rows_old = nums.size(); 
        int num_cols_old = nums[0].size();
            
        // Check for cases where the reshape is not possible 
        if(nums[0].size() * nums.size()!= r * c) return nums; 
        
        // Create an empty matrix 
        vector<vector<int>> ans(r, vector<int> (c));
        
        for(int i=0; i< num_rows_old * num_cols_old; i++)  ans[getRowInd(i, c)][getColInd(i, c)] =  nums[getRowInd(i,num_cols_old)][getColInd(i, num_cols_old)];      
        
        return ans; 
    }
};


//////////////////////////////////////////////////////////////////////////////

// [n] Normal matrix multiplication 

for(int i = 0; i< num_rows_in_mat_1; i++)
   for(int j=0; j< num_cols_in_mat_1; j++)
      for(int k=0; k< num_rows_in_mat_2; k++)
	{
            ans[i][j]+= A[i][k] * B[k][j];	
	}



/////////////////////////////////////////////////////////////////////////////////
// [311] Sparse matrix multiplication 

class Solution {
public:
    
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;  
    }
};
    
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
            
        // Loop through all elements of A and insert into an unordered map 
        unordered_map<pair<int,int>, int, pair_hash> mapA; 
        
        for(int i=0; i< A.size(); i++)
        {
            for(int j=0; j < A[0].size(); j++)
            {
                if(A[i][j]!=0) mapA.insert({make_pair(i,j), A[i][j]}); 
            }
        }
        
        // Loop through all elements of B and insert into an unordered map 
        unordered_map<pair<int,int>, int, pair_hash> mapB;     
        
        for(int i=0; i< B.size(); i++)
        {
            for(int j=0; j < B[0].size(); j++)
            {
                if(B[i][j]!=0) mapB.insert({make_pair(i,j), B[i][j]}); 
            }
        }
        
        vector<vector<int>> ans(A.size(), vector<int> (B[0].size()));
        
        for(auto x: mapA)
        {
            for(auto y: mapB)
            {
                if(x.first.second == y.first.first)
                {
                    ans[x.first.first][y.first.second]+= x.second * y.second; 
                }
            }
        }
        
        return ans; 
        }
};

///////////////////////////////////////////////////////////////////////////
// [867] Transpose of a matrix 

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int num_rows = A.size();
        int num_cols = A[0].size(); 
        
        // If matrix is square, we have a faster routine where we can just exchange 
        bool isSquare = num_rows == num_cols; 
        
        if (isSquare)
        {
            for(int i = 0; i < num_rows; i++)
            {
                for (int j = i+1; j < num_cols; j++)
                {
                    swap(A[j][i], A[i][j]);
                }
            }  
            
            return A; 
        }

        
        vector<vector<int>> A_trans(num_cols, vector<int> (num_rows));

        for(int i=0; i< num_rows; i++)
        {
            for( int j=0; j < num_cols; j++)
            {
                A_trans[j][i] = A[i][j];
            }
        }
        
        return A_trans; 
    }
};

///////////////////////////////////////////////////////////////////////////////////
// [56] Merge Intervals 

class Solution {
public:
    
    bool isNoOverlap(vector<int>& vec1, vector<int>& vec2)
    {
//         // x1< = y2 && y1 <= x2  
        return (vec1[0] < vec2[1] && vec1[1]< vec2[0]); 
    }
    
    vector<int> mergeLoc(vector<int>& vec1, vector<int>& vec2)
    {
        vector<int> vec;
        vec.push_back(min(vec1[0], vec2[0]));
        vec.push_back(max(vec1[1], vec2[1]));
        return vec; 
    }
    
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
        if(intervals.size() == 0) return ans; 
        
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& vec1, const vector<int>& vec2)
             {
              return (vec1[0] < vec2[0]);   
             });
        
        auto temp = intervals[0];
        
        int start = 0;
        int end = 1; 
        int i = 1;
        
        
        while(i < intervals.size())
        {
            // Check if temp and i are overlapping
            // If yes, find merged interval, store it in temp; i++
            if(!isNoOverlap(temp, intervals[i]))
            {
                temp = mergeLoc(temp, intervals[i]); 
                i++; 
            }
            
            else
            {
                // Push current temp to answer
                ans.push_back(temp);
                temp.clear(); 
                temp = intervals[i];
                i++; 
            }
        }
        
        if(!temp.empty()) ans.push_back(temp); 
        
        return ans; 
                
    }
};



/* Trial 1: Using while loop

        
        
        
// for(int idx = 1; idx< intervals.size()-1; idx++)
// {       
//     // If there is overlap between idx and idx + 1, keep merging till no ovelap exists 
//     if(!isNoOverlap(temp, intervals[idx]))
//        {
//             while(!isNoOverlap(temp, intervals[idx]) && idx< intervals.size()-1)
//             {
//               start = temp[0]; 
//               temp.clear();
//               temp.push_back(start);
//               temp.push_back(intervals[idx][1]);
//               ans.push_back(temp); 
//               idx++; 
//             } 
//         cout << idx << endl; 
//         temp =  intervals[idx]; 
//         }
//     else
//       {
//         // No overlap betwen temp and next
//         ans.push_back(temp);  
//     } 
// }



*/


////////////////////////////////////////////////////////////////////////////
// [190] Reverse bits 

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        std::bitset<32> foo;
        for(int i=0; i<32; i++) foo.set(31-i, ((n & ( 1 << i )) >> i));         
        return (int)(foo.to_ulong());         
    }
};

/////////////////////////////////////////////////////////////////////////////
// [268] Missing number 

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = ((nums.size())*(nums.size() + 1))/2;
        for(auto i: nums) sum-= i;
        return sum;   
    }
};

///////////////////////////////////////////////////////////////////////////////
// [435] Non overlapping intervals 

class Solution {
public:
    
    bool isNoOverlap(int idx1, int idx2, vector<vector<int>>& intervals)
    {
        return (intervals[idx1][0] <=intervals[idx2][1] &&  intervals[idx1][1] <= intervals[idx2][0]); 
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        if(intervals.size() == 0) return 0; 
        if(intervals.size() == 1) return 0; 

        // Sort the vector of vectors according to the first element 
        sort(intervals.begin(), intervals.end(), [] (const vector<int>& vec1, const vector<int>& vec2){  
        return vec1[0] < vec2[0]; 
        });
        
        int prev = 0; 
        int num_changes = 0; 
        
        for(int i= 1; i<intervals.size(); i++)
        {
            if(!isNoOverlap(prev, i, intervals))
            {
                num_changes ++; 
                if(intervals[prev][1] > intervals[i][1])  prev = i;    
            }
            
            else prev = i; 
        }
    
        return num_changes; 
    }
};

/////////////////////////////////////////////////////////////////////////////////////
//  [912] Sort an array 


    /*
    Bubble sort: Most naive algorithm. 
    After end of each loop, the max value in the array reaches the end. 
    Hence, every time, we need to go 1 less time. 
    Core logic: if (nums[j-1] > nums[j]) swap them. 
    Time complexity: O(n*n)
    */
    vector<int> bubbleSort(vector<int>& nums)
    {
        for(int i= nums.size()-1; i>=0; i--)
        {
            for(int j=1; j<=i; j++)
            {
                if(nums[j-1] > nums[j]) 
                {
                    swap(nums[j], nums[j-1]);
                }
            }
            
        }
        return nums; 
    }
    
    /* Selection sort 
    Core logic: Initialize the min index to i. Loop from j = i+1 to end. If arr[j] < arr[min], store the new minIndex as j. At the end of the j loop, swap the value at min index with the value at ith index. Do this repeatedly. 
    Time complexity: O(n*n)
    */

    vector<int> selectionSort(vector<int>& nums){
        int minInd = 0; 
        for(int i=0; i< nums.size(); i++)
        {
            minInd = i;
            for(int j= i+1; j< nums.size(); j++)
            {
               // Update min if arr[j] < min
               if(nums[j] < nums[minInd]) minInd = j;
            }
            swap(nums[i], nums[minInd]);
        }
        return nums; 
    }


    /*
    Insertion sort: Key steps
     Start loop from 0 + 1. For each value, i, store the value at that point in a temporary variable. Do j = i. Check if the previous value aka temp < nums[j-1]. If yes, we need to overwrite nums[j] with nums[j-1]. Then we go one index behind. At the end of the while loop, we reach at the index, where we need to place temp.

	Average case:
	Best case: (bounds for 2 to n)=  (n-2) + 1 = n-1 comparisons, 1+ (n-1)*2 moves = 2n-1 moves   
	Worst case: (n+2((n-1)/2 comparisons, (n*n)+ 3(n) -2 / 2  moves

  
     */    
    vector<int> insertionSort(vector<int>& nums){

        for(int i=1; i<nums.size(); i++)
        {
            int temp = nums[i];
            int j = i; 
            // Using j > 0 allows us to use array indexed at 0 without setting nums[0] to INT_MIN
            while(j > 0 && temp < nums[j-1])
            {
                nums[j] = nums[j-1];
                j--;
            }
            // At the point we exit 
            nums[j] = temp; 
        }
    
        return nums; 
    }
   
////////////////////////////////////////////////
// [242] Valid anagrams 
    
    bool areAnagrams(int ind1, int ind2, vector<string>& strs)
    {
        string s1= strs[ind1];
        string s2= strs[ind2];
        
        // Check if the given two strings are anagrams 
        if(s1.length()!= s2.length()) return false; 
        // Create a table of size 26,0 
        vector<int> table(26,0);
        // Increment the value in table for one string, decrement for another 
        for(int i=0; i<s1.length(); i++)
        {
            table[s1[i]-'a'] = table[s1[i]-'a'] +1;
            // Decrement value for second string
            table[s2[i]-'a']= table[s2[i]-'a']-1;
        }
        
        for(int i=0; i<table.size(); i++)
        {
            if(table[i]!=0) return false; 
        }
        
        return true;
    }

////////////////////////////////////////////////////////
// [867] Middle of Linked List 

    ListNode* middleNode(ListNode* head) {
        
        auto fast = head;
        auto slow = head; 
        
        while(fast!= NULL && fast->next!= NULL)
        {
            fast = fast->next->next;
            slow = slow->next; 
        }
        
        return slow; 
                
    }

/////////////////////////////////////////////////////////
// [109] Sorted List to BST 

class Solution {
public:
    
    ListNode* findMid(ListNode* head)
    {
        // The prev pointer will be one behind the slow pointer and will be used to disconnect the LL 
        ListNode* fast = head;
        ListNode* slow = head; 
        ListNode* prev = NULL; 
        // Core code to find middle of LL 
        while(fast!= NULL && fast->next!= NULL)
        {
            prev = slow; 
            fast = fast->next->next;
            slow = slow->next;
        }
        // Used to disconnect the linked list 
        if(prev!= NULL) prev->next = NULL; 
        return slow; 
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        if(head == NULL) return NULL; 
        // Find middle of linked list 
        ListNode* mid = findMid(head); 
        // Initialize the root using mid 
        TreeNode* root = new TreeNode(mid->val); 
        // Base case 
        if(mid == head) return root;
        root->left = sortedListToBST(head);
        // In cases where mid->next does not exist, we get NULL 
        root->right = sortedListToBST(mid->next); 
        return root; 
    }
};


///////////////////////////////////////////////////////////////////
// [190] Reverse bits 
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        std::bitset<32> foo;
        for(int i=0; i<32; i++) foo.set(31-i, ((n & ( 1 << i )) >> i));         
        return (int)(foo.to_ulong());         
    }
};


/////////////////////////////////////////////////////////////////////
// [191] Number of 1 bits 

class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int num = 0; 
        for(int i = 0; i< 32; i++)
        {
            if( ((n & (1 << i)) >> i) == 1) num++; 
        }
        
        return num; 
    }
};

////////////////////////////////////////////////////////////////
// [371] Sum of two integers


class Solution {
public:
    int getSum(int a, int b) {
    if (b==0) return a;
        int sum = a^b; // finding the sum
        int carry = (unsigned int)(a & b)<<1; // finding the carry
        return getSum(sum, carry);
    }
};
        

////////////////////////////////////////////////////////////////////////
// [153] Find minimum in rotated sorted array 

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        if (nums.size() == 1) return nums[0]; 
        
        int start = 0;
        int end = nums.size()-1;
        int mid = 0; 
        
        // If the array is already sorted with no rotations 
        if(nums[start] < nums[end]) return nums[start];
        
        while(start < end)
        {
           mid = (start + end) / 2; 
            // Searching for inflection point 
            if(nums[mid] > nums[mid+1]) return nums[mid+1];
            if (nums[mid-1] > nums[mid]) return nums[mid];
           // Find sorted side
           // If Left side is sorted, go right 
               if(nums[mid] > nums[start]) start = mid + 1;  
            // If Right side is sorted, go left 
                else  end = mid - 1;                     
        }
        
        return nums[start]; 

    }
};

///////////////////////////////////////////////////////////////////////////
// [15] 3Sum 

class Solution {
public:
    struct VectorHash {
        size_t operator()(const std::vector<int>& v) const {
            std::hash<int> hasher;
            size_t seed = 0;
            for (int i : v) {
                seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            }
            return seed;
        }
    };  
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans; 
        unordered_set<vector<int>, VectorHash> s;
        
        // Naive case
        if(nums.empty()) return ans;  
        else if(nums.size() < 3) return ans;
        
        
        vector<int> temp; 
        
        // Sort the array 
        sort(nums.begin(), nums.end());
        
        // If no negative numbers exist, we cannot 
        if(nums[0] == 0) return ans; 
        
        int j = 0;
        int k = 0;
        
        int prev = 0;
        int sum = 0; 
        
        for(int i=0; i< nums.size(); i++)
        {
            // If we have already found a solution for this number, we don't wanna do it again 
            if(i> 0 && nums[i] == prev) continue; 
            
            // Initializing two other pointers 
            j = i+1; 
            k = nums.size()-1;
            
            // Initializing sum to the current ith number 
            sum+= nums[i]; 
            
            while(j< k)
            {                
                if(sum+ nums[j] + nums[k] == 0)
                {
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    
                    if(s.find(temp)!= s.end()) temp.clear(); 
                    else
                    {
                        ans.push_back(temp);
                        s.insert(temp); 
                        temp.clear();   
                    }
                    
                    j++;
                    k--;                     
                }
                
                else if(sum + nums[j] + nums[k] < 0) j++;
                else if (sum + nums[j]+ nums[k] > 0) k--;

            }
            
            // Setting sum to 0 
            sum = 0; 
            // Updating the previous value for next step 
            prev = nums[i]; 
        }
        
        return ans;  
    }
};

///////////////////////////////////////////////////////////////////////////
//[Quicksort in Python]

def quicksort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quicksort(left) + middle + quicksort(right)

///////////////////////////////////////////////////////////////////////////
// [Quicksort in C++]

#include<bits/stdc++.h>
using namespace std;
int partition(int *a,int start,int end)
{
    int pivot=a[end];
    //P-index indicates the pivot value index
    
    int P_index=start;
    int i,t; //t is temporary variable
    
    //Here we will check if array value is 
    //less than pivot
    //then we will place it at left side
    //by swapping 
    
    for(i=start;i<end;i++)
    {
    	if(a[i]<=pivot)
        {
            t=a[i];
            a[i]=a[P_index];
            a[P_index]=t;
            P_index++;
        }
     }
     //Now exchanging value of
     //pivot and P-index
      t=a[end];
      a[end]=a[P_index];
      a[P_index]=t;
    
     //at last returning the pivot value index
     return P_index;
 }
 void Quicksort(int *a,int start,int end)
 {
	if(start<end)
	{
	     int P_index=partition(a,start,end);
             Quicksort(a,start,P_index-1);
             Quicksort(a,P_index+1,end);
	}
}
int main()
{
	int n;
        cout<<"Enter number of elements: ";
        cin>>n;
        int a[n];
        cout<<"Enter the array elements:\n";
        for(int i=0;i<n;i++)
       {
    	 cin>>a[i];
       }
      Quicksort(a,0,n-1);
      cout<<"After Quick Sort the array is:\n";
      for(int i=0;i<n;i++)
      {
    	 cout<<a[i]<<" ";
      }
	return 0;
}


///////////////////////////////////////////////////////////////////////////
// [973] Kth closest point to origin 

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        vector<vector<int>> ans; 
        typedef pair<float,int> pi; 
        // Define a min heap of pairs 
        priority_queue<pi, vector<pi>, greater<pi>>pq; 
        
        for(int i=0; i< points.size(); i++)
        {
            float dist = sqrt(pow(points[i][0],2) + pow(points[i][1],2));
            pq.push(make_pair(dist, i));
        }
        
        for(int k = 0; k < K; k ++)
        {
            auto temp = pq.top(); 
            ans.push_back(points[temp.second]); 
            pq.pop(); 
        }
        
        return ans; 
        
    }
};

///////////////////////////////////////////////////////////////////////////
// [206] Reverse Linked list 

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // zero nodes case 
        if(head == NULL) return head;
        // one node case 
        else if(head->next== NULL) return head; 
        
        // Initializing prev to NULL is important 
        ListNode* temp = head; 
        ListNode* prev = NULL;
        
        while(temp!=NULL)
        {
            // Store next ptr 
            auto nextPtr = temp->next; 
            // Perform reversal
            temp->next = prev;
            // Store previous ptr 
            prev= temp; 
            // Update temp to next 
            temp = nextPtr; 
        }
                
        return prev; 
    }
};

///////////////////////////////////////////////////////////////////////////
// [143] Reorder List 

class Solution {
public:
    void reorderList(ListNode* head) {
        
        if(head == NULL) return; 
        
        deque<ListNode*> dq;
        //stack<ListNode*> s;
        
        auto temp= head; 
        int list_size = 0; 
        
        // Store the values in a queue and a stack 
        while(temp!=NULL)
        {
            // Push to queue and stack 
            dq.push_back(temp); 
            temp = temp->next; 
            list_size ++; 
        }
        
        // head remains the same, hence it has to be removed from queue 
        dq.pop_front(); 
        list_size --; 
        
        temp = head; 

        while(list_size > 0)
        {
            temp->next = dq.back(); 
            dq.pop_back(); 
            temp= temp->next;
            list_size --; 
            
            if(list_size == 0) break; 

            temp->next = dq.front(); 
            dq.pop_front();
            temp= temp->next; 
            list_size --; 
        }
        
    temp->next = NULL;  
        
    }
};

///////////////////////////////////////////////////////////////////////////
// [19] Remove Nth node from end of list 

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head == NULL || head->next == NULL) return NULL; 
        
        // A dummy node is inserted before head to deal with edge cases. 
        ListNode* dummy = new ListNode(0);
        dummy->next = head; 
        
        // The fast pointer is n times faster than slow 
        auto fast = dummy;
        auto slow = dummy; 
        
        // As the fast pointer is initialized at dummy, we go till n+1 
        for(int i= 0; i< n+1; i++) fast = fast->next;   

        while(fast!= NULL)
        {
            slow = slow->next;
            fast = fast->next; 
        }
        
        // Because of slow starting at dummy, we end up one before the node we need to delete 
         slow->next = slow->next->next;
        
        return dummy->next; 
    }
};


////////////////////////////////////////////////////////////////////////////
// [378] Kth Smallest Element in Sorted Matrix 

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        // L = left most element , R= Rightmost element, if this matrix was flattened as an array 
        int mat_size = matrix.size(), l = matrix[0][0], r = matrix[mat_size-1][mat_size-1];
        while(l < r)
        {
            // Start off from 0th index 
            // We are making a guess that the value m could be our required value
            int idx = 0, mid = (l+r)/2;
            // Loop through the whole matrix and find index of first element bigger than mid
            for(int i = 0; i < mat_size; ++i) 
                idx += upper_bound(matrix[i].begin(), matrix[i].end(), mid)-matrix[i].begin();
        
            if(idx < k) l = mid+1;
            else r = mid;
        }
        return r;
    }
};
