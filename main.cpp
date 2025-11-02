exercice 1 





#include<iostream> 
using namespace  std ; 

class node {

     public : 
       
     int item ;
     node *next; 

     public : 

     node(){
          
        item = 0 ;
        next = NULL ;
     }
     
} ;

     class stack {
     	
     	public :
         
        
        node *top ; 

        public :
        stack() {

            top=NULL ; 
        }
        


        void push(int data) {
            node *new_node = new node() ; 
            if(top==NULL) {
                
                new_node->item = data ;
                new_node->next = NULL ;
                top =new_node ;


            }

            else{
                    
                 new_node->item = data ;
                new_node->next = top ;
                top =new_node ;


            }
        }
            
            void pop() { 
            
              node *tmp  ;
			   
              
              while(top!=NULL) {
              	
              	tmp = top ;
              	
              	
              	cout<<tmp->item<<endl ;
              	top=top->next ; 
              	delete tmp ; 
			  }
              
              
            	
            	
			}

        


        void display() {

            node *tmp = top ;

            while(tmp!= NULL) {
              
                cout<<tmp->item<<endl ;

                tmp=tmp->next ;

            }
        }
        

     } ;


int main() {

   int it ;
    
   stack l1 , l2  ; 


   
   for(int i =0 ; i < 5 ;i++ ) {


    cout<<"entre le item  :  " ; 
     cin>>it ;


    l1.push(it) ;


   }

   l1.display();
   
   
    
   for(int i =0 ; i < 5 ;i++ ) {


    cout<<"entre le item  :  " ; 
     cin>>it ;


    l2.push(it) ;


   }

   l2.display();
   
   l1.pop() ;
   l2.pop() ;
   



}

exercice 2


#include <iostream>
#include <cstring>
#include <cstdlib> 

using namespace std;

class Fichier {
private:
    char *adresse; 
    int longueur;   

public:
    
    Fichier() : adresse(NULL), longueur(0) {}

    
    ~Fichier() {
        if (adresse != NULL) {
            delete[] adresse; 
            adresse = NULL;
            longueur = 0;
            cout << "\n Mémoire libérée par le Destructeur." << endl;
        }
    }

   
    void Creation(int taille) {
        if (adresse != NULL) {
            cout << " Fichier déjà alloué. Libérez l'ancienne mémoire d'abord." << endl;
            return;
        }
        longueur = taille;
        
        adresse = new char[longueur]; 
        cout << " Zone mémoire de " << longueur << " octets allouée à l'adresse: " << (void*)adresse << endl;
    }

    
    void Remplit() {
        if (adresse == NULL) {
            cout << " Allocation non faite. Impossible de remplir." << endl;
            return;
        }
        cout << " Remplissage arbitraire de la zone mémoire..." << endl;
        for (int i = 0; i < longueur; ++i) {
            
            adresse[i] = 'A' + (rand() % 26); 
        }
        adresse[longueur - 1] = '\0'; 
        cout << " Remplissage terminé." << endl;
    }

    
    void Affiche() const {
        if (adresse == NULL) {
            cout << " Aucune mémoire à afficher." << endl;
            return;
        }
        cout << "\n--- Affichage du Contenu du Fichier ---" << endl;
        cout << "Contenu : " << adresse << endl;
        cout << "Longueur : " << longueur << " octets." << endl;
        cout << "Adresse de début : " << (void*)adresse << endl;
        cout << "--------------------------------------" << endl;
    }
};


int main() {
    cout << "--- Démarrage Fichier Dynamique ---" << endl;
    
    
    Fichier *monFichier = new Fichier(); 
    
   
    monFichier->Creation(50); 
    
   
    monFichier->Remplit();
    
    
    monFichier->Affiche();
    
   
    delete monFichier; 
    
    return 0;
}



exercice 3 



#include<iostream>
#include<fstream> 
using namespace  std ; 

class node {
	public : 
	
	int data ; 
	node *next ; 
	
	node():data(0),next(NULL) {}
	
};

class list {
	
	
	private :
	node *debut =NULL ; 
	
	public :
		
	void creation(int valeur) {
		
		node *new_node=new node() ;
		
		new_node->data = valeur ;
		
		new_node->next = debut ;
		
		debut = new_node ;
			 
			
	}
	
