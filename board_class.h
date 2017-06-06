#pragma once
#ifndef board_class_H
#define board_class_H


#include"board_square.h"
#include <vector>
class board_class
{
private:
	const int board_size = 10;
	std::vector<board_square> board_game;
	bool win;
public:
	const board_class& operator=(const board_class& otherboard);
	board_class(const board_class& otherboard);
	void copyboard(const board_class& otherboard);
	board_class();
	virtual ~board_class();
	bool move_piece( player_piece piece);
	bool check_move(int current, int next); // return true if movie is posible
	bool square_empty(int pos);// check if the square x is empty or nah

	std::vector<board_square> get_board()const;
	void set_board(const std::vector<board_square>& otherboard);

	void initialisation();
};

#endif // !board_class_H
