//
//  main.cpp
//  Test
//
//  Created by Bharath Marulasiddappa on 2/13/21.
//

#include <iostream>

// C++ program to detect and remove loop
using namespace std;

typedef struct Node* NODE;

struct Node {
    int key;
    NODE next;
};


NODE newNode(int key)
{
    NODE temp = new Node;
    temp->key = key;
    temp->next = NULL;
    return temp;
}
 
// A utility function to print a linked list
void printList(NODE head)
{
    while (head != NULL) {
        cout << head->key << " -> ";
        head = head->next;
    }
    cout << "NULL";
    cout << endl;
}
 
// Function to detect and remove loop
// in a linked list that may contain loop
void detectAndRemoveLoop(NODE head)
{
    // If list is empty or has only one node
    // without loop
    if (head == NULL || head->next == NULL)
        return;
 
    NODE slow = head;
    NODE fast = head;
    bool loopExists = false;
     
    // Move slow and fast 1 and 2 steps
    // ahead respectively.
    slow = slow->next;
    fast = fast->next->next;
 
    // Search for loop using slow and
    // fast pointers
    while (fast && fast->next) {
        if (slow == fast) {
            loopExists = true;
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
 
    /* If loop exists */
    if (loopExists)
    {
        slow = head;
           
        // this check is needed when slow
        // and fast both meet at the head of the LL
          // eg: 1->2->3->4->5->6->7->8 and then
        // 8->next = 1 i.e the head of the LL
          if(slow == fast) {
              while(fast->next != slow) fast = fast->next;
        }
          else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }
 
        /* since fast->next is the looping point */
        fast->next = NULL; /* remove loop */
    }
}
 
/* Driver program to test above function*/
int main()
{
    NODE head = newNode(1);
    head->next = head;
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(6);
    head->next->next->next->next->next->next = newNode(7);
    head->next->next->next->next->next->next->next = newNode(8);

    /* Create a loop for testing */
    head->next->next->next->next->next->next->next->next = head->next;

    detectAndRemoveLoop(head);
 
    printf("Linked List after removing loop \n");
    printList(head);
 
    return 0;
}
