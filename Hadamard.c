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

int* hadamard(int *matrice,int nb_user)
{
  //affiche_matrice(matrice,nb_user);
  //int matrice_temp[nb_user][nb_user];
  int *matrice_temp;
  matrice_temp = malloc(nb_user*nb_user*sizeof(int));
  //Condition d'arret
  if (nb_user>4)  return 0;


  if (nb_user==1) {
    matrice[0*nb_user+0]=1;
    //copie_matrice(matrice,*matrice_temp,nb_user);

    printf("nb_user: %i\n",nb_user);
    affiche_matrice(matrice,nb_user);

    return (hadamard(matrice,nb_user*2));
  }
  else
  {
    matrice = realloc(matrice,nb_user*nb_user*sizeof(int));

    /*for(int i=0; i<nb_user/2 ;i++)
    {
      for(int j=0; j<nb_user/2 ;j++)
      {
        //printf("valeur--%i\n",matrice[i*nb_user+j]);
        for(int k=0; k<nb_user ;k++)
        {
          for(int z=0; z<nb_user ;z++)
          {

            if (k<nb_user/2 && z>=nb_user/2 || k>=nb_user/2 && z<nb_user/2) {
              matrice[k*nb_user+z]=matrice[i*nb_user+j];
            }
            else if (k>=nb_user/2 && z>=nb_user/2)  //4/4 quart
            {
              matrice[k*nb_user+z]=-matrice[i*nb_user+j];
            }
            else
            {
              //matrice[k*nb_user+z]=matrice[k*nb_user+z];
            }

          }
        }

      }
      printf("\n");
    }*/

    for(int i=0; i<nb_user/2 ;i++)
    {
      for(int j=0; j<nb_user/2 ;j++)
      {
        //printf("valeur--%i\n",matrice[i*nb_user+j]);
        for(int k=0; k<nb_user ;k++)
        {
          for(int z=0; z<nb_user ;z++)
          {

            if (k>=nb_user/2 && z>=nb_user/2) {
              matrice[k*nb_user+z]=-matrice_temp[k*nb_user+z];
            }
            else
            {
              matrice[k*nb_user+z]=matrice_temp[k*nb_user+z];
            }

          }
        }

      }
      printf("\n");
    }
    copie_matrice(matrice,matrice_temp,nb_user);
    printf("nb_user: %i\n",nb_user);
    affiche_matrice(matrice,nb_user);
    printf("\n");
    return(hadamard(matrice,nb_user*2));
  }

}
int* hadamard2(int *matrice,int nb_user)
{

  //int *array;

  if (nb_user>8) {
    //free(array);

    return matrice;
  }

  if (nb_user==1) {
    //array = malloc(nb_user*sizeof(int));
    //matrice[0*nb_user+0]=1;
    //copie_matrice(matrice,matrice_temp,nb_user);
    affiche_matrice(matrice,nb_user);
    return (hadamard2(matrice,nb_user*2));
  }
  else
  {
    matrice = realloc(matrice,nb_user*sizeof(int));


  /*  for(int i=0; i<nb_user/2 ;i++)
    {
      for(int j=0; j<nb_user/2 ;j++)
      {
        for(int k=0; k<nb_user ;k++)
        {
          for(int z=0; z<nb_user ;z++)
          {
            //matrice[k*nb_user+z]=matrice_temp[i*nb_user+j];

          }
        }

      }
    }*/
    affiche_matrice(matrice,nb_user);
    return(hadamard2(matrice,nb_user*2));
  }

}

void matrice_a_table(int *matrice,int array,int taille)
{
  for (int i = 0; i < taille; i++)
  {
    for (int i = 0; i < taille; i++)
    {

    }
  }
}

