#include <stdio.h>
#include <stdlib.h>

#define MAX_DUGUM 10

// Agirlikli graf icin dugum yapisi
typedef struct dugum {
    int dugum_no;
    int agirlik;          // Kenarin agirligi
    struct dugum *pNext;  // Sonraki dugumun isaretcisi
} DUGUMLER;

// Komsuluk listesi yapisi
typedef struct liste {
    DUGUMLER *satir[MAX_DUGUM];  // Komsuluk listesi
} LISTELER;

// Kenar ekleme fonksiyonu (Agirlikli) - Yeni komsu sona ekle
void KenarEkle(LISTELER *graf, int src, int dest, int agirlik) {
    DUGUMLER *yeniDugum = (DUGUMLER*) malloc(sizeof(DUGUMLER));
    /* Ilk dugum yapisini olustururken bir dugumun 3 adet degeri olabilirdi:
	dugum numarasi, agirligi ve siradaki dugumunun isaretcisi.
	simdi iki dugum arasindaki baglantiyi kurarken bu 3 degeri de set etmemiz gerekiyor. */
    yeniDugum->dugum_no = dest;
    yeniDugum->agirlik = agirlik; // Kenarin agirligini ekle
    yeniDugum->pNext = NULL; // Yeni dugumun son olmasi gerektigi icin pNext NULL

    // Eger src'nin komsulari bossa (ilk komsu ekleniyorsa)
    if (graf->satir[src] == NULL)
        graf->satir[src] = yeniDugum; // Ilk komsu olarak ekle
    else {  // Son komsuya gidip yeni komsu ekle
        DUGUMLER *p = graf->satir[src];
        while (p->pNext != NULL) {
            p = p->pNext; // Son komsuya ulas
        }
        p->pNext = yeniDugum; // Son komsunun pNext'ine yeni dugumu ekle
    }
}

// Komsuluk listesini yazdirma fonksiyonu
void yazdir(LISTELER *graf) {
    for (int i = 0; i < MAX_DUGUM; i++) {
        DUGUMLER *p = graf->satir[i];
        printf("Dugum %d: ", i);
        while (p != NULL) {
            printf("%d (Agirlik: %d) -> ", p->dugum_no, p->agirlik);
            p = p->pNext;
        }
        printf("NULL\n");
    }
}

int main() {
    LISTELER graf = {{0}};  // Baslangicta her satir NULL

    // Agirlikli kenarlari ekleyelim
    KenarEkle(&graf, 0, 1, 10);
    KenarEkle(&graf, 0, 4, 5);
    KenarEkle(&graf, 1, 2, 3);
    KenarEkle(&graf, 2, 3, 7);

    // Komsuluk listesini yazdiralim
    yazdir(&graf);

    return 0;
}
