#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct nodeStruct* List_createNode(int item){
    struct nodeStruct* node = malloc(sizeof(struct nodeStruct));
    node->item = item;
    node->next = NULL;
    return node;
}

void List_insertHead (struct nodeStruct **headRef, struct nodeStruct *node){
    if((*headRef)!=NULL){
        node->next = (*headRef);
        *headRef = node;
    }
    else{
        *headRef = node;
    }
    return;
}

void List_insertTail (struct nodeStruct **headRef, struct nodeStruct *node){
    struct nodeStruct* tmp = malloc(sizeof(struct nodeStruct));
    tmp = *headRef;
    if((*headRef)!=NULL){
        while(tmp->next != NULL){
            tmp=tmp->next;
        }
        tmp->next = node;
    }
    else{
        headRef = &node;
    }
    return;
}

int List_countNodes (struct nodeStruct *head){
    int i = 0;
    struct nodeStruct* tmp = malloc(sizeof(struct nodeStruct));
    tmp = head;
    if((head)!=NULL){
        i++;
        while(tmp->next != NULL){
            i++;
            tmp=tmp->next;
        }
    }
    return i;
}


struct nodeStruct* List_findNode(struct nodeStruct *head, int item){
    
    struct nodeStruct* tmp;
    tmp = head;
    if((head)!=NULL){
            while(tmp->item != item && tmp->next != NULL){
                    tmp=tmp->next;
            }
            if(tmp->item == item){
                return tmp;
            }
            else{
                return NULL;
            }
    }
    else{
        return NULL;
    }
}

void List_deleteNode (struct nodeStruct **headRef, struct nodeStruct *node){
    if(*headRef == node){
        if(node->next != NULL){
            (*headRef) = (node->next);
            free(node);
        }
        else{
            node = NULL;;
        }
    }
    else{
        struct nodeStruct* tmp = malloc(sizeof(struct nodeStruct));
        tmp = (*headRef);
        while(tmp->next != NULL && tmp->next != node){
            tmp = tmp->next;
        }
        if(tmp->next == node){
		struct nodeStruct* tmp2 = malloc(sizeof(struct nodeStruct));
        	tmp2 = tmp->next;
                tmp->next = tmp->next->next;
        	free(tmp2);
        }
    }
    return;
}
void List_sort (struct nodeStruct **headRef){
	struct nodeStruct *tmp = *(headRef);
	struct nodeStruct *tmp2 = *(headRef);
	struct nodeStruct *tmp3 = NULL;
	// Find the node containing the smallest element in the list first and make tmp2 point to it. 	
	while(tmp!=NULL){
		if(tmp->item < tmp2->item){
			tmp2=tmp;
		}
		else{
			tmp=tmp->next;
		}
	}
	/* 
         * If the node containing the minimal element is not the head of the list we 
         * will relink the list and make the minimal item node be the head of the list
         */
	if(tmp2	!= (*headRef)){
		tmp=(*headRef);
 		while (tmp!=tmp2){
			tmp3 = tmp;
			tmp = tmp->next;
		}
		tmp3->next=tmp->next;  
		tmp->next=(*headRef);
		(*headRef)=tmp;
	}

 	struct nodeStruct* current=(*headRef)->next;
	while(current!=NULL){
		tmp3=(*headRef);
		tmp=(*headRef)->next;
		/*
		 * Find the node containing the element that is bigger than the
		 * element at the current node.
		 */ 
		while((tmp->item <= current->item ) && (tmp!=current)){
			tmp3=tmp;
			tmp=tmp->next;
		}
 
		/* 
                 * Swap the node found containing an element greater than the current
                 * nodes element.
                 */
		if(tmp!=current){
			struct nodeStruct* PrevTraverse=(*headRef);
			while(PrevTraverse->next != current){
				PrevTraverse=PrevTraverse->next;
			}
			PrevTraverse->next =current->next;
			tmp3->next=current;
			current->next=tmp;
		}
		// Update the current node to be the next next node
		current=tmp->next;
		//tmp=(*headRef);
	}
 	
}







