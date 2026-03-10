#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<unistd.h>

void update() {
    printf("\033[H\033[J");
}

void gotoxy(int x, int y) {
    printf("\033[%d;%dH", x, y);
}

void affiche_vache(int etat)
{
    switch (etat)
    {
        case 0: printf("            ^__^\n");
                printf("            (xx)\\_______\n");
                printf("            (__)\\       )\\/\\\n");
                printf("                ||_---w |_\n");
                printf("^^^^ ^^^^^^ ^^^^^^^ ^^^^^ ^^^^^^^^^^ ^^^^\n");
                break;

        case 1: printf("            ^__^\n");
                printf("            (--)\\_______\n");
                printf("            (__)\\       )\\/\\\n");
                printf("            ( ) ||----w |\n");
                printf("            ( ) ||     ||\n");
                printf("^^^^ ^^^^^^ ^--^^^^ ^^^^^ ^^^^^^^^^^ ^^^^\n");
                break;

        case 2: printf("   ----\n");
                printf(" < mooo > \n");
                printf("   ----\n");
                printf("                  /\\ /\\\n");
                printf("        \\   ^__^ /  \\  \\\n");
                printf("         \\  (o-)\\_______\n");
                printf("            (__)\\       )\\/\\\n");
                printf("             U  \\\\----w \\\n");
                printf("                 \\\\     \\\\\n");
                printf("\n");
                printf("^^^^ ^^^^^^ ^^^^^^^ ^^^^^ ^^^^^^^^^^ ^^^^\n");
                break;
    }
}
    


int stock_update(int lunchfood, int stock){
	int crop = rand() % 7 - 3;                    // Prend un chiffre aléatoire entre -3 et 3
	int stock2 = stock - lunchfood + crop;
	if (stock2 < 0)
	{
		stock = 0;
	} 
	else if (stock2 > 10)
	{
		stock = 10;
	} 
	else
	{
		stock = stock2;
	}
	
	return stock;
}

int fitness_update(int lunchfood, int fitness){

	int digestion = rand() % 4 -3;                    // Prend un chiffre aléatoire entre -3 et 0
	int fitness2 = (fitness + lunchfood )+ digestion;
	if (fitness2 < 0)
	{
		fitness = 0;
	} 
	else if (fitness2 > 10)
	{
		fitness = 10;
	} 
	else
	{
		fitness = fitness2;
	}
	
	return fitness ;
}




int main ()
{   
        int etat=2;
	int stock = 5;
	int fitness = 5;
	int lunchfood;
	
	/* Intialise le generateur de nombres aleatoires */
	time_t t ;
	srand ((unsigned) time(&t)) ;
	
	int duree_de_vie=1;
    	while (etat !=  0){
        	update();
        	affiche_vache(etat);
        	printf("stock = %d\n",stock);
        	printf("Entrez une quantite de nourriture : \n");
        	scanf("%d",&lunchfood);
        while (lunchfood > stock){
                printf("Stock insuffisant. Entrez une nouvelle valeur :\n");
                scanf("%d",&lunchfood);
        }
        stock = stock_update (lunchfood,stock);
        fitness = fitness_update(lunchfood,fitness);
        if ((fitness == 0)||(fitness == 10) ){
            etat = 0;
            update();
            affiche_vache (etat);
            printf ("Ohh Nonn votre vache est morte!!! Elle n'a vecu que %d jour(s) :(\n", duree_de_vie);
        }
        else if (((1<=fitness)&&(fitness<=3))||((7<=fitness)&&(fitness<=9))){
            etat = 1; 
        }
        else {
            etat = 2;
        }
        duree_de_vie ++ ;
        }
    
	
    return 0;
}    
    
    
    
    
    
  
