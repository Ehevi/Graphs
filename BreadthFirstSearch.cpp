#include <iostream>
#include <iomanip>
using namespace std;

struct node
{
    node* next;
    int value;
};

struct FIFO
{
    node* first;
    node* last;
};

FIFO* newFifo()
{
    FIFO* queue=new FIFO;
    queue->first=NULL;
    queue->last=NULL;
    return queue;
}

void deleteFifo(FIFO* queue)
{
    delete [] queue;
}

bool isEmpty(FIFO* queue)
{
    if(queue->first==NULL && queue->last==NULL) return true;
    return false;
}

void put(FIFO* queue, int tmp)
{
    node* pointer=new node;
    pointer->next=NULL;
    pointer->value=tmp;
    if(isEmpty(queue))
    {
        queue->first=pointer;
        queue->last=pointer;
    }
    else
    {
        queue->last->next=pointer;
        queue->last=pointer;
    }
}

int get(FIFO* queue)
{
    int toReturn=queue->first->value;
    node* pointer=queue->first;
    queue->first=queue->first->next;
    if(queue->first==NULL) queue->last=NULL;
    delete pointer;
    return toReturn;
}

//fcja rekurencyjna wszerz
void BFS(int v, int n, int** A, FIFO* queue)
{
  int i, next;
  for(i=0; i<n; i++)
  {
      if(A[v][i]==1) put(queue, i); //wszystkie sasiednie wezly do kolejki
      //jako zaznaczone, nieprzetworzone
  }
  cout<<setw(4)<<v;  //przetworzenie wezla (wypisujemy jego numer)
    while(!isEmpty(queue))
    {
        next=get(queue);
        BFS(next, n, A, queue);
    }
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

  for(i = 0; i<n; i++)
    A[i]=new int[n];  // Wiersze macierzy adjacencji [n x n]

  // Macierz wype³niamy zerami
  for(i = 0; i<n; i++)
  {
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

  // Przejscie wszerz
  FIFO* queue=newFifo();
  BFS(0, n, A, queue);

  // Usuwamy macierz

  for(i=0; i<n; i++) delete A[i];
  delete [] A;
  deleteFifo(queue);
  
  cout<<endl;

  return 0;
}
