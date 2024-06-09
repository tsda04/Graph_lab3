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
    // -------------------------- Вершины ------------------------------
    // Проверка наличия вершины
    bool has_vertex(const Vertex& v) const {
        
    }

    // Добавление вершины
    void add_vertex(const Vertex& v) {
        
    }

    // Удаление вершины
    bool remove_vertex(const Vertex& v);

    // Получение списка вершин
    std::vector<Vertex> vertices() const;

    // -------------------------- Ребра ------------------------------
    // Добавление ребра
    void add_edge(const Vertex& from, const Vertex& to, const Distance& d);

    // Удаление ребра по вершинам
    bool remove_edge(const Vertex& from, const Vertex& to);

    // Удаление ребра по объекту Edge
    bool remove_edge(const Edge& e);

    // Проверка наличия ребра по вершинам
    bool has_edge(const Vertex& from, const Vertex& to) const;

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
    Graph<std::string, int> graph;

    return 0;
}