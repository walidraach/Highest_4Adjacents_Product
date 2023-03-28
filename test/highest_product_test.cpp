#include <algorithm>
#include "gtest/gtest.h" // Include the Google Test framework
#include "highest_product.h"

// Declare the functions to be tested
std::vector<std::vector<int>> parse_input(const std::string& input);
int get_product(std::vector<std::vector<int>>& matrix, int x, int y, int dx, int dy);
int find_highest_product(std::vector<std::vector<int>>& matrix);

// Define the test cases

TEST(FindHighestProductTest, Horizontal) {
    std::vector<std::vector<int>> matrix = {{1, 2, 3, 4},
                                            {5, 6, 7, 8},
                                            {9, 10, 11, 12},
                                            {13, 14, 15, 16}};
    int expected_output = 43680; 
    int actual_output = find_highest_product(matrix);
    EXPECT_EQ(actual_output, expected_output);
}

TEST(FindHighestProductTest, Vertical) {
    std::vector<std::vector<int>> matrix = {{1, 2, 3, 13},
                                            {5, 6, 7, 14},
                                            {9, 10, 11, 15},
                                            {1, 13, 5, 16}};
    int expected_output = 43680; 
    int actual_output = find_highest_product(matrix);
    EXPECT_EQ(actual_output, expected_output);
}

TEST(FindHighestProductTest, Diagonal) {
    std::vector<std::vector<int>> matrix = {{13, 2, 3, 4},
                                            {5, 14, 7, 8},
                                            {9, 10, 15, 12},
                                            {3, 14, 5, 16}};
    int expected_output = 43680; 
    int actual_output = find_highest_product(matrix);
    EXPECT_EQ(actual_output, expected_output);
}

TEST(FindHighestProductTest, AntiDiagonal) {
    std::vector<std::vector<int>> matrix = {{1, 2, 3, 13},
                                            {5, 6, 14, 1},
                                            {9, 15, 11, 12},
                                            {16, 4, 15, 6}};
    int expected_output = 43680; 
    int actual_output = find_highest_product(matrix);
    EXPECT_EQ(actual_output, expected_output);
}

TEST(FindHighestProductTest, Basic) {
    std::vector<std::vector<int>> matrix = {{1, 13, 3, 4},
                                            {5, 14, 7, 8},
                                            {9, 15, 11, 12},
                                            {3, 16, 15, 6}};
    int expected_output = 43680; 
    int actual_output = find_highest_product(matrix);
    EXPECT_EQ(actual_output, expected_output);
}

TEST(FindHighestProductTest, Random6x6Grid) {
    std::vector<std::vector<int>> matrix = {{7, 5, 8, 1, 2, 3},
                                            {9, 2, 5, 1, 6, 4},
                                            {3, 5, 2, 7, 9, 16},
                                            {4, 1, 6, 8, 15, 7},
                                            {6, 7, 9, 14, 1, 5},
                                            {8, 3, 13, 6, 4, 2}};
    int expected_output = 43680; 
    int actual_output = find_highest_product(matrix);
    EXPECT_EQ(actual_output, expected_output);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}