#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"


void ajouter_hebergement(hebergement h){

	FILE*f=NULL;

	f=fopen("hebergement.txt","a+");

	fprintf(f,"%s %s %s %d %d %d %d %d %d %d %s \n", h.id, h.nom, h.prenom, h.date_entree.jour, h.date_entree.mois, h.date_entree.annee, h.date_sortie.jour, h.date_sortie.mois, h.date_sortie.annee, h.etage, h.bloc);
	fclose(f);

}

void supprimer_hebergement(char *id){
	FILE*f=NULL;
	FILE*f1=NULL;
	hebergement h;

	f=fopen("hebergement.txt","r");
	f1=fopen("hebergement_nouveau.txt","w+");

	while(f,fscanf(f,"%s %s %s %d %d %d %d %d %d %d %s \n", h.id, h.nom, h.prenom, &h.date_entree.jour, &h.date_entree.mois, &h.date_entree.annee, &h.date_sortie.jour, &h.date_sortie.mois, &h.date_sortie.annee, &h.etage, h.bloc)!=EOF){
		if(strcmp(id,h.id)!=0){
			fprintf(f1,"%s %s %s %d %d %d %d %d %d %d %s \n", h.id, h.nom, h.prenom, h.date_entree.jour, h.date_entree.mois, h.date_entree.annee, h.date_sortie.jour, h.date_sortie.mois, h.date_sortie.annee, h.etage, h.bloc);
		}

	}

	fclose(f);
	fclose(f1);
	remove("hebergement.txt");
	rename("hebergement_nouveau.txt","hebergement.txt");

}

void modifier_hebergement(hebergement h){
	supprimer_hebergement(h.id);
	ajouter_hebergement(h);
}

hebergement get_hebergement(char *id){
	FILE*f=NULL;
	hebergement h;

	f=fopen("hebergement.txt","r");

	while(f,fscanf(f,"%s %s %s %d %d %d %d %d %d %d %s \n", h.id, h.nom, h.prenom, &h.date_entree.jour, &h.date_entree.mois, &h.date_entree.annee, &h.date_sortie.jour, &h.date_sortie.mois, &h.date_sortie.annee, &h.etage, h.bloc)!=EOF){
		if(strcmp(h.id,id)==0)
		return h;
	}

	return;
	fclose(f);
}


int nombre_etudiants_par_etage(int etage){
	FILE*f=NULL;
	hebergement h;
	int nb = 0;

	f=fopen("hebergement.txt","r");

	while(f,fscanf(f,"%s %s %s %d %d %d %d %d %d %d %s \n", h.id, h.nom, h.prenom, &h.date_entree.jour, &h.date_entree.mois, &h.date_entree.annee, &h.date_sortie.jour, &h.date_sortie.mois, &h.date_sortie.annee, &h.etage, h.bloc)!=EOF){
		if(h.etage == etage)
			nb++;
	}
	fclose(f);
	return nb;
}
