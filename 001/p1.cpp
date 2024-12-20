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

    std::sort(vector_one.begin(), vector_one.end());
    std::sort(vector_two.begin(), vector_two.end());

    std::vector<int> distances(vector_one.size());
    std::transform(vector_one.begin(), vector_one.end(), vector_two.begin(), distances.begin(), [](int a, int b) {return std::abs(b-a);});

    std:: cout << std::accumulate(distances.begin(), distances.end(), 0) << std::endl;

    return 0;
}
