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

//Class for buttons on main screen

//Class for each board tile

//Class for board
