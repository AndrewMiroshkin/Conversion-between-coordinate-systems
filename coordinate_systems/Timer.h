#pragma once
#include <iostream>
#include <chrono>

class Timer {
private:
	std::chrono::time_point<std::chrono::steady_clock> start, end;

public:
	Timer() { 
		start = std::chrono::high_resolution_clock::now(); 
	}

	~Timer(){
		end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration = end - start;
		std::cout << "Execution time: " << duration.count()<< " sec\n";
	}
};