#include <iostream>

typedef struct{
	double attack;		//��������
	double defense;		//�ڂ�����
	double hitpoint;	//HP
} Stats;

typedef struct{
	Stats statsInBattle;//�o�g������Stats(�o�g�����ω����邱�Ƃ����邩��)
	double evasion;		//���
	double accuracy;	//������
} BattleStats;

typedef struct{
	Stats baseStats;		//�푰�l
	double effortValue;		//�w�͒l
	double individualValue;	//�̒l
} Ability;

typedef struct{
	char* name;
	double power;
	double accuracy;
} Move;	//�Z

/*----------------------------------------------------------------------------------------*/
//	�|�P�����N���X
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
