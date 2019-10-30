#include "llist.h"
#include <stdlib.h>
#include <string.h>

// This method is used to initialize the list with the head and tail both NULL
void llInit(list *myList) {
  myList->head = NULL;
  myList->tail = NULL;
}

// This method is iterates through te list and returns the the size
int llSize(list *myList) {
  int count = 0;
  node *temp = myList->head;
  while (temp != NULL) {
    count++;
    temp = temp->next;
  }
  return count;
}

// This method is used to add elements to the head
int llPushFront(list *myList, char *toStore) {
  if (toStore != NULL) {
    node *newNode = (node *)malloc(sizeof(node));
    char *strPoint = (char *)malloc(sizeof(strlen(toStore) + 1));
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

// This method removes the head
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

// This method is used to add elements to the tail
int llPushBack(list *myList, char *toStore) {
  if (toStore != NULL) {
    node *newNode = (node *)malloc(sizeof(node));
    char *strPoint = (char *)malloc(sizeof(strlen(toStore) + 1));
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

// This method removes the tail
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

// This method is used to clear out the entire list
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

// This method adds elements after a specified node
int llInsertAfter(list *myList, node *insNode, char *toStore) {
  if ((myList->head != NULL) && (insNode != NULL)) {
    node *newNode = (node *)malloc(sizeof(node));
    char *strPoint = (char *)malloc(sizeof(strlen(toStore) + 1));
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

// This method adds elements before a specified node
int llInsertBefore(list *myList, node *insNode, char *toStore) {
  if ((myList->head != NULL) && (insNode != NULL)) {
    node *newNode = (node *)malloc(sizeof(node));
    char *strPoint = (char *)malloc(sizeof(strlen(toStore) + 1));
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

// This method removes a specified node
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
