#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void kopiuj(const string src, char* dest){
  if(dest != nullptr){
    strcpy(dest, src.c_str());
  }
}

void kopiuj(const char* src, string& dest, const int n){
  int length = strlen(src);
  if(n <= length){
    for(int i = n; i < length; i++){
      dest += src[i];      
    }
  }

}

string kopiuj(const string src, string dest, const int n){
  dest.clear();

    for(size_t i = n; i < src.length(); i++){
      dest += src[i];
      
    }
  return dest;
}

int pozycja(const char* str, const string src){
  
  bool var = false;
  size_t length_str = strlen(str);
  size_t length_src = src.size();
  
  for(size_t i = 0; i < length_src; i++){
    
    if(src[i] == str[0]){
      var = true;
      
      for(size_t j = 1; j < length_str; j++){	
	if(src[i + j] != str[j]){
	  var = false;
	  break;
	}
      }
      if(var){
	return i;
      }
    }
  }
  return 0;
}

int pozycja(const string str, const string src){
  
  bool var = false;
  size_t length_str = str.size();
  size_t length_src = src.size();
  
  for(size_t i = 0; i < length_src; i++){
    
    if(src[i] == str[0]){
      var = true;
      
      for(size_t j = 1; j < length_str; j++){	
	if(src[i + j] != str[j]){
	  var = false;
	  break;
	}
      }
      if(var){
	return i;
      }
    }
  }
  return 0;
}

int porownanie(const string str1, const string str2){
  if(str1 < str2){
    return -1;
  }
  else if(str1 == str2){
    return 0;
  }
  else if(str1 > str2){
    return 1; 
  }
  return 2;
}



int main(int argc, char* argv[]){
  if(argc != 6){

    cerr << "Zła liczba argumentów";
    return 1;
  }

  const string src = argv[1];
  const string str1 = argv[2];
  const string str2 = argv[3];
  const char* str = argv[4];
  const int n = stoi(argv[5]);
  

  char kopia_fun[64];
  kopiuj(src, kopia_fun);
  cout << "Kopia poprzez funkcje: " << kopia_fun << endl;
  
  string kopia = src;
  cout << "Kopia poprzez przypisanie: " << kopia << endl;

  string polaczone;
  polaczone = str1 + str2;
  cout << "Polaczenie str1 i str2: " << polaczone << endl;

  string kopia_n;
  kopiuj(kopia_fun, kopia_n, n);
  cout << "Kopia odejmujaca pierwsze: " << n << " znakow: " << kopia_n <<endl;

  string kopia_n2;
  kopia_n2 = kopiuj(src, kopia_n2, n);
  cout << "Kopia odejmujaca pierwsze: " << n << " znakow i zwracajaca dest: " << kopia_n2 << endl;

  int poz;
  poz = pozycja(str, src);
  cout << "Pozycja: " << str << " w slowie " << src << " to: " << poz << endl;

  int poz2;
  poz2 = pozycja(str2, src);
  cout << "Pozycja: " << str2 << " w slowie " << src << " to: " << poz2 << endl;


  int por;
  por = porownanie(str1, str2);
  switch(por){
  case -1:
    cout << str1 << " < " << str2 << endl;
    break;
  case 0:
    cout << str1 << " = " << str2 << endl;
    break;
  case 1:
    cout << str1 << " > " << str2 << endl;
  }
  
  cout << endl;
  return 0;
}
