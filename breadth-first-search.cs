// cd output && csc ..\breadth-first-search.cs && .\breadth-first-search.exe & cd ..

using System;
using System.Collections.Generic;
using System.Diagnostics;

class Program {

    class Vertex {
        public int? distance;
        public int? predecessor;
    }

    static void Main() {

        var bfs = (List<List<int>> graph, int source) => {

            var bfsInfo = new List<Vertex>();

            for (var i = 0; i < graph.Count; i++) {
                bfsInfo.Add(new Vertex() {
                    distance = null,
                    predecessor = null
                });
            }

            bfsInfo[source].distance = 0;

            var queue = new Queue<int>();
            queue.Enqueue(source);

            while (queue.Count > 0) {

                var v = queue.Dequeue();
                var neighbors = graph[v];

                for (var i = 0; i < neighbors.Count; i++) {
                    var n = neighbors[i];
                    if (bfsInfo[n].distance == null) {
                        bfsInfo[n].distance = bfsInfo[v].distance + 1;
                        bfsInfo[n].predecessor = v;
                        queue.Enqueue(v);
                    }
                }
            }

            return bfsInfo;
        };

        var adjacencyList = new List<List<int>> {
            new List<int>() { 1 },
            new List<int>() { 0, 4, 5 },
            new List<int>() { 3, 4, 5 },
            new List<int>() { 2, 6 }, // index 3
            new List<int>() { 1, 2 },
            new List<int>() { 1, 2, 6 },
            new List<int>() { 3, 5 },
            new List<int>() { }
        };

        var bfsInfo = bfs(adjacencyList, 3);

        for (var i = 0; i < adjacencyList.Count; i++) {
            Console.WriteLine("vertex " + i + ": distance = " + bfsInfo[i].distance + ", predecessor = " + bfsInfo[i].predecessor);
        }

        Debug.Assert(bfsInfo[0].distance == 4);
        Debug.Assert(bfsInfo[0].predecessor == 1);
        Debug.Assert(bfsInfo[1].distance == 3);
        Debug.Assert(bfsInfo[1].predecessor == 4);
        Debug.Assert(bfsInfo[2].distance == 1);
        Debug.Assert(bfsInfo[2].predecessor == 3);
        Debug.Assert(bfsInfo[3].distance == 0);
        Debug.Assert(bfsInfo[3].predecessor == null);
        Debug.Assert(bfsInfo[4].distance == 2);
        Debug.Assert(bfsInfo[4].predecessor == 2);
        Debug.Assert(bfsInfo[5].distance == 2);
        Debug.Assert(bfsInfo[5].predecessor == 2);
        Debug.Assert(bfsInfo[6].distance == 1);
        Debug.Assert(bfsInfo[6].predecessor == 3);
        Debug.Assert(bfsInfo[7].distance == null);
        Debug.Assert(bfsInfo[7].predecessor == null);

        Console.WriteLine("assertions pass");
    }
}