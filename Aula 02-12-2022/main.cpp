#include <iostream>
#include <cstdlib> 
#include <chrono>
using namespace std;
template<typename T>
void selectionsort(T A[],int l, int r){
    for(int i = l; i < r; i++){
        int indexMin = i;
        for(int j = i+1; j <= r; j++){
            if(A[j] < A[indexMin]){
                indexMin = j;
            }
            int aux = A[i];
            A[i] = A[indexMin];
            A[indexMin] = aux;
        }
    }
}

template<typename T>
void testalgoritmo(T vec[],int l, int r,string nome, void (*func)(T[],int,int)){
    auto start = std::chrono::steady_clock::now();
    func(vec, l, r);
    auto end = std::chrono::steady_clock::now();
    auto elapsed_time = end-start;
    auto duration = 
        std::chrono::duration_cast<std::chrono::microseconds>(elapsed_time);
    cout << "\ntime " << nome << ": " << duration.count() << " microseconds" << endl;

    //print(vec,l,r);
    
}

template< typename T >
void bubblesort(T A[], int l, int r) {
    bool trocou = true;
    for(int i = l; i < r && trocou; i++) {
        trocou = false;
        for(int j = r; j > i; j--) {
            if(A[j] < A[j-1]) {
                T aux = A[j];
                A[j] = A[j-1];
                A[j-1] = aux;
                trocou = true;
            }
        }
    }
}
template <typename T>
void insertionsort(T A[],int l, int r){
    for(int j = l+1; j <= r; j++){
        T key = A[j];
        int i = j-1;
        while(i >= l && A[i] > key){
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}
template< typename T >
void print(T A[], int l, int r) {
    for(int i = l; i <= r; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    const int n = 99999; 
    int vec[n], vec2[n],vec3[n];
    for(int i = 0; i < n; ++i) {
        vec[i] = vec2[i] = vec3[i] = rand() % 100;
    }
    testalgoritmo(vec,0,n-1,"bubblesort",bubblesort);
    testalgoritmo(vec2,0,n-1,"insertionsort",insertionsort);
    testalgoritmo(vec3,0,n-1,"selectionsort",selectionsort);
}