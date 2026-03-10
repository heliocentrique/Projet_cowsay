# include <stdio.h>

void affiche_vache(int argc, char *argv[])
{
	printf(" 	 ^__^\n");
	
	if (argc > 1)                                                                                        // Regarde si il y a des arguments.
	{
		if ((argv[1][0] == '-' && argv[1][1] == 'e' && argv[1][2] == '\0') && (argv[2][2] == '\0'))  // Vérifie si les 2 arguments correspondent bien à -e et un 2e argument qui a 2 caractères.
		{
			printf("	 (%s)\\_______ \n",argv[2]);
		} 
		else if (argv[1][0] == '-' && argv[1][1] == 'p' && argv[1][2] == '\0') 
		{
			printf("	 (@@)\\_______ \n");                                                 // Yeux @@ si -p
		} 
		else if (argv[1][0] == '-' && argv[1][1] == 'g' && argv[1][2] == '\0') 
		{
			printf("	 ($$)\\_______ \n");                                                // Yeux $$ si -g
		} 
		else if (argv[1][0] == '-' && argv[1][1] == 'b' && argv[1][2] == '\0') 
		{
			printf("	 (==)\\_______ \n");  						    // Yeux == si -b
		}                                               
		else 
		{
			printf("	 (00)\\_______ \n");
		}
	}
	else 
	{
		printf("	 (00)\\_______ \n");                                                         // Cas ou il n'y a pas d'arguments.
	}
	
  	printf("  	 (__)\\       )\\/\\ \n\
             ||----w |\n\
             ||     ||\n");
}

int main (int argc, char *argv[]) 
{
	affiche_vache(argc, argv);
	return 0;
}

