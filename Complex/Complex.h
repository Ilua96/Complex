#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

namespace ComplexLib
{
	class complex
	{
	public:
		complex() : x(0.0), y(0.0){};
		complex(double x, double y) : x(x), y(y){};
		~complex(){};
		complex operator+(const complex& src);
		complex operator+(const double n);
		complex operator-(const complex& src);
		complex operator-(const double n);
		complex operator*(const complex& src);
		complex operator*(const double n);
		complex operator/(const complex& src);
		complex operator/(const double n);
		complex operator=(const complex& src);
		complex operator=(const double n);
		bool operator==(const complex& src);
		bool operator==(const double n);
		virtual double abs();
		complex pow(const int n);
		double x;
		double y;
	};

	class ComplexPolar : public complex
	{
	public:
		ComplexPolar() : r(0.0), fi(0.0) {};
		ComplexPolar(double r, double fi) : r(r), fi(fi) {};
		ComplexPolar(complex src){
			if (src == 0)
				return;
			r = src.abs();
			fi = atan2(src.y, src.x);
		};
		~ComplexPolar(){};
		static complex ToComplex(const ComplexPolar& src);
		ComplexPolar operator+(const ComplexPolar& src);
		ComplexPolar operator+ (const double n);
		ComplexPolar operator-(const ComplexPolar& src);
		ComplexPolar operator- (const double n);
		ComplexPolar operator*(const ComplexPolar& src);
		ComplexPolar operator*(const double n);
		ComplexPolar operator/(const ComplexPolar& src);
		ComplexPolar operator/(const double n);
		ComplexPolar operator=(const ComplexPolar& src);
		ComplexPolar operator=(const double n);
		bool operator==(const ComplexPolar& src);
		bool operator==(const double n);
		double abs();
		complex pow(const int n);
		double r;
		double fi;
	};
}