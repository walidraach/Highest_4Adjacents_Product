#ifndef HIGHEST_PRODUCT_H
#define HIGHEST_PRODUCT_H

#include <vector>
#include <string>

std::vector<std::vector<int>> parse_input(const std::string& input);
int get_product(std::vector<std::vector<int>>& matrix, int x, int y, int dx, int dy);
int find_highest_product(std::vector<std::vector<int>>& matrix);

#endif // HIGHEST_PRODUCT_H