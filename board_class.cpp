#include "board_class.h"



const board_class & board_class::operator=(const board_class & otherboard)
{
	if (this != &otherboard)
		copyboard(otherboard);
	return *this;
}

board_class::board_class(const board_class & otherboard)
{
	copyboard(otherboard);
}

void board_class::copyboard(const board_class & otherboard)
{
	board_game.resize(board_size);
	for (int i = 0; i < board_size; i++)
	{
		this->board_game[i] = otherboard.board_game[i];
	}
}

board_class::board_class()
{
	board_game.resize(board_size);

	for (int i=0;i<board_size;i++)
	{
		board_game[i].initialisation();
	}
}


board_class::~board_class()
{
}

bool board_class::move_piece(player_piece piece)
{
	bool move = false;
	int current = piece.get_curent_position() - 1;
	int next = piece.get_next_position() - 1;
	if (square_empty(next) == true && check_move(current, next) == true)
	{
		if (current > -1)
		{
			board_game[next].add_piece(piece);
			board_game[current].remove_piece();
			move = true;
		}

		else if (current < 0)// if the is not on the board yet, dont delete
		{
			board_game[next].add_piece(piece);
			move = true;
		}	
	}
	return move;
}

bool board_class::check_move(int current, int next)
{
	bool move_allow = false;
	
	if (current == 0)
	{
		if (next == 1 || next == 3 || next == 4)
			move_allow = true;
	}
	else if (current == 1)
	{
		if (next == 0 || next == 2 || next == 4)
			move_allow = true;
	}
	else if (current == 2)
	{
		if (next == 1 || next == 5 || next == 4)
			move_allow = true;
	}
	else if (current == 3)
	{
		if (next == 0 || next == 6 || next == 4)
			move_allow = true;
	}
	else if (current == 5)
	{
		if (next == 2 || next == 8 || next == 4)
			move_allow = true;
	}
	else if (current == 6)
	{
		if (next == 3 || next == 7 || next == 4)
			move_allow = true;
	}
	else if (current == 7)
	{
		if (next == 6 || next == 8 || next == 4)
			move_allow = true;
	}
	else if (current == 8)
	{
		if (next == 7 || next == 5 || next == 4)
			move_allow = true;
	}
	else if (current == 4)
	{
		if (next == 1 || next == 2 || next == 3 || next == 5 || next == 6 || next == 7 || next == 8)
			move_allow = true;
	}
	else if (current < 0)// piece is not on the board yet
		move_allow = true;


	return move_allow;
}

bool board_class::square_empty(int pos)
{
	pos;
	if (pos > -1 && board_game[pos].is_square_empty() == true)
		return true;
	else return false;
}

std::vector<board_square> board_class::get_board() const
{
	return board_game;
}

void board_class::set_board(const std::vector<board_square>& otherboard)
{
	this->board_game = otherboard;
}

void board_class::initialisation()
{
	board_game.resize(board_size);

	for (int i = 0; i<board_size; i++)
	{
		board_game[i].initialisation();
	}
}

