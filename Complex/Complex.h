#pragma once

namespace ComplexLib
{
	class complex
	{
	public:
		complex(float x, float y) : x(x), y(y){};
		complex(){};
		complex operator+(const complex& src);
		complex operator+(const float n);
		complex operator-(const complex& src);
		complex operator-(const float n);
		complex operator*(const complex& src);
		complex operator*(const float n);
		complex operator/(const complex& src);
		complex operator/(const float n);
		complex operator=(const complex& src);
		complex operator=(const float n);
		bool operator==(const complex& src);
		bool operator==(const float n);
	private:
		float x;
		float y;
	};
}