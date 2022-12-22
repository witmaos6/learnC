// 노드의 개수 n과 간선 정보 edges가 주어진다. 이 때 각 노드에서 다른 리프노드의 경로의 합을 구하여라.

class Solution
{
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges)// O(n ^ 2)
    {
        Result.resize(n);
        Subtree.resize(n);
        SetGraph(n, edges);

        DFSCountSubtree(0 ,-1);
        
        DFS(0, -1 ,n);
        
        return Result;
    }

private:
    vector<int> Result;
    vector<int> Subtree;
    vector<vector<int>> Graph;

    void SetGraph(const int& n, vector<vector<int>>& edges)
    {
        Graph.resize(n);

        for(vector<int>& edge : edges)
        {
            Graph[edge[0]].push_back(edge[1]);
            Graph[edge[1]].push_back(edge[0]);
        }
    }

    void DFSCountSubtree(int currentNode, int parent)
    {
        for(int& child : Graph[currentNode])
        {
            if(child != parent)
            {
                DFSCountSubtree(child, currentNode);
            
                Subtree[currentNode] += Subtree[child];
            
                Result[currentNode] += Result[child] + Subtree[child];
            }
        }
        
        Subtree[currentNode] += 1;
    }
    
    void DFS(int currentNode, int parent, const int& n)
    {
        for(int& child : Graph[currentNode])
        {
            if(child != parent)
            {
                Result[child] = Result[currentNode] + (n - 2 * Subtree[child]);
            
                DFS(child, currentNode, n);
            }
        }
    }
};

// 상당히 까다로운 문제였다. 전체 탐색 문제기 때문에 DP로 풀어야 했는데 여전히 DP문제에 약하다는 걸 느꼈다.
