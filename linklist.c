
#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

 void printlist(list_t *l) {
   node_t* temp = l->head;
   while(temp != NULL){//while pointer's target has a vallue
     printf(" %d", temp->val);
     temp = temp->next;//travereses 
   }
   printf("\n");
  }

int list_length(list_t *l){
  node_t* temp = l->head;//head refernce
  int count = 0;
  while(temp != NULL){
    count++; //increment the count
    temp = temp->next;
  }
  return count;
}

void list_add_to_back(list_t *l, int value){
  node_t *temp = l->head;
  // have to allocate memory before inserting a newNode (ptr)
  node_t *newNode = (node_t*) malloc(sizeof(newNode));
  // assign a value
  newNode->val = value;
  //printf("%d", newNode.val);
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = newNode;
}

void list_add_to_front(list_t *l, int value){
  node_t *temp = l->head;//head of list refernce
  node_t *newNode = (node_t*) malloc(sizeof(newNode));//allocates memory for new node to be inserted
  newNode->val = value;//assigns new node to parameter
  newNode->next =temp; //points new node to head
  l-> head = newNode;//assigns new node to head of list
}

void list_add_at_index(list_t *l, int value, int index){
  node_t* temp = l->head;//head refernce
  node_t *newNode = (node_t*) malloc(sizeof(newNode));//a;llocates memory for new node
  newNode->val = value;//assigns new value to new node
  int count = 0;
  while(temp != NULL){//traveres list to add at index
    // if zero, then skip
    if(temp->val == 0){
      continue;
    }

    if (count == index-1){
      // the new node points to the head.next
      newNode->next = temp->next;
      
      // set the index to temp->next
      temp->next = newNode;
      return;
    }
    //printf("%d",count);
    count++;
    temp = temp->next;
  }

  // if we reach null then the index is not in the list and we cannot insert
  printf("Index out of bounds. Cannot insert\n");
}

int list_remove_from_back(list_t *l){
  node_t *temp = l->head;
  //traverse till end
  while(temp->next->next != NULL){
    temp = temp->next;
  }
  free(temp->next);//frees space
  temp->next = NULL;//sets space to null
  printf("\nnode is now deleted.\n");
  return 0;
}

int list_remove_from_front(list_t *l){
  node_t *temp = l->head;
  if(temp != NULL){ //traveres list
    l-> head = temp->next;//sets new heaad to next node
    printf("\n front node is now deleted.\n");
  }
 else{
  printf("\n Head node is NULL.\n");
 }
return 0;
}

  
int list_remove_at_index(list_t *l, int index){
  node_t* temp = l->head;
  int value = index;
  int count = 0;
  while(temp != NULL){
    // if zero, then skip
    if (count == value-1){
   // printf("Node at index ", value, "is deleted\n");
     temp->next = temp->next->next;
     printf("\nNode is deleted at index: %d\n",value);
    }
    //printf("%d",count);
    count++;
    temp = temp->next;
  }
  // if we reach null then the index is not in the list and we cannot insert
 // printf("Index out of bounds. Cannot insert\n");
  return 0;
}

bool list_is_in(list_t *l, int value){
  int target = value;
  node_t* temp = l->head;
  while(temp->next!= NULL){//traverses list
    if (temp->val == target){//checks to see if element is in list
      printf("True\n");
      return true;
    }

    temp = temp->next;
  }

  printf("False\n");
  return false;
 }  
    //checks to see if value is in list

int list_get_elem_at(list_t *l, int index){
  int target = index;
  node_t* temp = l->head;//head refence
  int count = 0;
    while(temp->next != NULL){//traveres lsit
      if(target == count){
        printf("\nNode at index: %d\n",target);//print element at specific index
        printf(" is %d\n",temp->val);
        return temp->val;
      }
      count++; //increment the count
      temp = temp->next;
    }
     printf("\nIndex is out of bounds");
  return -1;
}
int list_get_index_of(list_t *l, int value){
int target = value;
  node_t* temp = l->head;//head refernce
  int count = 0;
    while(temp->next != NULL){//travereses list
      if(target == temp->val){
        printf("\nThe value of %d", value);//prints current index
        printf(" is in index %d\n",count);
        return temp->val;//retrurns value at index
      }
      count++; //increment the count
      temp = temp->next;
    }
     printf("\nValue %d",value);
     printf(" is not in list");

  return -1; 
}

// allocate space for the list
list_t* list_alloc() {
  // create a local variable for the newNode and use that as the template for malloc
  node_t newNode;
  // create the head pointer
  node_t* newHead = (node_t*)malloc(sizeof(newNode));
  // make sure that the new node has NULL for next
  newHead->next = NULL;
  // create the new list
  list_t* newList;
  newList->head = newHead;
  //return the pointer
  return newList;

}
void list_free(list_t *l) {
  node_t* temp = l->head;
  //traverse freeing every node in the list
  while(temp != NULL){
    node_t* toFree = temp;
    temp = temp->next;
    free(toFree);
    toFree = NULL;

  }
}





