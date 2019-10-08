#include "llist.h"
#include <stdio.h>
/*
 * This method is inspired by Dr.Rothe's code and it is used to print out
 * all of the elements in the list
 */
void dump(list *myList) {
  node *aNode = myList->head;
  printf("List Has: %d\n", llSize(myList));
  while (aNode) {
    printf("%s\n", aNode->string);
    aNode = aNode->next;
  }
}

/*
 * This method is used for code cleanliness and readibility and it
 * creates a simple populated list to be sed for testing
 */
void createList(list *myList) {
  llPushFront(myList, "Four");
  llPushFront(myList, "Three");
  llPushFront(myList, "Two");
  llPushFront(myList, "One");
}

/*
 * This method is tests the push functions by creating a list and displaying it
 * on the terminal for validity
 */
void testPush() {
  list myList;
  llInit(&myList);
  llPushFront(&myList, "Two");
  llPushFront(&myList, "One");
  llPushBack(&myList, "Three");
  llPushBack(&myList, "Four");
  dump(&myList);
  llClear(&myList);
  printf("****************************\n");
}

/*
 * This method is tests the pop functions by taking a basic list and displaying
 * the changes on the terminal for validity
 */
void testPops() {
  list myList;
  llInit(&myList);
  createList(&myList);
  llPopFront(&myList);
  llPopBack(&myList);
  dump(&myList);
  llClear(&myList);
  printf("****************************\n");
}

/*
 * This method is tests the insert functions by creating a list and displaying
 * it on the terminal with the new additions made for validity
 */
void testInserts() {
  list myList;
  llInit(&myList);
  createList(&myList);
  llInsertAfter(&myList, myList.head->next, "Test1");
  llInsertBefore(&myList, myList.head->next, "Test2");
  dump(&myList);
  llClear(&myList);
  printf("****************************\n");
}

/*
 * This method is tests the remove function by creating a list and removing one
 * element, then displaying it on the terminal for validity
 */
void testRemove() {
  list myList;
  llInit(&myList);
  createList(&myList);
  llRemove(&myList, myList.head->next);
  dump(&myList);
  llClear(&myList);
  printf("****************************\n");
}

/*
 * This method is tests edge cases of the remove function by creating a list and
 * removing the head and tail nodes, and then displaying it on the terminal for
 * validity
 */
void testRemoveHT() {
  list myList;
  llInit(&myList);
  createList(&myList);
  llRemove(&myList, myList.tail);
  llRemove(&myList, myList.head);
  dump(&myList);
  llClear(&myList);
  printf("****************************\n");
}

/*
 * This method is tests edge cases of the insert functions by creating a list
 * and inserting new head and tail nodes, and then displaying it on the terminal
 * for validity
 */
void testInsertHT() {
  list myList;
  llInit(&myList);
  createList(&myList);
  llInsertBefore(&myList, myList.head, "NewHead");
  llInsertAfter(&myList, myList.tail, "NewTail");
  dump(&myList);
  llClear(&myList);
  printf("****************************\n");
}

/*
 * This method simply calls all of the tests and runs them for the user to
 * validate their code and make sure te tests pass
 */
int main() {
  testPush();
  testPops();
  testInserts();
  testRemove();
  testRemoveHT();
  testInsertHT();

  return 0;
}
