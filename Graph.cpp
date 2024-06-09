#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <unordered_map>


using namespace std;

template<typename Vertex, typename Distance = double>
class Graph {
public:
    struct Edge {
        Vertex _to;
        Vertex _from;
        Distance _distance;
        Edge(Vertex from, Vertex to, Distance distance): _to(to), _from(from), _distance(distance) {}
        bool operator==(const Edge& other) const {
            return (_to == other._to && _from == other._from && _distance == other._distance);
        }
    };
private:
    map <Vertex, vector<Edge>> _graph;
public:
    // -------------------------- ������� ------------------------------
    // �������� ������� �������
    bool has_vertex(const Vertex& v) const {
        if (_graph.size() == 0) return false;
		else return _graph.count(v) > 0;
    }

    // ���������� �������
    void add_vertex(const Vertex& v) {
        if (!has_vertex(v)) {
            _graph.insert({ v, vector<Edge>() });
        }
        else cout << "This vertex is already exist" << endl;
    }

    // �������� �������
    bool remove_vertex(const Vertex& v) {
        if (!has_vertex(v)) {
            cout << "This vertex isn't exist" << endl;
            return false;
        }
        
        // �������� ���� �����, ��������� � ��������
        for (auto it = _graph.begin(); it != _graph.end();) {
            if (it->from == v || it->to == v) {
                it = _graph.erase(it);
            }
            else {
                ++it;
            }
        }

        return _graph.erase(v);
        return true;
    }

    // TODO ��������� ������ ������
    std::vector<Vertex> vertices() const;

    // -------------------------- ����� ------------------------------
    // ���������� �����
    void add_edge(const Vertex& from, const Vertex& to, const Distance& d) {
            if (has_vertex(from) && has_vertex(to)) {
                _graph[from].push_back(Edge(from, to, d));
            }
            else {
                cout << "One of vertexes not exist." << endl;
                return;
            }
    }

    // �������� ����� �� ��������
    bool remove_edge(const Vertex& from, const Vertex& to) {
        if (has_edge(from, to)) {
            for (auto it = _graph.at(from).begin(); it != _graph.at(from).end(); ++it) {
                if (it->from == from && it->to == to) {
                    _graph.at(from).erase(it);
                    return true;
                }
            }
        }
        else return false;
    }
    // �������� ����� �� ������� Edge
    bool remove_edge(const Edge& e);

    // �������� ������� ����� �� ��������
    bool has_edge(const Vertex& from, const Vertex& to) const {
        if (has_vertex(from) && has_vertex(to)) {
            for (auto i = _graph.at(from).begin(); i != _graph.at(from).end(); ++i) {
                if ((*i)._to_id == to) {
                    return true;
                }
            }
            return false;
        }
        else return false;
    }
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
    Graph <string, double> graph;

    // ���������� ������
    graph.add_vertex("A");
    graph.add_vertex("B");
    graph.add_vertex("C");
    graph.add_vertex("D");
    graph.add_vertex("E");
    std::cout << "Vertices added." << std::endl;

    // ���������� �����
    graph.add_edge("A", "B", 1.0);
    graph.add_edge("A", "C", 2.0);
    graph.add_edge("B", "C", 3.0);
    graph.add_edge("B", "D", 4.0);
    graph.add_edge("C", "D", 5.0);
    graph.add_edge("D", "E", 6.0);
    std::cout << "Edges added." << std::endl;
    
    std::cout << "Graph has vertex 'A': " << graph.has_vertex("A") << std::endl;
    std::cout << "Graph has vertex 'F': " << graph.has_vertex("F") << std::endl;

    return 0;
}