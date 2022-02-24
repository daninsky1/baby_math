#include <iostream>
#include <vector>
//
// PRINT VECTOR
//
namespace dsk {
    template<typename T>
    void printv(const std::vector<T>& vector, const bool endline = true);
    template<typename T>
    void printv(const std::vector<std::vector<T>>& vector, const bool endline = true, const bool extra_indent = false);
    template<typename T>
    void printv(const std::vector<std::vector<std::vector<T>>>& vector);
}

template<typename T>
void dsk::printv(const std::vector<T>& vector, const bool endline)
{
    // 1D vector
    size_t v_size = vector.size();    // size of the vector

    std::cout << '{';
    for (int i = 0; i < v_size; ++i) {
        std::cout << vector[i];
        if (i < v_size - 1)   // put comma until the last element
            std::cout << ", ";
    }
    std::cout << '}';
    if (endline) std::cout << std::endl;
}

template<typename T>
void dsk::printv(const std::vector<std::vector<T>>& vector, const bool endline, const bool extra_indent)
{
    // 2D vector
    const int v_size = vector.size();        // size of the vector

    if (extra_indent) std::cout << "    ";
    std::cout << "{\n";
    for (int i = 0; i < v_size; ++i) {
        if (extra_indent) std::cout << "    ";
        std::cout << "    ";
        dsk::printv(vector[i], false);
        if (i < v_size - 1)   // put comma and \n until the last element
            std::cout << ", \n";
    }
    std::cout << '\n';
    if (extra_indent) std::cout << "    ";
    std::cout << '}';
    if (endline) std::cout << std::endl;
}

template<typename T>
void dsk::printv(const std::vector<std::vector<std::vector<T>>>& vector)
{
    // 3D vector
    const int v_size = vector.size();        // size of the vector

    std::cout << "{\n";
    for (int i = 0; i < v_size; ++i) {
        dsk::printv(vector[i], false, true);
        if (i < v_size - 1)   // put comma until the last element
            std::cout << ", \n";
    }
    std::cout << "\n}" << std::endl;
}

