#include<function.h>

void task1() {
    struct Stack *begin = NULL;
    int amount; 
    printf("Please, enter the desired amout of elements: ");
    if(input_Number(&amount) < 0 ){
       puts("Your request is incorrect. try again!\n");
       return;
    }
   input_Stack(&begin, amount);
   if(begin == NULL) {
       puts("Stack is empty");
       return;
   } else {
       puts("Contents of Stack:");
       view_Stack(begin, amount);
   }
   int sum = sum_Stack(begin);
   printf("The sum of stack elements is %d.\n", sum);
   free_Stack(begin);
   }

void task2() {
    struct Stack *Stack_1 = NULL;
    struct Stack *Stack_2 = NULL;
    struct Stack *Stack_Result = NULL;
    int amount; 
    printf("Please, enter the desired amout of elements: ");
    if(input_Number(&amount) < 0 ){
       puts("Your request is incorrect. try again!\n");
       return;
    }
   puts("Stack 1: ");
   input_Stack_ascending(&Stack_1, amount);
   puts("Stack 2: ");
   input_Stack_ascending(&Stack_2, amount);
   make_Stack_Resalt(Stack_1, Stack_2, Stack_Result);
   amount *= 2;
   puts("Stack Result:");
   view_Stack(Stack_Result, amount);
   free_Stack(Stack_Result);
}
