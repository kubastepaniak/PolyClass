#include "Poly.h"
#include <cstdlib>
#include <cmath>

Poly::Poly() { }

Poly::Poly(int x) { coefs[0] = x; }

Poly::~Poly() { }

double& Poly::operator[](int value)
{
	return coefs[value];
}

double Poly::operator()(double arg)
{
	double result = 0;
	for(auto const& it : coefs)
	{
		result += it.second * pow(arg, it.first);
	}
	return result;
}

Poly Poly::operator-()
{
	Poly p;
	for(auto const& it : coefs)
	{
		p[it.first] = -it.second;
	}
	return p;
}

Poly operator+(const Poly& p1, const Poly& p2)
{
	Poly p;
	for(auto const& it : p1.coefs)
	{
		p.coefs[it.first] = it.second;
	}
	for(auto const& it : p2.coefs)
	{
		p.coefs[it.first] += it.second;
	}
	return p;
}

Poly operator-(const Poly& p1, const Poly& p2)
{
	Poly p;
	for(auto const& it : p1.coefs)
	{
		p.coefs[it.first] = it.second;
	}
	for(auto const& it : p2.coefs)
	{
		p.coefs[it.first] -= it.second;
	}
	return p;
}

Poly operator*(const Poly& p1, const Poly& p2)
{
	Poly p;
	for(auto const& it1 : p1.coefs)
	{
		for(auto const& it2 : p2.coefs)
		{
			p.coefs[it1.first + it2.first] += (it1.second * it2.second);
		}
	}
	return p;
}

std::ostream& operator<<(std::ostream& out, const Poly& p)
{
	bool isFirst = true;
	for(auto const& it : p.coefs)
	{	
		if(it.second > 0)
		{
			if(!isFirst)
				out << " + ";
			out << it.second;
		}
		else if(it.second == 0)
			continue;
		else
		{
			if(isFirst)
				out << "-";
			else
				out << " - ";
			out << -it.second;
		}

		isFirst = false;
		if(it.first == 1)
			out << "x";
		else if(it.first != 0)
			out << "x^" << it.first;
	}
	return out;
}