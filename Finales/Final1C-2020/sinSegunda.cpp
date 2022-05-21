
std::list<T> sinSegunda(std::list<T> a, std::list<T> b) {
	std::list<T> result;

	// for (auto i : a)
	// for (const &T i : a)
	for (std::list<T>::iterator i = a.begin(), i != a.end(), i++) {
		bool esta_en_b = false;

		for(std::list<T>::iterator j = b.begin(), j != b.end(), j++) {
			if (i == j) {
				esta_en_b = true;
				break;
			}
		}

		if (!esta_en_b) result.push_back(i);
	}


	return result;
}