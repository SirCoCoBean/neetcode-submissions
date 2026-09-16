class Solution {
public:
    unordered_map<char,int> freq;
    priority_queue<pair<int,char>> ava;
    queue <tuple<int, int, char>> unava;
    // first  = release time
        //second = remaining count
        //third  = task

    int time = 0;
    int leastInterval(vector<char>& tasks, int n) {

        for (auto& c:tasks) {// creates the freq map
            freq[c]++;
        }

        for (auto& pairs:freq) {
            ava.push({pairs.second,pairs.first}); // adding freq to a prioQ
        }

        while (!ava.empty() || !unava.empty()) {
            time++;
        if (!unava.empty() && get<0> (unava.front()) <= time) {
            // checking our unavaQ, and if the release timer matches is less than or equal to time
            auto[release_timer,remaining_count, task] = unava.front();
            unava.pop();
            ava.push({remaining_count, task});
            
        }

        if (!ava.empty()) {
            auto[count, task] = ava.top();
            count--;
            ava.pop();

            if (count > 0) {
                unava.push({
                time + n + 1,
                count,
                task
            });
            }
        }
            
        }
        

    return time;
        
    }
};
