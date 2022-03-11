#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Cereal {
  enum {MAX_CHAR_LEN = 500};
  char name[MAX_CHAR_LEN] = {' '};
  double Calories;
  double Protein;
  double Fat;
  double Sodium;
  double Fiber;
  double Carbs;
  double Sugar;
  double CupsPerServing;
  int MaxCereal;
  Cereal();
};
int readInt(const char prompt[]);
double readDouble(const char prompt[]);
Cereal::Cereal(){
  Calories = 0;
  Protein = 0;
  Fat = 0;
  Sodium = 0;
  Fiber = 0;
  Carbs = 0;
  Sugar = 0;
  CupsPerServing = 0;
};


Cereal readCereal2(ifstream &cFile){
  Cereal a;
    cFile.get(a.name, Cereal::MAX_CHAR_LEN, ';');
    cFile.ignore(100,';');
    cFile >> a.Calories;
    cFile.ignore(100,';');
    cFile >> a.Protein;
    cFile.ignore(100,';');
    cFile >> a.Fat;
    cFile.ignore(100,';');
    cFile >> a.Sodium;
    cFile.ignore(100,';');
    cFile >> a.Fiber;
    cFile.ignore(100,';');
    cFile >> a.Carbs;
    cFile.ignore(100,';');
    cFile >> a.Sugar;
    cFile.ignore(100,';');
    cFile >> a.CupsPerServing;
    cFile.ignore(100,'\n');
  return a;
  }
const int MAXCEREAL = 100;
int readCereal(Cereal CerealType[]) {
    ifstream cFile("cereal.txt");
    int num = 0;
    while(cFile.peek() != EOF && num < MAXCEREAL) {
        CerealType[num] = readCereal2(cFile);
        num++;
    }
    return num;
}
void printCereal(ostream &out, Cereal CerealType){
    out << CerealType.name << ";";
    out << CerealType.Calories << ";";
    out << CerealType.Protein << ";";
    out << CerealType.Fat << ";";
    out << CerealType.Sodium << ";";
    out << CerealType.Fiber << ";";
    out << CerealType.Carbs << ";";
    out << CerealType.Sugar << ";";
    out << CerealType.CupsPerServing << endl;
}
void printArrayToScreen(Cereal CerealType[], int CerealMax){
    for (int index = 0; index < CerealMax; index++) {
        cout << "Index " << index << ": ";
        printCereal(cout, CerealType[index]);
    }
}
void printArrayToFile(const char fileName[], Cereal CerealType[], int MaxCereal) {
    ofstream outFile(fileName);
    for (int index = 0; index < MaxCereal; index++) {
        printCereal(outFile, CerealType[index]);
    }
}
void addCereal(Cereal CerealType[], int MaxCereal) {
  MaxCereal++;
  int addC = MaxCereal - 1;
    cout << "Enter name: ";
 cin >> CerealType[addC].name;
 CerealType[addC].Calories = readDouble("Enter Calories: ");
  CerealType[addC].Protein = readDouble("Enter Protein: ");
  CerealType[addC].Fat = readDouble("Enter Fat: ");
  CerealType[addC].Sodium = readDouble("Enter Sodium: ");
  CerealType[addC].Fiber = readDouble("Enter Fiber: ");
  CerealType[addC].Carbs = readDouble("Enter Carbs: ");
  CerealType[addC].Sugar = readDouble("Enter Sugar: ");
  CerealType[addC].CupsPerServing = readDouble("Enter CupsPerServing: ");
}
int readInt(const char prompt[]){
    int temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << prompt;
        cin >> temp;
    }
    return temp;
}
double readDouble(const char prompt[]){
    double temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << prompt;
        cin >> temp;
    }
    return temp;
}

void delCereal(Cereal CerealType[], int MaxCereal){
  int DeleteIndex = -1;
  DeleteIndex = readInt("What Cereal index do you want to delete? ");
  for(int index = DeleteIndex; index < MaxCereal - 1; index++){
    CerealType[index] = CerealType[index + 1];
  }
  }


void CerealQuestion(Cereal CerealType[], int MaxCereal){
  int amount;
  int quest2;
  cout << "1. Minimum or 2. Maximum? " << endl;
  cin >> quest2;
  while(quest2 != 1 && quest2 != 2){
    cout << "1. Minimum or 2. Maximum? " << endl;
  cin >> quest2;
  }
  cout << "How much" << endl;
  cin >> amount;
  for(int index = 0; index < MaxCereal; index++){
    if(quest2 == 1){
      if(CerealType[index].Calories > amount){
        cout << CerealType[index].name << ";";
        cout << CerealType[index].Calories << ";";
        cout << CerealType[index].Protein << ";";
        cout << CerealType[index].Fat << ";";
        cout << CerealType[index].Sodium << ";";
        cout << CerealType[index].Fiber << ";";
        cout << CerealType[index].Carbs << ";";
        cout << CerealType[index].Sugar << ";";
        cout << CerealType[index].CupsPerServing << endl;
      }
      }
    if(quest2 == 2){
      if(CerealType[index].Calories < amount){
        cout << CerealType[index].name << ";";
        cout << CerealType[index].Calories << ";";
        cout << CerealType[index].Protein << ";";
        cout << CerealType[index].Fat << ";";
        cout << CerealType[index].Sodium << ";";
        cout << CerealType[index].Fiber << ";";
        cout << CerealType[index].Carbs << ";";
        cout << CerealType[index].Sugar << ";";
        cout << CerealType[index].CupsPerServing << endl;
    }
  }
}
}
void cerealMenu(Cereal CerealType[], int NumCereal){
  int option = 0;
  cout << "Welcome to my cereal orginization." << endl;
  while(option != 7){
  cout << "Pick an option." << endl;
  cout << "1. Print cereals" << endl;
  cout << "2. Add cereal" << endl;
  cout << "3. Delete cereal" << endl;
  cout << "4. Restore Changes" << endl;
  cout << "5. Save Changes" << endl;
  cout << "6. Print all with specific calories" << endl;
  cout << "7. Quit" << endl;
  cin >> option;
  while(option < 1 && option > 7){
  cout << "Pick an option." << endl;
  cout << "1. Print cereals" << endl;
  cout << "2. Add cereal" << endl;
  cout << "3. Delete cereal" << endl;
  cout << "4. Restore Changes" << endl;
  cout << "5. Save Changes" << endl;
  cout << "6. Print all with specific calories" << endl;
  cout << "7. Quit" << endl;
  cin >> option;
  }
  if(option == 1){
    printArrayToScreen(CerealType, NumCereal);
    //printArrayToFile("cereal.txt", CerealType, MaxCereal);
  }
  if(option == 2){
    if(NumCereal < MAXCEREAL){
    addCereal(CerealType, NumCereal);
      NumCereal++;
  }
    }
  if(option == 3){
    delCereal(CerealType, NumCereal);
    NumCereal--;
    }
    
  if(option == 4){
    NumCereal = readCereal(CerealType);
  }
  if(option == 5){
    printArrayToFile("Cereal1.txt", CerealType, NumCereal);
  }
  if(option == 6){
    CerealQuestion(CerealType, NumCereal);
  }
    }
  }
int main(){
  int MaxCereal = 100;
  Cereal CerealType[MaxCereal];
  int num = readCereal(CerealType);
  cerealMenu(CerealType, num);
}