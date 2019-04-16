#include<iostream>

using namespace std;

class vector_

{
	int size;
	int *arr;
public:
	vector_();
	vector_(int size, int val = 0);
	vector_(const vector_ & obj);
	void push_back(int num);
	void pop_back();
	void erase(int pos);
	void clear();
	int getSize();
	bool empty();
	int getElement(int pos);
	void print();
	//prefix
	vector_& operator++();
	//postfix
	vector_ operator++(int);
	vector_ operator=(vector_&obj);
	vector_ operator+=(const vector_&obj);
	~vector_();
};

vector_ operator+(const vector_ & a, const vector_ & b);