/**
 * 
 * PUSH, POP and TOS operations of Stack 
 */

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

struct Stack
{
  int array[MAX_SIZE];
  int top;
};

int SIZE;

/**
 * Initialize stack
 * 
 * @param stackPointer
 */
void initialize(struct Stack *stackPointer) {
  stackPointer->top = -1;
} 

/**
 * Check if stack is empty
 * 
 * @param stackPointer
 */
int isEmpty(struct Stack *stackPointer) {
  if(stackPointer->top == -1)
    return 1;
  return 0;
}

/**
 * Check if stack is full
 * 
 * @param stackPointer
 */
int isFull(struct Stack *stackPointer) {
  if(stackPointer->top == SIZE - 1)
    return 1;
  return 0;
}

/**
 * Push an item into top of the stack
 * 
 * @param stackPointer
 * @param item
 */
void push(struct Stack *stackPointer, int item) {
  if(isFull(stackPointer)) {
    printf("\n Sorry, stack is full. \n");
  } else {
    stackPointer->top++;
    stackPointer->array[stackPointer->top] = item;
  }
}

/**
 * Pop an item from top of the stack
 * 
 * @param stackPointer
 * @returns
 */
void pop(struct Stack *stackPointer) {
  int item;

  if(isEmpty(stackPointer)) {
    printf("\n Sorry, stack is empty. \n");
  } else {
    item = stackPointer->array[stackPointer->top];
    stackPointer->top--;
    printf("\n %d successfully popped from stack. \n", item);
  }
}

/**
 * Display an item at top of the stack
 * 
 * @param stackPointer
 */
void tos(struct Stack *stackPointer) {
  int item;

  if(isEmpty(stackPointer)) {
    printf("\n Sorry, stack is empty. \n");
  } else {
    item = stackPointer->array[stackPointer->top];
    printf("\n %d is at top of the stack. \n", item);
  }
}

/**
 * Main function
 */
int main() {

  char choice;
  int item;
  struct Stack stack;

  initialize(&stack);

  printf("\n Enter size of the stack: ");
  scanf("%d", &SIZE);

  while(choice != '4') {
    printf("\n 1. PUSH \n 2. POP \n 3. TOS \n 4. EXIT \n");
    printf("\n Enter your choice (1, 2, 3 or 4): ");
    scanf(" %c", &choice);

    switch (choice)
    {
    case '1':
      printf("\n Enter an item to push into stack: ");
      scanf("%d", &item);
      push(&stack, item);
      break;

    case '2':
      pop(&stack);
      break;
    
    case '3':
      tos(&stack);
      break;

    case '4':
      exit(0);

    default:
      break;
    }
  }

  return 0;
}
