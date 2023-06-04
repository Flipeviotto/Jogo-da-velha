#include <stdio.h>

void mostramat(char * p){
    printf("\n");
    for(int i=0;i<9;i++){
        if(i%3==0){
            printf("\n");
        }
        printf("%4c",*(p+i));
    }
    printf("\n");
}

int valida(char *p,char c, char simbolo){
    for(int i=0;i<9;i++){
        if(*(p+i)==c){
            *(p+i) = simbolo;
            return 0;
        }
    }
    return 1;
}

void jogador(char *p, char simbolo, int jogador){
    printf("\njogador %d\n",jogador);
    char c;
    
    do{
        printf("Escolha uma posicao valida:\n");
        scanf(" %c",&c);
    }while(valida(p,c,simbolo));
}

int analisa(char * p, int marca, int jogador){
    int cont=0;

    for(int i=0;i<9;i++){ //analisa linhas
        if(*(p+i)== marca){
            cont++;
        }
        if(i%3==2){
            if(cont==3){
                mostramat(p);
                printf("\njogador %d venceu\n",jogador);

                return 1;
            }
            else{
                cont=0;
            }
        }
            
    }

    for(int i=0;i<3;i++){//i = coluna j= linha (analisa colunas)
        cont=0;
        for(int j = 0;j<3;j++){
            if(*(p+i+(j*3))==marca){
                cont++;
            }
            if(cont==3){
                mostramat(p);
                printf("\njogador %d venceu\n",jogador);

                return 1;
            }
        }
    }

    if(*(p+1+(1*3))==marca && *(p+2+(2*3))==marca && *(p+0+(0*3))==marca){
        mostramat(p);
        printf("\njogador %d venceu\n",jogador);
        return 1;
    }
    else if(*(p+0+(2*3))==marca && *(p+1+(1*3))==marca && *(p+2+(0*3))==marca){
        mostramat(p);
        printf("\njogador %d venceu\n",jogador);
        return 1;
    }
    return 0;

}

int main()
{
    char mat[3][3];
    char *p=&mat[0][0];

    int escolha=1;
    
    while(escolha){

        int i;
        for(i=0;i<9;i++){// inicializar matriz
            *(p+i) = i+49;
        }
        for(i=0;i<5;i++){//reprodução do jogo
            mostramat(p);

            jogador(p,'X',1);
            if(analisa(p,'X',1)){
                break;
            }

            mostramat(p);

            if(i==4){
                printf("\nDEU VELHA!!\n");
                break;
            }
            
            jogador(p,'O',2);
            if(analisa(p,'O',2)){
                break;
            }
        }

        printf("quer continuar jogando? [1]sim [0]nao\n");
        scanf("%d",&escolha);
    }
    return 0;
}