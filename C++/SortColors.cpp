/*
 * Sort Colors 
 *	Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 *
 *	Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 *
 *	Note:
 *		You are not suppose to use the library's sort function for this problem.
 *
 *	Follow up:
 *		A rather straight forward solution is a two-pass algorithm using counting sort.
 *		First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
 *
 *		Could you come up with an one-pass algorithm using only constant space?
 */


class Solution {
public:
    void sortColors2(int A[], int n) {
        int head = 0;
		int tail = n-1;
		for (; head < tail; ++head) {
			if (A[head] != 0) {
				for (; tail > head; --tail) {
					if (A[tail] == 0) {
						A[tail] = A[head];
						A[head] = 0;
						break;
					}
				}
				//if not found, end loop
				if (tail <= head)
					break;
			}
		}
		for (tail = n-1;tail > head; --tail) {
			if (A[tail] == 1) {
				for (; head < tail; ++head) {
					if (A[head] == 2) {
						A[tail] = 2;
						A[head] = 1;
						++head;
						break;
					}
				}
			}
		}
    }
	void sortColors(int A[], int n) {
		int count0 = 0;
		int count1 = 0;
		int count2 = 0;
		int i = 0;
		for (i=0; i<n; ++i)	{
			if (A[i] == 0)
				++count0;
			else if (A[i] == 1)
				++count1;
		}
		count2 = n - count0 - count1;
		for (i=0; i<count0; ++i) {
			A[i] = 0;
		}
		for (i=count0; i<count0+count1; ++i) {
			A[i] = 1;
		}
		for (i=count0+count1; i<n; ++i) {
			A[i] = 2;
		}
	}
};
