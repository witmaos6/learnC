// 시작지점은 1, 도착지점은 2, 갈 수 있는 경로는 0, 갈 수 없는 경로는 -1일 때, 시작점에서 도착점까지 모든 경로를 순회하며 grid를 지나는 경우의 수를 구하라.

struct Point
{
    int X;
    int Y;
    Point() : X(0), Y(0) {}
    Point(int x, int y) : X(x), Y(y) {}
};

class Solution 
{
public:
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        RowSize = static_cast<int>(grid.size());
        ColSize = static_cast<int>(grid[0].size());

        for(int row = 0; row < RowSize; row++)
        {
            for(int col = 0; col < ColSize; col++)
            {
                int Cell = grid[row][col];
                
                if(Cell == Path)
                {
                    NumberOfPath++;
                }
                else if(Cell == Start)
                {
                    StartPoint.X = row;
                    StartPoint.Y = col;
                }
            }
        }

        DFS(grid, Point(StartPoint.X + 1, StartPoint.Y));
        DFS(grid, Point(StartPoint.X - 1, StartPoint.Y));
        DFS(grid, Point(StartPoint.X, StartPoint.Y + 1));
        DFS(grid, Point(StartPoint.X, StartPoint.Y - 1));

        return Result;
    }

private:
    const int Start = 1;
    const int End = 2;
    const int Path = 0;
    const int InValidPath = -1;
    int RowSize = 0;
    int ColSize = 0;
    Point StartPoint;
    int NumberOfPath = 0;
    int Result = 0;

    void DFS(vector<vector<int>>& grid, Point p)
    {
        if(bValidPath(p) && grid[p.X][p.Y] != InValidPath)
        {
            int Cell = grid[p.X][p.Y];
            if(Cell == Path)
            {
                grid[p.X][p.Y] = InValidPath;
                NumberOfPath--;

                DFS(grid, Point(p.X + 1, p.Y));
                DFS(grid, Point(p.X - 1, p.Y));
                DFS(grid, Point(p.X, p.Y + 1));
                DFS(grid, Point(p.X, p.Y - 1));

                grid[p.X][p.Y] = Path;
                NumberOfPath++;
            }
            else
            {
                if(Cell == End && NumberOfPath == 0)
                {
                    Result++;
                }
            }
        }
    }

    bool bValidPath(const Point& p)
    {
        if(p.X >= 0 && p.X < RowSize && p.Y >= 0 && p.Y < ColSize)
        {
            return true;
        }
        return false;
    }
};

// 모든 경로를 지나며 도착점에 가야한다는 점 때문에 처음에는 한붓그리기와 비슷한 알고리즘으로 풀어야 하나 싶었다.
// 그런데 brute force로 먼저 풀었봤는데 답이라서 조금 당황했다. hard문제라고 지레 겁먹었던것 같기도하다.
