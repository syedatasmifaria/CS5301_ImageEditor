#include "History.h"
#include <iostream>

History::History() : head(nullptr) {}

History::~History() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

void History::addState(const std::vector<std::vector<int>>& pixels, int width, int height) {
    Node* newNode = new Node(pixels, width, height);

    newNode->next = head;
    head = newNode;

    std::cout << "State added to history.\n";
}

void History::deleteLast() {
    if (head == nullptr) {
        std::cout << "History is empty.\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;

    std::cout << "Last state deleted.\n";
}

void History::displayHistory() {
    Node* curr = head;
    int index = 1;

    while (curr != nullptr) {
        std::cout << "State " << index << ": " << curr->width << "x" << curr->height << "\n";
        curr = curr->next;
        index++;
    }

    if (index == 1) {
        std::cout << "History is empty.\n";
    }
}
