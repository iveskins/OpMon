/*
CT.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://opmon-game.ga
Contient la définition de la classe CT
*/
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_CT_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_CT_HPP_

#include "../../../utils/Class.hpp"
#include "Item.hpp"
#include "../Attaque.hpp"
/**
Définit un item de type CT
*/
class CT : public Item {
    public:
        CT(Class<Attaque *> atk, int ctNumber, int ID);
        Class<Attaque *> getAtk() const {
            return atk;
        }
        int itemTypeID = 3;
    private:
        /**Contient la classe de l'attaque de la CT*/
        Class<Attaque *> atk;
};

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_CT_HPP_ */
