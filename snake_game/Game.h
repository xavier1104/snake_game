#pragma once

class Player;
class Board;
class Snake;
class Game
{
public:
	Game();
	~Game();

	bool IsRunning() { return isRunning_; }
	void Update();
	void Init();

	shared_ptr<Snake> GetSnake() { return snake_; }
	shared_ptr<Board> GetBoard() { return board_; }
	shared_ptr<Player> GetPlayer() { return player_; }
private:
	bool isRunning_;
	shared_ptr<Player> player_;
	shared_ptr<Board> board_;
	shared_ptr<Snake> snake_;
};