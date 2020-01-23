
///////////////////////////////////////////////////////////////////////////////////////
//[104] Max Depth of binary tree  

    int maxLevel= 1;     
    int inOrderTraversal(TreeNode* temp, int level)
    {
        if(temp == NULL) return (level-1);         
	// At each step, find if the current level received is more than max or not ss
        maxLevel= max(maxLevel, inOrderTraversal(temp->left, level+1));
        maxLevel= max(maxLevel, inOrderTraversal(temp->right, level+1));
        return maxLevel; 
    }
    
    int maxDepth(TreeNode* root) {
        
        if(root == NULL) return 0;     
	// If just root
        if(root->left == NULL && root->right == NULL) return maxLevel; 
        int maxL=  inOrderTraversal(root, 1); 
        return maxL; 
    }


/////////////////////////////////////////////////////////////////////////////////////////
// [104] Find max depth of binary tree (compressed)
    int maxDepth(TreeNode* temp)
    {
        if(temp == NULL) return 0;
        return 1 + max(maxDepth(temp->left), maxDepth(temp->right)); 
    }

///////////////////////////////////////////////////////////////////////////////////////////////
//[110] Balanced Binary tree 

    int maxDepth(TreeNode* temp)
    {
        if(temp == NULL) return 0;          
        return 1 + max(maxDepth(temp->left), maxDepth(temp->right)); 
    }
  
    bool isBalanced(TreeNode* root) {
          
        if(root == NULL) return true; 
	// If difference between the max depth of left and right is more than 1, return false. 
         if(abs (maxDepth(root->left)- maxDepth(root->right)) > 1) return false; 
	 // Else, continue searching in the rest of the tree
         else return isBalanced(root->left) && isBalanced(root->right);
    }

///////////////////////////////////////////////////////////////////////////////////////////////

// [111] Minimum depth of binary tree 

    int minDepth_val= INT_MAX;
    
    int postOrderTrav(TreeNode* temp, int lvl)
    {
        if(lvl> minDepth_val || temp == NULL)  return (lvl-1);
        int level1= postOrderTrav(temp->left,  lvl+1);
        int level2= postOrderTrav(temp->right, lvl+1);
        // Only update at leaves 
        if(temp->left == NULL && temp->right == NULL) minDepth_val= min(minDepth_val, min(level1, level2));      
        return minDepth_val; 
    }
    
    int minDepth(TreeNode* root) {
        if(root ==  NULL)
        {
            return 0; 
        }
        
        if(root->left==  NULL && root->right == NULL)
        {
            return 1;
        }
        
        int minL= postOrderTrav(root, 1);
        
        return minL; 
///////////////////////////////////////////////////////////////////////////////////////////////
// [733] Flood Fill

class Solution {
public:
    
    int color= 0; 
    
    void dfs(vector<vector<int>> & image, int r, int c, int newColor)
    {        
        if(r < 0 || c < 0 || r == image.size() || c == image[0].size() || image[r][c] == newColor || image[r][c] != color) return;

        if(image[r][c]== color)
        {
            image[r][c]= newColor; 
        }

        dfs(image, r-1, c, newColor);
        dfs(image, r, c-1, newColor);
        dfs(image, r+1, c, newColor);
        dfs(image, r, c+1, newColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        color= image[sr][sc];    
        if(color!= newColor) dfs(image, sr, sc, newColor);      
        return image; 
    }
};


//////////////////////////////////////////////////////////////
// [617] Merge two binary trees 
class Solution {
public:
    
    // Recursive approach 
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        
        if(t1 == NULL) return t2;
        if(t2 == NULL) return t1; 
        
        t1->val+= t2->val; 
        t1->left= mergeTrees(t1->left, t2->left);
        t1->right= mergeTrees(t1->right, t2->right);
        
        return t1; 

        }
};


//////////////////////////////////////////////////////////////
// [637] Average of levels in BST 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> ans; 

        if(root == NULL) return ans; 
        
        queue<TreeNode*> q1;
        q1.push(root);
        q1.push(NULL);
        
        double sum = 0;
        int count = 0;
                
        while(!q1.empty())
        {
            auto node= q1.front(); 
            q1.pop();
            
 
            
            if(node!= NULL)
            {
                if(node->left!= NULL)  q1.push(node->left); 
                if(node->right!= NULL) q1.push(node->right);
                // Add node to sum and increase the node count by 1 
                sum+= node->val; 
                count++;
            }
            
            // We have reached end of level 
            else
            {
                // Add average to ans 
                ans.push_back(sum/count);
                sum = 0; 
                count = 0; 
                
                // We are the the last NULL node, don't add another null 
                if(q1.empty()) continue; 
                // Add another NULL to showcase end of level 
                else q1.push(NULL); 
            }
        }
        
        return ans; 
    }
};


