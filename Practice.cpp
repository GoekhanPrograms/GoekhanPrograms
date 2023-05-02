#include <iostream>
#include <fstream>
using namespace std;

/*To Use it, you have to start a new Terminal. Type in: g++ Practice.cpp -o Practice.exe
After that, type: ./Practice.exe   
*/

//funktion für die berechnung des gehalts
float gehalt(int ramy_stunden, int ramy_stundenlohn, int r_Üs)
{
    ramy_stunden += r_Üs;
return ramy_stunden * ramy_stundenlohn;
}

void saveData(int r_s, int r_sl, int r_Üs, float r_g_netto, float r_g)
{
ofstream file;
file.open("TempData.txt");
file << "Stunden: " << r_s << ", " << "Stundenlohn: " <<  r_sl << ", " << " Überstunden: " << r_Üs << std::endl;
file << "Nettolohn: " << r_g_netto << ", " << "Bruttolohn: " << r_g << std::endl;
file.close();
}

/*
void loadData(){
ifstream file;
file.open("TempData.txt");
string line;
while(getline(file, line))
{
string 


 }

file.close();
}
*/



int main (){
    //Var für stunden, std. lohn, Überst. und float für die Resultate
    int r_s, r_sl, r_Üs;
    float r_g_netto, r_g_abzug,  r_g;
std::cout<<"Ramy, schreibe dein Stundenanzahl: ";
std::cin >> r_s;
std::cout<<"Ramy, schreibe dein Stundenlohn: ";
std::cin >> r_sl;
std::cout<<"Ramy, schreibe dein Ueberstunden: ";
std::cin >> r_Üs;

//Schauen ob positiv und dann nettolohn berechnen
if(r_s > 0 && r_sl > 0 && r_Üs >= 0 )
{
r_g = gehalt(r_s, r_sl, r_Üs);

r_g_abzug = r_g * 0.35;
r_g_netto = r_g - r_g_abzug;
}

//Wird in TempData.txt temporär gespeichert bis die nächste Eingabe erfolgt
saveData(r_s, r_sl, r_Üs, r_g_netto, r_g);

//Ausgeben der Resultate
std::cout << "Ramy, dein Bruttogehalt ist: " << r_g << "$" << std::endl;
std::cout << "Ramy, dein Nettogehalt ist:  " << r_g_netto << "$" << std::endl;
    return 0;
}
