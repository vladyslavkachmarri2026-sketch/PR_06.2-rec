#include "pch.h"
#include "CppUnitTest.h"
#include "../PR_6.2 rec.cpp" // шлях до файлу проєкту з функціями (рекурсивний)

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest62rec
{
	TEST_CLASS(UnitTest62rec)
	{
	public:

		TEST_METHOD(TestIndexOfMax)
		{
			int a[5] = { 3, -5, 8, 1, -7 };
			int b[5] = { 5, 5, -2, -2, 0 };
			Assert::AreEqual(2, IndexOfMax(a, 5, 0, 0)); // звичайний випадок
			Assert::AreEqual(0, IndexOfMax(b, 5, 0, 0)); // однакові максимуми - перше входження
		}

		TEST_METHOD(TestIndexOfMin)
		{
			int a[5] = { 3, -5, 8, 1, -7 };
			int b[5] = { 5, 5, -2, -2, 0 };
			Assert::AreEqual(4, IndexOfMin(a, 5, 0, 0)); // мінімум в кінці
			Assert::AreEqual(2, IndexOfMin(b, 5, 0, 0)); // однакові мінімуми - перше входження
		}
	};
}