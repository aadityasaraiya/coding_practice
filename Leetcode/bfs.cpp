

///////////////////////////////////////////////////////////////
// [107] Binary Tree Level Order Travesal II 


class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q1;
        
        // Push first element into the queue
        q1.push(root);
        
        // Push NULL to identify end of first level 
        q1.push(NULL);
        
        vector<vector<int>> ans;
        stack<vector<int>> st1; 
        
        vector<int> temp; 
        
        if(root == NULL)
        {
            return ans; 
        }
        
        // While queue is not empty 
        while(!q1.empty())
        {
            auto node= q1.front();
            q1.pop();
            
            if(node!= NULL)
            {
                cout << node->val << endl; 

                temp.push_back(node->val);
            
                if(node->left!= NULL)
                {
                    q1.push(node->left);
                }
                
                if(node->right!= NULL)
                {
                    q1.push(node->right);
                }                
                
            }
            
            else
            {
                // We have reached the end of a level 
                if(!q1.empty())
                {
                    q1.push(NULL);   
                }
                st1.push(temp); 
                temp.clear(); 
            }
        }
        
        // Iterate through the stack and push all vectors into ans
        while(!st1.empty())
        {
            ans.push_back(st1.top());
            st1.pop();             
        }

        return ans; 
        
    }
};

///////////////////////////////////////////////////////////////
