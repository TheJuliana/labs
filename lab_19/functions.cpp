#include "functions.hpp"

namespace fn {
    void DeleteMas(std::vector<int>& mas) {
        for (int i=0; i < M; i++) {
            int k = rand()%N+1;
            for (auto j = mas.begin(); j != mas.end();) {
                if (*j == k) {
                    j = mas.erase(j);
                } else {
                    j++;
                }
            }
        }
    }

    void CreateMas(std::vector<int>& mas) {
        int r = 1;
        for (int i = 0; i<N; i++) {
            mas.push_back(r);
            r++;
        }
    }

    void PrintMas(std::vector<int>& mas) {
        for (auto& i : mas) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    void Add(T_List* head, int number) {
        T_List* p = new T_List;
        p->number = number;
        p->next = head->next;
        head->next = p;
    }

    void CreateList(T_List* head) {
        int r = 1;
        for (int i = 0; i<N; i++) {
            Add(head, r);
            r++;
        }
    }

    void Print(T_List* head) {
        T_List* p = head->next;
        while (p != nullptr) {
            std::cout << p->number << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }

    void Delete(T_List* head) {
        for (int i = 0; i<M; i++){
            T_List* tmp;
            T_List* p = head;
            int k = rand() % N + 1;
            while (p->next != nullptr) {
                if (p->next->number == k) {
                    tmp = p->next;
                    p->next = p->next->next;
                    delete tmp;
                } else {
                    p = p->next;
                }
            }
        }
    }

    void Clear(T_List* head) {
        T_List* tmp;
        T_List* p = head->next;
        while (p != nullptr) {
            tmp = p;
            p = p->next;
            delete tmp;
        }
    }
};