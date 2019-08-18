#include "stdafx.h"
#include "CppUnitTest.h"
#include "../proactor/MessageBlock.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define message "#AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA#"

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char buffer[4097] = { 0 };
			memset(buffer, 'a', 4096);
			MessageBlock block;
			block.add(buffer, 4096);

			Assert::AreEqual(4096L, block.length());

			

			char buffer2[4097] = { 0 };
			block.remove(buffer2, 4096);
			Assert::IsFalse(strcmp(buffer, buffer2));

			char buffer3[36] = { 0 };
			block.add("zhang", 5);
			Assert::AreEqual(5L, block.length());

			block.remove(buffer3, 5);
			Assert::AreEqual(0L, block.length());

			
			char buffer4[8193] = {};
			memset(buffer4, 'b', 8092);
			block.add(buffer4, 8192);
			Assert::AreEqual(8192L, block.length());
			
			char buffer5[8193] = {};
			block.remove(buffer5,8192);
			Assert::AreEqual(0L, block.length());




		}
		TEST_METHOD(Test_Resize){
			MessageBlock block;

			block.add("zhangxiaofei", 12);
			block.resize(100);
			block.add(message, strlen(message));
		}

	};
}