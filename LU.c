#include<stdio.h>

float main()
{
    int tamano,i,j,k;
    printf("ingresa el tamaño de la matriz \n");
    scanf("%i",&tamano);
    float mat[tamano][tamano];
    float B[tamano];
    float L[tamano][tamano];
    float U[tamano][tamano];
    float constantes[tamano];
    float Uentre1[tamano][tamano];
    float UparasacarL[tamano][tamano];
    float YparasacarX[tamano];
    float Yi[tamano];
    float X[tamano]; //sust hacia atras
    float Y[tamano]; //sust hacia adelante

    printf("\ningresa los valores de la matriz \n");
    for(i=0;i<tamano;i++)
    {
        for(j=0;j<tamano;j++)
        {
            printf("Ingresa el elemento A[%d][%d] :  ", i,j);
            scanf("%f",&mat[i][j]);
        }
    }
    
    printf("\nla matriz que ingresaste es la siguiente: \n");
        for(i=0;i<tamano;i++)
    {
        for(j=0;j<tamano;j++)
        {
            Uentre1[i][j]=(1/mat[i][j]);
            printf("%f   ",Uentre1[j][j]);
            
        }
        printf("\n");
    }
    
    printf("\ningresa el valor de las constantes \n");
    for(i=0;i<tamano;i++)
    {
        printf("constante C%d \n",i+1);
        scanf("%f",&constantes[i]);
    }

    printf("\nlas constantes que ingresaste son las siguientes: \n");
   
    for(i=0;i<tamano;i++)
    {
        printf("%f \n",constantes[i]);
    }


    for(i=0;i<tamano;i++)
    {
        for(j=0;j<tamano;j++)
        {
            U[i][j]=mat[i][j];
            L[i][j]=mat[i][j];
            UparasacarL[i][j]=mat[i][j];
            if(j>=i) 
            {
                for(k=0; k<=i-1; k++) 
                {
                    U[i][j]-=L[i][k]*U[k][j]; 
                } 

                if(i==j) //la diagonal son 1
                {
                    L[i][j]=1;

                } 

                else
                {
                    L[i][j]=0; //todos los demas elementos
                }

                
                    

            }
            else
            {
                for(k=0; k<=j-1; k++)
                {
                    UparasacarL[i][j]-=UparasacarL[i][k]*U[k][j];
                                            
                }
                L[i][j]=Uentre1[j][j]*UparasacarL[i][j];
                U[i][j]=0; //los demas elementos que no entran en j<=i
            }
            

            
        }
    }

    printf("\n[L] =  \n");
    for(i=0; i<tamano; i++)
    {
        for(j=0; j<tamano; j++)
            printf("%f  ",L[i][j]);
        printf("\n");
    }

    printf("\n\n[U] =  \n");

    for(i=0; i<tamano; i++)
    {
        for(j=0; j<tamano; j++)
            printf("%f  ",U[i][j]);
        printf("\n");
    }

    //sust hacia adelante
    for(i=0; i<tamano; i++)
    {
        B[i]=constantes[i];
        Y[i]=B[i];
        for(j=0; j<=i-1; j++)
        {
            Y[i]-=L[i][j]*Y[j];
        }
    }
    printf("\n\nSustitucion hacia adelante [Y] = \n");
    for(i=0; i<tamano; i++)
    {
        printf("%f \n",Y[i]);
    }

    //sust hacia atras
    for(i=tamano-1; i>=0; i--)
    {
        X[i] = Y[i];
        for(j=i+1; j<tamano; j++)
        {
            X[i]-=U[i][j]*X[j];
        }
        X[i]*=(1/U[i][i]);
    }
    
    printf("\n\nSustitucion hacia atras [X] = \n");
    for(i=0; i<tamano; i++)
    {
        printf("%f   ",X[i]);
    }

} 