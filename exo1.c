#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


char *mirroir (const char *s){
	int i = strlen(s)-1;
	char *result;
	result = malloc ((i+2) * sizeof(char));
	int j = 0;
	while(i >= 0){
		result[j] = s[i];
		i--;
		j++;
	}
	result[j] = '\0';
	return result;
}

char * saisie(){
	int taille = 10;
	char *result = malloc(taille*sizeof(char));
	char c;
	int i =0;
	printf("Entrez une phrase puis appuyez sur <Entrée>: ");
	while(!isspace(c)){
	   c = getchar();
	   result[i] = c;
	   i++;
	   		if(i%10 == 0){
	   			taille += 10;
	   			//char * tmp = result;
	   			result = realloc(result, taille*sizeof(char));
	   			//free(tmp);
	   		}
   	}
   	result[i] = '\0';
   	return result;

}

void clear(){
	int i;
	for (i = 0; i < 100; i++)
		printf("\n");
}

int main (int argc, char **argv)
{
	char* mot = NULL;
	int cmirroir = 0;
	int csaisir = 0;
	int chelp = 0;
	int i = 1;
	char* invalide = "Erreur : Commande invalide, utilisez l'option -h pour afficher l'aide.";
	clear();
	printf("\n**********************SUPER MIRROIR*******************\n\n");
	if(argc == 1)
		chelp = 1;
	
	while(i < argc){
		if(cmirroir == 1){
			if (strstr(argv[i], "-") != NULL){
				printf("%s\n", invalide);
				return 1;
			} else {
				mot = argv[i];
			}
		}
		if(strstr(&argv[i][0], "-") != NULL){
			if(strchr(argv[i], 'm') != NULL){
				cmirroir = 1;
			}
			if(strchr(argv[i], 's') != NULL){
				csaisir = 1;
			}
			if(strchr(argv[i], 'h') != NULL){
				chelp = 1;
			}
		}
		i++;
	}
	if(chelp){
		printf("\n**********************AIDE*******************\n\n");
		printf("-m suivi d’une chaîne affiche le miroir de la chaîne;\n-s seul permet de saisir une chaîne de taille quelconque et l’affiche;\n-ms -sm -s -m-sm -m -s ou tout autre combinaison d’options m et s permet de saisir une chaîne de longueur quelconque et affiche son miroir;\nsi la ligne de commande n’est pas valide (option erronée, trop ou trop peu d’arguments, ...), la commande affiche le message '%s' \n", invalide);
		printf("\n*********************************************\n\n");
	} else {
		if(csaisir){
			mot = saisie();
			printf("\n%s", mot);
		}
		if(cmirroir){
			if(mot != NULL){
				char *tmp = mirroir(mot);
				printf("%s\n", tmp);
				free(tmp);
			} else {
				printf("%s\n",invalide);
			}
		} 
	}
	if(csaisir){
		free(mot);
	}
	return 0;
}
/*
int main(int argc, char **argv)
{
	while(1)
		main2(argc, argv);
	return 0;
}
*/