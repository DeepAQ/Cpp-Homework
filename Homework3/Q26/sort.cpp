#include "sort.h"

void sortColors(int* nums, int numSize) {
	int colors[3];
	colors[0] = colors[1] = colors[2] = 0;
	for (int i=0; i<numSize; i++)
		colors[nums[i]]++;
	int s = 0;
	for (int i=0; i<3; i++)
		for (int j=0; j<colors[i]; j++) {
			nums[s] = i;
			s++;
		}
}
