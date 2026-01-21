/* --- Span.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 1/21/2026
------------------------------------------ */

#include "Span.h"
#include <stdexcept>
#include <algorithm>
#include <iostream>

Span::Span(unsigned int N) : N(N) { nums.reserve(N); }
Span::Span(Span const &other) { *this = other; }
Span::~Span() { }
Span &Span::operator=(Span const &other)
{
    nums = other.nums;
    N = other.N;
    return (*this);
}

void Span::addNumber(int const num)
{
    if (nums.size() >= N)
        throw std::logic_error("The span already has max size");
    nums.push_back(num);
}

static int find_dist(int l, int r) { return (std::abs(r - l)); }

int Span::shortestSpan() const
{
    checkForSpan();

    std::vector<int> diffs(nums.size() - 1);
    std::transform(nums.begin(), nums.end() - 1, nums.begin() + 1, diffs.begin(), find_dist);
    return *std::min_element(diffs.begin(), diffs.end());
}

int Span::longestSpan() const
{
    checkForSpan();
    return *std::max_element(nums.begin(), nums.end()) - *std::min_element(nums.begin(), nums.end());
}

void Span::checkForSpan() const
{
    if (nums.size() <= 1)
        throw std::logic_error("No span can be found because span has less than 2 elements");
}
