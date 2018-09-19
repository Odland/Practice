#include<stdio.h>
int Maxsub(const int *arr,int n);
int main (void) 
{
	const int arr[3]= {1,4,-5};
	printf("最大的子序列和是%d\n",Maxsub(arr,3));
	return 0;
}

int Maxsub (const int *arr,int n)
{
	int i,j;
	int Maxsum = 0;
	int thissum;
	for(i = 0;i < n; i++)
	{
		thissum = 0;
		for(j = i;j < n;j++)
		{
			thissum += arr[j];
			if (thissum > Maxsum)
			{
				Maxsum = thissum;
			}
		}
	}
	return Maxsum;
}
