#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

template<typename Vertex, typename Distance = double>
class Graph {
public:
    struct Edge {
        Vertex _from;
        Vertex _to;
        Distance _distance;
        Edge(Vertex from, Vertex to, Distance distance)
            : _from(from), _to(to), _distance(distance) {}
        bool operator==(const Edge& other) const {
            return (_to == other._to && _distance == other._distance);
        }
        
    };
private:
    map <Vertex, list<Edge>> _graph;
public:
    // -------------------------- ������� ------------------------------
    // �������� ������� �������
    bool has_vertex(const Vertex& v) const {
        
    }

    // ���������� �������
    void add_vertex(const Vertex& v) {
        
    }

    // �������� �������
    bool remove_vertex(const Vertex& v);

    // ��������� ������ ������
    std::vector<Vertex> vertices() const;

    // -------------------------- ����� ------------------------------
    // ���������� �����
    void add_edge(const Vertex& from, const Vertex& to, const Distance& d);

    // �������� ����� �� ��������
    bool remove_edge(const Vertex& from, const Vertex& to);

    // �������� ����� �� ������� Edge
    bool remove_edge(const Edge& e);

    // �������� ������� ����� �� ��������
    bool has_edge(const Vertex& from, const Vertex& to) const;

    // �������� ������� ����� �� ������� Edge
    bool has_edge(const Edge& e) const;

    // --------------------------------------------------------------
    // ��������� ���� �����, ��������� �� �������
    std::vector<Edge> edges(const Vertex& vertex);

    // ������� �����
    size_t order() const;

    // ������� �������
    size_t degree(const Vertex& v) const;

    // -------------------------- ������� ------------------------------

    // ����� ����������� ���� � ������� ��������� ��������-�����
    std::vector<Edge> shortest_path(const Vertex& from,
        const Vertex& to) const;

    // ����� 
    std::vector<Vertex> walk(const Vertex& start_vertex) const;

};

int main() {
    // �������� �����
    Graph<std::string, int> graph;

    return 0;
}