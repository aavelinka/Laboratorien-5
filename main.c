#include "function.h"
#include "task.h"

int main() {
    printf("Hi!\nLet's see what I can offer you today ;)\n");
    char repeat;
    do
    {
        rewind(stdin);
        printf("Please, enter task number: ");
        char option;
        scanf("%c", &option);

        switch(option)
        {
            case '1':
                task1();
                break;
            case '2':
                task2();
                break;
            default:
                printf("Oh! There is no this task, try again\n");
                break;
        }

        puts("Do you want repeat? YES - 1, NO - 0");
        scanf("%c", &repeat);
        
    } while (repeat == '1');
    
    puts("Good job, dear! See you later <3");
    return 0;
}
