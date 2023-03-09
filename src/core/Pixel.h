#ifndef _PIXEL
#define _PIXEL


class Pixel
{
private:
    unsigned char r, g, b;// les composantes du pixel
public :
    /**
     * @brief constructeur par default 
    *Constructeur par défaut de la classe: initialise le pixel à la couleur noire
    */ 
    Pixel();

    
    /**
     * @brief constructeur initialise r,g,b avec les paramètres
     * \param ng valeur rouge à initialiser
     * \param nv valeur vert à initialiser
     * \param nb valeur bleu à initialiser
    */ 
    Pixel(unsigned char nr, unsigned char ng, unsigned char nb);

    /**
     * @brief Accesseur : récupère la composante rouge du pixel
     * 
     * @return une valeur entre 0-255
    
      */ 
    unsigned char getRouge() const ;

    /**
     * @brief Accesseur : récupère la composante vert du pixel
     * 
     * @return une valeur entre 0-255
    
    */
    unsigned char getVert() const ;

    /**
     * @brief Accesseur : récupère la composante bleu du pixel
     * 
     * @return une valeur entre 0-255
    
    */
    unsigned char getBleu() const ;

    /**
     * @brief Mutateur : modifie la composante rouge du pixel
     * \param nr valeur rouge à modifier
    */
    void setRouge(unsigned char nr);

    /**
     * @brief Mutateur : modifie la composante vert du pixel
     * \param ng valeur vert à modifier 
    */
    void setVert(unsigned char ng);

    /**
     * @brief Mutateur : modifie la composante bleu du pixel
     * \param nb valeur bleu à modifier
    */
    void setBleu(unsigned char nb);
    /**
     * @brief Destructeur 
     * Destructeur, remet les pixel en noir
    */

};
/** 
 * @mainpage 

 *Documentation du module Image
 Cette documentation comprends les classes et fonctions aisni que procédures associées. 
 */
#endif // _PIXEL
