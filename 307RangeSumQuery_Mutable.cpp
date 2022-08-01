// 배열 nums가 주어지면 update(배열의 저장되어 있는 변수 변경), sumRange(Left부터 Right까지의 합)를 구현하라
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
	//int SegmentHeight = ceil(log2(size(nums))+1); // memory optimization
	//int SegmentSize = pow(2, SegmentHeight);
	//SegmentTree.reserve();

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
// 세그먼트 트리를 이용해서 풀었다. 개념은 이해되는데 구현을 하기가 좀 까다로웠다. 인수가 많은게 흠인데 인수를 줄일 방법이 생각나지가 않는다.
// 세그먼트 트리는 기본적으로 주어진 데이터의양 *4를 하면 넉넉하다고 한다. 그런데 메모리를 절약해야 하는 상황이 발생할 수 있기 때문에 메모리 최적화를 해주는 코드도 넣어봤다.
// 메모리 최적화 코드를 제출했는데 시간은 더 오래걸리긴 
