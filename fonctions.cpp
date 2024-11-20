#include "bibliotheques.h"
#include <iostream>

int longueur(const char* chaine){
    int l = 0, i = 0;
    while(*(chaine+i) != '\0'){
        l+=1;
        if(*(chaine+i) == ' ')
            l-=1;
        i++;
    }
    return l;
}

void copie(char* dest,const char* source){
    for(int i = 0; i<= 48; i++){
        *(dest+i) = *(source+i);
    }
    *(dest+49) = '\0';
}

void concatene(char* dest, const char* source){
    int j = 0, r = 0, i = 0;
    while(r != 1){
        if(*(dest+i) == '\0' && r == 0){
            *(dest+i) = ' ';
            r = 1;
        }
        i++;
    }
    if(r == 1){
        while(*(source+j) != '\0'){
            *(dest+i) = *(source+j);
            j++;
            i++;
            if(*(source+j) == '\0')
                *(dest+i) = '\0';
        }
    }
}

int compare(const char* chaine1, const char* chaine2){
    int l1 = longueur(chaine1);
    int l2 = longueur(chaine2);
    
    int esp1 = 0; int esp2 = 0;

    for(int i=0; i<= 49; i++){
        if(*(chaine1+i) == ' ')
            esp1 += 1;
        if(*(chaine2+i) == ' ')
            esp1 += 1;
    }

    if(l1 > l2)
        return 1;
    else if(l2 > l1)
        return -1;
    else if(l1 == l2)
        return 0;
        
    return 0;
}
char* cherche_char(const char* chaine, char caractere){
    for(int i = 0; i<=49; i++){
        if(*(chaine+i) == caractere){
            char* occ = new char(*(chaine+i));
            return occ;
        }
    }
    return 0;
}
void inverse(char* dest){

    char a;
    char b;
    
    int i = 0, j = 0, f = 0;
    
    while(*(dest+i) != '\0'){
        i++;
    }
    i = i-1;
    std::cout << i;
    if(i%2 == 0){
        while(f == 0){
            if(i-j == 2)
                f++;
            a = *(dest+j);
            std::cout << a;
            b = *(dest+i);
            std::cout << b << std::endl;
            *(dest+i) = a;  
            *(dest+j) = b;     
            i--;
            j++;
            
        }
        
    }else{
        while(f == 0){
            if(i-j == 1)
                f = 1;
            a = *(dest+j);
            std::cout << a;
            b = *(dest+i);
            std::cout << b << std::endl;
            *(dest+i) = a;  
            *(dest+j) = b;     
            i--;
            j++;
            
        }
    }
    
    
}
void to_upper(char* chaine){
    int i = 0, j = 0, t = 0;
    while(*(chaine+i) != '\0'){
        for(j = 1; j<=26; j++){
            if(*(chaine+i) == char(97+j))
            *(chaine+i) = char(65+j);
        }
        
        i++;
    }
}
void to_lower(char* chaine){
    int i = 0, j = 0, t = 0;
    while(*(chaine+i) != '\0'){
        for(j = 0; j<=26; j++){
            if(*(chaine+i) == char(65+j))
            *(chaine+i) = char(97+j);
        }        
        i++;
    }
}
char *cherche_mot(const char* phrase, const char* mot){
    int f = 0;
    int r = 0;
    int j = 0, i = 0;

    char t;

    

    while(*(phrase+i) != '\0'){
        if(i == 0){
            while(*(phrase+j) != ' ' && *(mot+j) != '\0'){
                if (*(phrase+j) == *(mot+j))
                    f++;
                j++;
            }
            r = longueur(mot);
            if(f == r){
                char* debut = new char[r];
                for(int s = 0; s < r ; s++){
                    t = *(phrase+j+s);
                    debut[s] = t;
                }
                return debut;
            }
        }else if(*(phrase+i) == ' '){
            
            while(*(phrase+j) != ' ' || *(phrase+j) != '\0'){
                if(*(phrase+j) == *(mot+j))
                    f++;
                j++;
            }
            r = longueur(mot);
            if(f == r){
                char* debut = new char[r];
                for(int s = 0; s < r ; s++){
                    t = *(phrase+j+s);
                    debut[s] = t;
                }
                return debut;
            }
        }
        i++;
    }
    return 0;
}
void sous_chaine(const char* source, char* dest, int debut, int longueur){
    int i = debut-1, t = 0;

    char a;

    for(i = debut-1 ; t < longueur; i++){
        a = *(source+i);
        *(dest+t) = a; 
        t++;
        if(*(source+i) != '\0'){
            *(dest+t) = '\0';
        }
    }
}
void supprime_caractere(char* chaine, char caractere){
    int j = 0, t = 0;
    for(int i =0; i<= 49; i++){
        if(*(chaine+i) == caractere){
            t = i+1;
            for( j = i; j<=49; j++){
                *(chaine+j) = *(chaine+t);
                t++;
            }
        }
    }
}
int compte_mots(const char* phrase){
    int m = 1;
    for(int i = 0; i<=49; i++){
        if(*(phrase+i) == ' ' && *(phrase+i-1) != ' ')
        m++;
    }
    return m;
}