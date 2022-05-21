#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;
int counter = 1;

void imprimir_primero() {
	while (counter <= 1000) {
		std::lock_guard<std::mutex> lk(mtx);
		if (counter % 3 == 1) {
			std::cout<< "thread 1 : "<< counter << std::endl;
			counter ++;
		} 
	}
}

void imprimir_segundo() {
	while (counter <= 1000) {
		std::lock_guard<std::mutex> lk(mtx);
		if (counter % 3 == 2) {
			std::cout<< "thread 2 : "<< counter << std::endl;
			counter ++;
		} 
	}
}

void imprimir_tercero() {
	while (counter <= 1000) {
		std::lock_guard<std::mutex> lk(mtx);
		if (counter % 3 == 0) {
			std::cout<< "thread 3 : "<< counter << std::endl;
			counter ++;
		} 
	}
}

int main (int argc, char* argv[]) {
	std::thread th1(imprimir_primero);
	std::thread th2(imprimir_segundo);
	std::thread th3(imprimir_tercero);

	th1.join();
	th2.join();
	th3.join();

	return 0;
}