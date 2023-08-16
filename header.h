#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <unordered_map>

using namespace std;

//Class to manage textures
class TextureManager
{
	static unordered_map<string, sf::Texture> textures;

	static void LoadTexture(string textureName)
	{
		string path = "images/";
		path += textureName + ".JPG";

		//string path = textureName + ".JPG";

		textures[textureName].loadFromFile(path);


	}
public:


	static sf::Texture& GetTexture(string textureName)
	{
		//If I don't find the texture
		if (textures.find(textureName) == textures.end())
		{
			LoadTexture(textureName);
		}
		return textures[textureName];

	}

	//Call once, at end of main
	static void Clear()
	{
		textures.clear();
	}

};

enum class Color { White, Black, None };
enum class Type { Queen, King, Bishop, Knight, Rook, Pawn, None };

//Class for each board tile
class Tiles
{

public:
	//Using enumeration to specify color/type of pieces, and whether or not they are on the board
	Color pieceColor;
	Type pieceType;

	//Create sprites for chess pieces
	sf::Sprite _whiteQueen;
	sf::Sprite _whiteKing;
	sf::Sprite _whiteBishop;
	sf::Sprite _whiteKnight;
	sf::Sprite _whiteRook;
	sf::Sprite _whitePawn;

	sf::Sprite _blackQueen;
	sf::Sprite _blackKing;
	sf::Sprite _blackBishop;
	sf::Sprite _blackKnight;
	sf::Sprite _blackRook;
	sf::Sprite _blackPawn;

	//Tiles defalt constructor
	Tiles()
	{
		pieceColor = Color::None;
		pieceType = Type::None;

		//Get the textures for the pieces
		_whiteQueen.setTexture(TextureManager::GetTexture("white_queen"));
		_whiteKing.setTexture(TextureManager::GetTexture("white_king"));
		_whiteBishop.setTexture(TextureManager::GetTexture("white_bishop"));
		_whiteKnight.setTexture(TextureManager::GetTexture("white_knight"));
		_whiteRook.setTexture(TextureManager::GetTexture("white_rook"));
		_whitePawn.setTexture(TextureManager::GetTexture("white_pawn"));

		_blackQueen.setTexture(TextureManager::GetTexture("black_queen"));
		_blackKing.setTexture(TextureManager::GetTexture("black_king"));
		_blackBishop.setTexture(TextureManager::GetTexture("black_bishop"));
		_blackKnight.setTexture(TextureManager::GetTexture("black_knight"));
		_blackRook.setTexture(TextureManager::GetTexture("black_rook"));
		_blackPawn.setTexture(TextureManager::GetTexture("black_pawn"));

	}

	//Tiles constructor
	Tiles(Color color, Type type)
	{
		//Get the piece color and type
		pieceColor = color;
		pieceType = type;

		//Get the textures for the pieces
		_whiteQueen.setTexture(TextureManager::GetTexture("white_queen"));
		_whiteKing.setTexture(TextureManager::GetTexture("white_king"));
		_whiteBishop.setTexture(TextureManager::GetTexture("white_bishop"));
		_whiteKnight.setTexture(TextureManager::GetTexture("white_knight"));
		_whiteRook.setTexture(TextureManager::GetTexture("white_rook"));
		_whitePawn.setTexture(TextureManager::GetTexture("white_pawn"));

		_blackQueen.setTexture(TextureManager::GetTexture("black_queen"));
		_blackKing.setTexture(TextureManager::GetTexture("black_king"));
		_blackBishop.setTexture(TextureManager::GetTexture("black_bishop"));
		_blackKnight.setTexture(TextureManager::GetTexture("black_knight"));
		_blackRook.setTexture(TextureManager::GetTexture("black_rook"));
		_blackPawn.setTexture(TextureManager::GetTexture("black_pawn"));


	};

