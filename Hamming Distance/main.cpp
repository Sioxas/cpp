/**
Hamming Distance

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ¡Ü x, y < 2^31.

Example:
Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
	   ¡ü   ¡ü

The above arrows point to positions where the corresponding bits are different.


Total Hamming Distance

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Now your job is to find the total Hamming distance between all pairs of the given numbers.

Example:
Input: 4, 14, 2

Output: 6

Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case). So the answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
Note:
Elements of the given array are in the range of 0 to 10^9
Length of the array will not exceed 10^4.

**/


#include<iostream>
#include<vector>
#include<numeric>

using namespace std;


int hammingDistance(int x, int y) {
	int z = x^y;
	int n = 0;
	while (z > 0) {
		if ((z & 1) == 1)
			n++;
		z >>= 1;
	}
	return n;
}

int accumulateHammingDistance(vector<int>& nums) {
	return accumulate(nums.begin(), nums.end(), 0, [](int x, int y)->int {
		int z = x^y;
		int n = 0;
		while (z > 0) {
			if ((z & 1) == 1)
				n++;
			z >>= 1;
		}
		return n;
	});
}

int totalHammingDistance(vector<int>& nums) {
	int n = 0;
	for (vector<int>::iterator i = nums.begin(); i != nums.end(); ++i)
		for (vector<int>::iterator j = i + 1; j != nums.end(); ++j)
			//n += hammingDistance(*i, *j);
			n += [](int x, int y)->int {
			int z = x^y;
			int n = 0;
			while (z > 0) {
				if ((z & 1) == 1)
					n++;
				z >>= 1;
			}
			return n;
		}(*i, *j);
		return n;
}

int main() {
	vector<int> nums = { 4,14,2 };
	//cout << hammingDistance(1, 4) << endl;
	cout << totalHammingDistance(nums) << endl;
	system("pause");
	return 0;
}