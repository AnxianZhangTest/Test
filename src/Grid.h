/**
 * @file Grid.h
 * @author Anxian Zhang (gadanxianzhang@gmail.com.com)
           Vick Ye (vickye2908@gmail.com)
 * @brief Composant de la grille
 * @version 7
 * @date 2021-12-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _GRID_
#define _GRID_

#include "Case.h"
#include "Problem.h"
#include "Historic.h"
#include "GameState.h"

struct Grid {
    Case** gameGrid;
    unsigned int lignes;
    unsigned int colonnes;
    GameState state; // �tat du jeu
};
/***************************** DEBUT COMMANDE 1 ******************************/
/**
 * @brief Cr�er le probl�me
 *
 * @param [in] g: la grille qui va �tre g�n�r� avec le probl�me donn�
 * @param [in] p: le probl�me
 */
void creation_problem(Grid& g, Problem& p);

/**
 * @brief Alloue dynamiquement un tableau � deux
 *        avec les dimensions donn�es
 *
 * @see allocation_grille: d�salloue le tableau �
 *                         2 dimensions
 *
 * @param [out] g: la grille
 */
void allocation_grille(Grid& g);

/**
 * @brief D�salloue le tableau � deux
 *        dimensions
 *
 * @param [out] g: la grille
 */
void desallocation_grille(Grid& g);

/**
 * @brief Initialise toutes les cases du tableau
 *        l'�tat HIDE et son contenue � 0
 *
 * @param [out] g: la grille
 * @param [in] p: le probl�me
 */
void initialisation_grille(Grid& g, const Problem& p);

/**
 * @brief Place le nombre de bombe indiqu�e en entr�e
 *        au d�but du tableau
 *
 * @see rand_bombes: m�lange le tableau pour les placer
 *                   all�atoirement
 *
 * @param [out] g: la grille de jeu
 * @param [in] p: le probl�me
 * @pre p.bombes <= p.lignes * p.colonnes
 */
void place_bombes_debut(Grid& g, const Problem& p);

/**
 * @brief M�lange les cases du tableau pour placer
 *        all�atoirement les bombes qui sont initialement au
 *        debut de ce-dernier
 *
 * @see get_pos_bombes: cherche les positions des bombes
 *
 * @param [out] g: la grille de jeu
 * @param [in] p: le probl�me
 */
void rand_bombes(Grid& g, const Problem& p);

/**
 * @brief Cherche toute les bombes qui se trouvent
 *        dans la grille pour ensuite stocker
 *        leurs positions dans le tableau de bombes
 *        cr�e dynamiquement
 *
 * @param [in] g: la grille de jeu
 * @param [in, out] p: le probl�me
 */
void get_pos_bombes(const Grid& g, Problem& p);
/***************************** FIN COMMANDE 1 ********************************/
/**************************** DEBUT COMMANDE 2 *******************************/

/**
 * @brief Saisit les donn�es necessaires
 *
 * @param [out] g: la grille
 * @param [out] p: le probl�me
 * @param [out] hc: l'historique des coups
 */
void saisie_grille(Grid& g, Problem& p, MoveHistoric& hc);

/**
 * @brief Initalise les positions des bombes donn�e en entr�e
 *        dans la grille de jeu (sont toujours � l'�tat CACHER)
 *
 * @param [out] g: le grille
 * @param [in] p: le probl�me
 */
void initialisation_bombe(Grid& g, const Problem& p);

/**
 * @brief Affiche une grille avec son contenue en fonction
 *        le l'�tat des cases
 *
 * @param [in] g: la grille de jeu
 * @param [in] p: le probl�me
 */
void affichage_grille(const Grid& g, const Problem& p);

/**
 * @brief Affecte les bombes � leurs position respective
 *        et met toutes les cases contenant des bombes
 *        � l'etat UNMASK si le dernier coup
 *        jouer met fin � la partie
 *
 * @param [out] g: la grille
 * @param [in] p: le probl�me
 */
void attribution_bombe_perdu(Grid& g, const Problem& p);

/**
 * @brief Verifie si la position du coup jouer
 *        corespond � celle d'une bombes
 *
 * @param [in] p: le probl�me
 * @param [in] pos_coup: la position du coup
 * @return int 1 si c'est vrais, 0 si c'est faux
 */
int verification(const Problem& p, const unsigned int pos_coup);

/**
 * @brief Marque une case donn�e que si elle ne pas
 *        corespond � celle d'une bombe
 *
 * @see attribution_bombe_perdu: met toute les bombes � l'�tat UNMASK
 *                               dans le cas contraire
 *
 * @param [out] g: la grille
 * @param [in] p: le probl�me
 * @param [in] posc: position du coup jouer
 * @param [in] lc: ligne du coup jouer
 * @param [in] cc: colonne du coup jouer
 */
void mark(Grid& g, const Problem& p, const unsigned int posc,
    const unsigned int lc, const unsigned int cc);

/**
 * @brief d�masque une ou plusieurs cases 
          si celle-ci n'est pas une bombe
 *
 * @see attribution_bombe_perdu: met toute les bombes � l'�tat UNMASK
 *                               dans le cas contraire
 * @see recurrence: se charge du d�masquage si le coup jouer n'est pas � la
 *                  position d'un bombe
 *
 * @param [out] g: la grille
 * @param [in] p: le probl�me
 * @param [in] posc: position du coup jouer
 * @param [in] lc: ligne du coup jouer
 * @param [in] cc: colonne du coup jouer
 */
