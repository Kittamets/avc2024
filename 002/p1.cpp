#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void read_files(const string &filename, vector<vector<int>> &vec) {
    ifstream file(filename);
    string line;
    int num;

    if (!file.is_open()) {
        cerr << "Error: Unable open the file" << endl;
        return;
    }

    while (getline(file, line, '\n')) {
        vector<int> tmp;
        istringstream ss(line);

        while (ss >> num) {
            tmp.push_back(num);
        }
        vec.push_back(tmp);
    }

    file.close();
}

bool is_safe(const vector<int> &vec) {
    bool asc = true, desc = true;
    for (int i = 0; i < vec.size() - 1; i++) {
        if (vec[i] > vec[i+1]) desc = false;
        if (vec[i] < vec[i+1]) asc = false;

        int diff = abs(vec[i] - vec[i+1]);
        if (diff < 1 || diff > 3) return false;
    }

    return asc || desc;
}

int main() {
    vector<vector<int>> vec;

    string filename = "input.txt";
    read_files(filename, vec);

    int total_safe(0);
    for (const auto &v : vec) {
        if (is_safe(v)) total_safe++;
    }

    cout << "Total safe: " << total_safe << endl;

    return 0;
}
