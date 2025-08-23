#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <utility> // pair 사용
#include <functional> // greater (for priority_queue)
#include <vector>     // 필요함

using namespace std;

// --- 상수 정의 ---
const int MAX_N = 10;
const int MAX_M = 10;
const int MAX_NODES = MAX_N * MAX_M;

// --- 전역 변수 정의 ---
int N, M;
int total_nodes;
char target_color;
vector<char> colors_palette = { 'r', 'g', 'b', 'y' };

// --- 이동 방향 배열 ---
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

// --- A* 상태 구조체 ---
struct State {
    vector<char> colors; // 현재 맵 색상 상태
    int g_cost;           // 실제 이동 횟수 (g(n))
    int h_cost;           // 휴리스틱 추정치 (h(n))
    // f_cost는 g_cost + h_cost

    // 우선순위 큐를 위한 비교 연산자 (f_cost가 작은 것을 우선)
    // priority_queue는 기본이 max-heap이므로, min-heap처럼 쓰려면 > 사용
    bool operator>(const State& other) const {
        return (g_cost + h_cost) > (other.g_cost + other.h_cost);
        // 만약 f_cost가 같다면 g_cost가 큰 것(덜 진행된 것)을 우선할 수도 있음 (Tie-breaking)
        // return (g_cost + h_cost) != (other.g_cost + other.h_cost) ?
        //        (g_cost + h_cost) > (other.g_cost + other.h_cost) : g_cost < other.g_cost;
    }
};

// --- 휴리스틱 함수: 목표 색깔이 아닌 컴포넌트 수 계산 ---
int calculate_heuristic(const vector<char>& current_node_colors) {
    int non_target_components = 0;
    vector<bool> visited_heuristic(MAX_NODES, false); // 휴리스틱 계산용 방문 배열

    for (int i = 0; i < total_nodes; ++i) {
        // 아직 방문 안했고, 목표 색깔이 아닌 노드 발견 시
        if (!visited_heuristic[i] && current_node_colors[i] != target_color) {
            non_target_components++; // 새로운 비목표 컴포넌트 발견
            queue<int> q_h; // 휴리스틱 계산용 내부 BFS 큐
            q_h.push(i);
            visited_heuristic[i] = true;

            // 해당 컴포넌트 전체를 방문 처리 (같은 컴포넌트 중복 카운트 방지)
            while (!q_h.empty()) {
                int current_h_node = q_h.front();
                q_h.pop();

                int y = current_h_node / M;
                int x = current_h_node % M;

                for (int k = 0; k < 4; ++k) {
                    int ny = y + dy[k];
                    int nx = x + dx[k];

                    if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
                        int neighbor_h_node = ny * M + nx;
                        // 아직 방문 안했고, *같은 색깔* 인 노드만 따라감 (컴포넌트 정의대로)
                        if (!visited_heuristic[neighbor_h_node] && current_node_colors[neighbor_h_node] == current_node_colors[i]) {
                             visited_heuristic[neighbor_h_node] = true;
                             q_h.push(neighbor_h_node);
                        }
                        // 다른 색이더라도, 이 휴리스틱 함수 범위 내에서는 방문 처리하여
                        // 다른 색 컴포넌트 탐색 시 중복으로 시작하지 않도록 함 (수정 필요할 수도 있음 - 아래 주석 참고)
                        //visited_heuristic[neighbor_h_node] = true; // 주의: 이렇게 하면 연결된 다른색 컴포넌트도 카운트 안될수 있음. 위 if문 내부가 맞음.
                    }
                }
            }
        }
         // 만약 방문 안 한 목표색 노드라도, 휴리스틱 계산 중복 방지를 위해 방문처리 필요할 수 있음
         // visited_heuristic[i] = true; // 이 로직을 넣을지 말지는 휴리스틱 설계에 따라 달라짐. 지금은 빼는게 나을듯.
    }
    return non_target_components;
}


