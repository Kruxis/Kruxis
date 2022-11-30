
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
// --- Strukturos ---
struct knygos 
{
  string au;
  string pvd;
  double kn;
};

struct knygynas 
{
  string pvd;
  int kk;
  int krt = 0;
  knygos K[100001];
};

// --- Masyvai ---
knygynas Kn[21];

// --- Kintamieji ---
int n;

// --- Funkcijos ---
void skaitymas();
void rasymas();
void rikiuoti();
void kartojasi();

// --- Darbas ---
int main() 
{
  skaitymas();
  rikiuoti();
  rasymas();
}
void skaitymas() 
{
  ifstream in("U2.txt");
  char a[14];
  in >> n;
  int k = 0;
  for (int i = 0; i < n; i++) 
  {
    in >> Kn[i].pvd >> Kn[i].kk;
    cout << Kn[i].pvd << " " << Kn[i].kk << endl;
    k = Kn[i].kk;
    for (int j = 0; j < k; j++) 
    {
      in >> ws;
      in.get(a, 14);
      Kn[i].K[j].au = a;
      in >> ws;
      in.get(a, 14);
      Kn[i].K[j].pvd = a;
      in >> Kn[i].K[j].kn;
    }
  }
  in.close();
}
void rasymas() 
{
  ofstream out("U2rez.txt");
  int k;
  for (int i = 0; i < n; i++) 
  {
    out << "-----" << endl;
    out << Kn[i].pvd << " " << Kn[i].kk << endl;
    out << "-----" << endl;
    k = Kn[i].kk;
    for (int j = 0; j < k; j++) 
    {
      out << Kn[i].K[j].au << " " << Kn[i].K[j].pvd << " " << Kn[i].K[j].kn << endl;
    }
  }
  out << "-----" << endl;
  kartojasi();
  for (int i = 0; i < n; i++) 
  {
    out << Kn[i].krt << endl;
  }
}
void rikiuoti() 
{
  for (int i = 0; i < n; i++) 
  {
    for (int j = 0; j < Kn[i].kk - 1; j++) 
    {
      for (int h = j + 1; h < Kn[i].kk; h++) 
      {
        if (Kn[i].K[j].au > Kn[i].K[h].au || Kn[i].K[j].au == Kn[i].K[h].au && Kn[i].K[j].pvd > Kn[i].K[h].pvd) 
        {
          swap(Kn[i].K[j], Kn[i].K[h]);
        }
      }
    }
  }
}
int check() {}
void kartojasi() 
{
  for (int i = 0; i < n; i++) 
  {
    for (int j = 0; j < Kn[i].kk-1; j++) 
    {
      
      }
  }
