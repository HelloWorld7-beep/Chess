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
		path += textureName + ".png";

		//string path = textureName + ".png";

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

enum class Color {White, Black, None};
enum class Type {Queen, King, Bishop, Knight, Rook, Pawn, None};

//Class for each board tile
class Tiles
{
	//Using enumeration to specify color/type of pieces, and whether or not they are on the board
	Color pieceColor;
	Type pieceType;

public:

	//Tiles constructor
	Tiles(Color color, Type type)
	{
		pieceColor = color;
		pieceType = type;
	};

	//Function to set position of tile images
	void setPosition(int x, int y)
	{

	}

};

//Class for board
class Board
{
	//Create a vector of tiles to represent the board;
	vector<vector<Tiles>> tileVector;

public:

	//Board constructor
	Board()
	{
		//Create a tile vector with 64 tiles, and each tile has None color, None type
		tileVector.resize(8, vector<Tiles>(8, Tiles(Color::None, Type::None)));
	}

};

//Class for buttons on main screen


