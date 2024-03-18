#include <iostream>

size_t dlugosc(const char* src) {
  size_t i = 0;
  while (src[i] != '\0') {
    i++;
  }
  return i;
}

char* kopiuj(const char* src) {
  size_t len = dlugosc(src);
  char* dest = new char[len + 1];
  for (size_t i = 0; i < len; i++) {
    dest[i] = src[i];
  }
  dest[len] = '\0';
  return dest;
}

char* dolacz(const char* dest, const char* src, size_t n) {
  size_t len_dest = dlugosc(dest);
  size_t len_src = dlugosc(src);
  size_t len_new = len_dest + n + 1;
  char* new_str = new char[len_new];
  for (size_t i = 0; i < len_dest; i++) {
    new_str[i] = dest[i];
  }
  for (size_t i = 0; i < n; i++) {
    new_str[len_dest + i] = src[i];
  }
  new_str[len_new - 1] = '\0';
  return new_str;
}

char* wstaw(const char* src, char s) {
  size_t len = dlugosc(src);
  size_t new_len = len * 2 / 3 + len + 1;
  char* new_str = new char[new_len];
  size_t i, j;
  for (i = 0, j = 0; i < len; i++) {
    new_str[j++] = src[i];
    if ((i + 1) % 3 == 0) {
      new_str[j++] = s;
    }
  }
  new_str[new_len - 1] = '\0';
  return new_str;
}

void wstaw(char* dest, const char* src, char s) {
  size_t i, j;
  for (i = 0, j = 0; src[i] != '\0'; i++) {
    dest[j++] = src[i];
    if ((i + 1) % 3 == 0) {
      dest[j++] = s;
    }
  }
  dest[j] = '\0';
}

int porownaj(const char* str1, const char* str2) {
  while (*str1 != '\0' && *str2 != '\0') {
    if (*str1 > *str2) {
      return 1;
    } else if (*str1 < *str2) {
      return -1;
    }
    str1++;
    str2++;
  }
  if (*str1 == '\0' && *str2 == '\0') {
    return 0;
  } else if (*str1 == '\0') {
    return -1;
  } else {
    return 1;
  }
}

size_t szukaj(const char* src, char c) {
  size_t licznik = 0;
  for (size_t i = 0; src[i] != '\0'; i++) {
    if (src[i] == c) {
      licznik++;
    }
  }
  return licznik;
}

int main() {
  const char* napis1 = "Ala ma kota";
  const char* napis2 = "X";

  // Wstawienie "X" co trzeci znak (wersja 1 - alokowanie pamięci)
  char* nowy_napis = wstaw(napis1, napis2[0]);

  // Wyświetlenie nowego napisu
  std::cout << nowy_napis << std::endl;

  // Długość nowego napisu
  size_t dlugosc_nowego_napisu = dlugosc(nowy_napis);
  std::cout << "Długość nowego napisu (wersja 1): " << dlugosc_nowego_napisu << std::endl;

  // Zwolnienie pamięci
  delete[] nowy_napis;

  // Wstawienie "X" co trzeci znak (wersja 2 - bez alokowania pamięci)
  char napis3[50] = "Ala ma kota";
  wstaw(napis3, napis2[0]);

  // Wyświetlenie nowego napisu
  std::cout << napis3 << std::endl;

  // Długość nowego napisu (bez zmian)
  std::cout << "Długość nowego napisu (wersja 2): " << dlugosc(napis3) << std::endl;

  // Porównanie napisów
  int wynik_porownania = porownaj(napis1, napis2);
  if (wynik_porownania > 0) {
    std::cout << "Napis \"" << napis1 << "\" jest leksykograficznie większy od napisu \"" << napis2 << "\"." << std::endl;
  } else if (wynik_porownania < 0) {
    std::cout << "Napis \"" << napis1 << "\" jest leksykograficznie mniejszy od napisu \"" << napis2 << "\"." << std::endl;
  } else {
    std::cout << "Napisy \"" << napis1 << "\" i \"" << napis2 << "\" są leksykograficznie równe." << std::endl;
  }

  // Liczba wystąpień znaku 'a' w napisie
  size_t liczba_a = szukaj(napis1, 'a');
  std::cout << "Liczba wystąpień znaku 'a' w napisie \"" << napis1 << "\": " << liczba_a << std::endl;

  return 0;
}