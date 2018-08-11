/**

https://leetcode.com/problems/median-of-two-sorted-arrays/description/

4. Median of Two Sorted Arrays

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5


**/

#include<iostream>
#include<vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int t = nums1.size() + nums2.size(),n=0,i=0,j=0;
	if (t % 2 == 0) {
		t = t / 2;
		while (n < t) {

		}
	}
	else {

	}
}

int main() {

}