#include "PieceFactory.hpp"


namespace Chess::Pieces
{
	std::shared_ptr<Piece> PieceFactory::CreatePiece(PieceType type, Color color)
	{
		switch (type)
		{
		case PieceType::PAWN:	return std::make_shared<Pawn>(color,std::make_shared<PawnMovementStrategy> (PawnMovementStrategy()));
		case PieceType::ROOK:	return std::make_shared<Rook>(color, std::make_shared<RookMovementStrategy>(RookMovementStrategy()));
		case PieceType::KNIGHT: return std::make_shared<Knight>(color, std::make_shared<KnightMovementStrategy>(KnightMovementStrategy()));
		case PieceType::BISHOP: return std::make_shared<Bishop>(color, std::make_shared<BishopMovementStrategy>(BishopMovementStrategy()));
		case PieceType::QUEEN:	return std::make_shared<Queen>(color, std::make_shared<MockMovement>(MockMovement()));
		case PieceType::KING:	return std::make_shared<King>(color, std::make_shared<KingMovementStrategy>(KingMovementStrategy()));
		default:
			throw std::runtime_error("Tried to create an invalid piece!");

		}
	}
}