//////////////////////////////////////////////////////////////
// [700] Search in BST 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* searchBST(TreeNode* root, int val) {
        
        
        if(root == NULL) return NULL; 
        if(root->val == val) return root; 
        if(val < root->val) 
        {
            auto node= searchBST(root->left, val);
            return node; 
        }
        
        else 
        {
            auto node= searchBST(root->right, val); 
            return node; 
        }        
        
    }
};


//////////////////////////////////////////////////////////////////////
// [501] Find mode in BST 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    unordered_map<int,int> m; 
    
    void inOrderTraversal(TreeNode* temp)
    {
        if(temp == NULL) return;
        
        inOrderTraversal(temp->left);
        
        auto it= m.find(temp->val);
        // Found element already in map 
        if(it!= m.end()) it->second+=1; 
        else
        {
            m.insert({temp->val, 1});
        }
        
        inOrderTraversal(temp->right);
        
        return ;
    }
    
    vector<int> findMode(TreeNode* root) {
        
        inOrderTraversal(root); 
        vector<int> ans; 

        // Check if map was empty 
        if(m.empty()) return ans; 
        
        // Max frequency  
        int max_val = 0; 
        for(auto it= m.begin(); it!= m.end(); it++)
        {
            if(it->second > max_val)
            {
                max_val= it->second; 
            }
        }
        
        // Loop through map and find all those keys which have max frequency 
        for(auto it= m.begin(); it!= m.end(); it++)
        {
            if(it->second == max_val)
            {
                ans.push_back(it->first);
            }
        }
                
        return ans;         
        
    }
};


//////////////////////////////////////////////////////////////////////
// [235] Lowest Common Ancestor in BST 
class Solution {
public:
    
    int p_val = 0;
    int q_val= 0; 
    
    TreeNode* lca_recur(TreeNode* temp)
    {
        if(temp == NULL) return temp; 
        // Explore left subtree
        if(p_val < temp->val && q_val < temp->val) return lca_recur(temp->left);
         // Explore right subtree
        else if(p_val > temp->val && q_val > temp->val) return lca_recur(temp->right);
        // We are at LCA, return it 
        else return temp; 
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        p_val = p->val; 
        q_val = q->val; 
        auto ans= lca_recur(root); 
        return ans; 
    }
};


/////////////////////////////////////////////////////////////////////////
// [530] Minimum absolute difference BST 

class Solution {
public:
  
    int val = -1;
    int min_diff = INT_MAX; 
    
    int getMinimumDifference(TreeNode* root) {
        // Recursively go to the left most (inordertrav)
        if(root->left!= NULL) getMinimumDifference(root->left);
        if(val>=0) min_diff = min(min_diff, abs(root->val - val));
        // Storing old values for comparison at next step 
        val= root->val; 
        if(root->right!= NULL) getMinimumDifference(root->right);
        return min_diff; 
    }
};

//////////////////////////////////////////////////////////////////////////
// [669] Trim BST 

class Solution {
public:
    
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        
        if(root == NULL) return root; 
        if(root->val > R) return trimBST(root->left, L, R);
        if(root->val < L) return trimBST(root->right, L, R);
        
        root->left= trimBST(root->left, L, R);
        root->right= trimBST(root->right, L, R);
                
        return root;   
    }
};

/////////////////////////////////////////////////////////////////////////
// [100] Same tree 

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && q) return false; 
        if(p && !q) return false; 
        if(!p && !q) return true; 
        if(p->val != q->val) return false; 
        
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right)); 
    }
};

//////////////////////////////////////////////////////////////////////////
// [572] Subtree of another tree 

class Solution {
public:
    
    bool ans = false; 
    
