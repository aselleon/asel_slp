#include <iostream>
#include <chrono>
#include <fstream>

int main() {
    std::chrono::time_point <std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();

    int n;
    std::ifstream input;
    input.open("input.txt");
    input >> n;
    input.close();
    if (n > 100000000) {
        std::cout << "Number is too large!\n";
        std::cout << "This program can support only 100 000 000\n";
        return 0;
    }

    bool *prime_numbers = new bool[n + 1];
    for (int i = 0; i <= n; ++i) {
        prime_numbers[i] = true;
    }

    std::ofstream output;
    output.open("output.txt");

    for (int j = 4; j <= n; j += 2) {
        prime_numbers[j] = false;
    }

    if (n >= 2){
        output << 2;
    }

    for (int i = 3; i * i <= n; i++) {
        if (prime_numbers[i]) {
            output << ", " << i;
            for (int j = i * i; j <= n; j += 2 * i) {
                prime_numbers[j] = false;
            }
        }
    }

    output.close();

    delete[] prime_numbers;

    std::chrono::time_point <std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    std::cout << "Execution time: " << duration.count() << " ms\n";

    return 0;
}
