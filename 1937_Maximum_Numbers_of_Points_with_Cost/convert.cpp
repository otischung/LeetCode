#include <string>
#include <iostream>
#include <fstream>

auto init = []()
{ 
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    return 'c';
}();

int main(int argc, char *argv[]) {
    std::string input;
    std::cin >> input;
    std::ofstream out_file;
    int row = 0, col = 0;
    out_file.open("./out.txt");
    for (const auto &c : input) {
        if (c == '[') {
            ++row;
            col = 0;
            out_file << '\n';
        } else if (c == ']') {
            out_file << '\n';
        } else if (c == ',') {
            out_file << ' ';
        } else {
            ++col;
            out_file << c;
        }
    }
    std::cout << row - 1 << '\n' << col << '\n';
    return EXIT_SUCCESS;
}