    bool isSameTree(TreeNode* t1, TreeNode* t2)
    {
        if(t1== NULL && t2 == NULL) return true;
        else if(t1!=NULL && t2== NULL) return false; 
        else if(t1==NULL && t2!= NULL) return false; 
        if(t1->val != t2->val) return false; 
        return (isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right)); 
    }
    
    

    bool inTrav(TreeNode* s, TreeNode* t)
    {
        if(s == NULL) return true; 
        if(ans == true) return true; 
        
        bool temp = inTrav(s->left, t);
        bool temp2= false; 
        
        if(s->val == t->val) temp2= isSameTree(s, t);         
        if(temp2) ans= true;
        temp = inTrav(s->right, t);
        
        return temp; 
        
    }
    
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
    
        bool temp= inTrav(s, t);
        return ans; 
    }
};

//////////////////////////////////////////////////////////////////////////////
// [105] Construct binary tree from preorder and inorder traversal 

class Solution {
public:
    
    int findInorderInd(int val, int start, int end, vector<int>& inorder)
    { 
        int ind = 0;
        for(int i= start; i <= end; i++)
        {
            if(val == inorder[i]) 
            {
                ind = i;
                break; 
            }
        }
        return ind; 
    }
    
    TreeNode* buildTreeRecur(vector<int>& preorder, vector<int>& inorder, int start, int end, int preorder_ind)
    {
        // Return NULL given an invalid condition 
        if(start > end) return NULL; 
        if(preorder_ind > preorder.size()-1) return NULL; 
        // Initialize the node given its preorder index 
        TreeNode* root= new TreeNode(preorder[preorder_ind]);
        // Find inorder index for the given value
        int inorder_ind = findInorderInd(preorder[preorder_ind], start, end, inorder);
        // Build left and right subtree 
        root->left = buildTreeRecur(preorder, inorder, start, inorder_ind-1, preorder_ind+1);
        root->right= buildTreeRecur(preorder, inorder, inorder_ind+1, end, preorder_ind + inorder_ind - start + 1); 
        return root; 
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if(preorder.size()!= inorder.size()) return NULL; 
        else if (preorder.size() == 0) return NULL; 
        int start = 0;
        int end = preorder.size()-1;
        int preorder_ind = 0; 
        // Build a tree 
        TreeNode* root = buildTreeRecur(preorder, inorder, start, end, preorder_ind); 
        return root; 
    }
};

///////////////////////////////////////////////////////////////
// [200] Number of islands unoptimized using unordered set 


class Solution {
public:

    struct pair_hash{
      
        template <class T1, class T2>
        std::size_t operator() (const std::pair<T1,T2> &p) const 
        {
            std::size_t h1 = std::hash<T1>{} (p.first);
            std::size_t h2 = std::hash<T2>{} (p.second);
            return h1 ^ h2; 
        }
    };
    
    void dfsMain(vector<vector<char>>& grid, unordered_set<pair<int, int>, pair_hash> &visited, 
             int row, int col, int num_rows, int num_cols)
    {
        
        // Insert pair to set 
        visited.insert(make_pair(row,col));
        
        if(row<0 || row> num_rows-1 || col<0 || col > num_cols - 1 || grid[row][col]!='1')
        {
            return;
        }
        
    
        if(visited.find(make_pair(row-1, col))== visited.end())
        {
            dfsMain(grid, visited, row-1,   col,   num_rows, num_cols); 
        }

        if(visited.find(make_pair(row, col-1))== visited.end())
        {
            dfsMain(grid, visited, row,   col-1, num_rows, num_cols);
            
        }
        
        if(visited.find(make_pair(row+1, col))== visited.end())
        {
            dfsMain(grid, visited, row+1, col, num_rows, num_cols);
            
        }
        
        if(visited.find(make_pair(row,   col+1))== visited.end())
        {
            dfsMain(grid, visited, row,   col+1, num_rows, num_cols);   
        }
        
        
        return; 
    }
    
