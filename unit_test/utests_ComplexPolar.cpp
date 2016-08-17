#include "gtest\gtest.h"
#include "Complex.h"
#include <complex>
#include <conio.h>


using namespace std;

int TestValues(ComplexLib::ComplexPolar c, double r, double fi){
	EXPECT_DOUBLE_EQ(c.r, r);
	EXPECT_DOUBLE_EQ(c.fi, fi);
	return 0;
}

TEST(init_ComplexPolar, init){
	ComplexLib::ComplexPolar test(3.0, 4.0);
	TestValues(test, 3.0, 4.0);
}


TEST(init_ComplexPolar, init_zero){
	ComplexLib::ComplexPolar test;
	TestValues(test, 0.0, 0.0);
}

TEST(to_complex, to_complex){
	ComplexLib::ComplexPolar test(ComplexLib::complex(3.0, 4.0));
	TestValues(test, abs(complex <double>(3.0, 4.0)), arg(complex <double>(3.0, 4.0)));
}

TEST(to_complex, to_complex_zero) {
	ComplexLib::ComplexPolar test(ComplexLib::complex(0.0, 0.0));
	TestValues(test, abs(complex <double>(0.0, 0.0)), arg(complex <double>(0.0, 0.0)));
}

TEST(plus_ComplexPolar, plus_ComplexPolar){
	ComplexLib::ComplexPolar test(ComplexLib::complex(3.0, 4.0));
	TestValues(test + test, abs(complex <double>(3.0, 4.0) + complex <double>(3.0, 4.0)), arg(complex <double>(3.0, 4.0) + complex <double>(3.0, 4.0)));
}

TEST(plus_ComplexPolar, plus_double){
	ComplexLib::ComplexPolar test(ComplexLib::complex(3.0, 4.0));
	TestValues(test + 2.5, abs(complex <double>(3.0, 4.0) + 2.5), arg(complex <double>(3.0, 4.0) + 2.5));
}

TEST(minus_ComplexPolar, minus_ComplexPolar){
	ComplexLib::ComplexPolar test(ComplexLib::complex(3.0, 4.0));
	TestValues(test - ComplexLib::ComplexPolar(ComplexLib::complex(1.0, 3.0)), abs(complex <double>(3.0, 4.0) - complex <double>(1.0, 3.0)),
		arg(complex <double>(3.0, 4.0) - complex <double>(1.0, 3.0)));
}

TEST(minus_ComplexPolar, minus_double){
	ComplexLib::ComplexPolar test(ComplexLib::complex(3.0, 4.0));
	TestValues(test - 2.5, abs(complex <double>(3.0, 4.0) - 2.5), arg(complex <double>(3.0, 4.0) - 2.5));
}

TEST(multiply_ComplexPolar, multiply_ComplexPolar){
	ComplexLib::ComplexPolar test(ComplexLib::complex(3.0, 4.0));
	TestValues(test * test, abs(complex <double>(3.0, 4.0) * complex <double>(3.0, 4.0)), arg(complex <double>(3.0, 4.0) * complex <double>(3.0, 4.0)));
}

TEST(multiply_ComplexPolar, multiply_double){
	ComplexLib::ComplexPolar test(ComplexLib::complex(3.0, 4.0));
	TestValues(test * 2.5, abs(complex <double>(3.0, 4.0) * 2.5), arg(complex <double>(3.0, 4.0) * 2.5));
}

TEST(divide_ComplexPolar, divide_ComplexPolar){
	ComplexLib::ComplexPolar test(ComplexLib::complex(3.0, 4.0));
	TestValues(test / ComplexLib::ComplexPolar(ComplexLib::complex(1.0, 3.0)), abs(complex <double>(3.0, 4.0) / complex <double>(1.0, 3.0)),
		arg(complex <double>(3.0, 4.0) / complex <double>(1.0, 3.0)));
}