	void supprimer() {
		
		if(debut==NULL) {
			cout<<"la list est vide"<<endl ; 
			
		}
		
		else if (debut->next==NULL) {
			delete debut ; 
			cout<<"le premier element est bien suprimer !"<<endl ; 
		}
        
		else{
			
			node*tmp =debut ;
			
			debut=debut->next ;
			
			delete tmp ;
			
		} 		
	}
	
	void afficher() { 
	  
	     node *tmp=debut ; 
	     
	     while(tmp!=NULL) { 
	     
	     	cout<<"la valeur est : "<<tmp->data<<endl ; 
	     	
	     	tmp=tmp->next ;
	     	
		 }
		 
		
		
	}
};


int main() {
	
	
	list l1 ;
	int data ;
	
	for(int i=1; i<5 ; i++  ) {
		  
		  cout<<"entre la valeur : "<<endl  ;
		  cin>>data ;
		  
		  l1.creation(data);
 		
	}
	
	l1.afficher() ;
	l1.supprimer() ;
	l1.afficher() ;
	
	
}
	   

exercice 4 : 


#include<iostream>
#include<string> 
using namespace  std ; 

class client{
	
	private :
		
	int id ; 
	string nom , prenom ;
	
	public : 
	
	client() {
		id = 0 ; 
		nom = "unknown"   ;
		prenom ="unkonwn" ;
	}
	
	client(int i , string N , string P ) : id(i) , nom(N) , prenom(P) 
	 {  } 
	 
	 client(const client& client_a_copier) {
       
        this->id = client_a_copier.id;
        this->nom = client_a_copier.nom;
        this->prenom = client_a_copier.prenom;  
    }
        
        ~client() {} 
        
     void afficher() {
     	
     	cout<<id<<endl<<nom<<endl<<prenom ;
	 }   
	 
};


class compte {
	
	public : 
	
	int num_cmpt ;
	float solde ;
	client * Client ; 
	static int nbr  ;
	
	public : 
	
	compte() : num_cmpt(0) , solde(0),Client(NULL)  {nbr++;}
    compte(int 	N , float S , client *C )  	: num_cmpt(N) , solde(S) , Client(C) { nbr++ ;}
	compte(const  compte & compte_a_copier) {
		this->num_cmpt = compte_a_copier.num_cmpt ; 
		this->solde = compte_a_copier.solde ;
	this->Client = new client(*(compte_a_copier.Client));
	nbr++;
	} 
	
	
	~compte() {
		delete Client ;
		nbr--;
	}
	
		 
	
	void afficher() {
		 
		 cout<<"le numero de compte : "<<num_cmpt<<endl ;
		 cout<<"le solde : " <<solde<<endl   ; 
		 
		 Client->afficher() ;
	}
	
	static void afficher_nbr() {
		cout<<"le nombre de compte : "<<nbr ; 
	}
	
};


   int compte::nbr = 0;

	float calcul_interet(float solde , float taux) {
	
      solde += solde * (taux / 100);
        return solde;
	   
   	
   }


int main () {
	
	client c1(100,"Sacha","Ayoub") ,c2(101,"Said","bousabir") , c3(103,"driss","jetou") ; 
	
	compte p1(1, 100.2 ,&c1) ,p3(3,302,&c3) ,  p2(p3) , p4(p1) ;
	
	p1.afficher() ;
	p2.afficher() ;
	p1.afficher_nbr();
	
	calcul_interet(100,30);
	 
	
     
}














Différence entre copie superficielle et copie profonde :

Copie superficielle : copie uniquement les adresses des objets (pointeurs).

Copie profonde : crée une nouvelle copie indépendante de l’objet pointé (nouvelle zone mémoire).

 Pourquoi le compteur doit être statique ?
Parce qu’il doit être partagé par tous les objets de la classe, et non propre à chaque instance.

Différence entre méthode statique et méthode normale :

Statique : appartient à la classe, pas à un objet.

Normale : agit sur un objet spécifique (utilise this).

 Quand rendre une fonction inline ?
Quand la fonction est courte et souvent appelée, pour éviter le coût d’appel de fonction.

 Si on oublie de libérer la mémoire dans le destructeur :
Il y aura une fuite de mémoire (memory leak), car la mémoire allouée ne sera jamais libérée.
	   
	 
	 
	 
	 
	 
	 
	 
	
	
	


