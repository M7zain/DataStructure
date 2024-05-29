#include <iostream>
using namespace std; 
class Node
{
public:
	Node(int data = 0) : veri(data), pSonraki(nullptr) {}
	int veri;
	Node* pSonraki;
	void linkedListMenu();
	int elemanSayisi() const;
	void addtoListMenu();
	void removeFromListMenu();
	void Temizle();
	void Yazdir(); 
};

