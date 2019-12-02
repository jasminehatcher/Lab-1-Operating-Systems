#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"



int main() {
  struct node n1, n2, n3;
  struct node *head;
  struct list l1;

  n1.val = 25;
  n2.val = 10;
  n3.val = 60;

  

  //links values
  head = &n3;//sets head to n3
  n3.next = &n2; //connescts pointer n2 to head
  n2.next = &n1;
  n1.next= NULL; //this is where the list ends

  // add the first node as the head of the list
  l1.head = head;

  //work
  printlist(&l1);
  list_add_to_back(&l1, 5);//checks to see if function to add node to back of list works

  //work 
  printlist(&l1);
  list_add_to_front(&l1, 18);//checks to see if function to add node to front of list works

  //works
  printlist(&l1);
  list_add_at_index(&l1,90,2);//checksfunction to add node at specific index in list
  printlist(&l1);

  //works 
  list_add_at_index(&l1,50,200);//checks to see if code checks for out bound indexes
  printlist(&l1);

  //works
  list_remove_from_back(&l1);//checks to see if function properly removes the node at the end of the list
  printlist(&l1);

  list_remove_from_front(&l1);//checks to see if function removes head of list
  printlist(&l1);

  list_remove_at_index(&l1, 2);//testing to remove element at  specific index 
    printlist(&l1);

  list_is_in(&l1, 90);//testung to check if 90 is in list
  list_is_in(&l1, 100);//testing to check if 100 is in list
  list_get_elem_at(&l1, 1); //gets value at certain index
  // get the length 
  list_get_index_of(&l1,60);
   list_get_index_of(&l1,100);
  printf("\nLength: %d\n",list_length(&l1));

  // allocate for new list
  list_t* l2 = list_alloc();
  list_add_to_front(l2, 2); // since it is just a pointer, you can just pass the value in
  list_add_to_back(l2, 89);
  printlist(l2);
}

