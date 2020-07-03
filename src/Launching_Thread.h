#pragma once
#include <iostream>
#include <thread>
#include <pthread.h>

void foo() {
	printf("Hello from foo-%d\n", std::this_thread::get_id());
}

class Callable_Object {
public:
	void operator ()() {
		printf("Hello from callable class-%d\n", std::this_thread::get_id());
	}
};

void run() {
	Callable_Object obj;
	std::thread thread1(foo);
	std::thread thread2(obj);
	std::thread thread3([]
	{
		printf("Hello from Lambda -%d\n", std::this_thread::get_id());
	}
	);
	thread1.join();
	thread2.join();
	thread3.join();

	printf("Hello from main-%d\n", std::this_thread::get_id());
}

