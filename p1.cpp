#include <iostream>

using namespace std;

int max(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}

int longestZigZag(int a[], int n)
{

	int dp[n][2];

	int max_length = 1;

	for(int i=0; i<n; i++)
	{	
		//initialize all values to 1
		dp[i][0] = 1;
		dp[i][1] = 1;
	}

	for(int i=1; i< n; i++)
	{
		for(int j=0; j<i; j++)
		{
			if(a[j] < a[i] && dp[i][0] < dp[j][1] + 1)
				dp[i][0] = dp[j][1] + 1;
			if(a[j] > a[i] && dp[i][1] < dp[j][0] + 1)
				dp[i][1] = dp[j][0] + 1;
		}

		if(max_length < max(dp[i][0], dp[i][1]))
			max_length = max(dp[i][0], dp[i][1]);

	}

	return max_length;
}




int main()
{
	int n;
	int arr1[] = {1,7,4,9,2,5};
	n = sizeof(arr1)/sizeof(int);
	cout << longestZigZag(arr1,n) << endl;

	int arr2[] = { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 };
	n = sizeof(arr2)/sizeof(int);
	cout << longestZigZag(arr2,n) << endl;

	int arr3[] = {44};
	n = sizeof(arr3)/sizeof(int);
	cout << longestZigZag(arr3,n) << endl;

	int arr6[] = 	
{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	n = sizeof(arr6)/sizeof(int);
	cout << longestZigZag(arr6,n) << endl;

	int arr4[] = { 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 };
	n = sizeof(arr4)/sizeof(int);
	cout << longestZigZag(arr4,n) << endl;

	int arr5[] =  	
{ 374, 40, 854, 203, 203, 156, 362, 279, 812, 955, 
600, 947, 978, 46, 100, 953, 670, 862, 568, 188, 
67, 669, 810, 704, 52, 861, 49, 640, 370, 908, 
477, 245, 413, 109, 659, 401, 483, 308, 609, 120, 
249, 22, 176, 279, 23, 22, 617, 462, 459, 244 };
	n = sizeof(arr5)/sizeof(int);
	cout << longestZigZag(arr5,n) << endl;

}