/**
 * @file Problem.h
 * @author Anxian Zhang (gadanxianzhang@gmail.com.com)
           Vick Ye (vickye2908@gmail.com)
 * @brief composant du problème
 * @version 2
 * @date 2021-12-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _PROBLEM_
#define _PROBLEM_

struct Problem {
    unsigned int lignes;
    unsigned int colonnes;
    unsigned int bombes;
    unsigned int* pos_bombe; // position des bombes
};

/**
 * @brief Permet la saisie d'un probl�me
 *
 * @param [out] p: probl�me � cr�er
 */
void saisie_problem(Problem& p);

/**
 * @brief Alloue dynamiquement un tableau pour le nombre
 *        de bombes donn�e
 *
 * @see desallocation_bombe: d�salloue le tableau de bombe
 *
 * @param [out] p: le probl�me
 */
void allocation_bombe(Problem& p);

/**
 * @brief Verifie si la position du coup jou�
 *        corespond � celle d'une bombes
 *
 * @param [in] p: le probl�me
 * @param [in] pos_coup: la position du coup
 * @return int 1 si c'est vrais, 0 si c'est faux
 */
int verification(const Problem& p, const unsigned int pos_coup);

/**
 * @brief d�salloue le tableau de bombe
 *
 * @param [out] p: le probl�me
 */
void desallocation_bombe(Problem& p);

/**
 * @brief Affiche le probl�me
 *
 * @param [in] p: le probl�me
 */
void affichage_problem(const Problem& p);

#endif // !_PROBLEM_
