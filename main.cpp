#include "Graph.h"
#include <iostream>

int main()
{
    setlocale(LC_ALL, "");

    Graph g;

    g.addVertex("Иван");
    g.addVertex("Мария");
    g.addVertex("Александр");
    g.addVertex("Нина");
    g.addVertex("Павел");
    g.addVertex("Елена");
    g.addVertex("Никита");
    g.addVertex("Екатерина");
    g.addVertex("Сергей");
    g.addVertex("Ольга");
    
    g.addEdge("Иван", "Мария");
    g.addEdge("Иван", "Александр");    
    g.addEdge("Александр", "Павел");
    g.addEdge("Александр", "Нина");
    g.addEdge("Мария", "Нина");
    g.addEdge("Нина", "Елена");
    g.addEdge("Павел", "Елена");
    g.addEdge("Елена", "Никита");
    g.addEdge("Елена", "Сергей");
    g.addEdge("Елена", "Екатерина");
    g.addEdge("Никита", "Сергей");
    g.addEdge("Екатерина", "Сергей");
    g.addEdge("Сергей", "Ольга");
    
    g.findMinDistancesFloyd();
    g.print3Handshake();

    g.delVertex("Екатерина");
    g.delVertex("Павел");
    g.findMinDistancesFloyd();
    g.print3Handshake();

    Graph gHand;
    while (true) {
        std::cout << "\n\nВвести граф вручную - любой символ" << std::endl;
        std::cout << "Выход               - 0" << std::endl;
        char out = '1';
        std::cin >> out;

        if (out == '0')
            return 0;
        else {                                      
            std::string nameVer;                    
            char out2 = '1';

            while (out2 != '0') {                   //добавление вершин 
                std::cout << "Введите имя вершины: ";
                std::cin >> nameVer;
                gHand.addVertex(nameVer);
                std::cout << "\nДобавить еще вершину? (Да - любой символ, Нет - 0. ";
                std::cin >> out2;                
            }

            std::string nameVer1, nameVer2;         
            char out3 = '1';
            std::cout << "Введите связи между людьми (ребра): " << std::endl;
            while (out3 != '0') {                   //добавление ребер
                std::cout << "Введите имя 1-ой вершины: ";
                std::cin >> nameVer1;
                std::cout << "Введите имя 2-ой вершины: ";
                std::cin >> nameVer2;
                gHand.addEdge(nameVer1, nameVer2);
                std::cout << "\nДобавить еще связь (ребро)? (Да - любой символ, Нет - 0. ";
                std::cin >> out3;                
            }
            gHand.findMinDistancesFloyd();
            gHand.print3Handshake();
        }
    }    
    return 0;
}