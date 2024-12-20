#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include <vector>

using namespace std;

void read_file(const std::string& file_path, string& content) {
    ifstream file(file_path);

    if (!file.is_open()) {
        cerr << "ERROR: Unable to open the file" << endl;
        return;
    }

    content.assign((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));

    file.close();
}

int main() {
    string file_path = "input.txt";
    string content;
    read_file(file_path, content);

    vector<int> vec_1;
    vector<int> vec_2;

    regex pattern(R"(don't|do|mul\((\d+),(\d+)\))");
    sregex_iterator begin(content.begin(), content.end(), pattern);
    sregex_iterator end;

    bool allowed = true;
    for (auto it = begin; it != end; ++it) {
        if ((*it).str() == "don't") {
            allowed = false;
        } 
        else if ((*it).str() == "do") {
            allowed = true;
        } 
        else if ((*it)[1].matched) {
            if (allowed) {
                vec_1.push_back(std::stoi((*it)[1].str()));
                vec_2.push_back(std::stoi((*it)[2].str()));
            }
        }
    }

    int total(0);
    for (size_t i = 0; i < vec_1.size(); i++) {
        total += vec_1[i] * vec_2[i];
    }

    cout << "Total: " << total << endl;

    return 0;
}