    int numIslands(vector<vector<char>>& grid) {

        if(grid.empty())
        {
            return 0; 
        }
        
        int num_rows= grid.size();
        int num_cols= grid[0].size(); 
        

        
        // Store the pairs of [r,c] which are already visited 
        unordered_set<pair<int, int>, pair_hash> visited;
        
        
        int num_islands= 0; 
        
        for(int row=0; row <num_rows; row++)
        {
            for(int col=0; col <num_cols; col++)
            {
                // If not visited, do DFS, pass vistied by reference and change it 
                if(visited.find(make_pair(row,col))== visited.end() && grid[row][col]== '1')
                {
                    dfsMain(grid, visited, row,  col, num_rows, num_cols);
                    num_islands ++; 
                }
                
            }
        }
        
        return num_islands; 
        
        
    }
};


///////////////////////////////////////////////////////////////

// replace set with a vector of characters to be able to store visited or not 

// [200] Number of islands optimized

class Solution {
public:
   
void dfsMain(vector<vector<char>>& grid, vector<vector<int>> &visited, 
         int row, int col, int num_rows, int num_cols)
{

    if(row<0 || row> num_rows-1 || col<0 || col > num_cols - 1 || grid[row][col]!='1') return;

    // Insert pair to set
    visited[row][col] = 1; 
        
    // Left 
    if( row-1 >= 0 && visited[row-1][col]!= 1) dfsMain(grid, visited, row-1, col, num_rows, num_cols); 
    // Right 
    if(row + 1 <= num_rows-1 && visited[row+1][col]!= 1) dfsMain(grid, visited, row+1, col, num_rows, num_cols); 
    // Up 
    if(col-1 >= 0 && visited[row][col-1]!= 1) dfsMain(grid, visited, row, col-1, num_rows, num_cols);     
    //Down 
    if(col + 1 <= num_cols-1 && visited[row][col+1]!= 1) dfsMain(grid, visited, row, col+1, num_rows, num_cols); 

    return; 
}
    
int numIslands(vector<vector<char>>& grid) {

    if(grid.empty()) return 0; 

    int num_rows= grid.size();
    int num_cols= grid[0].size(); 
    
    vector<vector<int>> visited(num_rows, vector<int>(num_cols, 0)); 
    int num_islands= 0; 

    for(int row=0; row <num_rows; row++)
    {
        for(int col=0; col <num_cols; col++)
        {
            // If not visited, do DFS, pass vistied by reference and change it 
            if(visited[row][col] == 0 && grid[row][col] == '1')
            {
                dfsMain(grid, visited, row,  col, num_rows, num_cols);
                num_islands ++; 
            }

        }
    }

    return num_islands; 
}
};

/////////////////////////////////////////////////////////////////////////////////
// [695] Max area of island 
class Solution {
public:
    
    int currArea = 0; 
    int maxArea = 0; 
    
    void dfsMain(vector<vector<int>>& grid, vector<vector<int>> &visited, int row, int col, int num_rows, int num_cols)
    {

        if(row<0 || row> num_rows-1 || col<0 || col > num_cols - 1 || grid[row][col]!= 1) return;

        // Insert pair to set
        visited[row][col] = 1; 
        currArea ++; 

        // Left 
        if( row-1 >= 0 && visited[row-1][col]!= 1) dfsMain(grid, visited, row-1, col, num_rows, num_cols); 
        // Right 
        if(row + 1 <= num_rows-1 && visited[row+1][col]!= 1) dfsMain(grid, visited, row+1, col, num_rows, num_cols); 
        // Up 
        if(col-1 >= 0 && visited[row][col-1]!= 1) dfsMain(grid, visited, row, col-1, num_rows, num_cols);     
        //Down 
        if(col + 1 <= num_cols-1 && visited[row][col+1]!= 1) dfsMain(grid, visited, row, col+1, num_rows, num_cols); 

        return; 
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
    if(grid.empty()) return 0; 

    int num_rows= grid.size();
    int num_cols= grid[0].size(); 
    
    vector<vector<int>> visited(num_rows, vector<int>(num_cols, 0)); 
    int num_islands= 0; 

    for(int row=0; row <num_rows; row++)
    {
        for(int col=0; col <num_cols; col++)
        {
            // If not visited, do DFS, pass vistied by reference and change it 
            if(visited[row][col] == 0 && grid[row][col] == 1)
            {
                dfsMain(grid, visited, row,  col, num_rows, num_cols);
                maxArea = max(currArea, maxArea); 
                currArea = 0; 
            }

        }
    }

        
        return maxArea; 
        
    }
};

//////////////////////////////////////////////////////////////////////////////
// [1254] Number of closed islands 