	//Function to set position of tile images
	void setPosition(int x, int y)
	{
		_whiteQueen.setPosition(x + 5, y + 5);
		_whiteKing.setPosition(x + 5, y + 5);
		_whiteBishop.setPosition(x + 5, y + 5);
		_whiteKnight.setPosition(x + 5, y + 5);
		_whiteRook.setPosition(x + 5, y + 5);
		_whitePawn.setPosition(x + 5, y + 5);

		_blackQueen.setPosition(x + 5, y + 5);
		_blackKing.setPosition(x + 5, y + 5);
		_blackBishop.setPosition(x + 5, y + 5);
		_blackKnight.setPosition(x + 5, y + 5);
		_blackRook.setPosition(x + 5, y + 5);
		_blackPawn.setPosition(x + 5, y + 5);
	}

	//Function to get the sprite based on color/type
	sf::Sprite getSprite(Tiles tile)
	{
		if (tile.pieceColor == Color::White)
		{
			if (tile.pieceType == Type::Queen)
			{
				return _whiteQueen;
			}
			else if (tile.pieceType == Type::King)
			{
				return _whiteKing;
			}
			else if (tile.pieceType == Type::Bishop)
			{
				return _whiteBishop;
			}
			else if (tile.pieceType == Type::Knight)
			{
				return _whiteKnight;
			}
			else if (tile.pieceType == Type::Rook)
			{
				return _whiteRook;
			}
			else if (tile.pieceType == Type::Pawn)
			{
				return _whitePawn;
			}
		}
		else if (tile.pieceColor == Color::Black)
		{
			if (tile.pieceType == Type::Queen)
			{
				return _blackQueen;
			}
			else if (tile.pieceType == Type::King)
			{
				return _blackKing;
			}
			else if (tile.pieceType == Type::Bishop)
			{
				return _blackBishop;
			}
			else if (tile.pieceType == Type::Knight)
			{
				return _blackKnight;
			}
			else if (tile.pieceType == Type::Rook)
			{
				return _blackRook;
			}
			else if (tile.pieceType == Type::Pawn)
			{
				return _blackPawn;
			}
		}
		else
		{
			//Return blank sprite
			sf::Sprite none;
			return none;
		}

	}

	//Get the opposite of current piece color
	Color getOppsiteColor()
	{
		if (pieceColor == Color::Black)
		{
			return Color::White;
		}
		else if (pieceColor == Color::White)
		{
			return Color::Black;
		}
	}

};

//Method for debugging types
string typeToString(Type pieceType) 
{
	switch (pieceType) 
	{
		case Type::Queen: return "Queen";
		case Type::King: return "King";
		case Type::Bishop: return "Bishop";
		case Type::Knight: return "Knight";
		case Type::Rook: return "Rook";
		case Type::Pawn: return "Pawn";
		default: return "None";
	}
}

string colorToString(Color pieceColor)
{
	switch (pieceColor)
	{
		case Color::White: return "White";
		case Color::Black: return "Black";
		default: return "None";
	}
}

//Class for board
class Board
{
	

public:

	//Create a vector of tiles to represent the board;
	vector<vector<Tiles>> tileVector;

	//Board constructor
	Board()
	{
		//Create a tile vector with 64 tiles, and each tile has None color, None type
		tileVector.resize(8, vector<Tiles>(8, Tiles(Color::None, Type::None)));

		// Set up the starting positions for the white pieces
		tileVector[0][0] = Tiles(Color::White, Type::Rook);
		tileVector[0][1] = Tiles(Color::White, Type::Knight);
		tileVector[0][2] = Tiles(Color::White, Type::Bishop);
		tileVector[0][3] = Tiles(Color::White, Type::Queen);
		tileVector[0][4] = Tiles(Color::White, Type::King);
		tileVector[0][5] = Tiles(Color::White, Type::Bishop);
		tileVector[0][6] = Tiles(Color::White, Type::Knight);
		tileVector[0][7] = Tiles(Color::White, Type::Rook);
		for (int i = 0; i < 8; i++) 
		{
			tileVector[1][i] = Tiles(Color::White, Type::Pawn);
		}

		// Set up the starting positions for the black pieces
		tileVector[7][0] = Tiles(Color::Black, Type::Rook);
		tileVector[7][1] = Tiles(Color::Black, Type::Knight);
		tileVector[7][2] = Tiles(Color::Black, Type::Bishop);
		tileVector[7][3] = Tiles(Color::Black, Type::Queen);
		tileVector[7][4] = Tiles(Color::Black, Type::King);
		tileVector[7][5] = Tiles(Color::Black, Type::Bishop);
		tileVector[7][6] = Tiles(Color::Black, Type::Knight);
		tileVector[7][7] = Tiles(Color::Black, Type::Rook);
		for (int i = 0; i < 8; i++) 
		{
			tileVector[6][i] = Tiles(Color::Black, Type::Pawn);
		}
	}

