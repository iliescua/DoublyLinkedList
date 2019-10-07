#include "llist.h"
#include <stdlib.h>
#include <string.h>

/*
 * This metod is used to initialize the list with the head and tail both NULL
 */
void llInit(list *myList) {
  myList->head = NULL;
  myList->tail = NULL;
}

/*
 * This metod is iterates through te list and a count variable keeps track of
 * size This method returns the size of the list
 */
int llSize(list *myList) {
  int count = 0;
  node *temp = myList->head;
  while (temp != NULL) {
    count++;
    temp = temp->next;
  }
  return count;
}

/*
 * This metod is used to add an element to the front of the list
 * It takes in the list and the char array which need to be stored
 * It checks to make sure that the list is populated and if it isn't then
 * it has both the tail and head node point to the same location
 * This method makes sure to replace the head pointer with the new node
 * This method returns 1 if successful and 0 if it failed
 */
int llPushFront(list *myList, char *toStore) {
  if (toStore != NULL) {
    node *newNode = (node*)malloc(sizeof(node));
    char *strPoint = (char*)malloc(sizeof(strlen(toStore) + 1));
    strcpy(strPoint, toStore);
    newNode->string = strPoint;
    if (myList->head == NULL) {
      myList->head = newNode;
      myList->head->prev = NULL;
      myList->tail = newNode;
      myList->tail->next = NULL;
    } else {
      newNode->next = myList->head;
      newNode->prev = NULL;
      myList->head->prev = newNode;
      myList->head = newNode;
    }
    return 1;
  } else {
    return 0;
  }
}

/*
 * This metod is used to remove elements from the the front of the list
 * It also makes sure to replace where the head is
 * The method returns 1 f successful and 0 if it failed
 */
int llPopFront(list *myList) {
  if (myList->head != NULL) {
    node *temp = myList->head->next;
    free(myList->head->string);
    free(myList->head);
	myList->head = temp;
    myList->head->prev = NULL;
    return 1;
  } else {
    return 0;
  }
}

/*
 * This metod is used to add an element to the back of the list
 * It takes in the list and the char array which need to be stored
 * It checks to make sure that the list is populated and if it isn't then
 * it has both the tail and head node point to the same location
 * This method makes sure to replace the tail pointer with the new node
 * This method returns 1 if successful and 0 if it failed
 */
int llPushBack(list *myList, char *toStore) {
  if (toStore != NULL) {
    node *newNode = (node*)malloc(sizeof(node));
    char *strPoint = (char*)malloc(sizeof(strlen(toStore) + 1));
    strcpy(strPoint, toStore);
    newNode->string = strPoint;
    if (myList->head == NULL) {
      myList->head = newNode;
      myList->head->prev = NULL;
      myList->tail = newNode;
      myList->tail->next = NULL;
    } else {
      newNode->prev = myList->tail;
      newNode->next = NULL;
      myList->tail->next = newNode;
      myList->tail = newNode;
    }
    return 1;
  } else {
    return 0;
  }
}

/*
 * This metod is used to remove elements from the the back of the list
 * It also makes sure to replace where the tail is
 * The method returns 1 f successful and 0 if it failed
 */
int llPopBack(list *myList) {
  if (myList->head != NULL) {
    node *temp = myList->tail->prev;
    free(myList->tail->string);
    free(myList->tail);
    myList->tail = temp;
    myList->tail->next = NULL;
    return 1;
  } else {
    return 0;
  }
}

/*
 * This metod is used to clear the list and remove all of the elements from the
 * list
 */
void llClear(list *myList) {
  node *temp;
  while (myList->head != NULL) {
    temp = myList->head;
    myList->head = myList->head->next;
    free(temp->string);
    free(temp);
  }
  myList->head = NULL;
  myList->tail = NULL;
}

/*
 * This metod is used to insert a node in the list
 * The parameters the method takes is the list, the node after which a new node
 * should be added and the string value to be stored This method needs to check
 * to make sure that if the specified node is the tail node that the tail
 * pointer gets replaced with the new node This method returns 1 if successful
 * and 0 if failed
 */
int llInsertAfter(list *myList, node *insNode, char *toStore) {
  if (myList->head != NULL) {
    node *newNode = (node*)malloc(sizeof(node));
    char *strPoint = (char*)malloc(sizeof(strlen(toStore) + 1));
    strcpy(strPoint, toStore);
    newNode->string = strPoint;
    node *temp = insNode->next;
    if (insNode == myList->tail) {
      myList->tail->next = newNode;
      newNode->prev = myList->tail;
      myList->tail = newNode;
      newNode->next = NULL;
    } else {
      insNode->next = newNode;
      newNode->prev = insNode;
      temp->prev = newNode;
      newNode->next = temp;
    }
    return 1;
  } else {
    return 0;
  }
}

/*
 * This metod is used to insert a node in the list
 * The parameters the method takes is the list, the node after which a new node
 * should be added and the string value to be stored This method needs to check
 * to make sure that if the specified node is the head node that the head
 * pointer gets replaced with the new node This method returns 1 if successful
 * and 0 if failed
 */
int llInsertBefore(list *myList, node *insNode, char *toStore) {
  if (myList->head != NULL) {
    node *newNode = (node*)malloc(sizeof(node));
    char *strPoint = (char*)malloc(sizeof(strlen(toStore) + 1));
    strcpy(strPoint, toStore);
    newNode->string = strPoint;
    node *temp = insNode->prev;
    if (insNode == myList->head) {
      myList->head->prev = newNode;
      newNode->next = myList->head;
      myList->head = newNode;
      newNode->prev = NULL;
    } else {
      insNode->prev = newNode;
      newNode->next = insNode;
      temp->next = newNode;
      newNode->prev = temp;
    }
    return 1;
  } else {
    return 0;
  }
}

/*
 * This metod is used to remove a specifeid node from the list
 * This method takes as parameters the list and the node that is to be removed
 * This method needs to make sure that if the specified node is either the head
 * or the tail of the list that the pointers for each respectively also get
 * replaced, else it removes the specified node This method simply returns 0
 */
int llRemove(list *myList, node *rmvNode) {
  node *temp;
  if (rmvNode == myList->head) {
    temp = myList->head->next;
    free(myList->head->string);
    free(myList->head);
    temp->prev = NULL;
    myList->head = temp;
  } else if (rmvNode == myList->tail) {
    temp = myList->tail->prev;
    free(myList->tail->string);
    free(myList->tail);
    temp->next = NULL;
    myList->tail = temp;
  } else {
    temp = rmvNode->prev;
    temp->next = rmvNode->next;
    temp = rmvNode->next;
    temp->prev = rmvNode->prev;
    free(rmvNode->string);
    free(rmvNode);
  }
  return 0;
}