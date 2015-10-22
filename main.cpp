

#include <iostream>
#include <time.h>
#include "CPokemon.h"

Stats setStats(double _attack, double _defense, double _hitpoint);
Ability setAbility(Stats _basestats, double _effortValue, double _individualValue);
Move setMove(char* name, double power, double accurary);

int main(void) {
    // ���������i�m�肽����΃O�O���Ă��������j
    srand((unsigned int)time(NULL));

    CPokemon pikachu;
    Ability pikachu_ability = setAbility(setStats(55, 30, 35), 200, 100);
    Move pikachu_move[4];
    pikachu_move[0] = setMove("10���{���g", 90, 100);
    pikachu_move[1] = setMove("���݂Ȃ�", 120, 70);
    pikachu_move[2] = setMove("�A�C�A���e�[��", 100, 75);
    pikachu_move[3] = setMove("�ł񂶂ق�", 150, 50);
    pikachu.initialize(50, "�s�J�`���E", pikachu_ability, pikachu_move);

    CPokemon hitokage;
    Ability hitokage_ability = setAbility(setStats(55, 30, 35), 200, 100);
    Move hitokage_move[4];
    hitokage_move[0] = setMove("������ق�����", 90, 100);
    hitokage_move[1] = setMove("��������", 120, 70);
    hitokage_move[2] = setMove("�h���S���N���[", 100, 75);
    hitokage_move[3] = setMove("��񂲂�", 150, 50);
    hitokage.initialize(50, "�q�g�J�Q", hitokage_ability, hitokage_move);

    double damage = 0.0;
    while (1) {

        damage = pikachu.fightmenu()->attack(hitokage);
        hitokage.damaged(damage);
        if (!hitokage.isAlive()) {
            std::cout << pikachu.m_name << " defeated " << hitokage.m_name << " !" << std::endl;
            break;
        }

        damage = hitokage.fightmenu()->attack(hitokage);
        pikachu.damaged(damage);
        if (!pikachu.isAlive()) {
            std::cout << hitokage.m_name << " defeated " << pikachu.m_name << " !" << std::endl;
            break;
        }
    }
    return 0;
}

Stats setStats(double _attack, double _defense, double _hitpoint) {
    Stats retStats;
    retStats.attack = _attack;
    retStats.defense = _defense;
    retStats.hitpoint = _hitpoint;
    return retStats;
}

Ability setAbility(Stats _basestats, double _effortValue, double _individualValue) {
    Ability retAbility;
    retAbility.baseStats = _basestats;
    retAbility.effortValue = _effortValue;
    retAbility.individualValue = _individualValue;
    return retAbility;
}
Move setMove(char* _name, double _power, double _accuracy) {
    Move retMove;
    retMove.name = _name;
    retMove.power = _power;
    retMove.accuracy = _accuracy;
    return retMove;
}