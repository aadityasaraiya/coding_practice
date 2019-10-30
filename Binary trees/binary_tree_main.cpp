// Main program for binary trees 

/* TO DO 
Convert into generic binary tree class. Add functionalities like add node, print tree etc. 
*/

/* List of functions included. 
*/

#include<iostream>
#include<vector>
using namespace std;

/*

- As log (base 2) n layers, the average search time for a binary tree is log (base 2) n. 
- To fill an entire binary tree, sorted, takes roughly log (base 2) n * n

*/
struct Node{
    int val;
    Node* left;
    Node* right; 
};


class BinaryTree{


    public:
        BinaryTree()
        {
            root = NULL; 
        }

        ~BinaryTree()
        {
            //destroyTree();
        }


        // The insertion process always starts from the root. Aka you begin at the root and traverse to the leaf and add a new node. 
        void insert(int key)
        {
            if(root!= NULL)
            {
                insert(key, root); 
            }

            else
            {
                root= new Node; 
                root->val = key; 
                root->left= NULL;
                root->right = NULL; 
            }
        }
        
        // Pre-order traversal 
        /*
            Visit root first, then traverse left subTree, then do right subtree
        */

       void preorderPrint()
       {
           preOrderPrintMain(root);
       }


       void preOrderPrintMain(Node* temp)
       {
           if(temp== NULL)
           {
               return;
           }

           preOrderPrintMain(temp->left);
           std::cout << temp-> val << std::endl; 
           preOrderPrintMain(temp->right);
       }

        // In-order traversal 

        /*
            Left subtree, then visit root, then right subtree
            Notes: 
            1) Visiting root doesn't mean we return root. Root is only returned after you visit both left and right. 
            2) Tendency to go towards the leftmost. When we reach a leaf, then only does the first 'root' of that subtree get returned  
            2) For BST we can retrieve all data in sorted order using this 
        */

        // Post-order traversal 

        /*
            Left subtree, then right subtree, then visit root 
            Uses: Deletion of nodes from the tree 
        */

       private:
        struct Node* root;

        void destroyTree(Node* leaf)
        {
            if(leaf!= NULL)
            {
                destroyTree(leaf->left);
                destroyTree(leaf->right);
                delete leaf; 
            }
        } 

        void insert(int key, Node* leaf)
        {
            // If key is smaller than root, add to left 
            if(key < leaf->val)
            {
                // Search for the leaf for which the left is NULL
                if(leaf->left!= NULL)
                {
                    insert(key, leaf->left);
                }

                else
                {
                    leaf->left= new Node; 
                    leaf->left->val= key; 
                    leaf->left->left= NULL; 
                    leaf->left->right = NULL; 
                }
            }

            else if(key > leaf -> val)
            {
                // Search for the leaf for which the right is NULL 
                if(leaf->right!= NULL)
                {
                    insert(key, leaf->right);
                }

                else
                {
                    leaf->right= new Node;
                    leaf->right->val= key; 
                    leaf->right->left= NULL; 
                    leaf->right->right= NULL; 
                }
            }
        }
};

int main()
{
    BinaryTree bt= BinaryTree();
    bt.insert(10); 
    bt.insert(6);
    bt.insert(14);
    bt.insert(5);
    bt.insert(8);
    bt.insert(11);
    bt.insert(18);

    bt.preorderPrint();
    //bt.postorderPrint();
    //bt.inorderPrint(); 

    return 0; 
}



/*
struct Node* newNode(int dat)
{
    struct Node* temp= new Node; 
    temp->left= NULL;
    temp -> right= NULL; 
    temp->data= dat; 
    return temp; 
}
*/


/*
Notes:

*/