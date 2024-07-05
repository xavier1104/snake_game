#pragma once

class Part;
class Snake
{
public:
	Snake();
	~Snake();

	vector<shared_ptr<Part>> GetParts() { return parts_; }

private:
	vector<shared_ptr<Part>> parts_;
};