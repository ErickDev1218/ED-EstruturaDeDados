#include <iostream> // std::cout, std::fixed
#include <iomanip> // std::setprecision

struct aluno {
   float nota[3];
   float media;
};

// Recebe um aluno passado por referência, e preenche o campo 'media' com a
// média das 3 notas do aluno.
void calcula_media(aluno *a){
   float med;
   for(int i = 0; i < 3; i++){
       med += a->nota[i];
   }
   med = med/3;
   a->media = med;
   
}

int main(){
   aluno a;
   int i;
   for (i = 0; i < 3; i++)
      std::cin >> a.nota[i];
   
   // Chame a função 'calcula_media' passando o aluno 'a' por referência.
   calcula_media(&a);
   
   std::cout << std::fixed;
   std::cout << std::setprecision(1) << a.media;
   
   return 0;
}