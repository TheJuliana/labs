#include "functions.hpp"
namespace dl{
    void CreateList(List* head) {
        int r = 1;
        for (int  i = 0; i < N; i++) {
            Add(head, r);
            r++;
        }
    }

    void Add(List *head, int data) {
        List* p = new List;
        if (head->next != nullptr && head->prev != nullptr) {
            p->data = data;
            p->next = head->next;
            head->next->prev = p;
            head->next = p;
            p->prev = head;
        } else {
            p->data = data;
            head->next = p;
            p->prev = head;
            head->prev = p;
            p->next = head;
        }
    }

    void DeleteElem(List* head, int data) {
        List* x = head;
        for (;;) {
            if (x->data == data) {
                x->prev->next = x->next;
                x->next->prev = x->prev;
                delete x;
                break;
            }
            x = x->next;
        }
    }

    void PrintList(List* head) {
        List* x = head->next;
        while (x != head) {
            std::cout << x->data << " ";
            x = x->next;
        };
        std::cout << std::endl;
    }

    void PrintReverse(List* head) {
        List* x = head->prev;
        while (x != head) {
            std::cout << x->data << " ";
            x = x->prev;
        };
        std::cout << std::endl;
    }

    void Clear(List *head) {
        List* tmp;
        List* p;
        p = head->next;
        while (p != head) {
            tmp = p;
            p = p->next;
            delete tmp;
        };
    }


}