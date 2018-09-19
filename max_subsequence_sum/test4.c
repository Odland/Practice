#include <stdio.h>
int Maxsubsum (int *,int);
int main (void)
{
	int arr[] = {-20,30,-5,-8,9,-10};
	printf ("最大的子序列和为:%d",Maxsubsum(arr,6));
	return 0;
}

int Maxsubsum(int *arr,int n)
{
	int thissum,Maxsum,j;

	thissum = Maxsum = 0;

	for (j = 0;j < n;j++)
	{
		thissum += arr[j];
		if (Maxsum < thissum)
		{
			Maxsum = thissum;
		}
		else if (thissum < 0)
		{
			thissum = 0;
		}
	}
	return Maxsum;
}
