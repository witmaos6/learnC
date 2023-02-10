class Solution {
    const int Wall = 0;
    typedef tuple<int, int, int> Point;

    int RowSize = 0;
    int ColSize = 0;
    vector<pair<int, int>> Dirs = { {1,0},{-1,0},{0,1},{0,-1} };
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> Rank; // 이것도 typedef PQ같은 걸로 바꾸는게 나을지도 모르겠다.
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k)
    {
        RowSize = static_cast<int>(grid.size());
        ColSize = static_cast<int>(grid[0].size());

        queue<Point> BFS;
        BFS.push({0, start[0], start[1]});

        while(!BFS.empty())
        {
            size_t NrOfRange = BFS.size();

            for(size_t i = 0; i < NrOfRange; i++)
            {
                auto [Distance, Row, Col] = BFS.front();
                BFS.pop();
                Distance++;

                if(grid[Row][Col] != Wall)
                {
                    if(bIsValidPrice(grid[Row][Col], pricing))
                    {
                        Rank.push({Distance, grid[Row][Col], Row, Col});
                    }

                    grid[Row][Col] = Wall;

                    for(auto& p : Dirs)
                    {
                        int NextRow = Row + p.first;
                        int NextCol = Col + p.second;

                        if(bInBoundary(NextRow, NextCol) && grid[NextRow][NextCol] != Wall)
                        {
                            BFS.push({Distance, NextRow, NextCol});
                        }
                    }
                }
            }
        }

        return SetRank(k);
    }

private:
    bool bInBoundary(const int& row, const int& col)
    {
        if(row >= 0 && row < RowSize && col >= 0 && col < ColSize)
        {
            return true;
        }
        return false;
    }

    bool bIsValidPrice(const int& price, const vector<int>& pricing)
    {
        if(price >= pricing[0] && price <= pricing[1])
        {
            return true;
        }
        return false;
    }

    vector<vector<int>> SetRank(int& k)
    {
        vector<vector<int>> Result;
        
        while(!Rank.empty() && k > 0)
        {
            int Row = Rank.top()[2];
            int Col = Rank.top()[3];

            Result.push_back({Row, Col});
            Rank.pop();
            k--;
        }

        return Result;
    }
};

// BFS문제인데 꽤 골치 아팠다. BFS는 DFS보다 구현이 좀 더 어렵다고 하는데 확실히 처리 순서를 조금만 잘 못해도 오답이 나온다.
// DP를 사용할 수도 있을 것 같긴한데 일단 코드들이 너무 더러워서 나중에 해봐야겠다.
