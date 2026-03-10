#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void update() {
    printf("\033[H\033[J");
}

void affiche_vache(char *fichier) {
	FILE* f;
	f = fopen(fichier,"r");
    if (f == NULL) {
        printf("Erreur d'ouverture");
        exit(1);
    }
	char v[1024];
    if (fgets(v, sizeof(v), f) == NULL) {
        printf("Erreur de lecture");
        fclose(f);
        exit(1);
    }
    fclose(f);

    int l = strlen(v);
	char t=' ';	
    char x;
	
	while (l > 0) {
        update();
		printf(" -----\n");
		printf("< %s >\n", v);
        x=t;
		t = v[l-1];
		v[l-1] = '\0';
		l = strlen(v);
        printf("        \\   ^__^\n");
        printf("         \\  (oo)\\______\n");
        printf("            (__)\\       )\\/\\\n");
        printf("             %c  ||----w |\n" , x);
        printf("                ||     ||\n");
    
	    usleep(1000000);
	}
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Pas assez d'arguments\n");
		return 1;
	}
	affiche_vache(argv[1]);
	return 0;
}
