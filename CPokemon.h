#include <iostream>

typedef struct{
	double attack;		//こうげき
	double defense;		//ぼうぎょ
	double hitpoint;	//HP
} Stats;

typedef struct{
	Stats statsInBattle;//バトル中のStats(バトル中変化することがあるから)
	double evasion;		//回避率
	double accuracy;	//命中率
} BattleStats;

typedef struct{
	Stats baseStats;		//種族値
	double effortValue;		//努力値
	double individualValue;	//個体値
} Ability;

typedef struct{
	char* name;
	double power;
	double accuracy;
} Move;	//技

/*----------------------------------------------------------------------------------------*/
//	ポケモンクラス
/*----------------------------------------------------------------------------------------*/
class CPokemon
{

private:
	Stats m_stats;
	BattleStats m_battlestats;
	Ability m_ability;
	Move m_move[4];

	int selectedMoveNum;
	bool aliveFlag;
	void calcStats(Ability _ability);
	void calcBattleStats();

public:
	CPokemon();
	~CPokemon();
	
	int m_level;
	char* m_name;

	void initialize(int _level, char* _name, Ability _ability, Move _move[4]);
	BattleStats getBattleStats();
	CPokemon* fightmenu();
	double attack(CPokemon another);
	void damaged(double _damage);
	bool isAlive();

};
