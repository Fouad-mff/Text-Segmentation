#include <iostream>
#include <istream>
#include <fstream>
#include <vector>
#include <string>
#include "windows.h"

using namespace std;

vector<string> lines;
string del,rep,txt,c;
 
void lectureFichier(string filename){	
	ifstream file;
    string line;
    do{
    	for(int i = 0; i < filename.length(); i++){  //Correction des caractères spéciaux.
    		switch (filename[i]){
    			case '‚' : filename[i]='é';break;
    			case 'ٹ' : filename[i]='è';break;
    			case '‡' : filename[i]='ç';break;
    			case '…' : filename[i]='à';break;
    			case 'ˆ' : filename[i]='ê';break;    			
    		}
		}
    	file.open(filename.c_str()); //Ouverture de fichier.	
		if (!file){	//Vérification de l'existence de fichier.
			cout<<"Fichier '"<<filename<<"' non trouv\202.\nR\202essayez!\n";
			cin.ignore(0);getline(cin,filename); //getline pour la lecture de l'espace (blanc).
		}
	}while(!file);
	c=filename;
	while (getline(file, line)) { //lecture ligne par ligne.
        lines.push_back(line);
    }    
	file.close();
}

void ecritureFichier(string filename,string txt){
	ofstream file;
	file.open(filename.c_str());
	file<<txt; //Stocker le contenu de résultat dans le fichier cible.
	file.close();
}

void affichage(string txt){//Affichage de caractères spéciaux.
	for(int i = 0; i < txt.length(); i++){
    	switch (txt[i]){
    		case 'é' : cout<<'\202';break;
    		case 'è' : cout<<'\212';break;
    		case 'ç' : cout<<'\207';break;
    		case 'à' : cout<<'\205';break;
    		case 'ù' : cout<<'\227';break;
    		case 'µ' : cout<<'\346';break;
    		case 'î' : cout<<'\214';break;
    		case 'ï' : cout<<'\213';break;
    		case 'û' : cout<<'\226';break;
    		case 'ü' : cout<<'\201';break;
    		case 'ê' : cout<<'\210';break;
    		default  : cout<<txt[i];
    	}
	}	
}

int main(){	
	system("color 1F"); //Couleur bleue de fond et blanche pour l'écriture.
	system ("mode 90,40"); //Agrandir la fenêtre console.
	COORD size = {90,2000}; 
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), size); //Activer le défilement vertical de fenêtre console.
	cout<<"\n :=======================================:\n |                                       |";
	cout<<"\n |                                       |\n |           MERAD FOUAD FOUZI           |";
	cout<<"\n |          Segmenteur de Texte          |\n |     Bienvenue dans mon programme!!    |";
	cout<<"\n |                                       |\n |                                       |";
	cout<<"\n :=======================================:\n\n\n - Pour continuer, appuyez sur une touche...";
	system("pause>nul"); //Pause sans affichage de message.
	system("cls"); //Nettoyer la fenêtre console.
	lectureFichier("délimiteurs.txt");
	del=lines[0];
	lines.clear();
    cout<<"\n- Veuillez Entrer le chemin d'acc\212s (r\202pertoire) de fichier texte \205 traiter."<<endl;
    cout<<"// Ou bien ('nom_de_fichier'.txt) s'il est dans le m\210me r\202pertoire que le programme.\n\n";
    wcin.ignore(0);getline(cin,rep);
    lectureFichier(rep); //Appel à la fonction.
    rep=c;
    for(int i = 0; i < lines.size(); i++){
        txt+=lines[i]+'\n';
    }
    lines.clear();
    cout<<"\nVotre texte :\n\n";
    affichage(txt);
    cout<<"\n\nAppuyez sur une touche pour continuer!\n\n";
    system("pause>nul");
    for(int i = 0; i < txt.length(); i++){ //Elimination de délimiteurs.
        for(int j = 0; j < del.length(); j++){
        	if (txt[i]==del[j]){
        		txt[i]='\n';
			}
    	}
    }	
    lectureFichier("motsvides.txt");
    int i=0;
	do{  //Elimination de mots_vides.
			c="";
		while(txt[i]!='\n'){
			c+=txt[i];
			i++;
		}
			i++;
		for(int j=0; j<lines.size() ; j++){
			if(c==lines[j]){	
				for(int k=i-1-c.length(); k<i ; k++){
					txt[k]='\n';
				}
			}
		}			
	}while(i<txt.length());
	lines.clear();
	for(int i = 0; i < txt.length(); i++){ //Effacer les lignes vides.
    	if(txt[i]=='\n' && (txt[i+1]=='\n' || txt[i-1]=='\n')){
			txt[i]='\15';
		}
	}	
	cout<<"\n\nVoici les (mots-cl\202s) de votre texte apr\212s traitement :\n\n";
    affichage(txt);    
    rep.insert(rep.length()-4," (traité)"); //<répertoire/nom_texte_original (traité).txt>.
    ecritureFichier(rep,txt);
    cout<<"\n\n- Op\202ration r\202ussite!!\n- Fichier enregistr\202 sous: ";
	affichage(rep);
	cout<<"\n\n\n**********************************************\n*    Merci d'avoir utilis\202 mon programme.    *\n";
	cout<<"*                                            *\n**********************************************";
	cout<<"\n\nAppuyez sur une touche pour quitter!\n\n\n\n";
	system("pause>nul");
}
	
	

	
	
