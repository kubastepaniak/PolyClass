#pragma once
#include <iostream>
#include <map>

class Poly {
private:
	std::map<int, double, std::greater<int> > coefs;
	void clear();
	
public:
	Poly();
	Poly(int x);
	double& operator[](int key);
	double operator()(double arg);
	Poly operator-();
	friend Poly operator+(const Poly& p1, const Poly& p2);
	friend Poly operator-(const Poly& p1, const Poly& p2);
	friend Poly operator*(const Poly& p1, const Poly& p2);
	friend std::ostream& operator<<(std::ostream& out, const Poly& p);
};