#include <iostream>

std::list<T> DobleSiNo(std::list<T> a, std::list<T> b) {
	std::list<T> result;

	std::list<T>::iterator ptra;
	std::list<T>::iterator ptrb;

	for (ptra = a.begin(); ptra != a.end(); ptra ++) {
		bool esta = false;
		for (ptrb = b.begin(); ptrb != b.end(); ptrb ++) {
			if (*ptra == *ptrb) {
				esta = true;
				break;
			}
		}
		if (!esta) {
			result.push_back(*ptra);
			result.push_back(*ptra);
		}
	}

	return result;
}