int* hadamard3(int *matrice,int *matrice_temp,int nb_user)
{
  //int* matrice_temp;
  //matrice_temp=malloc(nb_user*nb_user*sizeof(int));
  if (nb_user>8) {
    free(matrice_temp);
    return matrice;
  }

  if (nb_user==1) {
    matrice[0*nb_user+0]=1;
    matrice_temp[0*nb_user+0]=1;
    //matrice_temp=malloc(nb_user*nb_user*sizeof(int));
    //copie_matrice(matrice,matrice_temp,nb_user);

    affiche_matrice(matrice,nb_user);
    return hadamard3(matrice,matrice_temp,nb_user*2);
  }
  /*else if(nb_user==2)
  {
    matrice[0*nb_user+0]=1;
    matrice[0*nb_user+1]=1;
    matrice[1*nb_user+0]=1;
    matrice[1*nb_user+1]=-1;

    matrice_temp = realloc(matrice_temp,nb_user*nb_user*sizeof(int));
    copie_matrice(matrice,matrice_temp,nb_user);

    affiche_matrice(matrice,nb_user);
    affiche_matrice(matrice_temp,nb_user);
    return hadamard3(matrice,matrice_temp,nb_user*2);
  }*/
  else
  {
    matrice = realloc(matrice,nb_user*nb_user*sizeof(int));
    initi_matrice(matrice,nb_user);
    int nb_user_temp = nb_user/2;
    //affiche_matrice(matrice_temp,nb_user/2);
    for(int i=0; i < nb_user ;i++)
    {
      for(int j=0;  j < nb_user ;j++)
      {
        if (i<nb_user/2 && j<nb_user/2)
        {
          //printf("1\n");
          //printf("valeur:%i\n",matrice_temp[i*nb_user_temp+j]);
          matrice[i*nb_user+j]=matrice_temp[i*nb_user_temp+j];

        }
        else if (i<nb_user/2 && j>=nb_user/2)
        {
          //printf("2\n");
          //printf("valeur:%i\n",matrice_temp[i*nb_user_temp+(j%(nb_user_temp))]);
          matrice[i*nb_user+j]=matrice_temp[i*nb_user_temp+(j%(nb_user_temp))];


        }
        else if (i>=nb_user/2 && j<nb_user/2)
        {
          //printf("3\n");
          //printf("valeur:%i\n",matrice_temp[(i%(nb_user_temp))*nb_user_temp+j]);
          matrice[i*nb_user+j]=matrice_temp[(i%(nb_user_temp))*nb_user_temp+j];

        }
        else if (i>=nb_user/2 && j>=nb_user/2)
        {
          //printf("4\n");
          //printf("valeur:%i\n",-matrice_temp[(i%(nb_user_temp))*nb_user_temp+(j%(nb_user_temp))]);
          matrice[i*nb_user+j]=-matrice_temp[(i%(nb_user_temp))*nb_user_temp+(j%(nb_user_temp))];
        }
      }
    }
    //printf("avant\n");
    //affiche_matrice(matrice_temp,nb_user/2);
    matrice_temp = realloc(matrice_temp,nb_user*nb_user*sizeof(int));
    //printf("apres \n");
    //affiche_matrice(matrice_temp,nb_user);
    copie_matrice(matrice,matrice_temp,nb_user);
    //printf("apres \n");
    //affiche_matrice(matrice_temp,nb_user);
    affiche_matrice(matrice,nb_user);
    return hadamard3(matrice,matrice_temp,nb_user*2);
  }
}



int main()
{
  int *matrice;
  int *matrice_temp;
  int nb_user = 1;

  matrice = malloc(nb_user*nb_user*sizeof(int));
  matrice_temp = malloc(nb_user*nb_user*sizeof(int));

  //initi_matrice(matrice,tailleMatrice);
  hadamard3(matrice,matrice_temp,nb_user);

  /*int matriceTest[nb_user][nb_user];
  int cpt=1;
  for(int i=0; i<nb_user ;i++)
  {
    for(int j=0; j<nb_user ;j++)
    {
      //printf("\n\nindex:%i:%i\n\n",i,j);
      if (i<nb_user/2 && j>=nb_user/2 || i>=nb_user/2 && j<nb_user/2) {
        //printf("test1 OK\n");
        matriceTest[i][j]=cpt;
      }
      else if(i>=nb_user/2 && j>=nb_user/2)
      {
        //printf("test2 OK\n");
        matriceTest[i][j]=-cpt;
      }
      else
      {
        matriceTest[i][j]=0;
      }
      printf("%i ",matriceTest[i][j]);
      cpt++;
    }
    printf("\n");
  }*/

  //free(matrice);

}
