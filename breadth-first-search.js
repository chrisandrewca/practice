'use strict';

const bfs = (graph, source) => {

    const bfsInfo = [];

    for (let i = 0; i < graph.length; i++) {
        bfsInfo.push({
            distance: null,
            predecessor: null
        });
    }

    bfsInfo[source].distance = 0;

    const queue = [source];

    // *****
    // this fits together beacause:
    // adjacency list indices are square
    // bfsInfo has been prepared
    // *****

    while (queue.length !== 0) {

        const v = queue.shift();
        const neighbors = graph[v];

        for (let i = 0; i < neighbors.length; i++) {
            const n = neighbors[i];
            if (bfsInfo[n].distance === null) {
                bfsInfo[n].distance = bfsInfo[v].distance + 1;
                bfsInfo[n].predecessor = v;
                queue.push(n);
            }
        }
    }

    return bfsInfo;
};

const adjacencyList = [
    [1],
    [0, 4, 5],
    [3, 4, 5],
    [2, 6], // index 3
    [1, 2],
    [1, 2, 6],
    [3, 5],
    []
];

const bfsInfo = bfs(adjacencyList, 3);

for (let i = 0; i < adjacencyList.length; i++) {
    console.log("vertex " + i + ": distance = " + bfsInfo[i].distance + ", predecessor = " + bfsInfo[i].predecessor);
}

console.assert(bfsInfo[0], { distance: 4, predecessor: 1 });
console.assert(bfsInfo[1], { distance: 3, predecessor: 4 });
console.assert(bfsInfo[2], { distance: 1, predecessor: 3 });
console.assert(bfsInfo[3], { distance: 0, predecessor: null });
console.assert(bfsInfo[4], { distance: 2, predecessor: 2 });
console.assert(bfsInfo[5], { distance: 2, predecessor: 2 });
console.assert(bfsInfo[6], { distance: 1, predecessor: 3 });
console.assert(bfsInfo[7], { distance: null, predecessor: null });