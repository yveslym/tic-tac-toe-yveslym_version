#include "board_square.h"



board_square::board_square()
{
	this->check_inside = false;
	this->piece_set.initialisation();
}

board_square::~board_square()
{
}

bool board_square::is_square_empty()
{
	if (check_inside == false)
		return true;
	else
		return false;

}

bool board_square::add_piece(const player_piece & piece)
{
	bool added = false;
	if (this->is_square_empty() == true)
	{
		this->piece_set = piece;
		this->check_inside = true;
		added = true;
	}
	return added;
}

void board_square::remove_piece()
{
	this->check_inside = false;
	this->piece_set.initialisation();
	this->piece_set.print();
}

void board_square::initialisation()
{
	this->check_inside = false;
	this->piece_set.initialisation();
}

void board_square::print()
{
 this->piece_set.print();
}

void board_square::set_board_square(const board_square & otherboard)
{
	this->piece_set = otherboard.piece_set;
	this->check_inside = otherboard.check_inside;
}

board_square board_square::get_board_square() const
{
	return *this;
}




