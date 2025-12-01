#include <iostream>
#include "Image.h"
#include "History.h"
#include "UndoRedo.h"


using namespace std;

int main() {
    
    History history;

    Image img;
    UndoRedo ur;


    img.loadCSV("../data/sample.csv");
    history.addState(img.getPixels(), img.getWidth(), img.getHeight());

int choice = -1;

while (choice != 0) {
    cout << "\n===== Simple Image Menu =====\n";
    cout << "1. Invert\n";
    cout << "2. Brighten\n";
    cout << "3. Darken\n";
    cout << "4. Threshold\n";
    cout << "5. Flood Fill\n";
    cout << "6. Show History\n";
    cout << "7. Save Image\n";
    cout << "8. Load New Image\n";
    cout << "9. Undo\n";
    cout << "10. Redo\n";
    cout << "0. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        ur.saveState(img.getPixels());
        img.invert();
        history.addState(img.getPixels(), img.getWidth(), img.getHeight());
        cout << "Inverted.\n";
    }

    else if (choice == 2) {
        int amount;
        cout << "Enter brighten amount: ";
        cin >> amount;
        ur.saveState(img.getPixels());
        img.brighten(amount);
        history.addState(img.getPixels(), img.getWidth(), img.getHeight());
        cout << "Brightened.\n";
    }

    else if (choice == 3) {
        int amount;
        cout << "Enter darken amount: ";
        cin >> amount;
        ur.saveState(img.getPixels());
        img.darken(amount);
        history.addState(img.getPixels(), img.getWidth(), img.getHeight());
        cout << "Darkened.\n";
    }

    else if (choice == 4) {
        int cutoff;
        cout << "Enter threshold cutoff: ";
        cin >> cutoff;
        ur.saveState(img.getPixels());
        img.threshold(cutoff);
        history.addState(img.getPixels(), img.getWidth(), img.getHeight());
        cout << "Threshold applied.\n";
    }

    else if (choice == 5) {
        int r, c, col;
        cout << "Start row: ";
        cin >> r;
        cout << "Start col: ";
        cin >> c;
        cout << "New color: ";
        cin >> col;
        ur.saveState(img.getPixels());
        img.floodFill(r, c, col);
        history.addState(img.getPixels(), img.getWidth(), img.getHeight());
        cout << "Flood fill done.\n";
    }

    else if (choice == 6) {
        history.displayHistory();
    }

    else if (choice == 7) {
        string fname;
        cout << "Enter filename to save (e.g. output.csv): ";
        cin >> fname;

        if (img.saveCSV("../data/" + fname)) {
            cout << "Image saved successfully.\n";
        } else {
            cout << "Error saving image.\n";
        }
    }

    else if (choice == 8) {
        string fname;
        cout << "Enter CSV filename (in data folder): ";
        cin >> fname;

        if (img.loadCSV("../data/" + fname)) {
            cout << "Image loaded.\n";

            // Reset undo/redo
            ur.clearRedo();
            ur = UndoRedo();
            ur.saveState(img.getPixels());

            // History log
            history.addState(img.getPixels(), img.getWidth(), img.getHeight());
        } 
        else {
            cout << "Error loading file.\n";
        }
    }

    else if (choice == 9) {
        if (ur.canUndo()) {
            auto prev = ur.undo(img.getPixels());
            img.setPixels(prev);
            cout << "Undo complete.\n";
        } else {
            cout << "Nothing to undo.\n";
        }
    }

    else if (choice == 10) {
        if (ur.canRedo()) {
            auto next = ur.redo(img.getPixels());
            img.setPixels(next);
            cout << "Redo complete.\n";
        } else {
            cout << "Nothing to redo.\n";
        }
    }

    else if (choice != 0) {
        cout << "Invalid choice.\n";
    }
}


    return 0;
}

