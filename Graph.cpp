#include "Graph.h"
#include <iostream>

#define VERYBIGINT 1'000'000'000

Graph::Graph() {
    // инициализация матрицы
    for (int i = 0; i < SIZE; i++)
    {
        names[i].clear();
        //number[i] = -1;
        for (int j = 0; j < SIZE; j++) { 
            matrix[i][j] = 0; 
            if (i == j) {
                weights[i][j] = 0; // путь до самой себя равен 0
            }
            else {
                weights[i][j] = VERYBIGINT; // если ребра нет                
            }
        }
    }    
    vertexCount = 0;
}

void Graph::addVertex(const std::string& name)
{
    names[vertexCount] = name;    
    vertexCount++;
}

void Graph::addEdge(const std::string& name1, const std::string& name2)
{
    int ind1 = numberName(name1);
    int ind2 = numberName(name2);
    matrix[ind1][ind2] = 1;
    matrix[ind2][ind1] = 1;
    weights[ind1][ind2] = 1;
    weights[ind2][ind1] = 1;
}

int Graph::numberName(const std::string& name)
{
    for (int i = 0; i < vertexCount; i++)
        if (names[i] == name)
            return i;
    std::cout << "Вершины с таким именем нет." << std::endl;
    return -1;
}

void Graph::delVertex(const std::string& name)
{
    int numVer = numberName(name);     
    
    for (int i = 0; i < SIZE; i++)
    {
        matrix[i][numVer] = 0;                  // обнуляем столбец и строку матрицы смежности
        matrix[numVer][i] = 0;
        weights[i][numVer] = VERYBIGINT;        
        weights[numVer][i] = VERYBIGINT;
    }
          
    names[numVer].clear();                         // удаляем вершину из списка вершин  
    findMinDistancesFloyd();    
}

void Graph::delEdge(const std::string& name1, const std::string& name2)
{
    matrix[numberName(name1)][numberName(name2)] = 0;
    matrix[numberName(name2)][numberName(name1)] = 0;
}

void Graph::findMinDistancesFloyd()
{    
    for (int k = 0; k < vertexCount; k++) // итерации по k
    {
        for (int i = 0; i < vertexCount; i++)
        {
            for (int j = 0; j < vertexCount; j++)
            {
                if (j == k)
                    continue;
                if (weights[i][k] + weights[k][j] < weights[i][j]) {
                    weights[i][j] = weights[i][k] + weights[k][j];
                }
            }
        }
    }
}

void Graph::print3Handshake() {

    std::cout << "\n*** Подсказка по чтению вывода:" << std::endl;
    std::cout << "*** Маша - Ваня (3), т.е." << std::endl;
    std::cout << "*** Маша знакома с Ваней через 3 рукопожатия." << std::endl;
    std::cout << "*** Связь Маша - Ваня и Ваня - Маша считается одной, т.е. выведется один раз.\n" << std::endl;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            if (weights[i][j] > 0 && weights[i][j] <=3)
            {
                std::cout << names[i] << " - " << names[j] << " (" << weights[i][j] << ")"<< std::endl;
            }            
        }
    }    
}