TEST(divide_ComplexPolar, divide_double){
	ComplexLib::ComplexPolar test(ComplexLib::complex(3.0, 4.0));
	TestValues(test / 2.5, abs(complex <double>(3.0, 4.0) / 2.5), arg(complex <double>(3.0, 4.0) / 2.5));
}

TEST(assignment_ComplexPolar, assignment_ComplexPolar){
	ComplexLib::ComplexPolar test1;
	ComplexLib::ComplexPolar test2(ComplexLib::complex(3.0, 4.0));
	test1 = test2;
	TestValues(test1, abs(complex <double>(3.0, 4.0)), arg(complex <double>(3.0, 4.0)));
}

TEST(assignment_ComplexPolar, assignment_double) {
	ComplexLib::ComplexPolar test1;
	ComplexLib::ComplexPolar test2(ComplexLib::complex(3.0, 4.0));
	test1 = 3.0;
	TestValues(test1, abs(complex <double>(3.0, 0.0)), arg(complex <double>(3.0, 0.0)));
}

TEST(equality_ComplexPolar, equality_ComplexPolar){
	ComplexLib::ComplexPolar test1(ComplexLib::complex(3.0, 4.0));
	ComplexLib::ComplexPolar test2(ComplexLib::complex(3.0, 4.0));
	complex <double> c1(abs(complex <double>(3.0, 4.0)), arg(complex <double>(3.0, 4.0)));
	complex <double> c2(abs(complex <double>(3.0, 4.0)), arg(complex <double>(3.0, 4.0)));
	bool test3;
	if (test1 == test2 && c1 == c2)
		test3 = true;
	else
		test3 = false;
	EXPECT_TRUE(test3);
}

TEST(equality_ComplexPolar, equality_false_ComplexPolar) {
	ComplexLib::ComplexPolar test1(ComplexLib::complex(3.0, 4.0));
	ComplexLib::ComplexPolar test2(ComplexLib::complex(4.0, 4.0));
	complex <double> c1(abs(complex <double>(3.0, 4.0)), arg(complex <double>(3.0, 4.0)));
	complex <double> c2(abs(complex <double>(4.0, 4.0)), arg(complex <double>(4.0, 4.0)));
	bool test3;
	if (test1 == test2 && c1 == c2)
		test3 = true;
	else
		test3 = false;
	EXPECT_FALSE(test3);
}

TEST(equality_ComplexPolar, equality_double){
	ComplexLib::ComplexPolar test1(ComplexLib::complex(3.0, 0.0));
	complex <double> c1(abs(complex <double>(3.0, 0.0)), arg(complex <double>(3.0, 0.0)));
	bool test3;
	if (test1 == ComplexLib::ComplexPolar(ComplexLib::complex(3.0, 0.0)).abs() && c1 == 3.0)
		test3 = true;
	else
		test3 = false;
	EXPECT_TRUE(test3);
}

TEST(equality_ComplexPolar, equality_false_double) {
	ComplexLib::ComplexPolar test1(ComplexLib::complex(3.0, 0.0));
	complex <double> c1(abs(complex <double>(3.0, 0.0)), arg(complex <double>(3.0, 0.0)));
	bool test3;
	if (test1 == ComplexLib::ComplexPolar(ComplexLib::complex(4.0, 0.0)).abs() && c1 == 4.0)
		test3 = true;
	else
		test3 = false;
	EXPECT_FALSE(test3);
}

TEST(abs_ComplexPolar, abs){
	double test = ComplexLib::ComplexPolar(ComplexLib::complex(3.0, 4.0)).abs();
	double n = abs(complex <double>(3.0, 4.0));
	EXPECT_DOUBLE_EQ(test, n);
}

TEST(pow_ComplexPolar, pow){
	int i = 3;
	ComplexLib::ComplexPolar test = ComplexLib::ComplexPolar(ComplexLib::complex(3.0, 4.0)).pow(i);
	complex <double> c = pow(complex <double>(3.0, 4.0), i);
	TestValues(test, abs(c), arg(c));
}