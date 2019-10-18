/*
 * Implementation of the Stack data structure.
 * Insertion and Remove with complexity of O(1).
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef struct{
    int size, maxSize;
    void* data;
} Stack;

 /*    FUNCTIONS    */ 
Stack* initStack( int numElements );
int isEmpty( Stack* s );
int isFull( Stack* s );
void push( Stack* s, void* element );
void* pop( Stack* s );
void print( Stack* s );

/* Initialize stack with size num_elements */
Stack* initStack( int numElements ) 
{
    Stack* s = malloc(sizeof(Stack));
    s->data = (void*) malloc(numElements * sizeof(void*)); 
    s->size = 0;
    s->maxSize = numElements;
    return s;
}

/* Return 1 if the is no element in Stack,
 * return 0, otherelse
 * @param: Stack* - pointer with stack structure
 *
 * @return: 1 if stack is empty, 0 otherelse
 */
int isEmpty( Stack* s )
{
    if ( s->size == 0){
        return 1;
    }
    return 0;
}

/* Return 1 if the Stack is full,
 * return 0, otherelse
 * @param: Stack* - pointer to a stack structure 
 */
int isFull( Stack* s)
{
    if ( s->size == s->maxSize ){
        return 1;
    }
    return 0; 
}

/* Add element to the stack if it's not full 
 * @param: Stack* - pointer to a stack structure
 * @param: void* - value to be pushed in the stack
 */

void push( Stack* s, void* value )
{
    if ( ! isFull(s) ) {
        void* tail = s->data + (s->size * sizeof(void*));
        memcpy( tail, value, sizeof(void*));
        s->size++;
    }
    else {
        printf("ERROR: Stack reached max number of elements.");
    }
}

/* Remove last element from the Stack and return it 
 * @param: Stack* - pointer to a stack structure
 */
void* pop( Stack* s)
{
    void* value = NULL;
    if ( ! isEmpty(s) ){
        value = s->data + s->size * sizeof(void*);
        s->size--;
    }
    else {
        printf("ERROR: There are no elements to be poped.");
    }
    return value;     
}

/* Print elements of Stack s, separated by spaces. 
 * @param: Stack* - pointer to a stack structure
 *
 */
void print(Stack *s){
    int i;
    for (i=0; i<s->size; i++) {
        void* value = s->data + ( i * sizeof(void*) );
        printf("%d ",  *((int*) value));
    }
    printf("\n");
}

/* Compare a void array with an int array 
 * This function is used to assertion in main function.
 * @param: void* - array with void type elements
 * @param: int* - array with integer type elements
 */
int compareVoidInt( void* voidArray, int* intArray, int size )
{
    int i;
    for ( i=0; i<size; i++ ){
        int voidElem = *(int*) (voidArray + i*sizeof(void*));
        int intElem = intArray[i];
        if ( voidElem != intElem ){
            return 0;
        }
    }  
    return 1;
}

/*
 * This main function will also work as
 * a type of unit test. So the functions
 * can be verified.
 */
void main() {

    int i, element; 
    const int NUM_ELEMENT=10;
    Stack *s = initStack(NUM_ELEMENT);
   
    /*===   TEST PUSH  ========== */ 
    printf("Test push\n");
    int array[10] = {2, 10, 49, -3, 29, 58, 100, 1, 42, 34};
    
    for (i=0; i<NUM_ELEMENT; i++) {
        push( s, (void*) &(array[i]));
    }
    assert( compareVoidInt( s->data, array, NUM_ELEMENT ) );

    /*===   TEST POP  =========== */ 
    printf("Test pop\n");
    int halfArray[5] = {2, 10, 49, -3, 29};
    for (i=0; i<NUM_ELEMENT/2; i++) {
        pop( s );
    }
    assert( compareVoidInt( s->data, array, NUM_ELEMENT/2 ));

    /*===   TEST STACK FULL ====== */ 
    printf("Test stack full\n");
    free(s->data);
    free(s);
    s = initStack(NUM_ELEMENT);

    for (i=0; i<NUM_ELEMENT; i++) {
        push( s, (void*) &(array[i]));
    }
    assert( isFull( s ) );
    assert( !isEmpty( s ) );

    /*===   TEST STACK EMPTY ===== */ 
    printf("Test stack void\n");
    for (i=0; i<NUM_ELEMENT; i++){
        pop( s );
    }
    assert( isEmpty( s ) );
    assert( !isFull( s ) );

    printf("========================\n");
    printf("= Passed in all tests. =\n");
    printf("========================\n");

    free(s->data);
    free(s);    
}
