/*
 * head -> e1 -> e2 -> tail
 *
 */

#include<stdio.h>

typedef struct{
    void* data;
    int* next;
} Element;

typedef struct{
    Element *head, *tail; 
    int size, maxSize;
    Element* data;
} Stack;

/*===============================
 * Functions
 ===============================*/
Stack* initStack(int numElements);
int push(Stack* s, void* element);
int pop(void* element);
void print(Stack *s);

/* Initialize stack with size num_elements */
Stack* initStack(int numElements) 
{
    Stack* s = malloc(sizeof(Stack));
    s->data = (Element*) malloc(numElements * sizeof(Element)); 
    s->size = 0;
    s->maxSize = numElements;
    s->head = NULL;
    s->tail = NULL;
    return s;
}

/* Add element to the stack if it's not full */
int push( Stack* s, void* element )
{
    if ( s->size < s->maxSize ) {
        Element* e = malloc( sizeof( Element*) );   
        (e->data) = element;
        e->next = NULL;

        if (s->head  == NULL) {
            s->head = e;
            s->tail = e;
        }
        else {
            s->tail->next = e; 
            s->tail = e;
        }
        s->size++;
    }
    else {
        printf("ERROR: Stack reached max number of elements.");
    }

    return 0;
}

void print(Stack *s){
    int i;
    Element *current = s->head;
    for (i=0; i<s->size; i++) {
        printf("%d ",  *((int*) current->data));
        current = current->next;
    }
    printf("\n");
}

void main() {

    int i, element;
    Stack *s = initStack(10);

    for (i=0; i<5; i++) {
        printf("Enter an integer: ");
        scanf("%d", &element); 
        push(s, (void*) &element);
        print(s);
    }
}


