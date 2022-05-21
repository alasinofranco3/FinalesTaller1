class public Add_x {

private:
	int x;

public:
	Add_x();	
	~Add_x();
	Add_x(int x);
	int operator() (const int y) const;
}

int Add_x::Add_x operator() (int y) {
	return x + y;
}

Add_x sumador_1(1);
sumador_1(5);

Add_x sumador_5(5);