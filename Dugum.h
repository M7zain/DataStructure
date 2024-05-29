//HAsh tablosu işlemleri yapalım:
#include <iostream>


using namespace std;


class Dugum {
public:
	int Anahtar; //önceden veri diyorduk
	Dugum* pSonraki;
	Dugum(int Anahtar)
	{
		this->Anahtar = Anahtar;
		pSonraki = NULL;
	}
};