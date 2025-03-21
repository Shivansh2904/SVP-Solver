#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <string>
#include <cctype>
#include <fstream>
#include <iomanip>


// Implementing Brute-Force algorithm into the main function
struct Vector {
    std::vector<double> components;

    explicit Vector(const std::vector<double>& input)
        : components(input) {}

    double norm() const {
        double sum = 0.0;
        for (const auto& component : components) {
            sum += component * component;
        }
        return std::sqrt(sum);
    }
};


// Parsing the input vectors and setting standard for the input
std::vector<double> parseVector(const std::string& vectorStr) {
    std::istringstream ss(vectorStr);
    char ch;
    std::vector<double> components;

    while (ss >> ch) {
        if (ch == '[') {
            continue;
        }
        if (ch == ']') {
            break;
        }
        ss.unget();
        double value;
        while (ss >> ch) {
            if (ch == ' ' || ch == ',') {
                break;
            }
            if (ch == ']') {
                ss.unget();
                break;
            }
            if (!std::isdigit(ch) && ch != '.' && ch != '-' && ch != '+') {
                throw std::runtime_error("Error: "
                        "Non-numeric character present");
            }
            ss.unget();
            ss >> value;
            components.push_back(value);
            if (ss.peek() == ',' || ss.peek() == ']') {
                break;
            }
        }
    }

    return components;
}

// Reading the vectors from the arguments and checking for errors
std::vector<Vector> readVectorsFromArguments(int argc, char* argv[]) {
    std::vector<Vector> vectors;
    std::string currentVector;
    bool isVectorOpen = false;

    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);

        if (arg.find('[') != std::string::npos) {
            isVectorOpen = true;
            currentVector = arg;
        } else if (isVectorOpen) {
            currentVector += " " + arg;
        }

        if (arg.find(']') != std::string::npos && isVectorOpen) {
            vectors.emplace_back(parseVector(currentVector));
            isVectorOpen = false;
            currentVector.clear();
        }
    }

    if (!currentVector.empty() && isVectorOpen) {
        throw std::runtime_error("Error: Vector not properly closed");
    }

    return vectors;
}

// Main function to run the program and print the results and result.txt
int main(int argc, char* argv[]) {
    try {
        if (argc < 2) {
            throw std::runtime_error("Error: No vectors provided");
        }

        std::vector<Vector> basisVectors = readVectorsFromArguments(argc, argv);

        if (basisVectors.empty()) {
            throw std::runtime_error("Error: No valid vectors parsed");
        }

        size_t dimensions = basisVectors[0].components.size();
        for (const auto& v : basisVectors) {
            if (v.components.size() != dimensions) {
                throw std::runtime_error("Error: Inconsistent dimensions");
            }
        }

        if (basisVectors.size() != dimensions) {
            throw std::runtime_error("Error:no. of vectors≠no. of dimensions");
        }

        Vector shortestVector = basisVectors[0];
        for (const auto& v : basisVectors) {
            if (v.norm() < shortestVector.norm()) {
                shortestVector = v;
            }
        }

        double norm = shortestVector.norm();
        std::cout << std::fixed << std::setprecision(5);

        std::cout << "Vector Dimension: " << dimensions << std::endl;
        std::cout << "Number of Vectors: " << basisVectors.size() << std::endl;
        std::cout << "Shortest Vector: [";
        for (size_t i = 0; i < shortestVector.components.size(); ++i) {
            std::cout << shortestVector.components[i];
            if (i < shortestVector.components.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
        std::cout << "Norm of Shortest Vector: " << norm << std::endl;

        std::ofstream outFile("result.txt");
        if (outFile.is_open()) {
            outFile << std::fixed << std::setprecision(5);
            outFile << norm;
            outFile.close();
            std::cout << "Shortest vector norm has been saved to ";
            std::cout << "result.txt" << std::endl;
        } else {
            std::cerr << "Unable to open file to write result." << std::endl;
        }
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
