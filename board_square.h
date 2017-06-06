#pragma once
#include"player_piece.h"
#include<iostream>

class board_square
{
private:
	player_piece piece_set;
	bool check_inside;
public:
	board_square();
	virtual ~board_square();
	bool is_square_empty();
	bool add_piece(const player_piece& piece);
	void remove_piece();
	void initialisation();
	void print();
	void set_board_square(const board_square& otherboard);
	board_square get_board_square()const;
};

