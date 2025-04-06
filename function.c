int input_Number(int* number) {
    rewind(stdin);
    *number = 0;
    int digit, sign = 1, started = 0;
    while ((digit = getchar()) != '\n' && digit != ' ') {
        if (digit == '-') {
            sign = -1;
        } else if (digit < '0' || digit > '9') {
            printf("Incorrect number\n");
            while ((digit = getchar()) != '\n' && digit != ' ');
            *number = 0;
            return -1;
        } else {
            started = 1;
            *number = *number * 10 + (digit - '0');
        }
    }
   return started ? *number * sign : 0;
} 

void input_Stack(struct Stack** begin, int amount) {
    for(int i = 0; i < amount; ++i){
        int in;
        struct Stack* t = (struct Stack*)malloc(sizeof(struct Stack));
        if(!t){
            puts("There was a problem finding free space.");
            return;
        }
        printf("Element %d - ", i + 1);
        t->info = input_Number(&in);
        t->next = *begin;
        *begin = t;
    }
}

void view_Stack(struct Stack* t, int amount) {
    while(t != NULL) {
        printf("Element %d - %d;\n", amount, t->info);
        t = t->next;
        amount--;
    };
}

int sum_Stack(struct Stack* t) {
    int sum = 0;
    while(t != NULL) {
        sum += t->info;
        t = t->next;
    };
    return sum;
}

void input_Stack_ascending(struct Stack** begin, int amount) {
    int in, buffer, flag = 0;
    for(int i = 0; i < amount; ++i){
        struct Stack* Stack = (struct Stack*)malloc(sizeof(struct Stack));
        if(!Stack){
            puts("There was a problem finding free space.");
            return;
        }
        printf("Element %d - ", i + 1);
        Stack->info = input_Number(&in);
        if(flag != 0 && Stack->info > buffer){
            puts("The input does not meet the requirements. Try again.");
            free(Stack);
            i--;
            continue;
        }
        buffer = Stack->info;
        Stack->next = *begin;
        *begin = Stack;
        flag++;
    }
}

void make_Stack_Resalt(struct Stack** Stack_1, struct Stack** Stack_2, struct Stack** Stack_Result) {
    *Stack_Result = NULL;
    struct Stack** current = Stack_Result;
    
    while (*Stack_1 != NULL || *Stack_2 != NULL) {
        struct Stack* new_node = (struct Stack*)malloc(sizeof(struct Stack));
        if (!new_node) {
            puts("Memory allocation failed");
            return;
        }
        
        if (*Stack_1 == NULL) {
            new_node->info = (*Stack_2)->info;
            *current = new_node;
            current = &((*current)->next);
            struct Stack* temp = *Stack_2;
            *Stack_2 = (*Stack_2)->next;
            free(temp);
        } else if (*Stack_2 == NULL) {
            new_node->info = (*Stack_1)->info;
            *current = new_node;
            current = &((*current)->next);
            struct Stack* temp = *Stack_1;
            *Stack_1 = (*Stack_1)->next;
            free(temp);
        } else if ((*Stack_1)->info > (*Stack_2)->info) {
            new_node->info = (*Stack_1)->info;
            *current = new_node;
            current = &((*current)->next);
            struct Stack* temp = *Stack_1;
            *Stack_1 = (*Stack_1)->next;
            free(temp);
        } else {
            new_node->info = (*Stack_2)->info;
            *current = new_node;
            current = &((*current)->next);
            struct Stack* temp = *Stack_2;
            *Stack_2 = (*Stack_2)->next;
            free(temp);
        }
    }
    *current = NULL;
}

void free_Stack(struct Stack* t) {
    struct Stack* current = NULL;
    while (t != NULL) {
        current = t->next;
        t = t->next;
        free(current);
    };
}
