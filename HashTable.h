//HAsh tablosu işlemleri yapalım:
#include <iostream>
#include "Dugum.h"


using namespace std;
static const int MAX = 10;


class HashTable {
public:
	Dugum* Veri[MAX]; //pointer dizisi. yani dizi adres tutacak
	HashTable(); //kurucu fonksiyon
	void Ekle(int Anahtar); //bağlı listelerde eklememe işlemi pek yok, o yüzden void
	Dugum* Bul(int Anahtar);//düğümü komple getirecek.düğümün olmadığını Null ile anlayacağız
	void Sil(int Anahtar);
	int TabloElemanSayisi();
	void hashTabloyuTemizle();
	void tabloyuYazdir();

	void hashTableMenu(); 

};