/**
@brief Module qui définit une classe pour afficher le jeu en mode texte
@file JeuTxt.h
@date 2023/03/14
*/
#ifndef _JEUTXT_H
#define _JEUTXT_H

#include "../core/Jeu.h"
#include "WinTxt.h"

/**
 * @brief affiche l'état du jeu dans une fenêtre
 * 
 * @param win référence vers WinTxt
 * @param jeu référence constante vers Jeu
*/
void txtAff(WinTXT & win, const Jeu & jeu);

/**
 * @brief gère la boucle de jeu en mode texte
 * 
 * @param j référence vers Jeu
*/
void MontxtBoucle (Jeu & j);


#endif
