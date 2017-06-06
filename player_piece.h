#pragma once
#include<iostream>
#include<string>
class player_piece
{
public:
	player_piece();
	player_piece(const int& current, const int& next);
	~player_piece();
	void destroy();

	player_piece(const player_piece& otherpiece);
	void copypiece(const player_piece& otherpiece);
	const player_piece& operator=(const player_piece& otherpiece);
	//player_piece(int current = 0, int next = 0);

protected:
	int current_position;
	int next_position;
	std::string print_piece;
public:
	int get_curent_position()const;
	int get_next_position()const;

	void set_current_position(const int& pos);
	void set_next_position(const int& pos);
	void set_print(const std::string& print);
	void print()const;

	void initialisation();
};

