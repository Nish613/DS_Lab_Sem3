/* Solve the problem of searching for an element in a list of numbers and 
finding the sum of all the
 numbers in a list of numbers using a C program.
 Create the list of numbers (1D array) using dynamic memory allocation 
 functions in the main function.
 Write a recursive function called BinSearch which accepts two integer 
 pointers and an integer
 which is the element to be searched, to search whether the element exists 
 in the array or not.
 Write a recursive function AddArray which accepts an integer pointer and 
 an integer to find the sum of the elements in the array.
 Test the above two functions from the main function.*/

 #include<stdio.h>
 #include<stdlib.h>
 
 int main()
 {
    printf("Enter no of ele : ");
    int n;
    scanf("%d",&n);

    int *a;
    a = (int)malloc(n*sizeof(int));

    
    return;
 }