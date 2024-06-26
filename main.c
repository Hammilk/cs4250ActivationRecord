#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

void f1();
void f2();
void f3();

int main(int argc, char *argv[])
{
    //f1();
    //f2();
    f3();

    return EXIT_SUCCESS;
}

void f1(){
    //Increments number of activation records
    static int n = 0;
    //Array of whatever
    char arr[SIZE];
    //Stores the starting address of the array
    static long int addr;
    
    long int arrSize = addr - (long int)&arr;
   
    n++;
    addr = (long int)&arr;
    printf("Call #%d   at %p\n", n, arr);
    printf("AR Size  #%d  is %li\n", n, arrSize);
    if(n < 10){
        f1();
    }
}

void f2(){
    //Increments number of activation records
    static int n = 0;
    //Array of whatever
    char arr[SIZE];
    //Stores the starting address of the array
    static long int addr;
    
    long int arrSize = addr - (long int)&arr;
   
    n++;
    addr = (long int)&arr;
    printf("Call #%d   at %p\n", n, arr);
    printf("AR Size  #%d  is %li\n", n, arrSize);
    printf("Stack Size   #%d   is %li\n", n, n * arrSize);
    f2();
}

void f3(){
    //Increments number of activation records
    static int n = 0;

    //Array of whatever
    char* arr;
    arr = (char *) malloc(SIZE * sizeof(char));
    //Stores the starting address of the array
    static long int addr;
    long int c = sizeof(arr);  
   
    n++;
    addr = (long int)&arr;
    printf("Call #%d   at %p\n", n, arr);
    printf("AR Size  #%d  is %li\n", n, c);
    if(n < 10){
        f3();
    }
    free(arr);
}


