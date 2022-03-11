// cl /W4 /EHsc breadth-first-search.cpp /Fo.\output\ /Fe.\output\ /link && .\output\breadth-first-search.exe

#include <cassert>
#include <deque>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

struct vertex {
    int distance;
    int predecessor;
};

void main() {

    auto bfs = [](vector<vector<int>> graph, int source) {

        vector<vertex> bfsInfo;

        for (int i = 0; i < graph.size(); i++) {
            bfsInfo.push_back(vertex{ -1, -1 });
        }

        bfsInfo[source].distance = 0;

        deque<int> queue;
        queue.push_back(source);

        while (queue.size() > 0) {

            int v = queue.front();
            queue.pop_front();

            auto neighbors = graph[v];

            for (int i = 0; i < neighbors.size(); i++) {
                int n = neighbors[i];
                if (bfsInfo[n].distance == -1) {
                    bfsInfo[n].distance = bfsInfo[v].distance + 1;
                    bfsInfo[n].predecessor = v;
                    queue.push_back(n);
                }
            }
        }

        return bfsInfo;
    };

    vector<vector<int>> adjacencyList = {
        vector<int>{ 1 },
        vector<int>{ 0, 4, 5 },
        vector<int>{ 3, 4, 5 },
        vector<int>{ 2, 6 }, // index 3
        vector<int>{ 1, 2 },
        vector<int>{ 1, 2, 6 },
        vector<int>{ 3, 5 },
        vector<int>{ }
    };

    auto bfsInfo = bfs(adjacencyList, 3);

    for (int i = 0; i < adjacencyList.size(); i++) {
        cout << "vertex " << i << ": distance = ";
        cout << bfsInfo[i].distance;
        cout << ", predecessor = ";
        cout << bfsInfo[i].predecessor;
        cout << endl;
    }

    assert(bfsInfo[0].distance == 4);
    assert(bfsInfo[0].predecessor == 1);
    assert(bfsInfo[1].distance == 3);
    assert(bfsInfo[1].predecessor == 4);
    assert(bfsInfo[2].distance == 1);
    assert(bfsInfo[2].predecessor == 3);
    assert(bfsInfo[3].distance == 0);
    assert(bfsInfo[3].predecessor == -1);
    assert(bfsInfo[4].distance == 2);
    assert(bfsInfo[4].predecessor == 2);
    assert(bfsInfo[5].distance == 2);
    assert(bfsInfo[5].predecessor == 2);
    assert(bfsInfo[6].distance == 1);
    assert(bfsInfo[6].predecessor == 3);
    assert(bfsInfo[7].distance == -1);
    assert(bfsInfo[7].predecessor == -1);

    cout << "assertions passed" << endl;
};