	//Boolean for whether or not piece movement is valid
	bool movePiece(int startX, int startY, int endX, int endY, string type, string color)
	{
		//X = col, Y = row

		//Get the starting/ending tiles
		//Tiles start = tileVector[startX][startY];
		//Tiles end = tileVector[endX][endY];

		cout << "startx: " << startX << "starty: " << startY << endl;

		/*
		for (int row = 0; row < 8; row++)
		{
			for (int col = 0; col < 8; col++)
			{
				cout << "  boardtype  " << typeToString(tileVector[row][col].pieceType);

				if (startX == row && startY == col)
				{
					cout << endl;
					cout << "row and col " << row << col;
					cout << endl;
					//cout << "type " << typeToString(start.pieceType) << endl;
					cout << endl;
				}

			}
			cout << endl;

		}
		*/

		//cout << "type " << typeToString(start.pieceType) << endl;

		//Check to see if piece is moving according to chess rules
		//Queen movement
		if (type == "Queen")
		{
			//Difference between starting x and y and ending x and y coordinates, aka the movement along the axis
			int dx = endX - startX;
			int dy = endY - startY;

			//Check for valid movement along the axis
			if ((dx == 0 && dy != 0) || (dx != 0 && dy == 0) || abs(dx) == abs(dy))
			{
				//Direction to "step" in
				int stepX = 0;
				int stepY = 0;

				if (dx > 0)
				{
					stepX = 1;
				}
				else if (dx < 0)
				{
					stepX = -1;
				}
				else
				{
					stepX = 0;
				}

				if (dy > 0)
				{
					stepY = 1;
				}
				else if (dy < 0)
				{
					stepY = -1;
				}
				else
				{
					stepY = 0;
				}

				int x = startX + stepX;
				int y = startY + stepY;

				//Check for obstruction and check end piece color
				while (x != endX || y != endY)
				{
					if (tileVector[y][x].pieceType != Type::None)
					{
						return false;
					}
					x += stepX;
					y += stepY;
				}

				return tileVector[endY][endX].pieceType == Type::None || tileVector[endY][endX].pieceColor != tileVector[startY][startX].pieceColor;
			}

			//Invalid movement for the Queen
			return false; 
		}
		//King movement
		if (type == "King")
		{
			int dx = abs(endX - startX);
			int dy = abs(endY - startY);

			//Check for valid movement (one square in any direction)
			if ((dx == 1 && dy <= 1) || (dx <= 1 && dy == 1))
			{
				//Check if the destination square is empty or has an opposing piece
				return tileVector[endY][endX].pieceType == Type::None || tileVector[endY][endX].pieceColor != tileVector[startY][startX].pieceColor;
			}

		}
		//Bishop movement
		if (type == "Bishop")
		{
			int dx = endX - startX;
			int dy = endY - startY;

			// Check for valid diagonal movement
			if (abs(dx) == abs(dy))
			{
				//Direction to "step" in
				int stepX = 0;
				int stepY = 0;

				if (dx > 0)
				{
					stepX = 1;
				}
				else if (dx < 0)
				{
					stepX = -1;
				}
				else
				{
					stepX = 0;
				}

				if (dy > 0)
				{
					stepY = 1;
				}
				else if (dy < 0)
				{
					stepY = -1;
				}
				else
				{
					stepY = 0;
				}

				int x = startX + stepX;
				int y = startY + stepY;

				// Check for obstruction and check end piece color
				while (x != endX)
				{
					if (tileVector[y][x].pieceType != Type::None)
					{
						return false;
					}
					x += stepX;
					y += stepY;
				}

				return tileVector[endY][endX].pieceType == Type::None || tileVector[endY][endX].pieceColor != tileVector[startY][startX].pieceColor;
			}
		}
		//Knight movement
		if (type == "Knight")
		{
			int dx = abs(endX - startX);
			int dy = abs(endY - startY);

			// Check for valid L-shaped movement (2 squares in one direction and 1 square in the other)
			if ((dx == 1 && dy == 2) || (dx == 2 && dy == 1))
			{
				// Check if the destination square is empty or has an opposing piece
				return tileVector[endY][endX].pieceType == Type::None || tileVector[endY][endX].pieceColor != tileVector[startY][startX].pieceColor;
			}
		}
		//Rook movement
		if (type == "Rook")
		{
			int dx = endX - startX;
			int dy = endY - startY;

			// Check for valid straight-line movement
			if ((dx == 0 && dy != 0) || (dx != 0 && dy == 0))
			{
				//Direction to "step" in
				int stepX = 0;
				int stepY = 0;

				if (dx > 0)
				{
					stepX = 1;
				}
				else if (dx < 0)
				{
					stepX = -1;
				}
				else
				{
					stepX = 0;
				}

				if (dy > 0)
				{
					stepY = 1;
				}
				else if (dy < 0)
				{
					stepY = -1;
				}
				else
				{
					stepY = 0;
				}

				int x = startX + stepX;
				int y = startY + stepY;

				// Check for obstruction and check end piece color
				while (x != endX || y != endY)
				{
					if (tileVector[y][x].pieceType != Type::None)
					{
						return false;
					}
					x += stepX;
					y += stepY;
				}

				return tileVector[endY][endX].pieceType == Type::None || tileVector[endY][endX].pieceColor != tileVector[startY][startX].pieceColor;
			}
		}
		//Pawn movement
		if (type == "Pawn")
		{
			//X = col, Y = row
			cout << "pawn " << endl;
			cout << "startx: " << startX << "starty: " << startY << endl;

			int dx = endX - startX;
			int dy = endY - startY;

			cout << "dx: " << dx << "dy: " << dy << endl;

			if (color == "White")
			{
				// Pawns can move one square forward
				if (dx == 0 && dy == 1 && tileVector[endY][endX].pieceType == Type::None)
				{
					return true;
				}

				// Pawns can move two squares forward from their starting position
				if (dx == 0 && dy == 2 && startY == 1 && tileVector[endY][endX].pieceType == Type::None)
				{
					return true;
				}

				// Pawns can capture diagonally
				if (abs(dx) == 1 && dy == 1 &&
					tileVector[endY][endX].pieceType != Type::None &&
					tileVector[endY][endX].pieceColor != tileVector[startY][startX].pieceColor)
				{
					return true;
				}
			}
			else
			{
				// Pawns can move one square forward
				if (dx == 0 && dy == -1 && tileVector[endY][endX].pieceType == Type::None)
				{
					return true;
				}

				// Pawns can move two squares forward from their starting position
				if (dx == 0 && dy == -2 && startY == 6 && tileVector[endY][endX].pieceType == Type::None)
				{
					return true;
				}

				// Pawns can capture diagonally
				if (abs(dx) == 1 && dy == -1 &&
					tileVector[endY][endX].pieceType != Type::None &&
					tileVector[endY][endX].pieceColor != tileVector[startY][startX].pieceColor)
				{
					return true;
				}
			}

			//En passant capture?

			return false;
			
		}

		//Return false if logic is not correct for any piece
		return false;
	}

	


};





