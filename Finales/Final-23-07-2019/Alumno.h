#include <iostream>


class public Alumno {
private:
	std::string nombre;
	int padron;
	int edad
public:
	Alumno();
	Alumno(Alumno&& al1);
	Alumno(const Alumno& al1);
	~Alumno();

	Alumno& operator+ (const Alumno& al1);
	Alumno& operator++();
	Alumno& operator--();
	friend std::istream& operator >>(std::istream& stream, Alumno& al1);
	friend std::ostream& operator <<(std::ostream& stream, const Alumno& al1);
	operator long() const;
};