#include "PieceFactory.hpp"

namespace Chess::Pieces
{
	std::shared_ptr<Piece> PieceFactory::CreatePiece(PieceType type, Piece::Color color)
	{
		switch (type)
		{
		case PieceType::PAWN:	return std::make_shared<Pawn>(color);
		case PieceType::ROOK:	return std::make_shared<Rook>(color);
		case PieceType::KNIGHT: return std::make_shared<Knight>(color);
		case PieceType::BISHOP: return std::make_shared<Bishop>(color);
		case PieceType::QUEEN:	return std::make_shared<Queen>(color);
		case PieceType::KING:	return std::make_shared<King>(color);

		}
	}
}