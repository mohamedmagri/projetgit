#include<gtk/gtk.h>


typedef struct{
int jour;
int mois;
int annee;
}date;


//tache 2
typedef struct 
{
    int etage;
    int jourpanne;
    int heure;
    char valeur;

}debit;


typedef struct{
char nom[20];
char prenom[20];
char sexe[10];
int CIN;
date date_naissance;

char username[20];
char password[20];

char role[20];
int num_telephone;
}users;



int id_existant(char id[]);
void ajouter_utilisateur(users U);
void modifier_utilisateur(users U);
void supprimer_utilisateur(char username[]);
users chercher_utilisateur(char username[]);
void afficher_utilisateur(GtkWidget *liste);
void etage_debit(GtkWidget*liste);
void afficher_etage(GtkWidget  *liste);
int auth_admin(char username[], char password[],char role []);