class Solution {
public:
    
    bool is_closed_island = true; 
    
    void dfsMain(int r, int c, int num_rows, int num_cols, vector<vector<int>>& grid, vector<vector<int>>& visited)
    {
        if(r < 0 || r > num_rows-1 || c < 0 || c > num_cols-1 || grid[r][c]!= 0) return; 
        
        // This particular index has been visited
        visited[r][c] = 1;
        
        //if(!is_closed_island) return; 

        // There is an index in the island which is at the edge of the grid, we don't have a closed island 
        if(r == 0 || r == num_rows-1 || c == 0 || c == num_cols-1) 
        {
            is_closed_island = false; 
        }
                
        // Left 
        if(r-1 >= 0 && visited[r-1][c]!= 1)          dfsMain(r-1, c, num_rows, num_cols, grid, visited); 
        // Right 
        if(r+1 <= num_rows-1 && visited[r+1][c]!= 1) dfsMain(r+1, c, num_rows, num_cols, grid, visited); 
        // Up 
        if(c-1 >=0 && visited[r][c-1]!= 1)           dfsMain(r, c-1, num_rows, num_cols, grid, visited);
        // Down
        if(c+1 <= num_cols-1 && visited[r][c+1]!= 1) dfsMain(r, c+1, num_rows, num_cols, grid, visited);
        return; 
    }
    
    
    int closedIsland(vector<vector<int>>& grid) {
        
        // Grid dimensions 
        int num_rows = grid.size(); 
        int num_cols = grid[0].size(); 
        
        // Counting number of closed islands 
        int num_closed_islands = 0; 
        
        // Storing information of visited points 
        vector<vector<int>> visited(num_rows, vector<int>(num_cols, 0));
        
        for(int r=0; r< num_rows; r++)
        {
            for(int c=0; c< num_cols; c++)
            {
                // If we haven't visited it alredy
                // Land is designated by 1 in this case
                if(grid[r][c] == 1)
                {
                    visited[r][c] = 1;
                    continue; 
                }
                
                if(visited[r][c] == 0 && grid[r][c] == 0)
                {
                    // Main driver DFS call 
                    dfsMain(r,c, num_rows, num_cols, grid, visited);
                    // Check for if the island is closed or not 
                    if(is_closed_island) num_closed_islands ++; 
                    is_closed_island = true; 
                }
            }
        }
        
        return num_closed_islands; 
        
        
    }
};


////////////////////////////////////////////////////////////////////////////
// [463] Island Perimeter 

class Solution {
public:
    
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int num_rows = grid.size();
        int num_cols = grid[0].size();
        int perimeter = 0; 
        int curr_lengths = 0; 
        
        for(int r=0; r< num_rows; r++)
        {
            for(int c=0; c< num_cols; c++)
            {
                curr_lengths = 4; 
                // If its an element in the island 
                if(grid[r][c])
                {
                    // Check for top 
                    if(r!= 0)
                    {
                       if(grid[r-1][c] == 1) curr_lengths--;   
                    }
                    
                    // Check for down 
                    if(r!= num_rows - 1)
                    {
                        if(grid[r+1][c] == 1) curr_lengths--; 
                    }
                    
                    // Check for left 
                    if(c!= 0)
                    {
                        if(grid[r][c-1] == 1) curr_lengths--; 
                    }
                    
                    // Check for right 
                    if(c!= num_cols - 1)
                    {
                        if(grid[r][c+1] == 1) curr_lengths--; 
                    }
                    
                    //cout << "Current addition: " << curr_lengths <<  " Perimeter: " << perimeter << endl; 
                    perimeter+= curr_lengths; 
                }
                
            }
        }
        
        return perimeter; 
    }
};

//////////////////////////////////////////////////////////////////////////
// [934] Shortest bridge (using manhattan distance method)



/*
Key steps 

2) Find the  two indices where the distance between them is minimum. 
3) Use a method to find how many blocks need to be traversed to be able to reach to that 
*/


class Solution {
public:
    
