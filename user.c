#ifdef HAVE_CONFIG_H
#include<config.h>
#endif


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "user.h"
#include<gtk/gtk.h>

enum
{	ENOM,
	EPRENOM,
	ESEXE,
	ECIN,
	EJOUR,
	EMOIS,
	EANNEE,
	EUSERNAME,
	EPASSWORD,
	EROLE,
	ENUMTEL,
	COLUMNS,
};
	
//ajouter utilisateurs
void ajouter_utilisateur(users u){
FILE* f=NULL;

f=fopen("user.txt","a+");
	if (f!= NULL){
		fprintf(f,"%s %s %s %d %d %d %d %s %s %s %d\n",u.nom,u.prenom,u.sexe,u.CIN,u.date_naissance.jour,u.date_naissance.mois,u.date_naissance.annee,u.username,u.password,u.role,u.num_telephone);
	}
fclose(f);
}


//supprimer utilisateurs
void supprimer_utilisateur(char username[])
{
FILE* f=NULL;
FILE* f1=NULL;
users U;
f=fopen("user.txt","r");
f1=fopen("ancienuser.txt","w+");
while(fscanf(f,"%s %s %s %d %d %d %d %s %s %s %d\n",U.nom,U.prenom,U.sexe,&U.CIN,&U.date_naissance.jour,&U.date_naissance.mois,&U.date_naissance.annee,U.username,U.password,U.role,&U.num_telephone)!=EOF)
{
if(strcmp(username,U.username)!=0)
fprintf(f1,"%s %s %s %d %d %d %d %s %s %s  %d\n",U.nom,U.prenom,U.sexe,U.CIN,U.date_naissance.jour,U.date_naissance.mois,U.date_naissance.annee,U.username,U.password,U.role,U.num_telephone);
}
fclose(f);
fclose(f1);
remove("user.txt");
rename("ancienuser.txt","user.txt");
}
//modifier utilisateur
void modifier_utilisateur(users U1)
{
FILE* f=NULL;
FILE* f1=NULL;
users U;
f=fopen("user.txt","r");
f1=fopen("ancienuser.txt","w+");

while(fscanf(f,"%s %s %s %d %d %d %d %s %s %s %d\n",U.nom,U.prenom,U.sexe,&U.CIN,&U.date_naissance.jour,&U.date_naissance.mois,&U.date_naissance.annee,U.username,U.password,U.role,&U.num_telephone)!=EOF)
{
if(strcmp(U1.username,U.username)!=0)
{
fprintf(f1,"%s %s %s %d %d %d %d %s %s %s  %d\n",U.nom,U.prenom,U.sexe,U.CIN,U.date_naissance.jour,U.date_naissance.mois,U.date_naissance.annee,U.username,U.password,U.role,U.num_telephone);
}
else 
{
fprintf(f1,"%s %s %s %d%d %d %d %s %s %s %d\n",U1.nom,U1.prenom,U1.sexe,U1.CIN,U1.date_naissance.jour,U1.date_naissance.mois,U1.date_naissance.annee,U1.username,U1.password,U1.role,U1.num_telephone);
}
}
fclose(f);
fclose(f1);
remove("user.txt");
rename("ancienuser.txt","user.txt");
}


//chercher les utilisateurs
users chercher_utilisateur(char identifiant[])
{
users U;
	FILE *f;
	f = fopen("user.txt","r");
	if(f != NULL){
    		while(fscanf(f,"%s %s %s %d %d %d %d %s %s %s %d\n",U.nom,U.prenom,U.sexe,&U.CIN,&U.date_naissance.jour,&U.date_naissance.mois,&U.date_naissance.annee,U.username,U.password,U.role,&U.num_telephone)!=EOF){
        	if(strcmp(U.username,identifiant) == 0){
       		     return U;
        	}
    	}
}
    fclose(f);
    return;	
}

//afficher les utilisateurs
void afficher_utilisateur(GtkWidget *liste)
{
	GtkCellRenderer *renderer;  //envoyer la saisir de l'utilisateur de 		chaque champ 
	GtkTreeViewColumn *column;//correspendre le contenue du champ a son 		attribue de la liste
	GtkTreeIter   iter;    //itterateur sur l'ensemble des elements de 		treeview
	GtkListStore  *store;    //l'enregistrement de treeview

char nom[20];
char prenom[20];
char sexe[10];
int CIN;
int jour;
int mois;
int annee;

char username[20];
char password[20];

char role[20];
int num_telephone;
store=NULL;
FILE *f;

store=gtk_tree_view_get_model(liste);//va prendre comme variable de la liste

if (store==NULL)
{
	
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",EPRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",ESEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",ECIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("username",renderer,"text",EUSERNAME,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("password",renderer,"text",EPASSWORD,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("role",renderer,"text",EROLE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("num_telephone",renderer,"text",ENUMTEL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
}
store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT);

