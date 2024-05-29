//HAsh tablosu işlemleri yapalım:
#include <iostream>
#include "HashTable.h"

using namespace std;

HashTable::HashTable()
{
	for (int i = 0; i < MAX; i++)
		Veri[i] = NULL;
}

void HashTable::Ekle(int Anahtar)
{
	Dugum* pYeni = new Dugum(Anahtar);
	int mod = Anahtar % MAX;
	if (!Veri[mod]) //ilgili hücrede bir adres var mı
	{//eğer varsa oaryaa bağlı bir bağlı liste var demektir
		Veri[mod] = pYeni;
		return;
	}
	//buraya geldiysek bağlı liste var:
	Dugum* pTemp = Veri[mod];//ilgili indisteki adres bilgisini pTemp'e atacağız.
	while (pTemp->pSonraki != NULL)
	{//son elemana kadar gideceğiz. Liste konusunda görmüştük
		pTemp = pTemp->pSonraki;
	}
	pTemp->pSonraki = pYeni;//son düğüme yeni düğümü ekleyebiliriz.
}

Dugum* HashTable::Bul(int Anahtar)
{
	int mod = Anahtar % MAX;
	Dugum* pTemp = Veri[mod];

	while (pTemp != NULL)
	{//döngü burada düğümün kendisini kontrol edecek
		if (pTemp->Anahtar == Anahtar)//aradığımız anahtar buysa adres dönecek
			return pTemp;
		pTemp = pTemp->pSonraki;
	}
	//listede aradığımızı bulamadık
	return NULL;
}

void HashTable::Sil(int Anahtar)//Kapalı adresleme yöntemi kullanacağız
{//Bağlı listelere benziyor
	int mod = Anahtar % MAX;
	//ilk durum hiç elemanın(düğümün) olmadığı durum
	if (!Veri[mod]) //Hiç bir elemanın olmadığı durum
	{
		return;
	}
	//buraya geldiysek en az 1 düğüm var
	//ilk düğümü çıkarmaya çalışacağız:
	if (!Veri[mod]->pSonraki) //tek düğüm olma durumudur
	{
		if (Veri[mod]->Anahtar == Anahtar)
		{//tamam 1 düğüm var ama bu benim aradığım düğüm mü. 
		 //Eğer öyle ise bu tek düğümü silelim
			delete Veri[mod]; //silicem ama yeterli değil, çünkü adresini silmedik
			Veri[mod] = NULL; //NULL yapmazsam hafıza hatasıyla karşılaşırım, 
			//çünkü orada düğüm var zannedecek
		}
		return; //aradığımız düğümse veya değilse her iki durumda da işlemi bitiriyoruz
	}
	//buraya geldiysek birden fazla düğüm var demektir.
	//Birden fazla elemanın(düğümün) olması durumu:
	if (Veri[mod]->Anahtar == Anahtar)
	{//birden fazla düğüm var ama ilk düğüm aradığımız düğüm ve sileceğiz
	  //ilk düğüm sileceğiz, dolayısıyla bağlı olan sonraki düğüme bağlanmalıyı 
		Dugum* pDon = Veri[mod]->pSonraki;//silinen düğüme bağlı olan düğüme ulaşamazdık 
		delete Veri[mod]; //silinen düğüm, şimdi ona bağlı olan düğüme bağlanalım:
		Veri[mod] = pDon;
		return;
	}
	//tek bir durum kaldı: aradığımız düğüm arada bir yerde
	//Listelerdeki aradan çıkarmaya benziyor.
	Dugum* pTemp = Veri[mod];//öncelikle ilk düğümün adresini alıyorum pTemp içerisine.
	while (pTemp->pSonraki != NULL)//son düğüme gidecek kadar bir döngü yapıyoruz
	{
		if (pTemp->pSonraki->Anahtar == Anahtar)
		{//çıkaracağımız düğümden önceki düğümün adresini bilmemiz gerekecek
			Dugum* pDon = pTemp->pSonraki; //düğümün adresini yedekliyoruz
			pTemp->pSonraki = pDon->pSonraki;//sonraki düğüme bağlıyoruz
			delete pDon;//silmek istediğimiz düğümü siliyoruz
			return;//silme işlemi gerçeklendiğine göre return
		}//ilk düğüm değilse while ile sonraki düğüme geçeceğiz:
		pTemp = pTemp->pSonraki;
	}
	//buraya geldiysek silinecek düğüm yok demektir.
}




// Implementation of hashTabloyuTemizle function
void HashTable::hashTabloyuTemizle()
{
	for (int i = 0; i < MAX; i++)
	{
		// Delete all nodes in each linked list
		Dugum* current = Veri[i];
		while (current != NULL)
		{
			Dugum* temp = current;
			current = current->pSonraki;
			delete temp;
		}
		// Set the head of the linked list to NULL
		Veri[i] = NULL;
	}
}

// Implementation of tabloyuYazdir function
void HashTable::tabloyuYazdir()
{
	for (int i = 0; i < MAX; i++)
	{
		cout << "Indeks " << i << ": ";
		Dugum* current = Veri[i];
		while (current != NULL)
		{
			cout << current->Anahtar << " ";
			current = current->pSonraki;
		}
		cout << endl;
	}
}

// Implementation of TabloElemanSayisi function
int HashTable::TabloElemanSayisi()
{
	int count = 0;
	for (int i = 0; i < MAX; i++)
	{
		Dugum* current = Veri[i];
		while (current != NULL)
		{
			count++;
			current = current->pSonraki;
		}
	}
	return count;
}


void HashTable::hashTableMenu() {

	int choice, value;
	do {
		cout << "Cirpilama (Hash Tablosu) icin islem seciniz\n";
		cout << "1 - Tabloya eleman ekle\n";
		cout << "2 - Tablodan eleman cikar\n";
		cout << "3 - tabloyu temizle\n";
		cout << "4 - Tablodaki elemanlari goster\n";
		cout << "5 - tablodaki eleman sayisini goster\n";
		cout << "6 - Ana sayfaya don\n";
		cout << "Seciminiz: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Eklemek istediginiz degeri giriniz: ";
			cin >> value;
			Ekle(value);
			break;
		case 2:
			cout << "Silmek istediginiz degeri giriniz: ";
			cin >> value;
			Sil(value);
			break;
		case 3:
			hashTabloyuTemizle();
			cout << "Hash tablosu temizlendi\n";
			break;
		case 4:
			tabloyuYazdir();
			break;
		case 5:
			cout << "hash tablosundaki eleman sayisi: " << TabloElemanSayisi() << endl;
			break;
		case 6:
			cout << "Ana sayfaya donuluyor...\n";
			break;
		default:
			cout << "Gecersiz secim. Lutfen tekrar deneyin.\n";
			break;
		}
	} while (choice != 6);
}