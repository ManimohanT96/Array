// maximum subArray sum problem

#include <iostream>
#include <climits>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	// Brute force Approach - O(n3)

	/*int maxSum = INT_MIN;
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			int sum = 0;
			for(int k=i; k<=j; k++){
				sum += arr[k];
				//cout<<arr[k]<<" ";
			}
			//cout<<endl;
			maxSum=max(maxSum, sum);
		}
	}*/

	// cumiletive Sum Approach- O(n2)

	/*int currSum[n+1];
	currSum[0] = 0;
	
	for(int i=1; i<=n; i++){
		currSum[i] = currSum[i-1]+arr[i-1];
	}
	
	int maxSum = INT_MIN;
	for(int i=1; i<=n; i++){
		int sum=0;
		for(int j=0; j<i; j++){
			sum = currSum[i]-currSum[j];
			maxSum = max(sum, maxSum);
		}
	}*/

	// Kadane's Algorithm - O(n)

	int currentSum = 0;
	int maxSum = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		currentSum += arr[i];

		if (maxSum < currentSum)
			maxSum = currentSum;

		if (currentSum < 0)
			currentSum = 0;
		//maxSum = max(maxSum, currentSum);
	}

	cout << maxSum << endl;
	return 0;
}
