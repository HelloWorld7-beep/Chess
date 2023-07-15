#include <iostream>
#include <SFML/Graphics.hpp>


#include <fstream>
#include <iostream>

#include "header.h"

#include <string>
#include <vector>

using namespace std;

//Defining textures static member variable
unordered_map<string, sf::Texture> TextureManager::textures;

void game()
{
    //Create window
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Chess");

    //Create board
    Board board;
    // Create tiles
    Tiles tiles;

    //Create event
    sf::Event event;

    // Main game loop, while the window is open
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        // Loop through each tile and draw the corresponding chess piece
        for (int row = 0; row < 8; row++)
        {
            for (int col = 0; col < 8; col++)
            {
                // Calculate the position of the current tile
                int x = col * 125;
                int y = row * 125;

                // Set the position of the tile sprite
                tiles.setPosition(x, y);

                // Draw the corresponding chess piece based on color and type
                if (board.tileVector[row][col].pieceColor == Color::White) 
                {
                    if (board.tileVector[row][col].pieceType == Type::Rook) 
                    {
                        window.draw(tiles._whiteRook);
                    }
                    else if (board.tileVector[row][col].pieceType == Type::Knight) 
                    {
                        window.draw(tiles._whiteKnight);
                    }
                    else if (board.tileVector[row][col].pieceType == Type::Bishop) 
                    {
                        window.draw(tiles._whiteBishop);
                    }
                    else if (board.tileVector[row][col].pieceType == Type::Queen) 
                    {
                        window.draw(tiles._whiteQueen);
                    }
                    else if (board.tileVector[row][col].pieceType == Type::King) 
                    {
                        window.draw(tiles._whiteKing);
                    }
                    else if (board.tileVector[row][col].pieceType == Type::Pawn) 
                    {
                        window.draw(tiles._whitePawn);
                    }
                }
                else if (board.tileVector[row][col].pieceColor == Color::Black) 
                {
                    if (board.tileVector[row][col].pieceType == Type::Rook) 
                    {
                        window.draw(tiles._blackRook);
                    }
                    else if (board.tileVector[row][col].pieceType == Type::Knight) 
                    {
                        window.draw(tiles._blackKnight);
                    }
                    else if (board.tileVector[row][col].pieceType == Type::Bishop) 
                    {
                        window.draw(tiles._blackBishop);
                    }
                    else if (board.tileVector[row][col].pieceType == Type::Queen) 
                    {
                        window.draw(tiles._blackQueen);
                    }
                    else if (board.tileVector[row][col].pieceType == Type::King) 
                    {
                        window.draw(tiles._blackKing);
                    }
                    else if (board.tileVector[row][col].pieceType == Type::Pawn) 
                    {
                        window.draw(tiles._blackPawn);
                    }
                }
            }
        }

        window.display();
    }
}
int main() {

    /*
     * Chess game needs:
     * 1) Main menu screen
     * 2) Start button
     * 3) Start over button
     * 4) Just do multiplayer for now?
     * 5) Add chess AI later
     * */

    game();


    return 0;
}