void unmask(Grid& g, const Problem& p, const unsigned int posc,
    const unsigned int lc, const unsigned int cc);

/**
* @brief Met qu'une case � l'�tat UNMASK si la case � d�masquer contient
*        un chiffre mais si la case de d�part est vide et que ces cases ajdacentes
*        sont elles aussi vide la fonction d�masquera ces case,
*        l'op�ration se r�p�te jusqu'� que la zone soit entour� par des chiffres
*
* @param [out] g: la grille
* @param [in] p: le probl�me
* @param [in] pos: la postion du coup
*/
void recurrence(Grid& g, const Problem& p, const unsigned int pos);

/**
 * @brief Indique le nombre de bombe dans les cases adjacentes
 *
 * @param [out] g: la grille de jeu
 * @param [in] p: le probl�me
 */
void give_value_adjacent(Grid& g, const Problem& p);

/**
 * @brief Traite les coups jouer pour savoir s'il faut
 *        marquer ou d�masquer
 *
 * @see demasquer: d�masque les cases indiqu�
 * @see marquer: marque les cases indiqu�
 *
 * @param [in] g: la grille de jeu
 * @param [in] p: le probl�me
 * @param [in] hc: l'historique de coup
 */
void reconnaissance_coup(Grid& g, const Problem& p, const MoveHistoric hc);

/**
 * @brief Cr�er la grille pour ensuite exploiter
 *        les donn�es lors de l'affichage
 *
 * @param [in] g: la grille de jeu
 * @param [in] p: le probl�me
 * @param [in] hc: l'historique de coup
 */
void creation_grille(Grid& g, Problem& p, MoveHistoric hc);
/***************************** FIN COMMANDE 2 ********************************/
/**************************** DEBUT COMMANDE 3 *******************************/
/**
 * @brief Fait des testes sur l'ensemble de la grille
 *        pour d�terminer si la partie est gagn� ou pas
 *        en affectant GAME_WON ou GAME_NOT_WON � l'�tat du jeu
 *
 * @param [in, out] g: la grille de jeu
 * @param [in] p: le probl�me
 */
void test_won(Grid& g, const Problem& p);

/**
 * @brief Affiche une ligne "game won" ou "game not won" en
 *        fonction de l'�tat de la grille
 *
 * @param [in] g: la grille de jeu
 */
void affichage_won(const Grid& g);
/***************************** FIN COMMANDE 3 ********************************/
/**************************** DEBUT COMMANDE 4 *******************************/
/**
 * @brief Fait des testes en comparant le dernier coup (car
 *        on ne peut que perde sur le dernier coup jouer)
 *        avec les positions des bombes, en fonction du coup
 *        (M ou D) GAME_LOST ou GAME_NOT_LOST sera 
 *        attrituer � l'�tat du jeu
 *
 * @param [in, out] g: la grille de jeu
 * @param [in] p: le probl�me
 * @param [in] hc: l'historique des coups
 */
void test_lost(Grid& g, const Problem& p, const MoveHistoric& hc);

/**
 * @brief Affiche une ligne "game lost" ou "games not lost"
 *        fonction de l'�tat de jeu de la grille
 *
 * @param [in] g: la grille de jeu
 */
void affichage_lost(const Grid& g);
/***************************** FIN COMMANDE 4 ********************************/
/**************************** DEBUT COMMANDE 5 *******************************/

/**
 * @brief Initialise le nombre de lignes et colonnes dans
 *        la stucture de donn�e
 *
 * @param [out] g: la grille
 */
void saisie_dimension_grille(Grid& g);

/**
 * @brief Convertit un chiffre de type char en unsigned int
 *        grace au calcul storage - '0' avec 0 = 48
 *
 * @param [in] storage: le chiffre � convertir
 * @return unsigned int: la valeur convertit
 * @pre storage >= '1' && storage <= '8'
 */
unsigned int val_adja(char storage);

/**
 * @brief Analyse la grille en entr�e et le stock
 *        les donn�es en fonction des valeurs lu
 * 
 * @see val_adja: convertit un chiffre ASCCI en entier naturel
 *
 * @param [in,out] g: la grille
 */
void traitement_grille(Grid& g);

/**
 * @brief Compte le nombre de case qui sont
 *        � l'�tat CACHER
 *
 * @param [in] g: la grille
 * @return unsigned int: le totale de case CACHER
 */
unsigned int count_hidden(const Grid& g);

/**
 * @brief Choisie un coups parmis les cases
 *        � l'�tat CACHER
 * 
 * @see count_hidden: compte le nombre totale de case cach�
 *
 * @param [in] g: la grille
 * @param [out] nw: la nouvelle position
 * @param [in] nb_cacher: nombre de case � l'�tat CACHER
 */
void choice_move(const Grid& g, MoveDetails& nw, const unsigned int nb_cacher);

/**
 * @brief Cr�er un nouveau coup en fonction de
 *        la grille donn�e
 *
 * @param [in] g: la grille
 * @param [in] nw: le nouveau coup
 */
void creat_new_move(Grid& g, MoveDetails& nw);
/***************************** FIN COMMANDE 5 ********************************/

#endif // !_GRID_
