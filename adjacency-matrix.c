#include <stdio.h>
#include <stdlib.h>

#define MAX_DUGUM 10
#define INF 0 // Agirlik olmayan yerler icin 0 kullaniyoruz, yoksa baska bir deger de secilebilir (ornegin, -1).

// Komsuluk matrisini baslatma fonksiyonu
void matrisBaslat(int matris[MAX_DUGUM][MAX_DUGUM]) {
    for (int i = 0; i < MAX_DUGUM; i++) {
        for (int j = 0; j < MAX_DUGUM; j++) {
            matris[i][j] = INF;  // Baslangicta dugumler arasinda baglanti kurulmamis oldugundan SONSUZ degeri veriyoruz.
        }
    }
}

// Kenar ekleme fonksiyonu (Agirlikli)
void KenarEkle(int matris[MAX_DUGUM][MAX_DUGUM], int src, int dest, int agirlik) {
    matris[src][dest] = agirlik; // src'den dest'e giden kenarin agirligini ekler.
}

// Komsuluk matrisini yazdirma fonksiyonu
void yazdir(int matris[MAX_DUGUM][MAX_DUGUM]) {
    for (int i = 0; i < MAX_DUGUM; i++) {
        printf("Dugum %d: ", i);
        for (int j = 0; j < MAX_DUGUM; j++) {
            if (matris[i][j] != INF) {  // INF olmayan yerleri yazdiriyoruz.
                printf(" -> %d (Agirlik: %d)", j, matris[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int matris[MAX_DUGUM][MAX_DUGUM]; // Komsuluk matrisi
    matrisBaslat(matris);  // Baslangicta tum kenarlar yok (INF ile baslatilir)

    // Agirlikli kenarlari ekleyelim
    KenarEkle(matris, 0, 1, 10);  // 0 -> 1 (Agirlik: 10)
    KenarEkle(matris, 0, 4, 5);   // 0 -> 4 (Agirlik: 5)
    KenarEkle(matris, 1, 2, 3);   // 1 -> 2 (Agirlik: 3)
    KenarEkle(matris, 2, 3, 7);   // 2 -> 3 (Agirlik: 7)

    // Komsuluk matrisini yazdiralim
    yazdir(matris);

    return 0;
}
