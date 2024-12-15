#include <iostream>

class Entity {
public:
	virtual void printName(){}
	
};

class Player : public Entity {
public:
};

class Enemy : public Entity {
public:
};
//int main() {
//	Player* player = new Player();
//	Entity* actuallyPlayer = player;
//	Entity* actuallyEnemy = new Enemy();
//
//	//Player* p = actuallyEnemy; // ERROR BECAUSE E is ENTITY NOT A PLAYER
//	//Player* p1 = actuallyEnemy; // ERROR BECAUSE E is ENTITY NOT A PLAYER
//	//Player* p1 = (Player*)actuallyEnemy; // IF ACCESSED NOT A MEMBER OF SPECIFIED CLASS IT WILL HAVE A PROBLEM
//	//Player* p2 = static_cast<Player*>(actuallyEnemy); // SAME WITH ABOVE
//
//	Player* p2 = dynamic_cast<Player*>(actuallyEnemy); // NULL  BECAUSE ITS AN ENEMY CLASS
//	Player* p3 = dynamic_cast<Player*>(actuallyPlayer); // CORRECT BECAUSE ITS ACTUALLY A PLAYER CLASS
//
//}