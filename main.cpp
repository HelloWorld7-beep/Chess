#include <iostream>
#include <SFML/Graphics.hpp>


#include <fstream>
#include <iostream>

#include "header.h"

#include <string>
#include <vector>

using namespace std;

void drawBoard(sf::RenderWindow& window, Tiles& tiles, Board& board)
{
    //Loop through each tile and draw the corresponding chess piece
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
}

//Defining textures static member variable
unordered_map<string, sf::Texture> TextureManager::textures;

void game()
{
    //Create window
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Chess");

    //Create board
    Board board;
    //Create tiles
    Tiles tiles;

    //Create event
    sf::Event event;

    //Boolean for which player is playing
    bool player = false;

    window.clear(sf::Color::White);

    drawBoard(window, tiles, board);

    window.display();

    //Integers to store selected row/col
    int clickedRow = -1;
    int clickedCol = -1;
    //String to store piece type
    string type = "";
    //String to store piece color
    string color = "";

    //While the window is open
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                //Get the released position
                int mouseX = event.mouseButton.x;
                int mouseY = event.mouseButton.y;
                //Translate it into rows/cols
                int col = mouseX / 125;
                int row = mouseY / 125;

                cout << "row, col " << row << " " << col << endl;

                //If there is a in the clicked area
                if ((board.tileVector[row][col].pieceType != Type::None) && player == false)
                {
                    if (board.tileVector[row][col].pieceColor == Color::White)
                    {
                        clickedRow = row;
                        clickedCol = col;

                        type = typeToString(board.tileVector[row][col].pieceType);
                        color = colorToString(board.tileVector[row][col].pieceColor);

                        cout << "clickedrow, clickedCol " << clickedRow << " " << clickedCol << endl;
                    }
                    
                }
                else if ((board.tileVector[row][col].pieceType != Type::None) && player == true)
                {
                    if (board.tileVector[row][col].pieceColor == Color::Black)
                    {
                        clickedRow = row;
                        clickedCol = col;

                        type = typeToString(board.tileVector[row][col].pieceType);
                        color = colorToString(board.tileVector[row][col].pieceColor);
                    }
                }

                cout << "type " << typeToString(board.tileVector[row][col].pieceType) << endl;
            }
            else if (event.type == sf::Event::MouseButtonReleased)
            {
                //Get the released position
                int mouseX = event.mouseButton.x;
                int mouseY = event.mouseButton.y;
                //Translate it into rows/cols
                int endCol = mouseX / 125;
                int endRow = mouseY / 125;

                cout << "endrow, endcol " << endRow << " " << endCol << endl;

                if (clickedRow != -1 && clickedCol != -1)
                {
                    cout << "clickedrow, clickedCol " << clickedRow << " " << clickedCol << endl;

                    if (board.movePiece(clickedCol, clickedRow, endCol, endRow, type, color))
                    {
                        cout << "movedpiece is true " << endl;

                        board.tileVector[endRow][endCol] = board.tileVector[clickedRow][clickedCol];
                        board.tileVector[clickedRow][clickedCol] = Tiles(Color::None, Type::None);

                        if (player == true)
                        {
                            player = false;
                        }
                        else
                        {
                            player = true;
                        }

                    }

                    //Reset clicked row/col
                    clickedRow = -1;
                    clickedCol = -1;
                    //Reset type
                    type = "";
                    //Reset color
                    color = "";
                }
                

                
            }

            window.clear(sf::Color::White);

            drawBoard(window, tiles, board);

            window.display();

            //cout << "window" << endl;

        }

    }
    
};

int main() {

    /*
     * TODO
     * Piece movement logic
     * Piece capture logic
     * Game end logic
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
