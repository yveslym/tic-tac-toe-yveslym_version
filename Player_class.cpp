#include "Player_class.h"



const Player_class & Player_class::operator=(const Player_class & otherplayer)
{
	if (this != &otherplayer)
		this->copyplayer(otherplayer);
	return *this;
}

Player_class::Player_class(const Player_class & otherplayer)
{
	this->copyplayer(otherplayer);
}

Player_class::Player_class()
{
	piece1.initialisation();
	piece2.initialisation();
	piece3.initialisation();
}


Player_class::~Player_class()
{
}

void Player_class::copyplayer(const Player_class & otherplayer)
{
	this->piece1 = otherplayer.piece1;
	this->piece2 = otherplayer.piece2;
	this->piece3 = otherplayer.piece3;
}

void Player_class::set_piece1(const player_piece & p1)
{
	this->piece1 = p1;
}

void Player_class::set_piece2(const player_piece & p2)
{
	this->piece2 = p2;
}

void Player_class::set_piece3(const player_piece & p3)
{
	this->piece3 = p3;
}

player_piece Player_class::get_piece1() const
{
	return this->piece1;
}

player_piece Player_class::get_piece2() const
{
	return this->piece2;
}

player_piece Player_class::get_piece3() const
{
	return this->piece3;
}

bool Player_class::winning_condition()
{
	bool win = false;
	if (this->piece1.get_curent_position() + this->piece2.get_curent_position() + this->piece3.get_curent_position() == 12)
	{
		if (this->piece1.get_curent_position() == 4 || this->piece2.get_curent_position() == 4 || this->piece3.get_curent_position() == 4)
			if (this->piece1.get_curent_position() == 7 || this->piece2.get_curent_position() == 7 || this->piece3.get_curent_position() == 7)
				win = true;
	}
	
	else if (this->piece1.get_curent_position() + this->piece2.get_curent_position() + this->piece3.get_curent_position() == 15)
	{
		if (this->piece1.get_curent_position() == 5 || this->piece2.get_curent_position() == 5 || this->piece3.get_curent_position() == 5) 
				win = true;
	}

	else if (this->piece1.get_curent_position() + this->piece2.get_curent_position() + this->piece3.get_curent_position() == 21)
	{
		win = true;
	}
	else if (this->piece1.get_curent_position() + this->piece2.get_curent_position() + this->piece3.get_curent_position() == 6)
	{
		if (this->piece1.get_curent_position() == 1 || this->piece2.get_curent_position() == 1 || this->piece3.get_curent_position() == 1)
			if (this->piece1.get_curent_position() == 2 || this->piece2.get_curent_position() == 2 || this->piece3.get_curent_position() == 2)
				if (this->piece1.get_curent_position() == 3 || this->piece2.get_curent_position() == 3 || this->piece3.get_curent_position() == 3)
					win = true;		
	}
	return win;
}
