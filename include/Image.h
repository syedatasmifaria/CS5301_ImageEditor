#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <string>

class Image {
private:
    std::vector<std::vector<int>> pixels; // 2D array for grayscale image
    int width;
    int height;
    void floodFillHelper(int r, int c, int oldColor, int newColor);


public:
    Image(); // empty constructor

    bool loadCSV(const std::string& filename);
    bool saveCSV(const std::string& filename);

    void invert();
    void brighten(int amount);
    void darken(int amount);
    void threshold(int cutoff);
    void floodFill(int startRow, int startCol, int newColor);
    // === NEW Getters for History + Undo/Redo ===
    std::vector<std::vector<int>> getPixels() const { return pixels; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    void setPixels(const std::vector<std::vector<int>>& newPixels) {
    pixels = newPixels;
    height = pixels.size();
    width = pixels[0].size();
}




    
    
};

#endif