f=fopen("user.txt","r");

if (f==NULL)
{
	return;
}

else
{
f=fopen("user.txt","a+");
	while( fscanf(f,"%s %s %s %d %d %d %d %s %s %s %d\n",nom,prenom,sexe,&CIN,&jour,&mois,&annee,username,password,role,&num_telephone)!=EOF)
	{
	gtk_list_store_append(store,&iter);

	gtk_list_store_set(store,&iter,ENOM,nom, EPRENOM,prenom,ESEXE,sexe,ECIN,CIN,EJOUR,jour,EMOIS,mois,EANNEE,annee,EUSERNAME,username,EPASSWORD,password,EROLE,role,ENUMTEL,num_telephone,-1);
	}
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}

}

int id_existant(char id[])
{

    users U;
    FILE *f;
    f = fopen("user.txt","r");
    if(f != NULL){
    	while(fscanf(f,"%s %s %s %d %d %d %d %s %s %s %d\n",U.nom,U.prenom,U.sexe,&U.CIN,&U.date_naissance.jour,&U.date_naissance.mois,&U.date_naissance.annee,U.username,U.password,U.role,&U.num_telephone)!=EOF)
{
        	if(strcmp(U.username,id) == 0){
       		     return 1;
        	}
    	}
}
    fclose(f);
    return 0;

}

/////////////////////////////////////////////////////////////////tache2/////////////////////////////////////////////

enum
{
EJOURPANNE,
EHEURE,
EETAGE,
EVALEUR,
 COLUMN};
void afficher_etage(GtkWidget  *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

int jourpanne;
        int heure;
        int etage;
        char valeur[10];


        store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{

        renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("jourpanne",renderer, "text",EJOURPANNE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("heure",renderer,"text",EHEURE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("etage",renderer, "text", EETAGE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" valeur",renderer, "text",EVALEUR,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

}

store=gtk_list_store_new (COLUMN,G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING);
f=fopen("debit.txt","r");
if(f==NULL)
{
return;
}
else
{
f= fopen("debit.txt","a+");
      while(fscanf(f,"%d %d %d %s \n",&jourpanne,&heure,&etage,valeur)!=EOF)            
{
gtk_list_store_append(store, &iter);
gtk_list_store_set(store,&iter, EJOURPANNE,jourpanne,EHEURE,heure,EETAGE,etage,EVALEUR,valeur,-1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref (store);
}
}
//////////////////////////////////////////////////////// affichage etage en panne
void etage_debit(GtkWidget*liste)

{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

    int jourpanne;
        int heure;
        int etage;
        char valeur[10];
float valeurf;


store=NULL;
FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("jourpanne",renderer, "text",EJOURPANNE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes("heure",renderer,"text",EHEURE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("etage",renderer, "text", EETAGE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" valeur",renderer, "text",EVALEUR,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


store=gtk_list_store_new (COLUMN,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING);
f=fopen("debit.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("debit.txt","a+");
      while(fscanf(f,"%d %d %d %s\n",&jourpanne,&heure,&etage,valeur)!=EOF)            
{
            valeurf=atof(valeur);
            if((valeurf<0)||(valeurf>30))                  
{
gtk_list_store_append(store, &iter);
gtk_list_store_set(store,&iter, EJOURPANNE,jourpanne,EHEURE,heure,EETAGE,etage,EVALEUR,valeur,-1);
}
                 }
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref (store);
}
}
}

///////////////////////////////authentification//////////////////////////////////:



int auth_admin(char username[], char password[],char role [])

{

FILE* f; int test=0;

 

char ch1[20],ch2[20];

f=fopen("utilisateurs.txt","r");

if (f!=NULL)

{

             while( fscanf(f,"%*s %*s %*s %*d %*d %*d %*d %s %s %s %*d\n",ch1,ch2,role)!=EOF)

                           {

                                        if ( (strcmp(ch1,username)==0) && (strcmp(ch2,password)==0))

{

                                                     test=1;

break;

}

                           }

}

fclose(f);

return test;

}






