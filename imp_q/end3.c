/*A set can be represented by a dynamic array of elements, 
where no repetition is permitted.
 Write C functions to perform the following operations on sets of 
 integer valued elements.
 i) int* BuildSet(int n): Read n number of elements and store them in a set
 ii) int SearchSet(int* A, int x): Search the set A to find if an element x 
 is in it.
 iii) Given two sets, compute the following.
 int* Union (int *A, int *B): To return the union of two sets A and B
 The main program should call the functions. All results should be stored 
 in their resultant sets and
 then display the results*/

#include<stdio.h>
#include<stdlib.h>
int final_size,sizea,sizeb,sizec;

int* BuildSet(int n)
{
  int *a = (int*)malloc(n*sizeof(int));
  int x,dup=0,count=0;

  printf("Enter ele : ");
  for(int i=0;i<n;i++)
  {
    scanf("%d",&x);
    dup=0;
    for(int j=0;j<count;j++)
    {
      if(x==a[j])
      {
        dup=1;
        break;
      }
      
    }
    if(dup==0)
    a[count++]=x;
  }
  a = (int*)realloc(a,count*sizeof(int));//since we remove duplicate ele new array size is lesser so we are resizing

  printf("\n");
  for(int i =0;i<count;i++)
  {
    printf("%d\t",a[i]);
  }
  final_size = count;
  sizea = final_size;
  sizeb = final_size;
  return a;
}

int SearchSet(int* a, int x)
{
  int flag=0;
  for(int i=0;i<final_size;i++)
  {
    if(x==a[i])
    {
      return 1;
    }
  }
  return 0;
}

int* Union (int *a, int *b)
{
  int count=0;
  int *c = (int*)malloc((sizea+sizeb)*sizeof(int));
  for(int i=0;i<sizea;i++)
  {
    c[count++] = a[i];
  }
  for(int i=0;i<sizeb;i++)
  {
    if(SearchSet(c,b[i])==0)
    c[count++] = b[i];
  }
  sizec = count;
  c = (int*)realloc(c,sizec*sizeof(int));

  printf("\n");
  for(int i=0;i<sizec;i++)
  {
    printf("%d\t",c[i]);
  }
  return c;
}

int main()
{
  printf("Enter no of ele : ");
  int n;
  scanf("%d",&n);
  int *a = BuildSet(n);

  printf("Enter ele to search : ");
  int key;
  scanf("%d",&key);

  int res = SearchSet(a, key);
  if(res==1)
  printf("Ele found");
  else
  printf("Ele not found\n");
  

  printf("Enter another set no of ele : ");
  int n2;
  scanf("%d",&n2);
  int *b = BuildSet(n2);

  int *c = Union(a,b);
  return 0;
}