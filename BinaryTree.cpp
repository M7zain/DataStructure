#include "BinaryTree.h"
#include <iostream>
using namespace std;


void BinaryTree::dugumEkle(int num)
{
	Agacdugum* yenidugum,	// yeni  düğümü işaret edecek
		* dugumPtr;	// ağacı dolaşacak işaretçi, pBas ile dolaşıyorduk ya.	

	// Yeni düğüm oluştur	
	yenidugum = new Agacdugum;
	yenidugum->deger = num;
	yenidugum->sol = yenidugum->sag = NULL;
	if (!kok)	// Ağaç boş mu?
		kok = yenidugum;
	else
	{
		dugumPtr = kok;
		while (dugumPtr != NULL)
		{
			if (num < dugumPtr->deger)
			{
				if (dugumPtr->sol)
					dugumPtr = dugumPtr->sol;
				else
				{
					dugumPtr->sol = yenidugum;
					break;
				}
			}//if kapat
			else if (num > dugumPtr->deger)
			{
				if (dugumPtr->sag)
					dugumPtr = dugumPtr->sag;
				else
				{
					dugumPtr->sag = yenidugum;
					break;
				}
			}//else if kapat
			else
			{
				cout << "Agacta ayni değer iki defa bulundu.\n";
				break;
			}
		}//while kapat			

	}//else kapat	
}//fonksiyon sonu


// Implementation of elemanSil function
void BinaryTree::elemanSil(int deger, Agacdugum*& dugum)
{
	if (dugum == NULL) // Base case: If the node is null, return
		return;

	if (deger < dugum->deger) // If the value is smaller than current node, go to left subtree
		elemanSil(deger, dugum->sol);
	else if (deger > dugum->deger) // If the value is greater than current node, go to right subtree
		elemanSil(deger, dugum->sag);
	else // If the value is found
	{
		if (dugum->sol == NULL) // If the node has no left child
		{
			Agacdugum* temp = dugum->sag;
			delete dugum;
			dugum = temp;
		}
		else if (dugum->sag == NULL) // If the node has no right child
		{
			Agacdugum* temp = dugum->sol;
			delete dugum;
			dugum = temp;
		}
		else // If the node has both left and right children
		{
			Agacdugum* temp = enKucukDugum(dugum->sag);
			dugum->deger = temp->deger;
			elemanSil(temp->deger, dugum->sag);
		}
	}
}

// Helper function to find the smallest node in a subtree
BinaryTree::Agacdugum* BinaryTree::enKucukDugum(Agacdugum* dugum)
{
	Agacdugum* current = dugum;
	while (current->sol != NULL)
		current = current->sol;
	return current;
}

// Implementation of agacElemanSayisi function
int BinaryTree::agacElemanSayisi(Agacdugum* dugum) const
{
	if (dugum == NULL) // Base case: If the node is null, return 0
		return 0;
	return 1 + agacElemanSayisi(dugum->sol) + agacElemanSayisi(dugum->sag);
}

// Implementation of agacElemanSayisi function (overloaded)
int BinaryTree::agacElemanSayisi() const
{
	return agacElemanSayisi(kok); // Call the recursive function with the root node
}

// Implementation of Temizle function
void BinaryTree::Temizle(Agacdugum* dugum)
{
	if (dugum == NULL) // Base case: If the node is null, return
		return;
	Temizle(dugum->sol); // Recursively delete left subtree
	Temizle(dugum->sag); // Recursively delete right subtree
	delete dugum; // Delete current node
}

// Implementation of Temizle function (overloaded)
void BinaryTree::Temizle()
{
	Temizle(kok); // Call the recursive function with the root node
	kok = NULL; // Set the root to NULL after deleting all nodes
}



//Ağaçta InOrder dolaşalım
void BinaryTree::InOrderDolasim(Agacdugum* dugumPtr)
{
	if (dugumPtr)
	{
		InOrderDolasim(dugumPtr->sol);
		cout << dugumPtr->deger << endl;
		InOrderDolasim(dugumPtr->sag);
	}
}

//Ağaçta PreOrder dolaşalım
void BinaryTree::PreOrderDolasim(Agacdugum* dugumPtr)
{
	if (dugumPtr)
	{
		cout << dugumPtr->deger << endl;
		PreOrderDolasim(dugumPtr->sol);
		PreOrderDolasim(dugumPtr->sag);
	}
}

//Ağaçta PostOrder dolaşalım
void BinaryTree::PostOrderDolasim(Agacdugum* dugumPtr)
{
	if (dugumPtr)
	{
		PostOrderDolasim(dugumPtr->sol);
		PostOrderDolasim(dugumPtr->sag);
		cout << dugumPtr->deger << endl;
	}
}


void BinaryTree::binaryTreeMenu() {

	int choice, value;
	do {
		cout << "ikili Agac icin islem seciniz\n";
		cout << "1 - agaca eleman ekle\n";
		cout << "2 - agactan eleman cikar\n";
		cout << "3 - agaci temizle\n";
		cout << "4 - agactaki eleman sayisini goster\n";
		cout << "5 - agaci InOrder dolasarak Elemanlari Goster\n";
		cout << "6 - agaci PreOrder dolasarak Elemanlari Goster\n";
		cout << "7 - agaci PostOrder dolasarak Elemanlari Goster\n";
		cout << "8 - Ana sayfaya don\n";
		cout << "Seciminiz: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Eklemek istediginiz degeri giriniz: ";
			cin >> value;
			dugumEkle(value);
			break;
		case 2:
			cout << "Silmek istediginiz degeri giriniz: ";
			cin >> value;
			elemanSil(value,kok);
			break;
		case 3:
			Temizle();
			cout << "agac temizlendi\n";
			break;
		case 4:
			cout << "agactaki eleman sayisi: " << agacElemanSayisi() << endl;
			break;
		case 5:
			InOrderDolasim(kok);
			break;
		case 6:
			PreOrderDolasim(kok);
			break;
		case 7: 
			PostOrderDolasim(kok); 
			break; 
		case 8:
			cout << "Ana sayfaya donuluyor...\n";
			break;
		default:
			cout << "Gecersiz secim. Lutfen tekrar deneyin.\n";
			break;
		}
	} while (choice != 8);
}
