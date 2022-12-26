#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
class Edge{
    int cost,to,from;
public:
    Edge(int cost, int to, int from) : cost(cost), to(to), from(from) {}

    friend ostream &operator<<(ostream &os, const Edge &edge) {
        os << "cost: " << edge.cost << " to: " << edge.to << " from: " << edge.from;
        return os;
    }

    bool operator<(const Edge &rhs) const {
        return cost < rhs.cost;
    }

    bool operator>(const Edge &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Edge &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Edge &rhs) const {
        return !(*this < rhs);
    }
    void print(){
        cout<<"from "<<from<<" to "<<to<<"  cost "<<cost<<endl;
    }
};
typedef vector<Edge>Graph;
void add_edge(Graph &graph, int from, int to, int cost){
    graph.push_back({cost,to,from});
}
void  print(Graph& graph){
    for (int i = 0; i < graph.size(); ++i) {
        graph[i].print();
    }
}

int main() {
    int  node ,edges;
    Graph graph;
    cin>>node>>edges;
    for (int i = 0; i < edges; ++i) {
        int from,to,cost;
        cin>>from>>to>>cost;
        add_edge(graph,from,to,cost);
    }
    sort(graph.begin(),graph.end());
    print(graph);
    return 0;
}
