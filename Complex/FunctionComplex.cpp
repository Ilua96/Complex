#include "Complex.h"
#include <math.h>


namespace ComplexLib
{
	//Complex

	complex complex::operator+(const complex& src){
		return complex(x + src.x, y + src.y);
	}

	complex complex::operator+(const float n){
		return complex(x + n, y);
	}

	complex complex::operator-(const complex& src){
		return complex(x - src.x, y - src.y);
	}

	complex complex::operator-(const float n){
		return complex(x - n, y);
	}

	complex complex::operator*(const complex& src){
		return complex(x * src.x - y * src.y, x * src.y + y * src.x);
	}

	complex complex::operator*(const float n){
		return complex(x * n, y * n);
	}

	complex complex::operator/(const complex& src){
		return complex((x * src.x + y * src.y) / (src.x * src.x + src.y * src.y), (x * src.x - y * src.y) / (src.x * src.x + src.y * src.y));
	}

	complex complex::operator/(const float n){
		return complex(x / n, y / n);
	}

	complex complex::operator=(const complex& src){
		return complex(src.x, src.y);
	}

	complex complex::operator=(const float n){
		return complex(n, 0);
	}

	bool complex::operator==(const complex& src){
		float eps = 0.000001f;
		if ((*this - src).abs() < eps)
			return true;
		else
			return false;
	}
	
	bool complex::operator==(const float n){
		float eps = 0.000001f;
		if ((*this - n).abs() < eps)
			return true;
		else
			return false;
	}

	float complex::abs(){
		return sqrt(x * x + y * y);
	}
}