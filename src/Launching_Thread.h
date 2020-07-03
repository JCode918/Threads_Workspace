#pragma once
#include <iostream>
#include <thread>
#include <pthread.h>

void test() {
	printf("Hello From Test \n");
}
void run() {
	std::thread thread1(test);

	if (thread1.joinable()) {
		printf("Thread1 is Joinable\n");
	} else {
		printf("Thread is not Joinable\n");
	}

	thread1.join();

	if (thread1.joinable()) {
		printf("Thread1 is Joinable\n");
	} else {
		printf("Thread is not Joinable\n");
	}
}

