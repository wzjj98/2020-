#include<iostream>
using namespace std;
int main()
{
	int a[100];
	int n = 0;
	scanf ("%d",&n);
	int max =0;
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		sum = (sum + a[i] > a[i]) ? (sum + a[i]) : a[i];
		max = (max > sum) ? max: sum;
	}
	printf("%d",max);
	return 0;
}