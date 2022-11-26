#include <stdio.h>
int NumberOfMatrix = 4;
int R[5] = {10,5,1,50,2};

// uncomment [-] if you wanna see the K matrix


int main(){

    int MainM[NumberOfMatrix][NumberOfMatrix];
    int KMtr[NumberOfMatrix][NumberOfMatrix];
    int aux = 0;

    for(int k = 0; k < NumberOfMatrix; k++){
                MainM[k][k] = 0;
                KMtr[k][k] = 0;
    }
    int j = 0;
    for(int d = 1; d < NumberOfMatrix; d++){
        for(int i = 0; i < NumberOfMatrix-d; i++){
            j = i + d;
            printf("i: %d, j: %d\n",i,j);
            MainM[i][j] = (MainM[i][i] + MainM[i+1][j]) + R[i] * R[i+1] * R[j+1];
            //[-]KMtr[i][j] = i;
            for(int k = i+1; k < j; k++){
                aux = (MainM[i][k] + MainM[k+1][j]) + R[i] * R[k+1] * R[j+1]; // (k+1) becuase in our code the index i in R corresponds to i-1, so k = i+1 is the index of i, and we wanna the index of k, so k = k +1 (or i + 2)
             //[-]   KMtr[i][j] = k;
                if(aux < MainM[i][j]){
                    MainM[i][j] = aux;
                 //   KMtr[i][j] = k;
                }
            }
        }
    }

    for(int i = 0; i < NumberOfMatrix; i++){
        for(int j = 0; j < NumberOfMatrix; j++){
            printf("%d ",MainM[i][j]);
        }
        printf("\n");
    }
    //[-]
   // printf("\n\n\n\n");
   // for(int i = 0; i < NumberOfMatrix; i++){
     //   for(int j = 0; j < NumberOfMatrix; j++){
     //       printf("%d ",KMtr[i][j]);
     //   }
     //   printf("\n");
  //  }

}
