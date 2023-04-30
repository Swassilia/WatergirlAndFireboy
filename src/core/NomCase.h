/**
@brief Module gérant les types "NomCase" du projet
@file NomCase.h
@date 2023/03/14
*/
#ifndef _NomCase
#define _NomCase

/**
 * @brief type énuméré NomCase, qui représente les cases du tableaux et leur équivalent en chaîne de caractère
*/
enum NomCase { 

    WALL='#', 
    BLOC='_', 
    SPACE=' ', 
    BONUSEAU='b', 
    BONUSFEU='r',
    RIVIEREeau='e', 
    RIVIEREfeu='f',
    RIVIEREvert='v',
    PORTEEAU='E', 
    PORTEFEU= 'F',

    };

#endif
