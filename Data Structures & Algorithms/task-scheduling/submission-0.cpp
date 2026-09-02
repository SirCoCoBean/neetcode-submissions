class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       // map to count frquenct 
       // priority_queue to keep track availble 
       // keep track of unvalible 
       // keep time to keep track of cycle

       int time = 0;

       unordered_map<char,int> freq;
       priority_queue <pair <int, char>> available;
       queue<tuple<int, int, char>> unavailable;
       // first  = release time
        //second = remaining count
        //third  = task

       for (auto& c: tasks) {
        freq[c]++;
       }

       for (auto& pairs : freq) {
        available.push({pairs.second, pairs.first});
       }

       while (!available.empty() || !unavailable.empty()) {
        time ++;

            if (!unavailable.empty() && get<0> (unavailable.front()) <= time) {
                auto [releaseTime, count, task] = unavailable.front();
                unavailable.pop();

            available.push({count, task});
        }

        if (!available.empty()) {

        auto [count, task] = available.top();
        count--;
        available.pop();

        

        // 3. If more copies remain, cooldown
        if (count > 0) {
            unavailable.push({
                time + n + 1,
                count,
                task
            });
        }
    }


    // 1. Check whether something finishes cooldown

    // 2. If a task is available:
    //       run it
    //       decrease its count
    //
    //       if count > 0:
    //           put it into cooldown

    // 3. Otherwise:
    //       this cycle is idle
       }

        return time;


    }
};
