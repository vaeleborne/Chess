#include "../../include/Players/Player.hpp"
#include <sstream>
#include "../../include/Helpers/ChessHelpers.hpp"
#include "../../include/Engine/ChessEngine.hpp"


namespace Chess
{

	Move Player::ParseAlgebraicMove(const std::string& input, const Board& board) const
	{
		if (!IsValidAlgebraic(input))
			throw std::invalid_argument("Input must be a valid algebraic expression such as e2e4 or special expression such as quit!");

		if (Helpers::IsCastlingExpression(input))
		{
			Pieces::Color color = this->GetColor();
			bool white = color == Pieces::Color::WHITE;
			const Board& board = Engine::ChessEngine::Get().GetBoard();
			Position from = white ? Position::FromAlgebraic("e1") : Position::FromAlgebraic("e8");
		
			if (Helpers::IsKingSideCastle(input))
			{
				if (board.CanCastleKingside(color))
				{
					Position to = white ? Position::FromAlgebraic("g1") : Position::FromAlgebraic("g8");
					return Move(from, to, SpecialMove::KINGSIDE_CASTLE);
				}
				else
				{
					throw std::invalid_argument("Attempting to castle kingside, however that's not possible currently!");
				}
			}
			else
			{
				//Must be queenside
				if (board.CanCastleQueenside(color))
				{
					Position to = white ? Position::FromAlgebraic("c1") : Position::FromAlgebraic("c8");
					return Move(from, to, SpecialMove::QUEENSIDE_CASTLE);
				}
				else
				{
					throw std::invalid_argument("Attempting to castle queenside, however that's not possible currently!");
				}
			}
		}

		Position from = Position::FromAlgebraic(input.substr(0, 2));
		Position to = Position::FromAlgebraic(input.substr(2, 2));

		return Move(from, to, SpecialMove::NONE);
	}

	bool Player::IsValidAlgebraic(const std::string& input) const
	{
		std::string testStr = Helpers::ToLower(input);

		//Checking special cases of castling
		if (Helpers::IsCastlingExpression(testStr))
			return true;

		//TODO: Add special valid algebraic expression checks here such as undo
		if (testStr == "u" || testStr == "undo" || testStr == "q" || testStr == "quit")
			return true;

		
		if (testStr.size() < 4)
			return false;

		char fileFrom = testStr[0];
		char fileTo = testStr[2];
		char rankFrom = testStr[1];
		char rankTo = testStr[3];

		bool filesValid = fileFrom >= 'a' && fileFrom <= 'h' && fileTo >= 'a' && fileTo <= 'h';
		bool ranksValid = rankFrom >= '1' && rankFrom <= '8' && rankTo >= '1' && rankTo <= '8';

		return filesValid && ranksValid;
	}
}