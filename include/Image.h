#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <string>

class Image {
private:
    std::vector<std::vector<int>> pixels; // 2D array for grayscale image
    int width;
    int height;

public:
    Image(); // empty constructor

    bool loadCSV(const std::string& filename);
    bool saveCSV(const std::string& filename);

    void invert();
    void brighten(int amount);
    void darken(int amount);

    int getWidth() const;
    int getHeight() const;
};

#endif
