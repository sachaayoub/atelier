char c = '\x01'    ;
    short int p = 10   ;


        /*les types char et short sont promus en int avant le calcul.*/


    p + 3;         /*valeur 13 type int */
    c + 1;        /* valeur = 2 type int*/
    p + c;        /* valeur = 11 type int   */
    3 * p + 5 * c;/* valeur  = 35  type int   */












    2_  

      char c = '\x05'; /* c=5 */
    int n = 5;
    long p = 1000;
    float x = 1.25;
    double z = 5.5;

    n + c + p;          /* valeur 1010 long */
    2 * x + c;          /* valeur 7,5 float */
    (char) n + c;       /* 10 int  */
    (float) z + n / 2;  /* 7,5 float   car la division entre deux entiere est donne un entier */
















    3_ 




    #include <iostream>
using namespace std;

int main() {
    int n = 5, p = 9;
    int q;
    float x;

    q = n < p;               /* 1 */
    q = n == p;              /* 0 */
    q = p % n + p > n;       /* 1 */
    x = p / n;               /* 1.0 */
    x = (float) p / n;       /* 1.8 */
    x = (p + 0.5) / n;       /* 1.9 */
    x = (int) (p + 0.5) / n; /* 1.0 */
    q = n * (p > n ? n : p); /* 25 */
    q = n * (p < n ? n : p); /* 45 */

    return 0;
}



#include <iostream>
using namespace std;
main () {
    int i, j, n;
    i = 0;
    n = i++;   /* on a n = i  puis on increment i i++ cest i=i+1 donc n == 0 et i == 1              */
    cout << "A : i=" << i << " n=" << n << "\n";   
    i = 10;
    n = ++i;
    cout << "B : i=" << i << " n=" << n << "\n";/*on incremente i avant d utiliser sa valeur daonc ici i==11 , n==11 */
    i = 20;
    j = 5;
    n = i++ * ++j;
    cout << "C : i=" << i << " j=" << j << " n=" << n << "\n";/*ici ona n =120 , j =6 et i =21 car on a une post incrementation de i */
    i = 15;
    n = i += 3;
    cout << "D : i=" << i << " n=" << n << "\n";/*i=18 n =18 */
    i = 3;
    j = 5;
    n = i *= --j;
    cout << "E : i=" << i << " j=" << j << " n=" << n << "\n";/*i=12 n = 12 j = 4*/
}



#include<iostream> 
using namespace std ;
  

    void remplir(int *arr , int taille ) { 

         int i ;
               
        for(i=0;i < taille ; i++ ) {

            cout<<"entre la case "  << i <<" :  " ; 
            cin >>*(arr+i) ; 
        }
         
    } 



    void afficher(const int *arr , int taille ) {
           int  i ;
          for(i=0 ;  i < taille ; i++ ) {
                  
             cout << "la case numero    " << i + 1 <<" : " << *(arr+i) <<endl  ;


          }
    }
    
    void inverser( int *arr , int taille ){
    	   
    	  int *arr1 = new int[taille];

		    
    	  int *p = arr + taille -1 , *q = arr1 ; 
    	  
    	  while(p >= arr  ) {
    	  	
    	  	*(q) = *(p) ; 
			  
			  q++ ; 
			  p-- ; 
			   
		  }
		  
		  q = arr1 ; 
		  p = arr ;
		  
		  while(q < arr1 + taille ) {
		  	*(p) = * (q) ; 
		  	p++ ;
		  	q++ ;
		  }
		  
		  while(p < arr+taille ) {
		  	
		  	*(arr) = *(p) ; 
		  }
                   	  
						 
    	  
	}
	
	void inverser2 (int *arr, int taille) {
    int *debut = arr;             
    int *fin = arr + taille - 1;  
    while(debut < fin) {
        
        int temp = *debut;
        *debut = *fin;
        *fin = temp;

        debut++;
        fin--;
    }
}
     
     
     int&trouverMax(int * arr ,int taille) {
     	  int *p ;
     	  int *max = arr ; 
     	  for(p=arr ; p<arr+ taille ;p++) {
     	  	   if(*p > *max ) {
     	  	   	
     	  	   	max = p ;
     	  	
			 }
		   }
		   
		   return *max ; 
     	
	 }




int main() { 

   int taille ;

    cout<<"entre la taille de tableau : " ;
    cin >> taille ; 

    int *arr = new int[taille] ; 
     
    remplir(arr,taille) ; 
    afficher(arr,taille) ;
    int &max = trouverMax(arr,taille) ;
    cout<<"max est :"  <<max ;
	max = 10 ; 
	
	
    inverser(arr,taille)  ;
    afficher(arr,taille) ;


}