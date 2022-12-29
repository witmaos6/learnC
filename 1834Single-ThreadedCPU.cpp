// Single-ThreadedCPU 구현
struct Task
{
    int Index;
    int EnqueueTime;
    int ProcessingTime;
    Task(int index, int enqueue, int process) : Index(index), EnqueueTime(enqueue), ProcessingTime(process) {}
};

struct CPUcompare
{
    bool operator()(const Task& a, const Task& b)
    {
        if(a.EnqueueTime == b.EnqueueTime)
        {
            if(a.ProcessingTime == b.ProcessingTime)
            {
                return a.Index > b.Index;
            }
            return a.ProcessingTime > b.ProcessingTime;
        }
        return a.EnqueueTime > b.EnqueueTime;
    }
};

struct TaskCompare
{
    bool operator()(const Task& a, const Task& b)
    {
        if(a.ProcessingTime == b.ProcessingTime)
        {
            return a.Index > b.Index;
        }
        return a.ProcessingTime > b.ProcessingTime;
    }
};

class Solution 
{
public:
    vector<int> getOrder(vector<vector<int>>& tasks) 
    {
        vector<int> CompleteTask;
        priority_queue<Task, vector<Task>, CPUcompare> CPU;

        for(int i = 0; i < tasks.size(); i++)
        {
            CPU.push(Task(i, tasks[i][0], tasks[i][1]));
        }
        
        priority_queue<Task, vector<Task>, TaskCompare> AvailableTasks;

        AvailableTasks.push(CPU.top());
        CPU.pop();
        unsigned int Time = AvailableTasks.top().EnqueueTime;
        while(!CPU.empty() && AvailableTasks.top().EnqueueTime == CPU.top().EnqueueTime)
        {
            AvailableTasks.push(CPU.top());
            CPU.pop();
        }    

        while(!AvailableTasks.empty())
        {
            Task CurrentTask = AvailableTasks.top();
            AvailableTasks.pop();

            Time += CurrentTask.ProcessingTime;
            CompleteTask.push_back(CurrentTask.Index);

            if(AvailableTasks.empty())
            {
                if (Time < CPU.top().EnqueueTime)
                {
                    Time += CPU.top().EnqueueTime - Time;
                }
            }
            while(!CPU.empty() && Time >= CPU.top().EnqueueTime)
            {
                AvailableTasks.push(CPU.top());
                CPU.pop();
            }
        }

        return CompleteTask;
    }
};

// 코드가 너무 복잡하다고 생각했는데 다른 사람들의 코드를 보니 크게 다르지는 않았다.
// compare를 하나만으로 해결할 수는 없나 생각했지만 도저히 떠오르지 않았다.
