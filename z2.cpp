#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
  // Pobranie danych z linii uruchomienia programu
  string str = argv[1];
  string str2 = argv[2];
  int pos = stoi(argv[3]);
  char c = argv[4][0];

  // Wyświetlenie napisu źródłowego
  cout << "Napis źródłowy: " << str << endl;

  // Przypisanie nowej wartości do napisu
  str.assign("Nowy napis");
  cout << "Napis po przypisaniu: " << str << endl;

  // Rozszerzenie napisu
  str.append(" - Dodatkowy tekst");
  cout << "Napis po rozszerzeniu: " << str << endl;

  // Pobranie odwołania do znaku na danej pozycji
  char ch = str.at(pos);
  cout << "Znak na pozycji " << pos << ": " << ch << endl;

  // Zmiana wartości ostatniego znaku
  str.back() = c;
  cout << "Napis po zmianie ostatniego znaku: " << str << endl;

  // Porównanie wartości napisu
  int comparisonResult = str.compare(str2);
  if (comparisonResult < 0) {
    cout << "Napis \"" << str << "\" jest mniejszy od napisu \"" << str2 << "\"." << endl;
  } else if (comparisonResult > 0) {
    cout << "Napis \"" << str << "\" jest większy od napisu \"" << str2 << "\"." << endl;
  } else {
    cout << "Napisy \"" << str << "\" i \"" << str2 << "\" są takie same." << endl;
  }

  // Kopiowanie podciągu do tablicy znaków
  char strCopy[str.length() + 1];
  str.copy(strCopy, pos, str.length() - pos);
  strCopy[str.length() - pos] = '\0';
  cout << "Podciąg skopiowany do tablicy: " << strCopy << endl;

  // Przeszukiwanie napisu
  int foundPos = str.find(str2, pos);
  if (foundPos == -1) {
    cout << "Nie znaleziono \"" << str2 << "\" w napisie." << endl;
  } else {
    cout << "Znaleziono \"" << str2 << "\" na pozycji " << foundPos << endl;
  }

  // Wstawianie znaków do napisu
  str.insert(pos, " - Wstawiony tekst");
  cout << "Napis po wstawieniu tekstu: " << str << endl;

  // Zastępowanie części napisu
  str.replace(pos, str2.length(), " - Zastąpiony tekst");
  cout << "Napis po zastąpieniu tekstu: " << str << endl;

  // Pobieranie napisu ze strumienia
  string line;
  getline(cin, line);
  cout << "Pobrany napis: " << line << endl;

  return 0;
}
