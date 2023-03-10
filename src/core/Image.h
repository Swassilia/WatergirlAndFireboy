#ifndef _IMAGE
#define _IMAGE
#include "Pixel.h"
#include <string>

class Image{

 private :

  Pixel * tab;    // le tableau 1D de pixel
  unsigned int dimx, dimy ;        // les dimensions de l'image

 public :

  
   /**
    *  @brief Constructeur par defalut
    * 
    * Constructeur par défaut de la classe: initialise dimx et dimy à 0 ce constructeur n'alloue pas de pixel
   */
    Image ();

   /**
    * @brief Constructeur qui initialise dimx et dimy
    * 
    * Constructeur de la classe: initialise dimx et dimy (après vérification)
      puis alloue le tableau de pixel dans le tas (image noire)
   */
    Image (const unsigned int &dimensionX, const unsigned int &dimensionY);

   /**
   * @brief Destructeur
   * Destructeur de la classe: déallocation de la mémoire du tableau de pixels
   et mise à jour des champs dimx et dimy à 0
   */
    ~Image ();

    /**
    * @brief Accesseur: récupère le pixel original de coordonnées (x,y)
    *  Accesseur : récupère le pixel original de coordonnées (x,y) en vérifiant leur validité
    la formule pour passer d'un tab 2D à un tab 1D est tab[y*dimx+x]
    * \param x coordonnée entiere de largeur 
    * \param y coordonnée entiere de longueur
   */
   Pixel &getPix (const unsigned int x,const unsigned int y)const;//-> 'Pixel' (l'original, pas une copie)

   /**
    * @brief Mutateur : modifie le pixel de coordonnées (x,y)
    * \param x coordonée entiere de largeur 
    * \param y coordonnée entiere de longueur
   */
   void setPix (const unsigned int x,const unsigned int y, const Pixel &couleur) const;

   /**
    * @brief Dessine un rectangle plein de la couleur dans l'image 
    * 
    * Dessine un rectangle plein de la couleur dans l'image (en utilisant setPix, indices en paramètre compris)
    * \param Xmin coordonée entiere inferieur de largeur 
    * \param Xmax coordonée entiere superieur de largeur 
    * \param Ymin coordonée entiere inferieur de longueur 
    * \param Ymax coordonée entiere superieur de longueur
    * \param couleur Pixel qui sera la nouvelle couleur du rectangle
    */
   void dessinerRectangle (const unsigned int Xmin, const unsigned int Ymin,const unsigned int Xmax, const unsigned int Ymax,const Pixel& couleur);

   /** 
    * @brief Efface l'image en la remplissant de la couleur en paramètre
    * \param couleur Pixel qui sera la couleur qui remplacera celle effacer 
   */
   void effacer (const Pixel & couleur);

   /**
    * @brief Effectue une serie de tests 
    * Effectue une série de tests vérifiant que le module fonctionne et
    que les données membres de l'objet sont conformes
    * 
    */ 
   void testRegression () const ;
   /**
    * @brief Sauvegarde une image dans un fichier Pixel par Pixel
    * \param filename nomdu fichier ou sera sauvegarder l'image
   */
   void sauver(const std::string & filename) const;
   /**
    * @brief Ouvre le fichier où est sauver l'image 
    * \param filename nom du fichier  à ouvrir
   */
   void ouvrir(const std::string & filename)   ;
    /**
    * @brief Affiche dans la console les valeurs des pixels 
   */
   void afficherConsole() const;
   
};
#endif // Image
