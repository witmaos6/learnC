// 1 부터 n 까지의 숫자가 한개 혹은 두개씩 있다. 이 때 중복된 숫자를 출력하라
// 시간복잡도는 O(N) 공간복잡도는 O(1)이 보장되어야 한다.

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums)
    {
        vector<int> Duplicates;
        int N = static_cast<int>(nums.size());
        
        for(int i = 0; i < N; i++)
        { 
            int IndexOfElem = abs(nums[i]) - 1;
            
            nums[IndexOfElem] *= -1; // 이것을 else if(nums[IndexOfElem] > 0) 조건에서 실행되게 바꾼다면 중복된 원소가 3개 이상일 때도 수행이 가능한 코드가 될것 같다.
                                      // 물론 출력 조건에 따라서 또 달라진다.
            
            if(nums[IndexOfElem] > 0)
            {
                Duplicates.push_back(IndexOfElem + 1);
            }
        }

        return Duplicates;
    }
};

// 첫번 째 솔루션은 정렬을 한 뒤 중복된 원소들을 Duplicates에 입력하는 것이었다.
// 이 때 정렬함수의 시간복잡도는 O(NlogN)이므로 이 부분이 병목점이 되어 O(N) 시간복잡도를 보장해 줄 수 없게 된다.

// 해시테이블을 사용할 경우에 시간복잡도를 O(N)으로 만들 수 있지만 공간복잡도는 O(N)이 되기 때문에 마찬가지로 안된다.
// 물론 정렬이나 해시테이블을 사용하는 솔루션은 패스가 되긴 한다.

// 위에 솔루션 처음보고 감탄했다. nums의 원소들은 1 부터 N까지의 원소들 이라는 조건이 있기 때문에 이 조건을 이용하여 풀 수 있지 않을까 싶었지만 떠올리지 못했다.
// 물론 이 솔루션은 중복된 원소가 최대 2개라는 조건도 있기에 가능하다. 근데 코드를 약간 수정하면 3개 이상도 될 것 같다.
