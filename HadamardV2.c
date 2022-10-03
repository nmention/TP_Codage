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

void affiche_matrice(int *matrice,int tailleMatrice,int isVector)

{
  if(isVector)
  {
      for (int i = 0; i < tailleMatrice; ++i)
      {
          printf("%i",matrice[i]);
      }
  }
  else
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

int createMessage(int *buf,int size,char *string){
    for (int i = 0; i < size; ++i) {
        buf[i] = atoi(&string[i]);
    }
    return 0;
}


int* transcript(int *matrice, int *messsage){
    return 0;
}




int* hadamard(int *matrice,int *matrice_temp,int nb_user)
{

  if (nb_user>8) {
    free(matrice_temp);
    return matrice;
  }

  if (nb_user==1) {
    matrice[0*nb_user+0]=1;
    matrice_temp[0*nb_user+0]=1;

    affiche_matrice(matrice,nb_user,0);
    return hadamard(matrice,matrice_temp,nb_user*2);
  }

  else
  {
    matrice = realloc(matrice,nb_user*nb_user*sizeof(int));
    initi_matrice(matrice,nb_user);
    int nb_user_temp = nb_user/2;
    for(int i=0; i < nb_user ;i++)
    {
      for(int j=0;  j < nb_user ;j++)
      {
        if (i<nb_user/2 && j<nb_user/2)
        {

          matrice[i*nb_user+j]=matrice_temp[i*nb_user_temp+j];

        }
        else if (i<nb_user/2 && j>=nb_user/2)
        {

          matrice[i*nb_user+j]=matrice_temp[i*nb_user_temp+(j%(nb_user_temp))];


        }
        else if (i>=nb_user/2 && j<nb_user/2)
        {

          matrice[i*nb_user+j]=matrice_temp[(i%(nb_user_temp))*nb_user_temp+j];

        }
        else if (i>=nb_user/2 && j>=nb_user/2)
        {

          matrice[i*nb_user+j]=-matrice_temp[(i%(nb_user_temp))*nb_user_temp+(j%(nb_user_temp))];
        }
      }
    }

    matrice_temp = realloc(matrice_temp,nb_user*nb_user*sizeof(int));

    copie_matrice(matrice,matrice_temp,nb_user);

    affiche_matrice(matrice,nb_user,0);
    return hadamard(matrice,matrice_temp,nb_user*2);
  }
}

int* seqPlusSeq(int* seq1,int* seq2,int *seqFinale,int tailleSeq)
{

  for (int i = 0; i < tailleSeq; i++) {
    seqFinale[i] = seq1[i] + seq2[i];
  }
  return seqFinale;
}

int main()
{
  int *matrice;
  int *matrice_temp;
  int *message;
  int nb_user = 1;




  matrice = malloc(nb_user*nb_user*sizeof(int));
  matrice_temp = malloc(nb_user*nb_user*sizeof(int));



  char *msg_to_send = "101";
  message = malloc(3 * sizeof(int));
  createMessage(message,3,msg_to_send);
  hadamard(matrice,matrice_temp,nb_user);
  printf("---------------------- \n");

  affiche_matrice(message,3,1);



  //free(matrice);

}
