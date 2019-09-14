// Driver program for LinkedLists 
/* List of functions included. 

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Node{
  int   data;
  Node* next;   
};


class SinglyLinkedList{
    public:
        SinglyLinkedList()
        {
            head= NULL; 
            tail= NULL; 
        }

        // Create a new node 
        void createNode(int data)
        {
            Node* temp= new Node;
            temp->data= data; 
            temp->next= NULL;  
            
            // The linked list is empty 
            if(head == NULL)  
            {
                // Initialize head to temp 
                head= temp; 
                // Initialize tail to temp as well. 
                tail= temp; 
                // Set temp to NULL 
                temp= NULL; 
            }

            // Linked List is not empty 
            else
            {
                // Change the original tails next to temp 
                tail->next= temp; 
                // After that, change the tail to temp 
                tail= temp; 
            }
        }

        // Insert node at start: O(1) 
        void insertStart(int data)
        {
            // If head == NULL, we cannot do this 
            Node* temp= new Node; 
            temp-> data= data; 
            temp->next= head; 
            head= temp; 
        }

        // Just a wrapper function to the create node function 
        void insertEnd(int data)
        {
            createNode(data);
        }

        // Insert node at position: O(n)
        void insertNPos(int data, int pos)
        {
            if(head == NULL)
            {
                return; 
            }

            Node* temp= new Node; 
            Node* curr= new Node;
            Node* prev= new Node; 

            temp = head; 
            for( int i= 0; i< pos; i++)
            {
                prev= temp; 
                temp= temp->next; 
            }

            curr->data= data; 
            curr->next= temp; 
            prev->next= curr; 
        }

        // Delete node at position n: O(n)
        void deleteNPos(int pos)
        {
            Node* temp= new Node; 
            Node* prev= new Node; 
            temp = head; 

            for (int i=0; i<pos; i++)
            {
                prev= temp; 
                temp= temp->next; 
            }

            prev->next= temp->next;
            delete temp; 
        }

        // Delete node from start: O(1)
        void deleteStart()
        {
            Node* temp= new Node; 
            temp = head; 
            head= head->next; 
            delete temp; 
        }

        // Delete node from the end: O(n)
        void deleteEnd()
        {
            Node* temp= new Node; 
            Node* prev= new Node; 

            temp = head; 
            while(temp->next!= NULL)
            {
                prev= temp; 
                temp= temp->next; 
            }

            tail = prev; 
            prev->next= NULL; 
            delete temp; 

        }

        // Delete whole linked list: O(n)
        void deleteLinkedList()
        {
            Node* temp= new Node; 
            Node* prev= new Node; 
            temp= head; 
            head= NULL; 

            while(temp!= NULL)
            {
                prev= temp; 
                temp= temp->next; 
                delete prev; 
            }
            tail= NULL; 
        }

        // Print the linked list 
        void printLinkedList()
        {
            Node* temp= new Node;
            temp= head; 

            while(temp!= NULL)
            {
                std::cout << temp-> data << " -> ";
                temp= temp->next; 
            }

            std::cout << " " << std::endl; 
        }

    private:
        Node* head; 
        Node* tail; 
};


class DoublyLinkedList{
    public:

    private: 
};

class CircularLinkedList{

    public:

    private: 
};

int main()
{
    SinglyLinkedList sll;
    std::vector<int> requiredll= {10, 20, 30, 40}; 

    for (auto w: requiredll)
    {
        // Add all the elements to the singly linked list 
        sll.createNode(w); 
    }

    sll.printLinkedList(); 
    sll.deleteLinkedList();
    sll.printLinkedList(); 

    return 0; 
}