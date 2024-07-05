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
private:
	bool isRunning_;
	shared_ptr<Player> player_;
	shared_ptr<Board> board_;
	shared_ptr<Snake> snake_;
};