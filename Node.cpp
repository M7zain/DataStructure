#include "Node.h"
#include <iostream>

using namespace std;

void ArayaEkle(Node*, Node*, int);
void SonaEkle(Node*, Node*);
Node* AradanCikar(Node*, int);
Node* SondanCikar(Node*);

void ArayaEkle(Node* pBas, Node* pYeni, int index)
{
    for (int i = 0; i < index - 2; i++)
        pBas = pBas->pSonraki;
    pYeni->pSonraki = pBas->pSonraki;
    pBas->pSonraki = pYeni;
}

void SonaEkle(Node* pBas, Node* pYeni)
{
    while (pBas->pSonraki != NULL)
        pBas = pBas->pSonraki;
    pBas->pSonraki = pYeni;
}

Node* AradanCikar(Node* pBas, int index)
{
    for (int i = 0; i < index - 2; i++) // Düzeltildi
        pBas = pBas->pSonraki;

    Node* pTemp = pBas->pSonraki;
    pBas->pSonraki = pBas->pSonraki->pSonraki;
    return pTemp;
}

Node* SondanCikar(Node* pBas)
{
    while (pBas->pSonraki->pSonraki != NULL)
        pBas = pBas->pSonraki;
    Node* pTemp = pBas->pSonraki;
    pBas->pSonraki = NULL;
    return pTemp;
}

int Node::elemanSayisi() const
{
    int count = 0;
    Node* current = pSonraki;

    while (current != NULL) {
        count++;
        current = current->pSonraki;
    }

    return count;
}
void Node::Temizle()
{
    Node* current = pSonraki;
    Node* next;

    while (current != NULL) {
        next = current->pSonraki;
        delete current;
        current = next;
    }

    pSonraki = NULL;
}

void Node::Yazdir()
{
    Node* current = pSonraki;

    cout << "Bagli listedeki elemanlar:\n";
    while (current != NULL) {
        cout << current->veri << " ";
        current = current->pSonraki;
    }
    cout << endl;
}
void Node::addtoListMenu()
{
    int choice;
    do
    {
        cout << "Ekleme turunu seciniz:\n";
        cout << "1-ِAraya eleman ekle        \n";
        cout << "2-Sona eleman Ekle     \n";
        cout << "3-Liste islemlerine geri don\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int index, value;
            cout << "Eklemek istediginiz elemanin degerini: ";
            cin >> value; 
            cout << "Eklemek istediginiz elemanin indisini giriniz :"; 
            cin >> index;
            Node* newNode = new Node(value);
            ArayaEkle(this, newNode, index);
            break;
        }
        case 2:
        {
            int value;
            cout << "Eklemek istediginiz elemanin degerini giriniz: ";
            cin >> value;
            Node* newNode = new Node(value);
            SonaEkle(this, newNode);
            break;
        }
        case 3:
            // Return to the previous menu
            break;
        default:
            cout << "Gecersiz secim. Lutfen tekrar deneyin.\n";
            break;
        }
    } while (choice != 3);
}

void Node::removeFromListMenu()
{
    int choice;
    do
    {
        cout << "Cikarma turunu seciniz:    \n";
        cout << "1-aradan eleman cikar       \n";
        cout << "2-sondan eleman cikar        \n";
        cout << "3-Liste islemlerine geri don \n";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int index;
            cout << "Cikarmak istediginiz elemanin indisini giriniz: ";
            cin >> index;
            Node* removedNode = AradanCikar(this, index);
            delete removedNode;
            break;
        }
        case 2:
        {
            Node* removedNode = SondanCikar(this);
            delete removedNode;
            break;
        }
        case 3:
            // Return to the previous menu
            break;
        default:
            cout << "Gecersiz secim. Lutfen tekrar deneyin.\n";
            break;
        }
    } while (choice != 3);
}




void Node::linkedListMenu()
{

    int choice, value;
    do {
        cout << "Bagli liste icin islem seciniz\n";
        cout << "1 - bagli listeye eleman ekle\n";
        cout << "2 - bagli listeden eleman cikar\n";
        cout << "3 - bagli listeyi temizle\n";
        cout << "4 - bagli listedeki elemanlari goster\n";
        cout << "5 - bagli listedeki eleman sayisini goster\n";
        cout << "6 - Ana sayfaya don\n";
        cout << "Seciminiz: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addtoListMenu();
            break;
        case 2:
            removeFromListMenu();
            break;
        case 3:
            Temizle();
            cout << "Bagli liste temizlendi\n";
            break;
        case 4:
            Yazdir();
            break;
        case 5:
            cout << "bagli listedeki eleman sayisi: " << elemanSayisi() << endl;
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
