/*AUTHOR - SATYAM RAMAWAT
Date - 12th May 2020
OpenMP program that processes all of the elements of a list in parallel.
Performed by the Linear search algorithm

Program has been run in MacOS 3.1 GHz Dual-Core Intel Core i5
Used: Clang
clang -Xpreprocessor -fopenmp -lomp linearsearchOpenMp.c -o ls
*/

#include<stdio.h>
#include <omp.h>

int main()
{
	int a[100],n,i,search,found=0;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a[i]=i;
		printf("%d",a[i]);
	}
	
	printf("Enter the number to search:");
	scanf("%d",&search);
	
    #pragma omp parallel for num_threads(50)
	for(i=0;i<n;i++)
	{
		if(a[i]==search)
		{
			printf("The element is present at location %d",i+1);
			found=1;
		}
	}
	if(found==0)
	{
		printf("The element is not found");
	}
	return 0;
}