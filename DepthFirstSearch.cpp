#include <iostream>
#include <iomanip>

using namespace std;

//fcja rekurencyjna w glab
void DFS(int v, int n, int** A, bool* visited)
{
  int i;
  visited[v]=true; //zaznaczenie odwiedzenia danego wierzcholka
  cout<<setw(4)<<v;  // przetworzenie wezla (wypisujemy jego numer)

// rekurencyjnie odwiedzamy nieodwiedzonych sasiadow

  for(i=0; i<n; i++)
    if((A[v][i]==1) && !visited[i]) DFS(i, n, A, visited);
    //jezeli istnieje krawedz v->i oraz wierzcholek i nie jest oznaczony jako odwiedzony
}

int main()
{
  int n;
  int e, i,j,v1,v2;
  cout<<"Liczba wierzcholkow: ";
  cin>>n;
  cout<<"Liczba krawedzi: ";
  cin>>e;
  int** A = new int*[n];    // Tablica wskaznikow na wierzcholki
  bool* visited=new bool[n]; // Tablica odwiedzin

  for(i = 0; i<n; i++)
    A[i]=new int[n];  // Wiersze macierzy adjacencji [n x n]

  // Macierz wype³niamy zerami
  for(i = 0; i<n; i++)
  {
    visited[i] = false;  // Zaden wierzcholek nie byl jeszcze odwiedzony
    for(j=0; j<n; j++) A[i][j]=0; //Zerowanie tablicy adjacencji
  }

  // Odczyt kolejnych definicji krawedzi

cout<<"Krawedzie: "<<endl;
  for(i=0; i<e; i++)
  {
    cout<<"v1: ";
    cin>>v1; //v1: wierzcholek startowy krawedzi
    cout<<"v2: ";
    cin>>v2;    // v2: wierzcholek koncowy krawedzi
    A[v1][v2]=1;   // zaznaczenie istnienia krawedzi v1->v2
  }

  cout<<endl;

  // Przejscie w glab

  DFS(0, n, A, visited);

  // Usuwamy macierz

  for(i=0; i<n; i++) delete A[i];
  delete [] A;
  delete [] visited;

  cout<<endl;

  return 0;
} 
