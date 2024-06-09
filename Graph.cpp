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
        for (auto it = _graph.begin(); it != _graph.end(); ++it) {
            if (has_edge(it->first, v)) {
                remove_edge(it->first, v);
            }
        }
        return _graph.erase(v);
    }


    // ��������� ������ ������
    std::vector<Vertex> vertices() const {
        vector<Vertex> vert;
        if (_graph.size() == 0) return vert;
        else {
            for (auto i : _graph) {
                vert.push_back(i.first);
            }
            return vert;
        }
    }


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
                if ((*it)._to == to) {
                    _graph.at(from).erase(it);
                    return true;
                }
            }
        }
        else return false;
    }
 

    // �������� ������� ����� �� ��������
    bool has_edge(const Vertex& from, const Vertex& to) const {
        if (has_vertex(from) && has_vertex(to)) {
            for (auto it = _graph.at(from).begin(); it != _graph.at(from).end(); ++it) {
                if ((*it)._to == to) {
                    return true;
                }
            }
            return false;
        }
        else return false;
    }

    // --------------------------------------------------------------
    // ��������� ���� �����, ��������� �� �������
    std::vector<Edge> edges(const Vertex& v) {
        vector<Edge>  result;
        if (!has_vertex(v)) return  result;
        for (auto it = _graph.at(v).begin(); it != _graph.at(v).end(); ++it) {
            result.push_back((*it));
        }
        return edges;
    }

    // ������� �����
    size_t order() const {
        return _graph.size();
    }
    size_t degree(const Vertex& v) const {
        if (!has_vertex(v)) return 0;
        else return _graph.at(v).size();
    }
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

    // �������� �����
    graph.remove_edge("B", "D");
    
    
    // �������� �������
    graph.remove_vertex("D");

    // ��������� ������ ������
    std::cout << "List of vertexes: ";
    for (const auto& vertex : graph.vertices()) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;

    // ������� �����
    std::cout << "Order: " << graph.order() << std::endl;
    
    // ������� �������
    std::cout << "Degree \"A\": " << graph.degree("A") << std::endl;
    return 0;
}