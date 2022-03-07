#include "functions.hpp"

namespace tr{
    Elem* TreeMake(Elem* p, int numb) {
        Elem* q = new Elem;
        q->numb = numb;
        q->left = nullptr;
        q->right = nullptr;
        q->parent = p;
        return q;
    }

    int FindDepth(Elem*& root, int numb) {
        int depth = 0;
        Elem* x = root;
        while (x->numb != numb) {
            if (x->numb < numb) {
                x = x->right;
            } else {
                x = x->left;
            }
            depth++;
        };
        return depth;
    }

    Elem* TreeSearch(Elem *x, int k) {
        if (x == nullptr) {
            return x;
        }
        if (x->numb == k) {return x;}
        if (k < x->numb) {
            return TreeSearch(x-> left, k);
        } else {
            return TreeSearch(x->right, k);
        }
    }

    void TreeInsert(Elem*& root, int numb) {
        if (root == nullptr) {
            root = TreeMake(nullptr, numb);
            return;
        }
        Elem* x = root;
        while ((numb < x->numb && x->left != nullptr) || (numb > x->numb && x->right != nullptr)) {
            if (numb < x->numb) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        if (numb == x->numb) {return;}
        Elem* u = TreeMake(x, numb);
        if (numb < x->numb) {
            x->left = u;
        } else {
            x->right  = u;
        }
    }

    void TreeDelete(Elem*& root, int numb) {
        Elem* u = TreeSearch(root, numb);
        if (u == nullptr) {return;}
        if (u->left == nullptr && u->right == nullptr && u == root) {
            root = nullptr;
            return;
        } if (u->right != nullptr) {
            Elem* t = u->right;
            while (t->left != nullptr) {
                t = t->left;
            }
            u->numb = t->numb;
            u = t;
        } else if(u->left != nullptr) {
            Elem* t = u->left;
            while (t->right != nullptr) {
                t = t->right;
            }
            u->numb = t->numb;
            u = t;
        }
        Elem* t;
        if (u->left == nullptr) {
            t = u->right;
        } else {
            t = u->left;
        }
        if (u->parent->left == u) {
            u->parent->left = t;
        } else {
            u->parent->right = t;
        }
        if (t != nullptr) {
            t->parent = u->parent;
        }
    }

    void TreePass(Elem *x) {
        if (x == nullptr) {return;}
        TreePass(x->left);
        std::cout << x->numb << std::endl;
        TreePass(x->right);
    }
}
