// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

#include <cstdlib>

struct Queue {
  unsigned *elems;
  size_t front;
  size_t back;
  size_t capacity;

  void enqueue(int elem) {
    if (back == capacity) {
      return;
    }
    elems[back++] = elem;
  }

  unsigned dequeue() {
    if (empty()) {
      return -1;
    }
    unsigned elem = elems[front++];
    if (front == back) {
      front = 0;
      back = 0;
    }
    return elem;
  }

  [[nodiscard]] bool empty() const { return back == 0; }
};

struct GraphNode {
  unsigned vertex;
  GraphNode *next;
};

struct Graph {
  const unsigned V;
  GraphNode **adj;

  void push(unsigned src, unsigned dst) {
    adj[src] = new GraphNode{dst, adj[src]};
    adj[dst] = new GraphNode{src, adj[dst]};
  }
};

unsigned *BFS(const Graph &graph, unsigned start_vertex) {
  Queue Q = {new unsigned[graph.V], 0, 0, graph.V};
  bool *visited = new bool[graph.V];
  unsigned *pred = new unsigned[graph.V];
  for (unsigned i = 0; i < graph.V; ++i) {
    visited[i] = false;
    pred[i] = i;
  }
  visited[start_vertex] = true;
  Q.enqueue(start_vertex);
  while (!Q.empty()) {
    int current_vertex = Q.dequeue();
    for (GraphNode *head = graph.adj[current_vertex]; head != nullptr;
         head = head->next) {
      int adj_vertex = head->vertex;
      if (!visited[adj_vertex]) {
        visited[adj_vertex] = true;
        Q.enqueue(adj_vertex);
        pred[adj_vertex] = current_vertex;
      }
    }
  }
  delete[] visited;
  delete[] Q.elems;
  return pred;
}

int main() {
  const size_t V = 5000;
  Graph graph = {
      V,
      new GraphNode *[V],
  };

  for (unsigned i = 0; i < V; ++i) {
    graph.adj[i] = nullptr;
  }

  for (unsigned i = 0; i < V; ++i) {
    for (unsigned j = i + 1; j < V; ++j) {
      graph.push(i, j);
    }
  }

  unsigned *pred = BFS(graph, 0);

  for (unsigned i = 0; i < V; ++i) {
    GraphNode *head = graph.adj[i];
    while (head != nullptr) {
      GraphNode *next = head->next;
      delete head;
      head = next;
    }
  }

  delete[] graph.adj;
  delete[] pred;

  return 0;
}
