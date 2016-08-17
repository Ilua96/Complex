#include "gtest\gtest.h"
#include "Complex.h"
#include <complex>
#include <conio.h>

using namespace std;

int TestValues(ComplexLib::complex c, double x, double y){
	EXPECT_DOUBLE_EQ(c.x, x);
	EXPECT_DOUBLE_EQ(c.y, y);
	return 0;
}

int TestValues(ComplexLib::complex c1, complex <double> c2){
	EXPECT_DOUBLE_EQ(c1.x, c2.real());
	EXPECT_DOUBLE_EQ(c1.y, c2.imag());
	return 0;
}

TEST(init_complex, init){
	ComplexLib::complex test(1.0, 2.0);
	TestValues(test, 1.0, 2.0);
}

TEST(init_complex, init_zero){
	ComplexLib::complex test;
	TestValues(test, 0.0, 0.0);
}

TEST(plus_complex, plus_complex){
	ComplexLib::complex test(1.0, 2.0);
	complex <double> c(1.0, 2.0);
	TestValues(test + test, c + c);
}

TEST(plus_complex, plus_double){
	ComplexLib::complex test(1.0, 2.0);
	complex <double> c(1.0, 2.0);
	TestValues(test + 1.0, c + 1.0);
}

TEST(minus_complex, minus_complex){
	ComplexLib::complex test1(1.0, 2.0);
	ComplexLib::complex test2(0.5, 1.0);
	complex <double> c1(1.0, 2.0);
	complex <double> c2(0.5, 1.0);
	TestValues(test1 - test2, c1 - c2);
}

TEST(minus_complex, minus_double){
	ComplexLib::complex test(1.0, 2.0);
	complex <double> c(1.0, 2.0);
	TestValues(test - 0.5, c - 0.5);
}

TEST(multiply_complex, multiply_complex){
	ComplexLib::complex test(1.0, 2.0);
	complex <double> c(1.0, 2.0);
	TestValues(test * test * test, c * c * c);
}

TEST(multiply_complex, multiply_double){
	ComplexLib::complex test(1.0, 2.0);
	complex <double> c(1.0, 2.0);
	TestValues(test * 2.5, c * 2.5);
}

TEST(divide_complex, divide_complex){
	ComplexLib::complex test1(1.0, 2.0);
	ComplexLib::complex test2(0.5, 1.0);
	complex <double> c1(1.0, 2.0);
	complex <double> c2(0.5, 1.0);
	TestValues(test1 / test2, c1 / c2);
}

TEST(divide_complex, divide_double){
	ComplexLib::complex test(1.0, 2.0);
	complex <double> c(1.0, 2.0);
	TestValues(test / 0.5, c / 0.5);
}

TEST(assignment_complex, assignment_complex){
	ComplexLib::complex test1;
	ComplexLib::complex test2(1.0, 2.0);
	test1 = test2;
	complex <double> c = complex <double> (1.0, 2.0);
	TestValues(test1, c);
}

TEST(assignment_complex, assignment_double){
	ComplexLib::complex test;
	test = 1.0;
	complex <double> c = 1.0;
	TestValues(test, c);
}

TEST(equality_complex, equality_complex){
	ComplexLib::complex test1(1.0, 2.0);
	ComplexLib::complex test2(1.0, 2.0);
	complex <double> c1(1.0, 2.0);
	complex <double> c2(1.0, 2.0);
	bool test3;
	if (test1 == test2 && c1 == c2)
		test3 = true;
	else
		test3 = false;
	EXPECT_TRUE(test3);
}

TEST(equality_complex, equality_false_complex) {
	ComplexLib::complex test1(1.0, 2.0);
	ComplexLib::complex test2(2.0, 2.0);
	complex <double> c1(1.0, 2.0);
	complex <double> c2(2.0, 2.0);
	bool test3;
	if (test1 == test2 && c1 == c2)
		test3 = true;
	else
		test3 = false;
	EXPECT_FALSE(test3);
}

TEST(equality_complex, equality_double){
	ComplexLib::complex test1(1.0, 0.0);
	complex <double> c1(1.0, 0.0);
	bool test3;
	if (test1 == 1.0 && c1 == 1.0)
		test3 = true;
	else
		test3 = false;
	EXPECT_TRUE(test3);
}

TEST(equality_complex, equality_false_double) {
	ComplexLib::complex test1(1.0, 0.0);
	complex <double> c1(1.0, 0.0);
	bool test3;
	if (test1 == 2.0 && c1 == 2.0)
		test3 = true;
	else
		test3 = false;
	EXPECT_FALSE(test3);
}

TEST(abs_complex, abs){
	double test = ComplexLib::complex(1.0, 2.0).abs();
	double n = abs(complex <double> (1.0, 2.0));
	EXPECT_DOUBLE_EQ(test, n);
}

TEST(pow_complex, pow){
	int i = 3;
	ComplexLib::complex test = ComplexLib::complex(1.0, 2.0).pow(i);
	complex <double> c = pow(complex <double>(1.0, 2.0), i);
	TestValues(test, c);
}

int main(int argc, char *argv[]){
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	_getch();
	return 0;
}