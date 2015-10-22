
#include "CPokemon.h"

/*----------------------------------------------------------------------------------------*/
//コンストラクタ
/*----------------------------------------------------------------------------------------*/
CPokemon::CPokemon() {
    selectedMoveNum = 0;
    aliveFlag = true;
}
/*----------------------------------------------------------------------------------------*/
//デストラクタ
/*----------------------------------------------------------------------------------------*/
CPokemon::~CPokemon() {
}


void CPokemon::initialize(int _level, char* _name, Ability _ability, Move _move[4]) {

    m_level = _level;
    m_name = _name;
    m_ability = _ability;
    for (int i = 0; i < 4; i++) {
        m_move[i] = _move[i];
    }
    calcStats(m_ability);
}

CPokemon* CPokemon::fightmenu() {
    std::cout << "\nNow " << this->m_name << "'s turn-------------------------" << std::endl;
    for (int i = 0 ; i < 4 ; i++) {
        std::cout << i + 1 << ": " << m_move[i].name << std::endl;
    }

    std::cout << "Choose a move. Input number: " << std::flush;
    std::cin >> selectedMoveNum;
    selectedMoveNum = selectedMoveNum - 1;
    printf("\n");

    return this;
}

double CPokemon::attack(CPokemon another) {

    std::cout << m_name << " used " << m_move[selectedMoveNum].name << "!" << std::endl;
    double damage, rnd;

    rnd = 0.0 + (int)(rand() * (100.0 - 0.0 + 1.0) / (1.0 + RAND_MAX));

    if (m_move[selectedMoveNum].accuracy < rnd) {
        std::cout << m_name << "'s attack missed! " << std::endl;
        damage = 0.0;
    } else {
        rnd = 85.0 + (int)(rand() * (100.0 - 85.0 + 1.0) / (1.0 + RAND_MAX));
        damage = ((m_level * 2.0 / 5.0 + 2.0)
                  * m_move[selectedMoveNum].power
                  * m_battlestats.statsInBattle.attack
                  / another.getBattleStats().statsInBattle.defense
                  / 50.0 + 2.0) * rnd / 100.0;
    }
    return damage;
}

void CPokemon::damaged(double _damage) {

    std::cout << m_name << " is damaged " << _damage << "!" << std::endl;

    m_battlestats.statsInBattle.hitpoint -= _damage;
    std::cout << m_name << "'s HP is " << m_battlestats.statsInBattle.hitpoint << "!" << std::endl;

    if (m_battlestats.statsInBattle.hitpoint <= 0.0) {
        aliveFlag = false;
    }
}

bool CPokemon::isAlive() {
    return aliveFlag;
}

BattleStats CPokemon::getBattleStats() {
    return m_battlestats;
}




void CPokemon::calcStats(Ability _ability) {

    m_stats.hitpoint = ((_ability.baseStats.hitpoint * 2.0
                         + _ability.individualValue
                         + _ability.effortValue / 4.0) * m_level / 100.0) + 10.0 + m_level;

    m_stats.attack = ((_ability.baseStats.attack * 2.0
                       + _ability.individualValue
                       + _ability.effortValue / 4.0) * m_level / 100.0) + 5.0;

    m_stats.defense = ((_ability.baseStats.defense * 2.0
                        + _ability.individualValue
                        + _ability.effortValue / 4.0) * m_level / 100.0) + 5.0;


    m_battlestats.statsInBattle = m_stats;
    m_battlestats.accuracy = 0.0;
    m_battlestats.evasion = 0.0;
}

void CPokemon::calcBattleStats() {

}