#include <stdio.h>

int Maxsubsum (const int *,int,int);
int Max (int,int,int);

int main (void)
{
	int arr[6]= {2,-7,9,-6};
	printf ("最大子序列和是%d",Maxsubsum(arr,0,3));
	return 0;
}
int Maxsubsum (const int *arr,int left,int right)
{
	int Maxleftsum,Maxrightsum;
	int Maxleftbordersum,Maxrightbordersum;
	int leftbordersum,rightbordersum;
	int center,i;
	
	if (left == right)
	{
		if (arr[left] > 0)
		{
			return arr[left];
		}
		else return 0;
	}
	center = (left + right) / 2;
	Maxleftsum = Maxsubsum (arr,left,center);
	Maxrightsum = Maxsubsum (arr,center + 1,right);

	Maxleftbordersum = 0;
	leftbordersum = 0;
	for (i = center; i >= left; i--)
	{
		if (leftbordersum > Maxleftbordersum)
		{
			Maxleftbordersum = leftbordersum;
		}
	}
	Maxrightbordersum = 0;
	rightbordersum = 0;
	for (i = center + 1; i <= right; i++)
	{
		rightbordersum += arr[i];
		if (rightbordersum > Maxrightbordersum)
		{
			Maxrightbordersum = rightbordersum;
		}
	}
	//printf ("三个数分别是%d\t%d\t%d",Maxleftsum,Maxrightsum,Maxleftsum+Maxrightsum);

	return Max(Maxleftsum,Maxrightsum,Maxleftsum + Maxrightsum);
}
int Max(int Maxleft,int Maxright,int sum)
{
	//sum = Maxleft + Maxright;
	return  sum > (Maxleft > Maxright ? Maxleft : Maxright) ? sum : (Maxleft > Maxright ? Maxleft : Maxright);
}
