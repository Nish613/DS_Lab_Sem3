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

 int BinSearch(int *arr,int low,int high,int key)
 {
   if(low>high)
   return 0;

   int mid = (low+high)/2;
   if(arr[mid]==key)
   return 1;

   else if(arr[mid]<key)
   return BinSearch(arr,low,mid-1,key);

   else 
   return BinSearch(arr,mid+1,high,key);
 }

 int AddArray(int *arr,int n)
 {
   if(n==0)
   return 0;
   return arr[n-1]+AddArray(arr,n-1);
 }

 int main()
 {
   printf("Enter no of ele : ");
   int n;
   scanf("%d",&n);

   int *arr = (int*)malloc(n*sizeof(int));
   printf("Enter sorted ele : ");
   for(int i=0;i<n;i++)
   {
      scanf("%d",&arr[i]);
   }

   printf("Enter ele to search : ");
   int key;
   scanf("%d",&key);
   int search = BinSearch(arr,0,n-1,key);
   if(search==1)
   printf("found\n");
   else
   printf("not found\n");

   printf("Sum : %d\n",AddArray(arr,n));
   free(arr);
   return 0;
 }
