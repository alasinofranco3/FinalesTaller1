#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>

class Alumno {
private:
	std::string nombre;
	int padron;
	int edad;
public:
	Alumno();
	Alumno(const Alumno& alumno2);
	Alumno(Alumno&& alumno2);
	~Alumno();

	Alumno& operator ++();
	Alumno& operator-(const Alumno& alumno1);
	
	bool operator==(const Alumno& alumno2) const;

	friend std::istream& operator>>(std::istream& stream,Alumno& al1);
	friend std::ostream& operator<<(std::ostream& stream,const Alumno& al1);

	operator float() const;
};


#endif
