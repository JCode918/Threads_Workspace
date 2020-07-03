#pragma once
#include <iostream>
#include <thread>
#include <pthread.h>
#include <chrono>

void foo()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	printf("Hello From Foo\n");
}

void bar()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	printf("Hello From Bar\n");
}

void run()
{
	std::thread foo_thread(foo);
	std::thread bar_thread(bar);
	bar_thread.detach();
	printf("This is after bar thread detach\n");

	foo_thread.join();
	printf("This is after foo thread join\n");
}

