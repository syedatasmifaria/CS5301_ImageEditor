#include "Image.h"
#include <fstream>
#include <sstream>
#include <iostream>

Image::Image() {
    width = 0;
    height = 0;
}

bool Image::loadCSV(const std::string& filename) {
    // We will fill this soon
    return true;
}

bool Image::saveCSV(const std::string& filename) {
    // We will fill this next
    return true;
}

void Image::invert() {
    // Will implement later
}

void Image::brighten(int amount) {
    // Will implement later
}

void Image::darken(int amount) {
    // Will implement later
}

int Image::getWidth() const {
    return width;
}

int Image::getHeight() const {
    return height;
}
