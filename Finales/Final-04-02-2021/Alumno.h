class Alumno {
private: 
	std::String nombre;
	int padron;
	int edad;
public:
	Alumno();
	Alumno(const Alumno& alu);
	Alumno(Alumno&& alu);
	~Alumno();

	Alumno& operator +(const Alumno& alu);
	Alumno& operator ++();
	Alumno& operator --();
	friend std::ostream& operator <<(std::ostream& stream, const Alumno& alu);
	friend std::istream& operator >>(std::istream& stream, Alumno& alu);

	Alumno& operator() ();

	bool operator ==(const Alumno& alu) const;
};