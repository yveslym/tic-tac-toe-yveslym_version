#include "player_piece.h"



player_piece::player_piece()
{
	
	this->current_position = -1;
	this->next_position = -1;
	this->print_piece = " ";
}

player_piece::player_piece(const int & current, const int & next)
{
	this->current_position = current;
	this->next_position = next;
}


player_piece::~player_piece()
{
	//delete &current_position;
	//delete &next_position;
}

void player_piece::destroy()
{
	this->~player_piece();
}

player_piece::player_piece(const player_piece & otherpiece)
{
	this->copypiece(otherpiece);
}

void player_piece::copypiece(const player_piece & otherpiece)
{
	this->current_position = otherpiece.current_position;
	this->next_position = otherpiece.next_position;
	this->print_piece = otherpiece.print_piece;
}

const player_piece & player_piece::operator=(const player_piece & otherpiece)
{
	if (this != &otherpiece)
		this->copypiece(otherpiece);
	return *this;
}

/*player_piece::player_piece(int current, int next)
{
	this -> current_position = current;
	this->next_position = next;
}*/


int player_piece::get_curent_position()const
{
	return this->current_position;
}


int player_piece::get_next_position()const
{
	return this->next_position;
}

void player_piece::set_current_position(const int& pos)
{
	this->current_position = pos;
}


void player_piece::set_next_position(const int& pos)
{
	this->next_position = pos;
}

void player_piece::set_print(const std::string & print)
{
	this->print_piece = print;
}

void player_piece::print() const
{
	std::cout<< this->print_piece;
}

void player_piece::initialisation()
{
	this->current_position = -1;
	this->next_position = -1;
	this->print_piece = " ";
}
