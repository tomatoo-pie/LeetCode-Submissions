class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);

        for(int i = 0 ; i < tasks.size(); i++){
            freq[tasks[i]-'A']++;
        }

        priority_queue<int> pq;
        for(int i = 0 ; i < freq.size(); i++){
            if(freq[i]>0)pq.push(freq[i]);
        }

        int time = 0;

        while(!pq.empty()){
            vector<int> temp;
            for(int i = 0 ;i <= n;i++){
                if(!pq.empty()){
                    int f = pq.top();
                    pq.pop();
                    f--;

                    if(f > 0)
                        temp.push_back(f);
                }
                time++;

                if(pq.empty() && temp.empty())
                    break;
            }

            for(int x : temp){
                pq.push(x);
            }
        }
        return time;
    }
};