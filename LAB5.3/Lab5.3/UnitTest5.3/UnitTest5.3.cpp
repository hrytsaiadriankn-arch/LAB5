#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>
#include "D:\LAB5.3\Lab5.3\Lab5.3\Lab5.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


extern double t(double x);

namespace UnitTestProject
{
    TEST_CLASS(UnitTestProject)
    {
    public:

        TEST_METHOD(Test_T_BigX)
        {
            double x = 2.0;
            double expected = (cos(x) + 1) / (exp(x) + sin(x) * sin(x));
            Assert::AreEqual(expected, t(x), 1e-10, L"Помилка при |x|>=1");
        }

        TEST_METHOD(Test_T_SmallX)
        {
            double x = 0.5;
            double S = 0;

            for (int j = 0; j <= 5; j++)
            {
                double a = pow(-1, j) * pow(x, 2 * j + 1) / tgamma(2 * j + 2);
                S += a;
            }

            Assert::AreEqual(S, t(x), 1e-10, L"Помилка при |x|<1");
        }

        TEST_METHOD(Test_T_At1)
        {
            double x = 1.0;
            double expected = (cos(x) + 1) / (exp(x) + sin(x) * sin(x));
            Assert::AreEqual(expected, t(x), 1e-10, L"Помилка при x=1");
        }

        TEST_METHOD(Test_T_Zero)
        {
            double x = 0;
            double expected = 0;
            Assert::AreEqual(expected, t(x), 1e-12, L"Помилка при x=0");
        }
    };
}
