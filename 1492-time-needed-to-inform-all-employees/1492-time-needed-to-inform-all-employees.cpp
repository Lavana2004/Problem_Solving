#define P pair<int,int>
class Solution 
{
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        if(n == 1) return 0;
        
        queue<P> q;
        unordered_map<int , vector<int>> mp;
        int time = 0;

        for(int i = 0; i < n; i++)
        {
            if(manager[i] != -1)
            {
                mp[manager[i]].push_back(i);
            }
        }

        q.push({headID, 0}); 
        
        while(!q.empty())
        {
            auto [node, curr] = q.front();
            q.pop();

            time = max(time, curr); 

            for(auto subordinate : mp[node])
            {
                q.push({subordinate, curr + informTime[node]});
            }
        }

        return time;
    }
};