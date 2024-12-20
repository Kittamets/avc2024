#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return 1;
    }

    std::vector<int> vector_one;
    std::vector<int> vector_two;

    int num1, num2;
    while (file >> num1 >> num2) {
        vector_one.push_back(num1);
        vector_two.push_back(num2);
    }

    file.close();

    std::vector<int> appears(vector_one.size());
    for (size_t i = 0; i < vector_one.size(); ++i) {
        appears[i] = std::count(vector_two.begin(), vector_two.end(), vector_one[i]) * vector_one[i];
    }
    std:: cout << std::accumulate(appears.begin(), appears.end(), 0) << std::endl;

    return 0;
}
