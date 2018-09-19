#include<stdio.h>
int binary_sea (const int *,int ,int );
int main (void)
{
	const int Arr[]={1,2,3,5,7,9,10,11,98};
	printf("位置是%d",binary_sea(Arr,12,9));
	return 0;
}



int binary_sea(const int *A,int X,int N)
{
	int Low = 0;
	int Hight = N-1;
	int Mid;

	while (1)
	{
		Mid = (Low + Hight) / 2;
		if (X < A[Mid])
		{
			Hight = Mid - 1;
		}
		else if(X > A[Mid])
		{
			Low = Mid + 1;
		}
		else if(X == A[Mid])
		{
			return Mid + 1;
		}
		else 
		{
			return -1;
		}
	}
}
