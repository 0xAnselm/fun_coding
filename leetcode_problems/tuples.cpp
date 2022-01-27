#include <iostream>
#include <string>
#include <tuple>

using namespace std;

template <typename T>
void printHelper() { std::cout << "unknown type\n"; }
template <>
void printHelper<int>() { std::cout << "int\n"; }
template <>
void printHelper<bool>() { std::cout << "bool\n"; }
template <>
void printHelper<char>() { std::cout << "char\n"; }
template <>
void printHelper<std::string>() { std::cout << "std::string\n"; }

struct myInt
{
    int a;
};

template <std::size_t I, class T>
void printTypeAtIndex()
{
    std::cout << "index " << I << " has type: ";
    using SelectedType = std::tuple_element_t<I, T>;
    printHelper<SelectedType>();
}

int main()
{
    typedef tuple<int, double &, string, char const *> tuple_idsc;
    double pi = 3.14;
    tuple_idsc idsc(59, pi, "hello", "fixed");
    get<2>(idsc) = "hello world";

    typedef tuple<int, myInt *> tuple_imyInt;
    myInt mI{3};
    tuple_imyInt imyInt(1, &mI);

    cout << "idsc size " << tuple_size<tuple_idsc>::value << '\n';
    string info;
    printTypeAtIndex<2, tuple_idsc>();
    return 0;
}
