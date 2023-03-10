// 배열 weights가 주어진다.
// weight[i] 가 나올 확률은 weights[i] / Sum(Weights.begin(), Weights.end()) 다. PickIndex 함수를 구현하라.
// 쉽게 말해 weights는 가중치고 가중치가 있는 랜덤함수를 구현하란 뜻.
class Solution {
    typedef pair<int, int> Range;

    int N = 0;
    int Sum = 0;
    vector<Range> Ranges;
public:
    Solution(vector<int>& Weights)
    {
        N = static_cast<int>(Weights.size());

        Sum = accumulate(Weights.begin(), Weights.end(), 0);

        Ranges.resize(N);
        Ranges[0] = {0, Weights[0] - 1};

        for(int i = 1; i < N; i++)
        {
            int Prev = Ranges[i - 1].second;
            Ranges[i] = {Prev + 1, Prev + Weights[i]};
        }
    }
    
    int pickIndex()
    {
        int Random = (rand() % Sum);
        int Low = 0, High = N - 1;

        while(Low < High)
        {
            int Mid = (High + Low) >> 1;

            if(Random >= Ranges[Mid].first && Random <= Ranges[Mid].second)
            {
                return Mid;
            }
            else if(Random > Ranges[Mid].second)
            {
                Low = Mid + 1;
            }
            else if(Random < Ranges[Mid].first)
            {
                High = Mid - 1;
            }
        }

        return Low;
    }
};

// Random 함수를 구현하는 문제들을 풀어봤다. linked list, vector 에서 랜덤 뽑기 마지막으로 가중치를 넣는 이번 문제해서 총 3문제
// 내가 푼 알고리즘은 Ranges vector를 만든 뒤 이진탐색하는 방식이다. pair를 이용하여 begin과 end값을 넣고 Random이 이 안에 포함되면 반환하는 형식인데
// 하나의 int로도 가능할 것 같다.
