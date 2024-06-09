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
    // -------------------------- Вершины ------------------------------
    // Проверка наличия вершины
    bool has_vertex(const Vertex& v) const {
        if (_graph.size() == 0) return false;
		else return _graph.count(v) > 0;
    }

    // Добавление вершины
    void add_vertex(const Vertex& v) {
        if (!has_vertex(v)) {
            _graph.insert({ v, vector<Edge>() });
        }
        else cout << "This vertex is already exist" << endl;
    }

    // Удаление вершины
    bool remove_vertex(const Vertex& v) {
        if (!has_vertex(v)) {
            cout << "This vertex isn't exist" << endl;
            return false;
        }
        
        // Удаление всех ребер, связанных с вершиной
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

    // TODO Получение списка вершин
    std::vector<Vertex> vertices() const;

    // -------------------------- Ребра ------------------------------
    // Добавление ребра
    void add_edge(const Vertex& from, const Vertex& to, const Distance& d) {
            if (has_vertex(from) && has_vertex(to)) {
                _graph[from].push_back(Edge(from, to, d));
            }
            else {
                cout << "One of vertexes not exist." << endl;
                return;
            }
    }

    // Удаление ребра по вершинам
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
    // Удаление ребра по объекту Edge
    bool remove_edge(const Edge& e);

    // Проверка наличия ребра по вершинам
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
    // Проверка наличия ребра по объекту Edge
    bool has_edge(const Edge& e) const;

    // --------------------------------------------------------------
    // Получение всех ребер, выходящих из вершины
    std::vector<Edge> edges(const Vertex& vertex);

    // Порядок графа
    size_t order() const;

    // Степень вершины
    size_t degree(const Vertex& v) const;

    // -------------------------- Вариант ------------------------------

    // Поиск кратчайшего пути с помощью алгоритма Беллмана-Форда
    std::vector<Edge> shortest_path(const Vertex& from,
        const Vertex& to) const;

    // Обход 
    std::vector<Vertex> walk(const Vertex& start_vertex) const;
    
};

int main() {
    // Создание графа
    Graph <string, double> graph;

    // Добавление вершин
    graph.add_vertex("A");
    graph.add_vertex("B");
    graph.add_vertex("C");
    graph.add_vertex("D");
    graph.add_vertex("E");
    std::cout << "Vertices added." << std::endl;

    // Добавление ребер
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