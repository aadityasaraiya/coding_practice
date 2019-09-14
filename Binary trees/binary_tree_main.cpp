// Main program for binary trees 

/* TO DO 
Convert into generic binary tree class. Add functionalities like add node, print tree etc. 
*/

/* List of functions included. 
*/

#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right; 
};

struct Node* newNode(int dat)
{
    struct Node* temp= new Node; 
    temp->left= NULL;
    temp -> right= NULL; 
    temp->data= dat; 
    return temp; 
}

int main()
{
    struct Node* root= newNode(2);
    return 0; 
}




/*
Notes:

*/