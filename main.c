#include <stdio.h>
#include <stdlib.h>
/*----------------------------------------------------FR---------------------------------------------------------------------*/
/***--NOTE: DANS LA FONCTION tri_mat_rapid IL FAUT Preciser LA TAILLE AVANT D'EXECUTER CAR LA MATRICE EST STATIQUE !!!!!! --***/
/*** void tri_mat_rapid(int mat[size][size],int deb_i,int deb_j,int fin_i,int fin_j,int limite)***/
/*** exemple d'une matrice 3*3 void tri_mat_rapid(int mat[3][3],int deb_i,int deb_j,int fin_i,int fin_j,int limite)***/

/*----------------------------------------------------ENG---------------------------------------------------------------------*/
/*** NOTE : you should change the size of your 2D array in tri_mat_rapid methode in mat[size][size] variable ***/
/*** example: for 2D array of 3*3 the function will be **/
/**void tri_mat_rapid(int mat[3][3],int deb_i,int deb_j,int fin_i,int fin_j,int limite)***/


    /*fonction tri fusion d'une  matrice avec la methode tri rapide*/
    /*Quick sort Function**/

void tri_mat_rapid(int mat[5][5],int deb_i,int deb_j,int fin_i,int fin_j,int limite)
{
    int pivot = mat[deb_i][deb_j];
    int pos_i=deb_i;
    int pos_j=deb_j;
    int b,k;//vraible boolean
    int i_i,i_j;
    //condition de sortie
    //exit condition
    printf("\n***************POSITION DEBUT =[%d][%d] FIN = [%d][%d] AVEC PIVOT = %d\n \n",deb_i,deb_j,fin_i,fin_j,pivot);
    if (deb_i>fin_i)
    {
        return;
    }else {
        if (deb_i==fin_i)
        {
            if (deb_j>=fin_j)
            {
                return;
            }
        }
    }

    //TRI
    //Sorting
    i_i=deb_i;
    i_j=deb_j;
    b=0;//condition d'arret dans les boucles //exit condition of loops
    i_i=deb_i;i_j=deb_j;
        //for(i_i=deb_i;i_i<limite;i_i++)
        while(i_i<limite)
        {
            if (b==1){break;}
            //for (i_j=deb_j;i_j<limite;i_j++)
            while (i_j<limite)
            {
                if ((i_i>fin_i)&&(i_j>fin_j)) {b=1;break;}
                    if (mat[i_i][i_j]<pivot) //permutation //Swapping
                    {
                        printf("PERMUTATION ----- \n");
                        printf("LES INDICES i_i=%d \n i_j=%d \n pos_i=%d \n pos_j=%d \n\n",i_i,i_j,pos_i,pos_j);
                        mat[pos_i][pos_j]=mat[i_i][i_j];
                        printf("permutation de mat[%d][%d]=mat[%d][%d]\n",pos_i,pos_j,i_i,i_j);
                        pos_j++;
                        printf("pos_j=%d \n",pos_j);
                        if (pos_j==limite) //fin de ligne //end of line
                        {
                            pos_j=0;
                            pos_i++;
                            printf("saut de ligne pos_i=%d pos_j=%d",pos_i,pos_j);
                        }
                        printf("permutation de mat[%d][%d]=mat[%d][%d]\n",i_i,i_j,pos_i,pos_j);
                        mat[i_i][i_j]=mat[pos_i][pos_j];
                        printf("permutation de mat[%d][%d]=""%d""\n",pos_i,pos_j,pivot);
                        mat[pos_i][pos_j]=pivot;
                        printf(" \n FIN PERMUT !!!\n");
                        /*
                        printf(" \n \n----------MATRICE APRES CHANGEMENT ---------\n");
                            //2D array after changes
                            //Matrice apres changement 
                            //unnecessary //non-nécessaire
                            for (int i=0;i<limite;i++)
                            {
                                for (int j=0;j<limite;j++)
                                {
                                    printf("%7d",mat[i][j]);
                                }
                                printf("\n");
                                }
                        */

                    }
                    i_j++;

                }
              i_j=0;//nouvelle ligne //new line
              i_i++;
            }


/*
    //Matrice apres tri d'une partie 
    //2D array after sorting PART
    //unnecessary //non-nécessaire
    printf("\n \n----------MATRICE APRES TRI DE LA PARTIE -------\n");
    for (int i=0;i<limite;i++)
    {
        for (int j=0;j<limite;j++)
        {
            printf("%7d",mat[i][j]);
        }
        printf("\n");
    }
*/
    // on appel la fonction recursive pour les autres parties du tableau
    // calling the sorting methode for the next sub parts of 2D array
    if (pos_j==limite){pos_j=0;pos_i++;}
    tri_mat_rapid(mat,deb_i,deb_j,pos_i,pos_j,limite);//partie gauche
    pos_j++;
    if (pos_j==limite){pos_j=0;pos_i++;}
    tri_mat_rapid(mat,pos_i,pos_j,fin_i,fin_j,limite);//partie droite

}

int main()
{
    int i,j,n;
    srand(time(NULL));

    printf("-------------------PROGRAMME TRI d UNE MATRICE AVEC LE TRI RAPID--------------\n");
    printf("donner la taille de la matrice ");
    scanf("%d",&n); 
    int mat[n][n];

    /**remplissage des valeurs**/
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            //filling the 2D array with integers 0-20 , you can change it to your desired values
            mat[i][j]=rand()%20; //vous pouvez changer le modulo pour avoir des valeurs plus grandes

        }
    }
    /*Affichage de la matrice */
    //printing 2D array
    printf("\n \n MATRICE AVANT TRI -------\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%7d",mat[i][j]);
        }
        printf("\n");
    }

    /*test*/
    //TEST
    tri_mat_rapid(mat,0,0,n-1,n-1,n);
    //Printing Results
    //affichage des résultats 
        printf("\n \n----------\\*\\*\\*\\*MATRICE APRES TRI TOTAL /*/*/*/-------\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%7d",mat[i][j]);
        }
        printf("\n");
    }






    return 0;

}

