#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define I 5
#define J 5
#define P 50

void f_limpar();
int main()
{   
  
  char palavras[P] = "papel";
  char underlines [P] = {};
  int cont_letras=0;
  int cont_vidas=5;
  char dig_letra;
  int  acertou = 0;
  int  repetida =0;
  int i = 0;

    // conta as letras do primeiro vetor e coloca o undelines no segundo vetor

        for (i = 0; palavras[i]!=0; i++)
        {
            if(palavras[i]!=' '){

                cont_letras++;
                underlines[i] = '_';
            }
            if(palavras[i]==' ') {

                underlines[i] = '-';
            }
            
        }
    //
    // plota o placar
        printf("Letras faltantes: %d\n",cont_letras);
        printf("vidas: %d\n\n",cont_vidas);
    //
   //plota vetor com underlines.
        for (i = 0; palavras[i]!=0; i++)
        {
                printf("%c",underlines[i]);
                printf(" ");
        }
    //
    // começo da repetição do jogo.
    do { 
        // pede a letra para o usuario:
            printf("\n\nDigite uma letra:");
            scanf("%c",&dig_letra);
            setbuf(stdin, NULL);
        //
    
        // confere se a letra ja esta no vetor underlines:
            for (i = 0; palavras[i]!=0; i++){

                if(underlines[i]==dig_letra){
                    repetida = 1;       
                }
            }
        //criar aqui esse for de conferencia.
        
        // limpar terminal
          f_limpar();
        //

        // segue o jogo ou repete.
            if(repetida==0){
                // checa se a letra esta no vetor palavras e muda de anderline para letra
                    for (i = 0; palavras[i]!=0; i++){

                        if(palavras[i]==dig_letra){

                            underlines[i]=dig_letra; 
                            cont_letras--;
                            acertou = 1;
                            
                        }
                    }
                //
                //Atualizar contador de vidas.
                    if (acertou==0)
                    {
                        cont_vidas--;
                    }
                //
                //zera variavel acertou
                  acertou=0;
                //
                // plota o placar
                    printf("Letras faltantes: %d\n",cont_letras);
                    printf("vidas: %d\n\n",cont_vidas);
                //
                //plota vetor com underlines.
                    for (i = 0; palavras[i]!=0; i++)
                    {
                            printf("%c",underlines[i]);
                            printf(" ");
                    }
                //
                
            }
            else{

                // plota o placar
                    printf("Letras faltantes: %d\n",cont_letras);
                    printf("vidas: %d\n\n",cont_vidas);
                //
                //plota vetor com underlines.
                    for (i = 0; palavras[i]!=0; i++)
                    {
                            printf("%c",underlines[i]);
                            printf(" ");
                    }
                //
                printf("\n\n***Letra Repetida digite outra letra!***");
                cont_vidas--;
                repetida = 0;
            }
        
        //
        
    } while(cont_letras>0 && cont_vidas>0);
    // limpar terminal para exibir resultado
     f_limpar();
    //
    //Mostra resultado do jogo:
        if(cont_letras==0){
        printf("\nWinner!");   
        }
        else {
            printf("\nGame Over");
        }
    //
    
    return 0;
}

// funcao para limpar terminal
 void f_limpar() {
        system("cls");
    }