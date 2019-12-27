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
