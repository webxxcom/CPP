/* --- Span.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 1/21/2026
------------------------------------------ */

#ifndef SPAN_H
#define SPAN_H

#include <vector>

class Span {
public:
    Span();
    Span(unsigned int N);
    Span(Span const& other);
    Span &operator=(Span const& other);
    ~Span();

    void addNumber(int const num);

    template<typename Iter>
    void addNumber(Iter begin, Iter end)
    {
        for(Iter it = begin; it != end; ++it)
            this->addNumber(*it);
    }

    int shortestSpan() const;
    int longestSpan() const;
private:
    std::vector<int> nums;
    unsigned int N;

    void checkForSpan() const;
};

#endif // SPAN_H
