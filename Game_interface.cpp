#include "Game_interface.h"

void game_interface::start()
{
	board_class myboard;
	const int size = 2;
	Player_class players[size];
	player_piece p1, p2, p3;

	myboard.initialisation();
	
	int piece = 0;
	int pos = -1;
	int p = 1;
	
	bool win = false;
	bool good = false;

	
	
	do
	{
		
			board(myboard);

			cout << " \n\n\t Player " << p << ", get piece #: ";
			cin >> piece; cout << endl;
			cout << "\t Player " << p << ", pick position in the board: ";
			cin >> pos; cout << endl;
			

			if (piece == 1)
			{
				
				
				p1 = players[p - 1].get_piece1();
				p1.set_next_position(pos);

				
				if (p == 1)		
					p1.set_print("X1");
				
				else 
					p1.set_print("01");
						

				if (myboard.move_piece(p1) == false)
				{
					cout << " \n this move is not allow...";
					sleep_for(milliseconds(3000));
					p--;
				}
				p1.set_current_position(pos);
				players[p - 1].set_piece1(p1);
				p1;
			}
			else if (piece == 2)
			{
				

				p2 = players[p - 1].get_piece2();
				p2.set_next_position(pos);

				if (p == 1)
					p2.set_print("X2");

				else
					p2.set_print("02");

				players[p-1].set_piece2(p2);

				if (myboard.move_piece(p2) == false)
				{
					cout << " \n this move is not allow...";
					sleep_for(milliseconds(3000));
					p--;
				}

				p2.set_current_position(pos);
				players[p - 1].set_piece2(p2);
				p2;
			}

			else if (piece == 3)
			{
				
				p3 = players[p - 1].get_piece3();
				p3.set_next_position(pos);

				if (p == 1)
					p3.set_print("X3");

				else
					p3.set_print("O3");

				players[p-1].set_piece3(p3);

				if (myboard.move_piece(p3) == false)// return false id the move is not allow
				{
					cout << " \n this move is not allow...";
					sleep_for(milliseconds(3000));
					p--;
				}
				p3.set_current_position(pos);
				players[p - 1].set_piece3(p3);
				p3;
			}
			
			win = players[p-1].winning_condition();
			
			if (win == true)
			{
				board(myboard);
				cout << "\n\n Player "<<p<<" won this game\n";
			}
			if (p <= 1)
				p++;
			else
				p--;

			pos = 0;
	} while (win == false);
}

void game_interface::board(board_class& myboard)
{
	system("cls");
	
	const int size = 9;
	board_square Board[size];
	
	for (int i = 0; i < 9; i++)
	{
		Board[i] = myboard.get_board()[i];
	}
	

	
	cout << "_________________________________________________" << endl;

	cout << "|	"; Board[0].print(); cout << "	|	"; Board[1].print(); cout << "	|	"; Board[2].print();cout << "	|" << endl;
	cout << "|_______________|_______________|_______________|" << endl;
	cout << "|	"; Board[3].print(); cout << "	|	"; Board[4].print(); cout << "	|	"; Board[5].print(); cout << "	|" << endl;
	cout << "|_______________|_______________|_______________|" << endl;
	cout << "|	"; Board[6].print(); cout << "	|	"; Board[7].print(); cout << "	|	"; Board[8].print(); cout << "	|" << endl;
	cout << "|_______________|_______________|_______________|" << endl;


}
