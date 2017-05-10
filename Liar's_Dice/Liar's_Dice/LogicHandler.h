#pragma once
class LogicHandler
{
public:
	LogicHandler();
	~LogicHandler();

	bool vecContentEqual(std::vector<int>, std::vector<int>);
	bool vecContains(std::vector<int>*, int);
};

