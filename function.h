#ifndef FUNCTION_H
#define FUNCTION_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack {
    int info;
    struct Stack* next;
};
int input_Number(int* );
void input_Stack(struct Stack**, int);
void input_Stack_ascending(struct Stack**, int amount); 
void view_Stack(struct Stack*, int);
int sum_Stack(struct Stack*);
void Stack_Result(struct Stack* Stack_1, struct Stack* Stack_2);

#endif