// --- 메인 함수 시작 ---
int main()
{
    // --- 입출력 속도 최적화 ---
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // --- 기본 입력 받기 ---
    cin >> N >> M >> target_color;
    total_nodes = N * M;

    // --- 초기 맵 색상 상태 설정 ---
    vector<char> starting_map_colors(MAX_NODES, ' ');
    string row_str;
    for (int y = 0; y < N; y++)
    {
        cin >> row_str;
        for (int x = 0; x < M; x++)
            starting_map_colors[y * M + x] = row_str[x];
    }

    // --- A* 준비 (우선순위 큐 및 방문 셋 초기화) ---
    // priority_queue<State, vector<State>, greater<State>> pq; // min-heap
    priority_queue<State, vector<State>, greater<State>> pq; // State 구조체에 > 연산자를 정의했으므로 greater 사용

    set<vector<char>> visited; // 방문한 맵 색상 상태 저장 셋 (중복 방지)

    // --- 시작 상태 추가 ---
    int initial_h = calculate_heuristic(starting_map_colors);
    pq.push({ starting_map_colors, 0, initial_h }); // 초기 상태 추가 (g=0)
    visited.insert(starting_map_colors); // 초기 상태 방문 기록

    // --- A* 메인 루프 시작 ---
    while (!pq.empty()) // 우선순위 큐가 빌 때까지 반복
    {
        // --- 우선순위 큐에서 가장 좋아 보이는 상태 꺼내기 ---
        State current_state = pq.top();
        pq.pop();

        vector<char> current_node_colors = current_state.colors;
		int current_moves = current_state.g_cost; // 실제 이동 횟수

        // --- 목표 상태 확인 ---
        bool goal_reached = true;
        for (int i = 0; i < total_nodes; ++i)
        {
            if (current_node_colors[i] != target_color)
            {
                goal_reached = false;
                break;
            }
        }
        if (goal_reached)
        {
            cout << current_moves;
            return 0;
        }

        // --- 현재 상태에서 노드 그룹 처리 여부 추적 배열 초기화 ---
        // A*에서는 이 배열이 꼭 필요하지 않을 수 있음 (휴리스틱 기반 탐색)
        // 하지만, 같은 상태 내에서 동일 컴포넌트 변경 연산을 줄이는 최적화로는 유효. 유지.
        vector<bool> processed_node(MAX_NODES, false);

        // --- 모든 노드 순회하며 다음 상태 생성 ---
        for (int node_index = 0; node_index < total_nodes; ++node_index)
        {
            // --- 해당 노드가 속한 그룹이 아직 처리되지 않았다면 ---
            if (!processed_node[node_index])
            {
                char original_color = current_node_colors[node_index];

                // --- 현재 노드와 연결된 같은 색 노드 그룹 찾기 (좌표 기반 Inline BFS) ---
                vector<int> node_group_indices;
                queue<int> q_group;
                vector<bool> node_group_visited(MAX_NODES, false);

                q_group.push(node_index);
                node_group_visited[node_index] = true;

                while (!q_group.empty())
                {
                    int current_group_node_index = q_group.front();
                    q_group.pop();
                    node_group_indices.push_back(current_group_node_index);

                    int current_y = current_group_node_index / M;
                    int current_x = current_group_node_index % M;
                    for (int i = 0; i < 4; ++i)
                    {
                        int next_y = current_y + dy[i];
                        int next_x = current_x + dx[i];

                        if (next_y >= 0 && next_y < N && next_x >= 0 && next_x < M)
                        {
                            int neighbor_node_index = next_y * M + next_x;
                            if (!node_group_visited[neighbor_node_index] && current_node_colors[neighbor_node_index] == original_color)
                            {
                                node_group_visited[neighbor_node_index] = true;
                                q_group.push(neighbor_node_index);
                            }
                        }
                    }
                }
                // --- 노드 그룹 찾기 로직 끝 ---

                // --- 찾은 노드 그룹 처리 완료 표시 ---
                for (int group_node_index : node_group_indices)
                {
                    processed_node[group_node_index] = true;
                }

                // --- 가능한 다음 색상으로 노드 그룹 변경 시도 ---
                for (char next_color : colors_palette)
                {
                    if (next_color == original_color) continue;

                    // --- 다음 상태 벡터 생성 및 색상 변경 ---
                    vector<char> next_node_colors = current_node_colors;
                    for (int group_node_index : node_group_indices)
                        next_node_colors[group_node_index] = next_color;

                    // --- 새로운 상태인지 확인 후 우선순위 큐에 추가 ---
                    if (visited.find(next_node_colors) == visited.end())
                    {
                        visited.insert(next_node_colors); // 방문 셋에 추가
                        int next_h = calculate_heuristic(next_node_colors); // 다음 상태 휴리스틱 계산
                        int next_g = current_moves + 1; // 다음 상태까지 실제 이동 횟수
                        pq.push({ next_node_colors, next_g, next_h }); // 우선순위 큐에 추가
                    }
                }
            }
        }
    }

    // --- 큐가 비었는데 목표를 찾지 못한 경우 ---
    return 0; // 혹은 오류 코드
}
// --- 메인 함수 끝 ---