    vector<pair<int,int>> extractIsland(int r, int c, int num_rows, int num_cols, vector<vector<int>>& A,  vector<vector<int>>& visited, vector<pair<int,int>>& island)
    {
        if(r < 0 || r > num_rows-1 || c < 0 || c > num_cols-1 || A[r][c]!= 1) return island; 
        
        // This particular index has been visited
        visited[r][c] = 1;
        
        // Push r and c index to island
        island.push_back(make_pair(r,c)); 
                
        // Left 
        if(r-1 >= 0 && visited[r-1][c]!= 1) island = extractIsland(r-1, c, num_rows, num_cols, A, visited, island); 
        // Right 
        if(r+1 <= num_rows-1 && visited[r+1][c]!= 1) island = extractIsland(r+1, c, num_rows, num_cols, A, visited, island); 
        // Up 
        if(c-1 >=0 && visited[r][c-1]!= 1)           island = extractIsland(r, c-1, num_rows, num_cols, A, visited, island);
        // Down
        if(c+1 <= num_cols-1 && visited[r][c+1]!= 1) island = extractIsland(r, c+1, num_rows, num_cols, A, visited, island);
        return island;         
    }    
    
    int shortestBridge(vector<vector<int>>& A) {
        
        
        // Number of columns and rows in the matrix 
        int num_rows = A.size();
        int num_cols = A[0].size(); 
        
        // To store all the visited points
        vector<vector<int>> visited(num_rows, vector<int>(num_cols, 0));
        
        
        vector<vector<pair<int,int>>> islands; 
        
        for(int r= 0; r< num_rows; r++)
        {
            for(int c=0; c<num_cols; c++)
            {
                if(visited[r][c] == 0 && A[r][c] == 1)
                {
                    vector<pair<int,int>> island; 
                    island= extractIsland(r,c,num_rows, num_cols, A, visited, island);
                    islands.push_back(island);
                    island.clear(); 
                }
            }
        }
        
        
        vector<pair<int,int>> island1 = islands[0]; 
        vector<pair<int,int>> island2 = islands[1]; 
        
        int dist = 0;
        int min_dist = INT_MAX; 
        
        for(int i=0; i<island1.size(); i++)
        {
            for(int j=0; j<island2.size(); j++)
            {
                dist = (abs(island1[i].first - island2[j].first) + abs(island1[i].second - island2[j].second))-1;
                min_dist = min(dist, min_dist);
            }
        }
        
        return min_dist; 
        
    }
};


/////////////////////////////////////////////////////////////////////////////////////////////////////////
// [980] Unique Paths III

class Solution {
public:
    
    int numPaths = 0; 
    int numValidCells = 0; 

    
    void findNumPaths(int r, int c, int num_rows, int num_cols, vector<vector<int>>& visited, vector<vector<int>>& grid, int count)
    {
        // cout << "Row Index: " << r  << " " << "Col index: " << c << " Count: " << count << endl;  
        // We reached the end of the grid in either direction 
        if(r < 0 || r > num_rows - 1 || c < 0 || c > num_cols -1) return;
        // We reached an obstacle (or) and already visited point
        else if(grid[r][c] == -1 || visited[r][c] == 1) return; 

        else 
        {
            // Mark point as visited 
            visited[r][c] = 1;
            // We reached our destination, update answer
            // Count + 1 as destination is also considered as a valid grid cell
            if(count+1 == numValidCells && grid[r][c] == 2 ) numPaths++;
            else
            {
                findNumPaths(r+1, c, num_rows, num_cols, visited, grid, count+1);
                findNumPaths(r, c+1, num_rows, num_cols, visited, grid, count+1);  
                findNumPaths(r-1, c, num_rows, num_cols, visited, grid, count+1);
                findNumPaths(r, c-1, num_rows, num_cols, visited, grid, count+1);
            }
            visited[r][c] = 0; 
        }
        
        return;        
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        if(grid.empty()) {
            return 0;
        } 
        
        int num_rows = grid.size();
        int num_cols = grid[0].size(); 
        vector<vector<int>> visited(num_rows, vector<int>(num_cols, 0));

        int start_r = -1, start_c = -1;
        
        // Loop through the whole grid once, find start and number of valid cells 
        for(int r= 0; r< num_rows; r++)
        {
            for(int c = 0; c < num_cols; c++)
            {
                if(grid[r][c] == 1)
                {
                    start_r = r;  
                    start_c = c; 
                }
                
                if(grid[r][c]!= -1) numValidCells ++; 
            }
        }
        

        
        findNumPaths(start_r, start_c, num_rows, num_cols, visited, grid, 0);
        
        return numPaths; 
        
        
    }
};

