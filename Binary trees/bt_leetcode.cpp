
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
