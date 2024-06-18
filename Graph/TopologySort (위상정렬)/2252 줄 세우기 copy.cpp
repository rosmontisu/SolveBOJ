#include <iostream>
using namespace std;

struct StatInfo
{
	int hp; // +0
	int attack; // +4
	int defence; // +8
};

void EnterLobby();
StatInfo CreatePlayer(); // 포인터 사용 전 버젼 
void CreateMonster(StatInfo* info); // 포인터 사용 후 버젼


int main()
{	
	EnterLobby();
	return 0;
}

void EnterLobby()
{
	cout << "로비에 입장했습니다." << endl;

	StatInfo player;
	player = CreatePlayer();

	StatInfo monster;
	CreateMonster(&monster);


}

StatInfo CreatePlayer()
{
	StatInfo ret;

	cout << "플레이어 생성" << endl;

	ret.hp = 100;
	ret.attack = 10;
	ret.defence = 2;

	return ret;
}

void CreateMonster(StatInfo* info)
{
	cout << "몬스터 생성" << endl;

	info->hp = 40;
	info->attack = 8;
	info->defence = 1;
}
