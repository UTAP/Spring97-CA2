#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef vector<pair<int, vector<int>>> WeightedGraph;

WeightedGraph read_graph(int v, int e) {
    WeightedGraph g = vector<pair<int, vector<int>>>(v, pair<int, vector<int>>(0, vector<int>()));
    for(int i = 0, weight; i < v; i++)
        g[i].first = (cin >> weight, weight);
    for(int i = 0, from, to; i < e; i++) {
        cin >> from >> to;
        g[to].second.push_back(from);
    }
    return g;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int calc_longest_dependency_seq(const WeightedGraph &g, int n) {
    int dependants_length = 0;
    for(int i  = 0; i < g[n].second.size(); i++)
        dependants_length = max(dependants_length, calc_longest_dependency_seq(g, g[n].second[i]));
    return dependants_length + g[n].first;
}

int main() {
    int v, e, n;
    cin >> v >> e >> n;
    cout << calc_longest_dependency_seq(read_graph(v, e), n) << endl;
    return 0;
}
