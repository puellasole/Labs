#include<iostream>
#include<fstream>
#include "lab6/Logger.hpp"
#include<chrono>

int main()
{
	esp::Log log1(esp::LogType::ERROR);
	esp::Log log2(esp::LogType::INFO);
	esp::Log log3(esp::LogType::DEBUG);

	esp::Log::SetLogPath("log.txt");
	esp::Log::SetLodLvl(esp::LogLvl::DEBUG);

	esp::Log::Write(log1, "Hello, world");
	esp::Log::Write(log2, "Other another");
	esp::Log::Write(log3, "debUg");
}
