#include <iostream>
#include <string>
#include <cstring>


using namespace std;

// Funkcja kopiująca napis źródłowy do napisu docelowego
void copyString(const string& src, char* dest) {
  strcpy(dest, src.c_str());
}


// Funkcja kopiująca napis źródłowy do napisu docelowego (operator przypisania)
void copyStringToStr(const string& src, string& dest) {
  dest = src;
}

// Funkcja łącząca dwa napisy
string concatenateStrings(const string& str1, const string& str2) {
  return str1 + str2;
}

// Funkcja kopiująca napis źródłowy do napisu docelowego z pominięciem n pierwszych znaków
void copyStringWithOffset(const string& src, string& dest, int n) {
  dest = src.substr(n);
}

// Funkcja kopiująca napis źródłowy do napisu docelowego z pominięciem n pierwszych znaków (zwracająca dest)
string copyStringWithOffsetReturn(const string& src, int n) {
  return src.substr(n);
}

// Funkcja zwracająca pozycję pierwszego wystąpienia poszukiwanego napisu
int findFirstOccurrence(const string& src, const string& str) {
  return src.find(str);
}

// Funkcja zwracająca pozycję pierwszego wystąpienia poszukiwanego napisu (od określonej pozycji)
int findFirstOccurrenceFromPos(const string& src, const string& str, int pos) {
  return src.find(str, pos);
}

// Funkcja zwracająca pozycję pierwszego wystąpienia poszukiwanego napisu
int findFirstOccurrence2(const string& src, const string& str) {
  int i = 0;
  int j = 0;
  while (src[i] != '\0') {
    if (src[i] == str[j]) {
      // Sprawdź, czy cały wzorzec pasuje
      bool found = true;
      while (str[j] != '\0' && found) {
        if (src[i + j] != str[j]) {
          found = false;
          break;
        }
        j++;
      }
      if (found) {
        return i; // Znaleziono wzorzec
      }
      j = 0; // Resetuj indeks wzorca
    }
    i++;
  }
  return -1; // Nie znaleziono wzorca
}

// Funkcja zwracająca pozycję pierwszego wystąpienia poszukiwanego napisu (od określonej pozycji)
int findFirstOccurrenceFromPos2(const string& src, const string& str, int pos) {
  int i = pos;
  int j = 0;
  while (src[i] != '\0') {
    if (src[i] == str[j]) {
      // Sprawdź, czy cały wzorzec pasuje
      bool found = true;
      while (str[j] != '\0' && found) {
        if (src[i + j] != str[j]) {
          found = false;
          break;
        }
        j++;
      }
      if (found) {
        return i; // Znaleziono wzorzec
      }
      j = 0; // Resetuj indeks wzorca
    }
    i++;
  }
  return -1; // Nie znaleziono wzorca
}

// Funkcja porównująca dwa napisy
int compareStrings(const string& str1, const string& str2) {
  return str1.compare(str2);
}

// Funkcja porównująca dwa napisy
int compareStrings2(const string& str1, const string& str2) {
  int i = 0;
  while (str1[i] != '\0' && str2[i] != '\0') {
    if (str1[i] < str2[i]) {
      return -1;
    } else if (str1[i] > str2[i]) {
      return 1;
    }
    i++;
  }
  // Sprawdź długość łańcuchów
  if (str1[i] == '\0' && str2[i] != '\0') {
    return -1;
  } else if (str1[i] != '\0' && str2[i] == '\0') {
    return 1;
  }
  return 0; // Napisy
}

int main(int argc, char** argv) {
  // Pobranie danych z linii uruchomienia programu
  string src = argv[1];
  string dest;
  string str1 = argv[2];
  string str2 = argv[3];
  int n = stoi(argv[4]);
  int pos = stoi(argv[5]);

  // Wyświetlenie napisu źródłowego
  cout << "Napis źródłowy: " << src << endl;

  // Kopiowanie napisu źródłowego do napisu docelowego
  char destChar[src.length() + 1];
  copyString(src, destChar);
  cout << "Napis docelowy (char*): " << destChar << endl;

  // Kopiowanie napisu źródłowego do napisu docelowego (operator przypisania)
  copyStringToStr(src, dest);
  cout << "Napis docelowy (string): " << dest << endl;

  // Łączenie dwóch napisów
  string concatenatedString = concatenateStrings(str1, str2);
  cout << "Połączone napisy: " << concatenatedString << endl;

  // Kopiowanie napisu źródłowego do napisu docelowego z pominięciem n pierwszych znaków
  copyStringWithOffset(src, dest, n);
  cout << "Napis docelowy z pominięciem " << n << " pierwszych znaków: " << dest << endl;

  // Kopiowanie napisu źródłowego do napisu docelowego z pominięciem n pierwszych znaków (zwracająca dest)
  string dest2 = copyStringWithOffsetReturn(src, n);
  cout << "Napis docelowy z pominięciem " << n << " pierwszych znaków (zwracana): " << dest2 << endl;

  // Znajdowanie pierwszego wystąpienia poszukiwanego napisu
  int firstOccurrence = findFirstOccurrence(src, str);
  cout << "Pierwsze wystąpienie napisu \"" << str << "\": " << firstOccurrence << endl;

  // Znajdowanie pierwszego wystąpienia poszukiwanego napisu (od określonej pozycji)
  int firstOccurrenceFromPos = findFirstOccurrenceFromPos(src, str, pos);
  cout << "Pierwsze wystąpienie napisu \"" << str << "\" od pozycji " << pos << ": " << firstOccurrenceFromPos << endl;

  // Porównywanie dwóch napisów
  int comparisonResult = compareStrings(str1, str2);
  if (comparisonResult < 0) {
    cout << "Napis \"" << str1 << "\" jest mniejszy od napisu \"" << str2 << "\"." << endl;
  } else if (comparisonResult > 0) {
    cout << "Napis \"" << str1 << "\" jest większy od napisu \"" << str2 << "\"." << endl;
  } else {
    cout << "Napisy \"" << str1 << "\" i \"" << str2 << "\" są takie same." << endl;
  }

  return 0;
}
