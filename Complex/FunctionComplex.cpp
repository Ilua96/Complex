#include "Complex.h"
#include <math.h>


namespace ComplexLib
{
	//Complex

	complex complex::operator+(const complex& src){
		return complex(x + src.x, y + src.y);
	}

	complex complex::operator+(const double n){
		return complex(x + n, y);
	}

	complex complex::operator-(const complex& src){
		return complex(x - src.x, y - src.y);
	}

	complex complex::operator-(const double n){
		return complex(x - n, y);
	}

	complex complex::operator*(const complex& src){
		return complex(x * src.x - y * src.y, y * src.x + x * src.y);
	}

	complex complex::operator*(const double n){
		return complex(x * n, y * n);
	}

	complex complex::operator/(const complex& src){
		return complex((x * src.x + y * src.y) / (src.x * src.x + src.y * src.y), (y * src.x - x * src.y) / (src.x * src.x + src.y * src.y));
	}

	complex complex::operator/(const double n){
		return complex(x / n, y / n);
	}

	complex complex::operator=(const complex& src){
		x = src.x;
		y = src.y;
		return *this;
	}

	complex complex::operator=(const double n){
		x = n;
		y = 0.0;
		return *this;
	}

	bool complex::operator==(const complex& src){
		float eps = 0.000001f;
		if ((*this - src).abs() < eps)
			return true;
		else
			return false;
	}
	
	bool complex::operator==(const double n){
		float eps = 0.000001f;
		if ((*this - n).abs() < eps)
			return true;
		else
			return false;
	}

	double complex::abs(){
		return sqrt(x * x + y * y);
	}

	complex complex::pow(const int n){
		complex c = *this;
		for (int i = 0; i < n - 1; i++)
			c = c * *this;
		*this = c;
		return *this;
	}

	//ComplexPolar

	ComplexPolar ComplexPolar::operator+(const ComplexPolar& src){
		return ComplexPolar(ToComplex(*this) + ToComplex(src));
	}

	ComplexPolar ComplexPolar::operator+(const double n){
		return ComplexPolar(ToComplex(*this) + n);
	}

	ComplexPolar ComplexPolar::operator-(const ComplexPolar& src){
		return ComplexPolar(ToComplex(*this) - ToComplex(src));
	}

	ComplexPolar ComplexPolar::operator-(const double n){
		return ComplexPolar(ToComplex(*this) - n);
	}

	ComplexPolar ComplexPolar::operator*(const ComplexPolar& src){
		return ComplexPolar(ToComplex(*this) * ToComplex(src));
	}

	ComplexPolar ComplexPolar::operator*(const double n){
		return ComplexPolar(ToComplex(*this) * n);
	}

	ComplexPolar ComplexPolar::operator/(const ComplexPolar& src){
		return ComplexPolar(ToComplex(*this) / ToComplex(src));
	}

	ComplexPolar ComplexPolar::operator/(const double n){
		return ComplexPolar(ToComplex(*this) / n);
	}

	ComplexPolar ComplexPolar::operator=(const ComplexPolar& src){
		r = ComplexPolar(src.r, src.fi).r;
		fi = ComplexPolar(src.r, src.fi).fi;
		return *this;
	}

	ComplexPolar ComplexPolar::operator=(const double n){
		*this = ComplexPolar(complex(n, 0.0));
		return *this;
	}

	bool ComplexPolar::operator==(const ComplexPolar& src){
		float eps = 0.000001f;
		if ((*this - src).abs() < eps)
			return true;
		else
			return false;
	}

	bool ComplexPolar::operator==(const double n){
		float eps = 0.000001f;
		if ((*this - ComplexPolar(complex(n, 0.0))).abs() < eps)
			return true;
		else
			return false;
	}

	double ComplexPolar::abs(){
		return r;
	}

	complex ComplexPolar::pow(const int n){
		double r1 = r;
		for (int i = 0; i < n - 1; i++)
			r *= r1;
		fi *= n;
		return ToComplex(*this);
	}

	complex ComplexPolar::ToComplex(const ComplexPolar& src){
		return complex(src.r * cos(src.fi), src.r * sin(src.fi));
	}
	
}