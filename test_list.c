#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

int main(int argc, char *argv[]){
	printf("Starting tests...\n");
	struct nodeStruct *head = NULL;

	// Starting count:
	assert(List_countNodes(head) == 0);

	// Create 1 node:
	struct nodeStruct* firstNode = List_createNode(0);
	List_insertHead(&head, firstNode);
	assert(List_countNodes(head) == 1);
	assert(List_findNode(head, 0) == firstNode);
	assert(List_findNode(head, 1) == NULL);

	// Insert tail:
	struct nodeStruct* lastNode = List_createNode(-5);
	List_insertTail(&head, lastNode);
	struct nodeStruct* lastNode2 = List_createNode(2);
	List_insertTail(&head, lastNode2);
	struct nodeStruct* lastNode3 = List_createNode(3);
	List_insertTail(&head, lastNode3);
	struct nodeStruct* lastNode4 = List_createNode(8);
	List_insertTail(&head, lastNode4);
	assert(List_countNodes(head) == 5);
	assert(List_findNode(head, 0) == firstNode);
	assert(List_findNode(head, -5) == lastNode);
	assert(List_findNode(head, 1) == NULL);

	// Verify list:
	struct nodeStruct *current = head;
	assert(current->item == 0);
	assert(current->next != NULL);
	current = current->next;
	assert(current->item == -5);
	assert(current->next != NULL);

	// Sort and verify:
	List_sort(&head);
	current = head;
	assert(current->item == -5);
	assert(current->next != NULL);
	current = current->next;
	assert(current->item == 0);
	assert(current->next != NULL);

	// Delete
	assert(List_countNodes(head) == 5);
	List_deleteNode(&head, firstNode);
	assert(List_countNodes(head) == 4);
	assert(List_findNode(head, 0) == NULL);
	assert(List_findNode(head, 1) == NULL);
	current = head;
	assert(current->item == -5);
	assert(current->next->item == 2);


	printf("\nExecution finished.\n");
	return 0;


    return 0;
}
