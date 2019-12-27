

//[104] Max Depth of binary tree  


    int maxLevel= 1; 
    
    int inOrderTraversal(TreeNode* temp, int level)
    {
        if(temp == NULL)
        {
            return (level-1); 
        }
        
        maxLevel= max(maxLevel, inOrderTraversal(temp->left, level+1));
        maxLevel= max(maxLevel, inOrderTraversal(temp->right, level+1));
        
        return maxLevel; 
        
    }
    
    
    int maxDepth(TreeNode* root) {
        
        if(root == NULL)
        {
            return 0; 
        }
        
        if(root->left == NULL && root->right == NULL)
        {
            return maxLevel; 
        }
        
        int maxL=  inOrderTraversal(root, 1); 
        
        return maxL; 
        
    }


///////////////////////////////////////////////////////////////////////////////////////////////
//[110] Balanced Binary tree 


    int maxDepth(TreeNode* temp)
    {
        if(temp == NULL)
        {
            return 0;
        }
                
        return 1 + max(maxDepth(temp->left), maxDepth(temp->right)); 
    }
    
    
    bool isBalanced(TreeNode* root) {
        
        
        if(root == NULL)
        {
            return true; 
        }
        
        int maxLvl1= maxDepth(root->left);
        int maxLvl2= maxDepth(root->right);
        
         if(abs(maxLvl1- maxLvl2)>1)
         {
             return false; 
         }
        
         else
         {
             return isBalanced(root->left) && isBalanced(root->right);
         }
    }

///////////////////////////////////////////////////////////////////////////////////////////////

// [111] Minimum depth of binary tree 

    int minDepth_val= INT_MAX;
    
    int postOrderTrav(TreeNode* temp, int lvl)
    {
        if(lvl> minDepth_val || temp == NULL)
        {
            return (lvl-1);
        }
        
        int level1= postOrderTrav(temp->left,  lvl+1);
        int level2= postOrderTrav(temp->right, lvl+1);
                
        // Only update at leaves 
        if(temp->left == NULL && temp->right == NULL)
        {
            minDepth_val= min(minDepth_val, min(level1, level2));   
        }
        
        
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

// This question can be termed as exploring an 

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
        
        if(color!= newColor)
        {
            dfs(image, sr, sc, newColor);  
        }
        
        return image; 
    }
};




