#pragma once
#include"player_piece.h"
#include<vector>
class Player_class
{
private:
	player_piece piece1;
	player_piece piece2;
	player_piece piece3;

public:
	const Player_class& operator=(const Player_class& otherplayer);
	
	Player_class();

	Player_class(const Player_class& otherplayer);//copy constructor
		
	virtual ~Player_class();

	void copyplayer(const Player_class& otherplayer);
	void set_piece1(const player_piece& p1);
	void set_piece2(const player_piece& p2);
	void set_piece3(const player_piece& p3);

	player_piece get_piece1()const;
	player_piece get_piece2()const;	
	player_piece get_piece3()const;

	bool winning_condition();

};

