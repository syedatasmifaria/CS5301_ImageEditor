#include "UndoRedo.h"

void UndoRedo::saveState(const vector<vector<int>>& pixels) {
    undoStack.push(pixels);

    // Clear redo whenever a new action happens
    while (!redoStack.empty()) {
        redoStack.pop();
    }
}

vector<vector<int>> UndoRedo::undo(const vector<vector<int>>& current) {
    redoStack.push(current);

    vector<vector<int>> prev = undoStack.top();
    undoStack.pop();
    return prev;
}

vector<vector<int>> UndoRedo::redo(const vector<vector<int>>& current) {
    undoStack.push(current);

    vector<vector<int>> next = redoStack.top();
    redoStack.pop();
    return next;
}

void UndoRedo::clearRedo() {
    while (!redoStack.empty()) {
        redoStack.pop();
    }
}
