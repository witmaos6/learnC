#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class NumArray {
public:
	vector<int> SegmentTree;
	unsigned int SegmentSize;

	NumArray(vector<int>& nums);
	void buildSegmentTree(vector<int>& nums, int segmentIndex, int Left, int Right);
	void update(int index, int val);
	void updateUtil(int index, int value, int position, int Left, int Right);
	int sumRange(int left, int right);
	int sumRangeUtil(int Left, int Right, int index, int sLeft, int sRight);
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> Nums = { 1,3,5 };

	NumArray numArray(Nums);
	numArray.sumRange(0, 2);
	numArray.update(1, 2);
	numArray.sumRange(0, 2);

	return 0;
}

NumArray::NumArray(vector<int>& nums)
{
	//double SegmentHeight = log2(size(nums)); // memory optimization
	//SegmentTree.reserve(ceil(SegmentHeight));

	SegmentSize = size(nums);
	SegmentTree.resize(SegmentSize * 4);
	buildSegmentTree(nums, 1, 0, SegmentSize - 1);
}

void NumArray::buildSegmentTree(vector<int>& nums, int segmentIndex, int Left, int Right)
{
	if (Left == Right)
	{
		SegmentTree[segmentIndex] = nums[Left];
	}
	else
	{
		int middle = Left + (Right - Left) / 2;
		buildSegmentTree(nums, 2 * segmentIndex, Left, middle);
		buildSegmentTree(nums, 2 * segmentIndex + 1, middle + 1, Right);
		SegmentTree[segmentIndex] = SegmentTree[2 * segmentIndex] + SegmentTree[2 * segmentIndex + 1];
	}
}

void NumArray::update(int index, int val)
{
	updateUtil(index, val, 1, 0, SegmentSize - 1);
}

void NumArray::updateUtil(int index, int value, int position, int Left, int Right)
{
	if (Left == Right)
	{
		SegmentTree[position] = value;
	}
	else
	{
		int middle = Left + (Right - Left) / 2;

		if (index <= middle)
		{
			updateUtil(index, value, 2 * position, Left, middle);
		}
		else
		{
			updateUtil(index, value, 2 * position + 1, middle + 1, Right);
		}
		SegmentTree[position] = SegmentTree[2 * position] + SegmentTree[2 * position + 1];
	}
}

int NumArray::sumRange(int left, int right)
{
	return sumRangeUtil(left, right, 1, 0, SegmentSize - 1);
}

int NumArray::sumRangeUtil(int Left, int Right, int index, int sLeft, int sRight)
{
	if (Left > Right)
	{
		return 0;
	}
	if (Left == sLeft && Right == sRight)
	{
		return SegmentTree[index];
	}
	int middle = sLeft + (sRight - sLeft) / 2;
	return sumRangeUtil(Left, min(Right, middle), 2 * index, sLeft, middle) +
		sumRangeUtil(max(Left, middle + 1), Right, 2 * index + 1, middle + 1, sRight);
}
