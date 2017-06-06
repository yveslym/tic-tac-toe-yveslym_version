#pragma once
#include<cstdlib>
#include<iostream>
#include<string>
#include"board_square.h"
#include"board_class.h"
#include "Player_class.h"
#include"player_piece.h"
#include<chrono>
#include<thread>
#include<exception>

using namespace std::chrono;
using namespace std::this_thread;


using namespace std;
namespace game_interface
{
	void start();
	void board(board_class& b);
}

