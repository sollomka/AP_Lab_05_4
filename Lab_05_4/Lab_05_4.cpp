#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_Lab_05_4/AP_Lab_05_4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab054
{
	TEST_CLASS(Lab054)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double t;
			t = P0(5, 10);
			Assert::AreEqual(t, 1.36328e-12, 0.0001);
		}
	};
}
