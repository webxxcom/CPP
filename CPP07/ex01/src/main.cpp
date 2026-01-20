#include <iostream>
#include <string>
#include "Iter.h"

/* ---------- FUNCTIONS USED FOR TESTING ---------- */

template <typename T>
void printElem(T& x) { std::cout << x << " "; }
void increment(int& x) { x++; }

void toUpper(std::string& s)
{
    for (size_t i = 0; i < s.size(); ++i)
        s[i] = std::toupper(s[i]);
}


/* -------------------- TESTS -------------------- */

int main()
{
    std::cout << "===== TEST 1: int array (non-const) =====\n";
    int intArr[] = {1, 2, 3, 4, 5};
    size_t intLen = sizeof(intArr) / sizeof(intArr[0]);

    iter(intArr, intLen, printElem<int>);
    std::cout << "\nApplying increment...\n";
    iter(intArr, intLen, printElem<int>);
    std::cout << "\n\n";

    std::cout << "===== TEST 2: const int array =====\n";
    const int constIntArr[] = {10, 20, 30};
    size_t constIntLen = sizeof(constIntArr) / sizeof(constIntArr[0]);

    iter(constIntArr, constIntLen, printElem<const int>);
    std::cout << "\n\n";

    std::cout << "===== TEST 3: string array =====\n";
    std::string strArr[] = {"hello", "world", "iter"};
    size_t strLen = sizeof(strArr) / sizeof(strArr[0]);

    iter(strArr, strLen, printElem<std::string>);
    std::cout << "\nApplying toUpper...\n";
    iter(strArr, strLen, toUpper);
    iter(strArr, strLen, printElem<std::string>);
    std::cout << "\n\n";

    std::cout << "===== TEST 4: char array =====\n";
    char charArr[] = {'a', 'b', 'c', 'd'};
    size_t charLen = sizeof(charArr) / sizeof(charArr[0]);

    iter(charArr, charLen, printElem<char>);
    std::cout << "\n\n";

    std::cout << "===== TEST 5: const char array =====\n";
    const char constCharArr[] = {'X', 'Y', 'Z'};
    size_t constCharLen = sizeof(constCharArr) / sizeof(constCharArr[0]);

    iter(constCharArr, constCharLen, printElem<const char>);
    std::cout << "\n\n";

    std::cout << "===== ALL TESTS DONE =====\n";
    return 0;
}
