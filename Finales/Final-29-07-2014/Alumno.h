#ifndef ALUMNO_H
#define ALUMNO_H


class Alumno {
private:
	std::string nombre;
	int padron;
	int edad;
public:
	Alumno();
	Alumno(int padron);
	Alumno(const Alumno &alumno);

	bool operator<(const Alumno &al1) const;
	bool operator==(const Alumno &al1) const; 
	Alumno& operator=(const Alumno &al1);
	friend std::ostream& operator<<(std::ostream& stream, const Alumno &al1);
	operator int() const;
}

#endif