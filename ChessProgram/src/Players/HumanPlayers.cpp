#include "../../include/Players/HumanPlayer.hpp"
#include "Colorful_IO.hpp"
#include "../../include/Engine/ChessEngine.hpp"
#include "../../include/Helpers/ChessColorDefines.hpp"

namespace Chess
{
	Move HumanPlayer::GetMove(const Board& board)
	{
		bool validInput = false;
		std::string notation;

		do
		{
			//Clear screen
			ColorfulIO::ClearConsole(std::cout);

			//Draw Board
			Engine::ChessEngine::Get().GetBoard().Print();

			//Prompt User:
			ColorfulIO::Write(std::cout, "\n\nEnter Your Desired Move In Algebraic Notation: ", false, true, Colors::PROMPT_COLOR);

			//Get Possible Notation
			notation = ColorfulIO::GetTrimmedLineFromUser();

			if (IsValidAlgebraic(notation))
				validInput = true;
			else
			{
				//Let user know their input was invalid
				ColorfulIO::WriteNewLines(std::cout, 3);
				ColorfulIO::PressAnyKeyAlert(std::cin, std::cout, "That was not a valid expression!", false, true, Colors::INVALID_INPUT);
			}

			//If we have valid input now, we will try to return the move, if an argument error is thrown we will prompt user again
			if (validInput)
			{
				try
				{
					//TODO: Add checks for special commands here?
					Move move = ParseAlgebraicMove(notation, board);

					//Move has been parsed, check validity based on pieces

					std::vector<Move> legal_moves = board.GetPieceAt(move.from)->GetLegalMoves(move.from, board);

					auto itr = std::find(legal_moves.begin(), legal_moves.end(), move);

					if (itr != legal_moves.end())
						return *itr;
					else throw std::invalid_argument("That is not a legal move!");

				}
				catch(std::invalid_argument err)
				{
					//Let user know their input was invalid
					ColorfulIO::WriteNewLines(std::cout, 3);
					std::string message = "There is an issue with your expression! " + std::string(err.what());
					ColorfulIO::PressAnyKeyAlert(std::cin, std::cout, message, false, true, Colors::ERROR);
					validInput = false;
				}
			}
		} while (!validInput);
	}
}
