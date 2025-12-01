#ifndef HISTORY_H
#define HISTORY_H

#include <vector>

class History {
private:
    struct Node {
        std::vector<std::vector<int>> pixels;
        int width;
        int height;
        Node* next;

        Node(const std::vector<std::vector<int>>& p, int w, int h)
            : pixels(p), width(w), height(h), next(nullptr) {}
    };

    Node* head;

public:
    History();
    ~History();

    void addState(const std::vector<std::vector<int>>& pixels, int width, int height);
    void deleteLast();
    void displayHistory();
};

#endif
