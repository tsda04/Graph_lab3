#include <iostream>

template<typename Vertex, typename Distance = double>
class Graph {
public:
    struct Edge {
        Vertex from;
        Vertex to;
        Distance distance;
        Edge(Vertex from, Vertex to, Distance distance)
            : from(from), to(to), distance(distance) {}
    };
};
int main() {
    return 0;
}