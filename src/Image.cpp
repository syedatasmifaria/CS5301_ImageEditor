#include "Image.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
Image::Image() {
    width = 0;
    height = 0;
}

bool Image::loadCSV(const std::string& filename) {
    pixels.clear();
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        vector<int> row;
        string value;
        stringstream ss(line);

        // split by comma
        while (getline(ss, value, ',')) {
            row.push_back(stoi(value));  // text -> int
        }

        pixels.push_back(row);
    }

    height = pixels.size();
    width = (height > 0 ? pixels[0].size() : 0);

    return true;
}

bool Image::saveCSV(const std::string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file for writing: " << filename << endl;
        return false;
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            file << pixels[i][j];

            // add comma except after last value
            if (j < width - 1) {
                file << ",";
            }
        }
        file << "\n"; // new line after each row
    }

    file.close();
    return true;
}

void Image::invert() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pixels[i][j] = 255 - pixels[i][j];
        }
    }
}

void Image::brighten(int amount) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            pixels[i][j] += amount;
            if (pixels[i][j] > 255) {
                pixels[i][j] = 255;   // clamp to max
            }

        }
    }
}

void Image::darken(int amount) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            pixels[i][j] -= amount;
            if (pixels[i][j] < 0) {
                pixels[i][j] = 0;    // clamp to black
            }

        }
    }

}
void Image::threshold(int cutoff) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            if (pixels[i][j] < cutoff)
                pixels[i][j] = 0;      // black
            else
                pixels[i][j] = 255;    // white

        }
    }
}
void Image::floodFill(int startRow, int startCol, int newColor) {
    // 1. Bounds check – stop if clicked outside image
    if (startRow < 0 || startRow >= height ||
        startCol < 0 || startCol >= width) 
    {
        return;
    }

    // 2. Find the color we want to replace
    int oldColor = pixels[startRow][startCol];

    // 3. If the old color is already the new color, nothing to do
    if (oldColor == newColor) return;

    // 4. Start recursive flood
    floodFillHelper(startRow, startCol, oldColor, newColor);
}
void Image::floodFillHelper(int r, int c, int oldColor, int newColor) {
    // Base case #1: if out of bounds → stop
    if (r < 0 || r >= height || c < 0 || c >= width)
        return;

    // Base case #2: if different color → stop
    if (pixels[r][c] != oldColor)
        return;

    // Step: replace pixel
    pixels[r][c] = newColor;

    // Recursive spread: 4 directions
    floodFillHelper(r + 1, c, oldColor, newColor); // down
    floodFillHelper(r - 1, c, oldColor, newColor); // up
    floodFillHelper(r, c + 1, oldColor, newColor); // right
    floodFillHelper(r, c - 1, oldColor, newColor); // left
}



