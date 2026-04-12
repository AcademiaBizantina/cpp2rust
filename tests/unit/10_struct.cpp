// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

struct GraphNode {
  unsigned dst;
  GraphNode *next;
};

struct Graph {
  unsigned V;
  GraphNode **adj;

  void push(unsigned src, unsigned dst) const {
    adj[src] = new GraphNode{dst, adj[src]};
    adj[dst] = new GraphNode{src, adj[dst]};
  }
};

int main() {
  Graph g{5, nullptr};
  return 0;
}
