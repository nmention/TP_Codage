#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initi_matrice(int *matrice,int tailleMatrice)
{

  for(int i=0; i<tailleMatrice ;i++)
  {
    for(int j=0; j<tailleMatrice ;j++)
    {
      matrice[i*tailleMatrice+j]=0;
    }
  }
}



void affiche_matrice(int *matrice,int tailleMatrice)
{
  printf("nb_user:%i\n",tailleMatrice);
  for(int i=0; i<tailleMatrice ;i++)
  {
    for(int j=0; j<tailleMatrice ;j++)
    {
      printf("%2.i ",matrice[i*tailleMatrice+j]);
    }
    printf("\n");
  }
  printf("\n");
}

int* copie_matrice(int *matrice_src,int *matrice_dest,int tailleMatrice)
{
  for(int i=0; i<tailleMatrice ;i++)
  {
    for(int j=0; j<tailleMatrice ;j++)
    {
      matrice_dest[i*tailleMatrice+j]=matrice_src[i*tailleMatrice+j];
    }
  }
  return matrice_dest;
}

int createMessage(int *buf,int size,int *value){

    for (int i = 0; i < size; i++) {
        buf[i] = value[i];
        printf("%i",buf[i]);
    }
    return 0;
}


int transcript(int *matrice, int *messsage,int row, int size_msg, int size_matrix,int *target){
    printf("%d!!!!",target[0]);
    target[0] = 17;
    printf("%d!!!!",target[0]);

    /*int *transcription;
    transcription = malloc(size_msg * size_matrix *sizeof(int));*/
    for (int i = 0; i < size_msg ; ++i) {
        for (int j = 0; j < size_matrix ; ++j) {
            if (messsage[i] == 0 ){
                target[size_matrix * i + j] = matrice[row*size_matrix+j]*-1;
                printf("case : %d \n",target[size_matrix * i + j]);
            }
            else{
                printf("case : %d \n",target[0]);
                printf("case : %d \n",matrice[0]);
                target[size_matrix * i +j] = matrice[row*size_matrix+j];
                printf("case : %d \n",target[0]);
            }
        }
    }

    return 0;
}




int* hadamard(int *matrice,int *matrice_temp,int nb_user,int nb_user_croissant)
{


  if (nb_user_croissant>nb_user) {
    free(matrice_temp);

    return matrice;
  }

  if (nb_user_croissant==1) {
    matrice[0*nb_user_croissant+0]=1;
    matrice_temp[0*nb_user_croissant+0]=1;

    affiche_matrice(matrice,nb_user_croissant);
    return hadamard(matrice,matrice_temp,nb_user,nb_user_croissant*2);
  }

  else
  {
    matrice = realloc(matrice,nb_user_croissant*nb_user_croissant*sizeof(int));
    initi_matrice(matrice,nb_user_croissant);
    int nb_user_temp = nb_user_croissant/2;
    for(int i=0; i < nb_user_croissant ;i++)
    {
      for(int j=0;  j < nb_user_croissant ;j++)
      {
        if (i<nb_user_croissant/2 && j<nb_user_croissant/2)
        {

          matrice[i*nb_user_croissant+j]=matrice_temp[i*nb_user_temp+j];

        }
        else if (i<nb_user_croissant/2 && j>=nb_user_croissant/2)
        {

          matrice[i*nb_user_croissant+j]=matrice_temp[i*nb_user_temp+(j%(nb_user_temp))];


        }
        else if (i>=nb_user_croissant/2 && j<nb_user_croissant/2)
        {

          matrice[i*nb_user_croissant+j]=matrice_temp[(i%(nb_user_temp))*nb_user_temp+j];

        }
        else if (i>=nb_user_croissant/2 && j>=nb_user_croissant/2)
        {

          matrice[i*nb_user_croissant+j]=-matrice_temp[(i%(nb_user_temp))*nb_user_temp+(j%(nb_user_temp))];
        }

      }
    }

    matrice_temp = realloc(matrice_temp,nb_user_croissant*nb_user_croissant*sizeof(int));

    copie_matrice(matrice,matrice_temp,nb_user_croissant);

    affiche_matrice(matrice,nb_user_croissant);
    return hadamard(matrice,matrice_temp,nb_user,nb_user_croissant*2);
  }
}

int* seqPlusSeq(int* seq1,int* seq2,int tailleSeq)
{
  int *seqFinale = malloc(tailleSeq*sizeof(int));
  for (int i = 0; i < tailleSeq; i++) {
    seqFinale[i] = seq1[i] + seq2[i];
  }
  return seqFinale;
}

int main()
{
    int *message;
  int *matrice;
  int *matrice_temp;
  int nb_user = 8;
  int *seqFinale;
  int seq1[]={1,-1,1,-1,1,-1,1,-1,-1,1,-1,1,-1,1,-1,1,1,-1,1,-1,1,-1,1,-1};
  int seq2[]={-1,1,1,-1,-1,1,1,-1,1,-1,-1,1,1,-1,-1,1,1,-1,-1,1,1,-1,-1,1};

  matrice = malloc(nb_user*nb_user*sizeof(int));
  matrice_temp = malloc(nb_user*nb_user*sizeof(int));


  matrice = hadamard(matrice,matrice_temp,nb_user,1);
  affiche_matrice(matrice,nb_user);
  seqFinale=seqPlusSeq(seq1,seq2,nb_user*3);
  for (int i = 0; i < nb_user*3; i++) {
    printf("%i ",seqFinale[i]);
  }
  printf("\n");

  int msg[] = {1,1,0};
  message = malloc(3 * sizeof(int));
  createMessage(message,3,msg);
  hadamard(matrice,matrice_temp,nb_user,1);

  int *target;
  target = malloc(3 * 8 *sizeof(int));
  transcript(matrice,msg,1,3,8,target);


  affiche_matrice(message,3);
  printf("---------------------- \n");
  affiche_matrice(target,8);

  free(seqFinale);
  //free(matrice);

}
