#include "highest_product.h"
#include <sstream>
#include <algorithm>

// Parse a string of space-separated integers into a 2D vector
std::vector<std::vector<int>> parse_input(const std::string& input) {
    std::vector<std::vector<int>> matrix;
    std::istringstream iss(input);
    std::string line;

    while (std::getline(iss, line)) {
        std::vector<int> row;
        std::istringstream line_stream(line);
        int num;

        while (line_stream >> num) {
            row.push_back(num);
        }

        matrix.push_back(row);
    }

    return matrix;
}

// Get the product of 4 adjacent numbers in the specified direction
int get_product(std::vector<std::vector<int>>& matrix, int x, int y, int dx, int dy) {
    int product = 1;

    for (int i = 0; i < 4; ++i) {
        product *= matrix[y][x];
        x += dx;
        y += dy;
    }

    return product;
}


// Find the highest product of 4 adjacent numbers in any direction
int find_highest_product(std::vector<std::vector<int>>& matrix) {
    int max_product = 0;

    // Check rows
    for (int y = 0; y < matrix.size(); ++y) {
        for (int x = 0; x < matrix[y].size() - 3; ++x) {
            int product = matrix[y][x] * matrix[y][x+1] * matrix[y][x+2] * matrix[y][x+3];
            max_product = std::max(max_product, product);
        }
    }

    // Check columns
    for (int y = 0; y < matrix.size() - 3; ++y) {
        for (int x = 0; x < matrix[y].size(); ++x) {
            int product = matrix[y][x] * matrix[y+1][x] * matrix[y+2][x] * matrix[y+3][x];
            max_product = std::max(max_product, product);
        }
    }

    // Check diagonals
    for (int y = 0; y < matrix.size() - 3; ++y) {
        for (int x = 0; x < matrix[y].size() - 3; ++x) {
            int product = matrix[y][x] * matrix[y+1][x+1] * matrix[y+2][x+2] * matrix[y+3][x+3];
            max_product = std::max(max_product, product);
        }
    }

    // Check anti-diagonals
    for (int y = 3; y < matrix.size(); ++y) {
        for (int x = 0; x < matrix[y].size() - 3; ++x) {
            int product = matrix[y][x] * matrix[y-1][x+1] * matrix[y-2][x+2] * matrix[y-3][x+3];
            max_product = std::max(max_product, product);
        }
    }

    return max_product;
}