#include "stdafx.h"
#include "CppUnitTest.h"
#include "../proactor/MessageBlock.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			MessageBlock block;
			block.add("zhangxiaofei", 12);
			Assert::AreEqual((long)12, block.length());
		}

	};
}