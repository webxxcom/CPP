/* --- MutantStack.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 1/23/2026
------------------------------------------ */

#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <stack>


// Iterator version with just exposing std::list<T> already defined iterator implementation
#ifdef EASY_ITER

#include <list>

template<typename T>
class MutantStack : public std::stack<T, std::list<T> > {
public:
	typedef typename std::stack<T, std::list<T> >::size_type 	size_type;
	typedef typename std::stack<T, std::list<T> >::value_type 	value_type;
	typedef typename std::stack<T, std::list<T> >::value_type* 	pointer;
	typedef typename std::stack<T, std::list<T> >::reference	reference;

	MutantStack() : std::stack<T, std::list<T> >() { }
	MutantStack(MutantStack<T> const& other) { *this = other; };
	MutantStack &operator=(MutantStack const& other) { std::stack<T, std::list<T> >::operator=(other); return (*this); };
	~MutantStack() { }

	typedef typename std::list<T>::iterator						iterator;
	
	iterator 	begin() 	{ return this->c.begin(); }
	iterator 	end() 		{ return this->c.end(); }
#else

#include <vector>

// A little harder version because we implement iterator ourselves :(
template<typename T>
class MutantStack : public std::stack<T, std::vector<T> > {
	public:
		typedef typename std::stack<T, std::vector<T> >::size_type 		size_type;
		typedef typename std::stack<T, std::vector<T> >::value_type 	value_type;
		typedef typename std::stack<T, std::vector<T> >::value_type* 	pointer;
		typedef typename std::stack<T, std::vector<T> >::reference		reference;
	
		MutantStack() : std::stack<T, std::vector<T> >() { }
		MutantStack(MutantStack<T> const& other) { *this = other; };
		MutantStack &operator=(MutantStack const& other) { std::stack<T, std::vector<T> >::operator=(other); return (*this); };
		~MutantStack() { }
	
	class iterator;

	iterator 	begin() { return iterator(&this->c); }
	iterator 	end() 	{ return iterator(&this->c, this->size()); }

	class iterator
	{
	private:
		std::vector<T>	*_vec;
		size_type		_n;

	public:
		iterator(std::vector<T> *vec) : _vec(vec), _n(0) { }
		iterator(std::vector<T> *vec, size_type n) : _vec(vec), _n(n) { }
		iterator(iterator const& other) { *this = other; }
		iterator &operator=(iterator const& other) { _vec = other._vec; _n = other._n; return (*this); }
		~iterator() { }

		iterator	operator++(int) 	{ iterator prev = *this; ++_n; return (prev); }
		iterator	operator++()		{ ++_n; return (*this); }
		iterator	operator--(int) 	{ iterator prev = *this; --_n; return (prev); }
		iterator	operator--() 		{ --_n; return (*this); }
		pointer		operator->() const	{ return &(*_vec)[_n]; }
		reference	operator*() const	{ return (*_vec)[_n]; }

		bool		operator==(iterator const& other) const	{ return _n == other._n && _vec == other._vec; }
		bool		operator!=(iterator const& other) const	{ return _n != other._n || _vec != other._vec; }
	};
#endif

};

#endif // MUTANTSTACK_H
