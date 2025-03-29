#ifndef IMOVE_COMMAND_HPP
#define IMOVE_COMMAND_HPP
#include "../Board/Board.hpp"
/**
 * @file    IMoveCommand.hpp
 * @author  Dylan Morgan
 * @brief   Defines an interface for commands so we can utilize a command pattern to more easily undo moves in the future, or log games!
 * @date    2025-03-27
 * @version 1.0
 * @copyright MIT License
 */

namespace Chess::Commands
{
	class IMoveCommand
	{
	public:
		virtual ~IMoveCommand() = default;

		virtual void Execute(Board& board) = 0;
		virtual void Undo(Board& board) = 0;
	};
}

#endif