////////////////////////////////////////////////////////////////
// [207] Course schedule I 

// Kahn's algorithm
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        list<int> *adj_list = new list<int>[numCourses];
        vector<int> indegree (numCourses, 0);
        queue<int> myqueue;
        int count{0};
        
        for (int i=0; i<prerequisites.size(); i++){
            vector<int> vec = prerequisites[i];
            adj_list[vec[1]].push_back(vec[0]);
            indegree[vec[0]]++;            
        }
        
        for(int i=0; i < numCourses; ++i){
            if (indegree[i] == 0)
                myqueue.push(i);
        }
        
        if (myqueue.empty())
            return false;
        
        while(!myqueue.empty()){
            count++;
            int v = myqueue.front();
            myqueue.pop();
            
            for (auto it=adj_list[v].begin(); it != adj_list[v].end(); ++it){
                indegree[*it]--;
                if (indegree[*it] == 0){
                    myqueue.push(*it);
                }
            }
        }
        
        if (count == numCourses){
            return true;
        }
        else{
            return false;
        }
        
    }
};


///////////////////////////////////////////////////////////////////////////
// [261] Graph valid tree 

class Solution {
public:
    
    bool dfsRecur(int node, int parent, vector<int>& seen, vector<vector<int>>& adjl)
    {
        seen[node] = 1; 
        for(auto v: adjl[node])
        {
            if(v == parent) continue;
            if(seen[v]!= 0) return false; 
            else seen[v]= 1;
            bool ans= dfsRecur(v, node, seen, adjl);
            if(!ans) return ans;
        }
        return true; 
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        
        // Create an adjacency list representation to store vectors 
        vector<vector<int>> adjl(n, vector<int>());
        for(auto e: edges) 
        {
            adjl[e[0]].push_back(e[1]);   
            adjl[e[1]].push_back(e[0]);   
        }
        vector<int> seen(n, 0);  

        bool ans = dfsRecur(0, -1, seen, adjl);
        if(!ans) return ans;              

        cout << "Entering checking" << endl; 
        // Check if we have visited all the n nodes 
        for(int i=0; i< seen.size(); i++) if(seen[i] == 0) return false; 
        
        return true; 
    }
};


/////////////////////////////////////////////////////////////////////////////
// [226] Invert a binary tree 

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
       if(root == NULL) return NULL; 
        swap(root->left, root->right);
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        return root; 
    }
};








/////////////////////////////////////////////////////////////////////////////
// [79] Word search TLE 

class Solution {
public:
    
    
    
    int numRows = 0;
    int numCols = 0;
    string q_word; 
    bool ans = false; 
    
    
    void dfs(int r, int c, int idx, vector<vector<char>>& board, vector<vector<int>>& visited)
    {
        if(r < 0 || r > numRows-1 || c < 0 || c > numCols - 1 || q_word[idx]!= board[r][c] || idx > q_word.length()-1 || visited[r][c]!=0) return;
        
        // Set visited to 1 
        visited[r][c] = 1;
        
        if(idx == q_word.length()-1) 
        {
            ans = true; 
            return; 
        }
        
        // Up 
        dfs(r-1, c, idx+1, board, visited);
        // Down 
        dfs(r+1, c, idx+1, board, visited);
        // Left 
        dfs(r, c-1, idx+1, board, visited);
        // Right 
        dfs(r, c+1, idx+1, board, visited);
        
        visited[r][c] = 0; 
        
        return; 

    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        
    numRows = board.size();
    numCols = board[0].size(); 
    q_word = word; 
        
    if(board.empty()) return false; 
    if(board[0].empty()) return false; 
        
    vector<vector<int>> visited(numRows, vector<int>(numCols, 0)); 
        
    for(int r= 0; r < numRows; r++)
    {
        for(int c= 0; c< numCols; c++)
        {
            if(board[r][c] == word[0])
            {
                dfs(r,c, 0, board, visited); 
                if(ans) return ans;
                // Reinitialize viisted back to 0
                vector<vector<int>> temp(numRows, vector<int>(numCols, 0)); 
                visited = temp; 
            }
        }
    }
        
    return false; 
    }
};
