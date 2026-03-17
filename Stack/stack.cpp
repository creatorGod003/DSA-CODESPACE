/**
 * Implementation of Stack using Array
 * 
 **/
#include <stdio.h>
#include <stdlib.h>

struct Stack{
  int *s;
  int top;
  int size;
};

void initializeStack(struct Stack *st, int *s, int top, int size){
    st->s = s;
    st->top = top;
    st->size = size;
    
    printf("Stack Initialized...\n");
}

void push(struct Stack *st, int x){
    
    if(st->top == st->size -1 ){
        printf("Stack Over Flow\n");
    }
    else{
        st->top++;
        st->s[st->top] = x;
    }
    
}

int pop(struct Stack *st){
    
    int x = -1;
    
    if(st->top == -1){
        printf("Stack underflow\n");
    }
    else{
        x = st->s[st->top];
        st->top--;
    }
    
    return x;
}

int peek(struct Stack st, int pos){
    int x = -1;
    if(st.top-pos+1 < 0){
        printf("Invalid Position\n");
    }
    else{
        x = st.s[st.top-pos+1];
    }
    return x;
}

int stackTop(struct Stack st){
    if(st.top == -1){
        return -1;
    }
    else{
        return st.s[st.top];
    }
}

int isStackFull(struct Stack st){
    if(st.top == st.size - 1){
        return 1;
    }
    else{
        return 0;
    }
}

int isStackEmpty(struct Stack st){
    if(st.top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int main()
{
    struct Stack st;
    int size;
    printf("Enter size of Stack:\n");
    scanf("%d", &size);
    int *p = (int *)malloc(size*sizeof(int));
    int top = -1;
    
    initializeStack(&st, p, top, size);
    
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    pop(&st);
    printf("Is Stack Empty: %d\n", isStackEmpty(st));
    printf("Is Stack Full: %d\n", isStackFull(st));
    printf("Top element in stack: %d\n", stackTop(st));
    
    return 0;
}
