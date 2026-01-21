#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "Span.h"

int main()
{
    srand((unsigned int)time(NULL));
    
    std::cout << "=== Basic Test ===" << std::endl;
    Span sp(5);
    try {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // expect 2
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;   // expect 14

        std::cout << "Trying to add extra number..." << std::endl;
        sp.addNumber(42); // should throw
    } catch (std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Edge Cases ===" << std::endl;
    Span emptySpan(5);
    try {
        emptySpan.shortestSpan(); // should throw
    } catch (std::exception &e) {
        std::cout << "Empty span shortestSpan: " << e.what() << std::endl;
    }
    try {
        emptySpan.longestSpan(); // should throw
    } catch (std::exception &e) {
        std::cout << "Empty span longestSpan: " << e.what() << std::endl;
    }

    Span singleSpan(5);
    singleSpan.addNumber(42);
    try {
        singleSpan.shortestSpan(); // should throw
    } catch (std::exception &e) {
        std::cout << "Single span shortestSpan: " << e.what() << std::endl;
    }

    std::cout << "\n=== Large Span Test ===" << std::endl;
    const int LARGE_SIZE = 10000;
    Span largeSpan(LARGE_SIZE);
    for (int i = 0; i < LARGE_SIZE; ++i)
        largeSpan.addNumber(rand() % 1000000);

    std::cout << "Shortest span (large): " << largeSpan.shortestSpan() << std::endl;
    std::cout << "Longest span (large): " << largeSpan.longestSpan() << std::endl;

    std::cout << "\n=== Range Addition Test ===" << std::endl;
    std::vector<int> numbers;
    for (int i = 0; i < 20; ++i)
        numbers.push_back(i * 3);

    Span rangeSpan(20);
    rangeSpan.addNumber(numbers.begin(), numbers.end());

    std::cout << "Shortest span (range): " << rangeSpan.shortestSpan() << std::endl; // expect 3
    std::cout << "Longest span (range): " << rangeSpan.longestSpan() << std::endl;   // expect 57

    std::cout << "\n=== Randomized Small Test ===" << std::endl;
    Span randSpan(10);
    for (int i = 0; i < 10; ++i)
        randSpan.addNumber(rand() % 100);
    std::cout << "Shortest span: " << randSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << randSpan.longestSpan() << std::endl;

    return 0;
}
