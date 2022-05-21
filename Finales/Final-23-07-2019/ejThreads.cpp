#include <iostream>
#include <mutex>
#include <thread>
#include <unistd.h>

//NO TERMINADO

int counter = 1;
std::mutex mtx;
std::condition_variable cv;

void sumar_imprimir(int id) {
	std::unique_lock<std::mutex> lk(mtx);
	while (counter <= 100;) {	
		cv.wait(lk);
		std::cout << "thread id: " << id << "numero: "<< counter << std::endl;
		counter++; 
	}
}

int main(int argc, char* argv[]) {
	
	std::thread th1 (sumar_imprimir,1);	
	std::thread th2 (sumar_imprimir,2);

	th1.join();
	th2.join();

	return 0;
}