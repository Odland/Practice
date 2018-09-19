//求最大子序列和
#include<stdio.h>
#include<time.h>
#include<string.h>

int Maxsum (const int *a, int n);


int main (void)
{
	unsigned s=clock();
	const int a[8]= {4,-3,5,-2,-1,2,6,-2};
	printf ("最大和为%d\n",Maxsub(a,8));
	printf("耗费时间为%ld\n",clock()-s);
	return 0;
}

int Maxsub (const int *a,int n)
{
	int i,j,k;
	int Maxsum = 0;
	int thissum;
	for(i = 0;i < n;i++)
		{
			for(j = i; j < n; j++)
			{
				thissum = 0;
				for(k = i; k <= j; k++)
				{
					thissum += a[k];
					if (Maxsum < thissum)
					{
						Maxsum = thissum;
					}
				}
			}
		}
	return Maxsum;	
}
