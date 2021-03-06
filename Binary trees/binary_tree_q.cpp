// Main program for binary trees 

/* List of functions included. 
*/

#include<iostream>
#include<vector>
using namespace std;



class Node{
    
    public:
        Node* left_;
        Node* right_;
        int val_;

    Node(int val)
    {
        val_= val;
        left_= NULL;
        right_= NULL;  
    }

};


class Solution
{
    
    public: 
        std::vector<int> findDist(Node* target, Node* rootPtr, int dist)
        {
            // Setting root and target pointer 
            rootPtr_= rootPtr;
            targetPtr_= target;
            dist_= dist; 

            int temp= preOrderTraversal(rootPtr_, 0);
            return ans_;   
        }
    
    private:
        std::vector<int> ans_;
        Node* rootPtr_= NULL; 
        Node* targetPtr_= NULL; 
        int dist_ = 0; 
        int targetCount_ = 0;         
        //int distCount;  
        
    int preOrderTraversal(Node* temp, int count)
    {       
        if(temp == NULL)
        {
            return (count-1);
        }

        if(temp  == targetPtr_)
        {
            // We are currently at the target pointer 
            targetCount_ = count; 
        }


        if(abs(count-targetCount_) == dist_)
        {
            std::cout << "Pushing val to ans:" << temp  -> val_  << std::endl; 
            ans_.push_back(temp ->val_);
        }

        std::cout << temp-> val_ <<  " " << count  << std::endl; 
        preOrderTraversal(temp->left_, count+1);
        preOrderTraversal(temp->right_, count+1);

        return 1; 
    }
};



int main()
{
    // Create tree root 
    Node* root= new Node(20);

    // Adding required nodes to tree 
    root->left_= new Node(8);
    root->right_= new Node(22);

    root->left_->left_= new Node(4);
    root->left_->right_= new Node(12);

    root->left_->right_->left_= new Node(10);
    root->left_->right_->right_= new Node(14);
    
    Solution solution; 

    std::vector<int> ans= solution.findDist(root->left_ ,root, 2);

    //std::vector<int> ans= solution.findDist(root->left_->right_->right_ ,root, 3);

    return 0; 
}


