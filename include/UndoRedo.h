#ifndef UNDOREDO_H
#define UNDOREDO_H

#include <stack>
#include <vector>
using namespace std;

class UndoRedo {
private:
    stack<vector<vector<int>>> undoStack;
    stack<vector<vector<int>>> redoStack;

public:
    void saveState(const vector<vector<int>>& pixels);

    bool canUndo() const { return !undoStack.empty(); }
    bool canRedo() const { return !redoStack.empty(); }

    vector<vector<int>> undo(const vector<vector<int>>& current);
    vector<vector<int>> redo(const vector<vector<int>>& current);

    void clearRedo();
};

#endif
