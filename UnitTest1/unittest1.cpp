#include "stdafx.h"
#include "CppUnitTest.h"
#include "../NetWork/LFThreadPool.h"
#include "../NetWork/ThreadManager.h"
#include "../NetWork/LoggingAccept.h"
#include "../NetWork/LFEventHandler.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			Reactor* reactor = new Reactor;
			LoggingAccept accept(reactor);
			
			ThreadManager threadManager(reactor);
			LFEventHandler lfEventHandler(reactor,threadManager.getThreadPool(), &accept);
			threadManager.startup();

		}

	};
}