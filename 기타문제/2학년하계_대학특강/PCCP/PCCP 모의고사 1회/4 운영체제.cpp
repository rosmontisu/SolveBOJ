#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

vector<long long> solution(vector<vector<int>> program) {
    vector<long long> answer(11, 0);

    sort(program.begin(), program.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> ready_pq;

    long long current_time = 0;
    int program_idx = 0;

    while (program_idx < program.size() || !ready_pq.empty()) {
        while (program_idx < program.size() && program[program_idx][1] <= current_time) {
            ready_pq.push({program[program_idx][0], program[program_idx][1], program[program_idx][2]});
            program_idx++;
        }

        if (ready_pq.empty()) {
            current_time = program[program_idx][1];
            continue;
        }

        int priority, call_time, run_time;
        tie(priority, call_time, run_time) = ready_pq.top();
        ready_pq.pop();

        answer[priority] += (current_time - call_time);
        current_time += run_time;
    }

    answer[0] = current_time;

    return answer;
}