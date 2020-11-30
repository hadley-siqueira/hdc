#ifndef HDC_UTIL_GRAPH_H
#define HDC_UTIL_GRAPH_H

#include <set>
#include <map>
#include <stack>
#include <sstream>

namespace hdc {
    template<class T>
    class Graph {
    private:
        std::map<T, std::set<T> > graph;
        std::set<T> deleted;
        std::map<T, int> assignedColors;

    public:
        void insertNode(T node) {
            std::set<T> l;

            graph.insert(std::pair<T, std::set<T> >(node, l));
        }

        void makeEdge(T n1, T n2) {
            if (graph.count(n1) == 0) {
                insertNode(n1);
            }

            if (graph.count(n2) == 0) {
                insertNode(n2);
            }

            graph[n1].insert(n2);
            graph[n2].insert(n1);
        }

        bool hasEdge(T n1, T n2) {
            if (graph.count(n1) > 0) {
                return graph[n1].count(n2) > 0;
            }

            return false;
        }

        void removeNode(T node) {
            typename std::set<T>::iterator it;

            if (graph.count(node) > 0) {
                for (it = graph[node].begin(); it != graph[node].end(); ++it) {
                    graph[*it].erase(node);
                }

                graph.erase(node);
            }
        }

        int countEdges(T node) {
            return graph[node].size();
        }

        std::map<T, int> coloring(int n_colors) {
            std::map<T, int> r;
            Graph<T> aux = *this;
            std::set<T> removed;
            std::stack<T> st;
            std::stack<std::set<T> > st_edges;
            bool foundVertex = true;
            std::set<int> colorsPool;
            int max_color = -1;

            typename std::map<T, std::set<T> >::iterator it1;

            for (int i = 0; i < n_colors; ++i) {
                colorsPool.insert(i);
            }

            while (foundVertex) {
                foundVertex = false;

                for (it1 = aux.graph.begin(); it1 != aux.graph.end(); ++it1) {
                    if (aux.countEdges(it1->first) < n_colors) {
                        std::cout << aux.to_str();

                        removed.insert(it1->first);
                        st.push(it1->first);
                        st_edges.push(it1->second);
                        foundVertex = true;
                        aux.removeNode(it1->first);
                        break;
                    }
                }
            }

            if (aux.graph.size() != 0) {
                std::cout << "Graph coloring: couldn't colore graph\nExiting...\n";
                exit(0);
            }

            std::cout << aux.to_str();

            while (st.size() > 0) {
                T node = st.top();
                std::set<int> availableColors = colorsPool;
                typename std::set<T>::iterator it;

                aux.insertNode(node);

                for (it = st_edges.top().begin(); it != st_edges.top().end(); ++it) {
                    aux.makeEdge(node, *it);

                    if (r.count(*it) > 0) {
                        availableColors.erase(r[*it]);
                    }
                }

                r[node] = *availableColors.begin();

                if (r[node] > max_color) {
                    max_color = r[node];
                }

                std::cout << aux.to_str();
                st.pop();
                st_edges.pop();
            }

            typename std::map<T, int>::iterator j;

            for (j = r.begin(); j != r.end(); ++j) {
                std::cout << j->first << ": " << j->second << '\n';
            }

            assignedColors = r;
            std::cout << "#colors = " << (max_color + 1) << std::endl;
            return r;
        }

        std::string to_str() {
            std::stringstream ss;
            typename std::map<T, std::set<T> >::iterator it1;
            typename std::set<T>::iterator it2;

            ss << "{\n";

            for (it1 = graph.begin(); it1 != graph.end(); ++it1) {
                 ss << "    " << it1->first << " -> {";

                 for (it2 = it1->second.begin(); it2 != it1->second.end(); ++it2) {
                     ss << *it2 << ", ";
                 }

                 ss << "}\n";
            }

            ss << "}\n";

            return ss.str();
        }

        std::string to_dot() {
            std::stringstream ss;
            std::map<T, int> colors = assignedColors;

            std::set<T> nodes;
            char const *cc[] = {
                "black",
                "red",
                "blue",
                "green",
                "yellow",
                "pink",
                "dimgray",
                "darkviolet",
                "gold2",
                "navyblue",
                "tomato",
                "coral4"
            };

            ss << "graph G {\n";

            typename std::map<T, std::set<T> >::iterator it;
            typename std::set<T>::iterator it2;

            for (it = graph.begin(); it != graph.end(); ++it) {
                ss << "    " << it->first << " [color=" << cc[colors[it->first]] << "];\n";
            }

            for (it = graph.begin(); it != graph.end(); ++it) {
                for (it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
                    if (nodes.count(*it2) == 0) {
                        ss << "    " << it->first << " -- " << *it2 << ";\n";
                    }
                }

                nodes.insert(it->first);
            }

            ss << "}\n";
            return ss.str();
        }
    };
}

#endif // GRAPH_H
