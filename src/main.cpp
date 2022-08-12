/**
 * @file main.cpp
 * @author Anxian Zhang (gadanxianzhang@gmail.com.com)
           Vick Ye (vickye2908@gmail.com)
 * @brief Application qui nous permet de jouer
          au d�mineur
 * @version 7
 * @date 2021-12-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <cassert>
using namespace std;

#include "Problem.h"
#include "Historic.h"
#include "Grid.h"

int main(void)
{

    // test de modif abzdoaobdbzobizaobizadobidzaoibdozbiaoibdzaoiblazdobilkdzaoil
    srand((unsigned)time(NULL));

    Grid jeu;
    Problem probleme;
    MoveHistoric historique;
    MoveDetails new_move;
    unsigned int num_commande;

    do
    {
        cin >> num_commande;
    } while (!(num_commande > 0 && num_commande <= 5));

    switch (num_commande)
    {
    case 1:
        // G�n�ration du probl�me
        saisie_problem(probleme);
        creation_problem(jeu, probleme);
        affichage_problem(probleme);
        desallocation_bombe(probleme);
        desallocation_grille(jeu);
        break;
    case 2:
        // G�n�ration de la grille
        saisie_grille(jeu, probleme, historique);
        creation_grille(jeu, probleme, historique);
        affichage_grille(jeu, probleme);
        desallocation_coup(historique);
        desallocation_bombe(probleme);
        desallocation_grille(jeu);
        break;
    case 3:
        // Partie gagn� ?
        saisie_grille(jeu, probleme, historique);
        creation_grille(jeu, probleme, historique);
        test_won(jeu, probleme);
        affichage_won(jeu);
        desallocation_coup(historique);
        desallocation_bombe(probleme);
        desallocation_grille(jeu);
        break;
    case 4:
        // Partie perdu ?
        saisie_grille(jeu, probleme, historique);
        test_lost(jeu, probleme, historique);
        affichage_lost(jeu);
        desallocation_coup(historique);
        desallocation_bombe(probleme);
        desallocation_grille(jeu);
        break;
    case 5:
        // Cr�ation d'un nouveau coup
        saisie_dimension_grille(jeu);
        creat_new_move(jeu, new_move);
        //affichage du nouveau coup
        cout << new_move.letter << new_move.position << endl;
        desallocation_grille(jeu);
        break;
    default:
        break;
    }
    return 0;
}