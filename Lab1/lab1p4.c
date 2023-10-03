#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//each node stores a pointer to its data and a pointer to the next node
struct Node
{
    char *data;
    struct Node *next;
};

struct Linkedlist
{
    struct Node *head;
};

void insertAtBeginning(struct Linkedlist *LL, char ele[]) {
    //allocate memory for a new node
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

    //duplicate input string and store in newnode.data
    newnode->data = strdup(ele);

    //make newnode the new head of the linked list
    newnode->next = LL->head;
    LL->head = newnode;
}

void insertAtTheEnd(struct Linkedlist *LL, char ele[]) {
    //allocate memory for a new node
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    
    //diplicate input string and store in newnode.data
    newnode->data = strdup(ele);

    //newnode is at the end of the list, so set newnode.next to NULL
    newnode->next = NULL;

    //if the list is empty, set newnode as the head of the list
    if(LL->head == NULL) {
        LL->head = newnode;
    }
    //if not empty, traverse to the end to update the last node's .next value
    else {
        struct Node *current = LL->head; //traversal pointer
        while(current->next != NULL) {
            current = current->next;
        }
        //once we reach the end, attach newnode to the end of the list
        current->next = newnode;
    }
}

void deleteNode(struct Linkedlist *LL, char ele[]) {
    //check if the list is empty; if it is, then nothing to delete
    if (LL->head == NULL) {
        return;
    }

    //declare pointers for traversal
    struct Node *current = LL->head;
    struct Node *prev = NULL;

    //traverse the linked list to find the node that matches the input
    while(current != NULL) {
        //check for match
        //remember that 0 means match
        if (strcmp(current->data, ele) == 0) {
            //if matching node is the head, update the head to the second node (may be NULL)
            if (prev == NULL) {
                LL->head = current->next;
            }
            //if not the head, update previous.next to skip the current
            else {
                prev->next = current->next;
            }
            //make sure to deallocate memory for the removed node!
            free(current->data); //deallocate the data first
            free(current);       //then deallocate the node
            return;
        }

        //if match not found yet, move to the next node
        prev = current;
        current = current->next;
    }
}

int findNode(struct Linkedlist LL, char ele[]) {
    //start at the head of the list
    struct Node *current = LL.head;

    //traverse through the list
    while (current != NULL) {
        //compare current node to input string
        //remember that 0 means match
        if(strcmp(current->data, ele) == 0) {
            return 1;
        }

        //if match not found yet, move to the next node
        current = current->next;
    }

    //if we reach this point, then there was no match
    return 0;
}

void displayLinkedList(struct Linkedlist LL) {
    //start at the head of the list
    struct Node *current = LL.head;

    //traverse through the list
    while (current != NULL) {
        //print the data of the current node
        printf("%s", current->data);

        //if theres another node after this, print a comma
        if (current->next != NULL) {
            printf(", ");
        }

        //move to the next node
        current = current->next;
    }

    //print a new line to finish it off
    printf("\n");
}

int main(int argc, char *argv[]) {
    //check that an argument was provided
    //remember that argv[0] is calling the program, and the ones after are the user arguments
    if (argc < 2) {
        printf("ERROR: The program must read at least one argument.\n");
        return 0;
    }

    //initialize linked list
    struct Linkedlist LL;
    LL.head = NULL;

    //iterate through arguments
    for (int i = 1; i < argc; i++) {
        //check that the word is not in the list already
        if(!findNode(LL, argv[i])) {
            //add uppercase words to the start,
            //and lowercase to the end
            if (isupper(argv[i][0])) {
                insertAtBeginning(&LL, argv[i]);
            } else if (islower(argv[i][0])) {
                insertAtTheEnd(&LL, argv[i]);
            }
        } else {
            //if already in the list, then delete the node
            deleteNode(&LL, argv[i]);
        }
    }

    //display the linked list
    printf("The list:- ");
    displayLinkedList(LL);

    //now that program is done, free the memory
    struct Node *current = LL.head; //traversal pointer
    while (current != NULL) {
        //we will free the node that "temp" is pointing to,
        //while we continue traversing the list with "current"
        struct Node *temp = current;
        current = current->next;

        //free the node's data, then
        free(temp->data);
        free(temp);
    }

    return 1;
}