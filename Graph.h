#pragma once

#include <string>
#define SIZE 10

class Graph {
public:
    Graph();
    ~Graph() = default;    
   
    void addVertex(const std::string& name);                            // добавление вершины
    void addEdge(const std::string& name1, const std::string& name2);   // добавление ребра

    void delVertex(const std::string& name);                            // удаление вершины    
    void delEdge(const std::string& name1, const std::string& name2);   // удаление ребра  
        
    void findMinDistancesFloyd();                       // поиск мин.дистанции алгоритмом Флойда
    void print3Handshake();                             // вывод всех знакомств менее 3 рукопожатий
      
private:
    
    int numberName(const std::string& name);            // возвращает номер вершины по имени
    
    std::string names[SIZE];         // имя вершины   
    int weights[SIZE][SIZE];         // матрица минимальных дистанций
    int matrix[SIZE][SIZE];          // матрица смежности
    int vertexCount;                 // количество вершин
};