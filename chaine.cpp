#include <iostream>
#include <stdlib.h>
#include "bibliotheques.h"

int main(int argc, char**argv){
    int max = 50;
    
    char first[max];
    const char* source = first;

    char chaine2[max];
    char* dest = chaine2;

    char chaine[max];
    const char* chained = chaine;

    char* result = nullptr;

    char c;

    int r;


    int l;

    std::cout << "Quelle operation realiser ? " << std::endl;
    std::cout << "1- Longueur d'une chaine " << std::endl;
    std::cout << "2- Copie d'une chaine " << std::endl;
    std::cout << "3- Concatenation de deux chaines " << std::endl;
    std::cout << "4- Comparaison lexicologique" << std::endl;
    std::cout << "5- Recherche d'un caractere" << std::endl;
    std::cout << "6- Inversion " << std::endl;
    std::cout << "7- Conversion en majuscule/minuscule" << std::endl;
    std::cout << "8- Trouver un mot dans une phrase" << std::endl;
    std::cout << "9- Extraction de sous-chaine" << std::endl;
    std::cout << "10- Suppression d'un caractere" << std::endl;
    std::cout << "11- Compter les mots dans une phrase" << std::endl;

    std::cout << "Operation:  ";

    std::cin >> r;

    switch (r)
    {
    case 1:
        std::cout << "Entrer la chaine dont on determine la longueur" << std::endl;
        std::cin.getline(first, max);
        std::cin.getline(first, max);
        l = longueur(source);
        std::cout << "La longueur de cette chaine est de: " << l << std::endl;
        break;

    case 2:
        std::cout << "Entrer la chaine copie" << std::endl;
        std::cin.getline(first, max);
        std::cin.getline(first, max);
        copie(dest,source);
        std::cout << "La chaine copie est: " << dest ;
        break;

    case 3:
        std::cout << "Entrer la premiere chaine" << std::endl;
        std::cin.getline(chaine2, max);
        std::cin.getline(chaine2, max);
        std::cout << "Entrer la deuxieme chaine" << std::endl;
        std::cin.getline(first, max);
        concatene(dest,source);
        std::cout << "La concatenation donne: " << std::endl;
        std::cout << dest;
        break;

    case 4:
        std::cout << "Entrer la premiere chaine" << std::endl;
        std::cin.getline(first, max);
        std::cin.getline(first, max);
        std::cout << "Entrer la deuxieme chaine" << std::endl;
        std::cin.getline(chaine, max);
        l = compare(source,chained);
        if(l == 1)
            std::cout << "La chaine 1 est plus grand que la chaine 2";
        else if(l == -1)
            std::cout << "La chaine 2 est plus grand que la chaine 1";
        else
            std::cout << "Les deux chaines sont egales";
        break;
    
    case 5:
        std::cout << "Entrer la chaine" << std::endl;
        std::cin.getline(first, max);
        std::cin.getline(first, max);
        std::cout << "Entrer le caractere a rechercher" << std::endl;
        std::cin  >> c;
        result = cherche_char(source,c);
        if(result != 0)
            std::cout << "L'element " << *result << " se trouve dans la chaine";
        else
            std::cout << "Il ne se trouve pas dans la chaine";
        delete result;
        break;

    case 6:
        std::cout << "Entrer la chaine" << std::endl;
        std::cin.getline(chaine2, max);
        std::cin.getline(chaine2, max);
        inverse(dest);
        std::cout << "L'inverse de cette chaine est:  ";
        std::cout << dest;
        break;

    case 7:
        std::cout << "Entrer la chaine" << std::endl;
        std::cin.getline(chaine2, max);
        std::cin.getline(chaine2, max);
        std::cout << "La chaine en majuscule: " << std::endl;
        to_upper(dest);
        std::cout << dest << std::endl;
        std::cout << "La chaine en minuscule: " << std::endl;
        to_lower(dest);
        std::cout << dest;
        break;
    
    case 8:
        std::cout << "Entrer la phrase" << std::endl;
        std::cin.getline(first, max);
        std::cin.getline(first, max);
        std::cout << "Entrer le mot" << std::endl;
        std::cin.getline(chaine, max);
        result = cherche_mot(source, chained);
        if(result != 0)
            std::cout << "Le mot " << result << " se trouve dans la phrase";
        else
            std::cout << "Le mot ne se trouve pas dens la chaine";

        delete[] result;
        break;

    case 9:
        std::cout << "Entrer la chaine" << std::endl;
        std::cin.getline(first, max);
        std::cin.getline(first, max);
        std::cout << "Entrer le debut" << std::endl;
        std::cin >> r;
        std::cout << "Entrer la longueur" << std::endl;
        std::cin >> l;
        sous_chaine(source,dest,r,l);
        std::cout << dest;
        break;
    
    case 10:
        std::cout << "Entrer la chaine" << std::endl;
        std::cin.getline(chaine2, max);
        std::cin.getline(chaine2, max);
        std::cout << "Entrer le caractere " << std::endl;
        std::cin >> c;
        supprime_caractere(dest,c);
        std::cout << "La nouvele chaine est :" << std::endl;
        std::cout << dest;
        break;
    
    case 11:
        std::cout << "Entrer la chaine" << std::endl;
        std::cin.getline(first, max);
        std::cin.getline(first, max);
        l = compte_mots(source);
        std::cout << "La chaine compte " << l << "mots";
        break;

    default:
        std::cout << "Entrer une vrai valeur";
        break;
    }


    

    return 0;

}