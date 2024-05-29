#include <iostream>

class BinaryTree
{
public:
    struct Agacdugum // düğüm oluşturalım
    {
        int deger;
        Agacdugum* sol;
        Agacdugum* sag;
    };

    Agacdugum* kok;

    BinaryTree() // Kurucu
    {
        kok = NULL;
    }

    // agac islemleri
    void dugumEkle(int);
    void elemanSil(int deger, Agacdugum*& dugum);
    Agacdugum* enKucukDugum(Agacdugum* dugum);

    //Ağaçta dolaşmak için gerekli fonksiyonlar
    void InOrderDolasim(Agacdugum* dugumPtr);
    void PreOrderDolasim(Agacdugum* dugumPtr);
    void PostOrderDolasim(Agacdugum* dugumPtr);

    // Güğümleri göstermek için gerekli fonksiyonlar
    void InOrderDugumGoster(void)
    {
        InOrderDolasim(kok);
    }

    void PreOrderDugumGoster()
    {
        PreOrderDolasim(kok);
    }

    void PostOrderDugumGoster()
    {
        PostOrderDolasim(kok);
    }

    void binaryTreeMenu();

    // Yeni eklenen fonksiyonlar
    void elemanSil(int deger);
    int agacElemanSayisi(Agacdugum* dugum) const;
    int agacElemanSayisi() const;
    void Temizle(Agacdugum* dugum);
    void Temizle();
};