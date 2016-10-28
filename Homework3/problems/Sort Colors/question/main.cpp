#include "sort.h"


int main() {


	int numSize;

	cin >> numSize;

	int *nums = new int[numSize];

	for (int i = 0; i < numSize; i++) {
		cin >> nums[i];
	}

	sortColors(nums, numSize);

	for (int i = 0; i < numSize; i++) {
		cout << nums[i] << " ";
	}

	delete[] nums;

	return 0;
}