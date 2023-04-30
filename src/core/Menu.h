/**
@brief Module gérant le menu (les modes d'affichage) du jeu
@file Menu.h
@date 2023/03/14
*/
#ifndef _MENU_H
#define _MENU_H

/**
 * @brief type énuméré ChoixMenu, qui représente les choix du menu possibles
*/
enum ChoixMenu { MENU_Choix1=1, MENU_Choix2=2,MENU_Quit=0 };

/**
 * @brief variable utilisée pour indiquer le nombre maximum de choix dans le menu
*/
extern const int MENU_MAX;

/**
 * @brief afficher les fonctions du menu
*/
void menuAff();

/**
 * @brief récupère le choix de l'utilisateur 
 * 
 * @return le type enuméré ChoixMenu
*/
ChoixMenu menuQuestion();

#endif
