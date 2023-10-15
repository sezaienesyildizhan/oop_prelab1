#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// Üç ayrı kod yerine tek kodda birleştirdim. -SEY

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }

    int count;
    inputFile >> count;

    if (count <= 0) {
        std::cerr << "Invalid count of integers." << std::endl;
        return 1;
    }

    std::vector<int> numbers(count);

    for (int i = 0; i < count; ++i) {
        inputFile >> numbers[i];
    }

    inputFile.close();

    int sum = 0;
    int product = 1;
    int smallest = numbers[0];

    for (int i = 0; i < count; ++i) {
        sum += numbers[i];
        product *= numbers[i];
        smallest = std::min(smallest, numbers[i]);
    }

    double average = static_cast<double>(sum) / count;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Product: " << product << std::endl;
    std::cout << "Average: " << average << std::endl;
    std::cout << "Smallest: " << smallest << std::endl;

    return 0;
}
