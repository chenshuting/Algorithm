/*
 * =====================================================================================
 *
 *       Filename:  minStack.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/05/2013 03:04:04 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Shuting Chen (cst), cicy0125@gmail.com
 *        Company:  ucas.ict.bwstor
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

template <typename T> class CStackWithMin
{
public:
	CStackWithMin(void) {}
	virtual ~CStackWithMin(void) {}

	T& top(void);
	const T& top(void) const;

	void push(const T& value);
	void pop(void);

	const T& min(void) const;
private:
	vector<T> m_data;
	vector<size_t> m_minIndex;
};

template <typename T> T& CStackWithMin<T>::top(void)
{
	return m_data.back();
}

template <typename T> const T& CStackWithMin<T>::top(void) const 
{
	return m_data.back();
}

template <typename T> void CStackWithMin<T>::push(const T& value)
{
	m_data.push_back(value);

	if(m_minIndex.size() == 0) {
		m_minIndex.push_back(0);
	} else {
		if (value < m_data[m_minIndex.back()]) {
			m_minIndex.push_back(m_data.size()-1);
		} else {
			m_minIndex.push_back(m_minIndex.back());
		}
	}
}

template <typename T> void CStackWithMin<T>::pop()
{
	m_data.pop_back();

	m_minIndex.pop_back();
}

template <typename T> const T& CStackWithMin<T>::min() const
{
	assert(m_data.size() > 0);
	assert(m_minIndex.size() > 0);

	return m_data[m_minIndex.back()];
}

int main() {
	CStackWithMin<int> *stack = new CStackWithMin<int>();

	stack->push(5);
	stack->push(4);
	stack->push(3);
	stack->push(2);
	stack->push(6);
	
	cout << "min:" << stack->min() << endl;
	stack->pop();
	cout << "min:" << stack->min() << endl;
	stack->pop();
	cout << "min:" << stack->min() << endl;

	return 0;
}
