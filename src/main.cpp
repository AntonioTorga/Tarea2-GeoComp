#include <iostream>
#include <vector>
#include "Utils.h"
#include "Poligono.h"
#include <chrono>
#include <fstream>

std::vector<int> N_TESTS = {10, 100, 1000, 10000, 100000};
std::vector<double> PCTG_TESTS = { 5,10,20,30, 40, 50};
std::vector<double> TIME_RESULTS_GS_RANDOM;
std::vector<double> TIME_RESULTS_GW_RANDOM;
std::vector<std::vector<double>> TIME_RESULTS_GS_SEMI_RANDOM(N_TESTS.size());
std::vector<std::vector<double>> TIME_RESULTS_GW_SEMI_RANDOM(N_TESTS.size());



int main() {
	std::cout << std::fixed;
	for (int i = 0; i < N_TESTS.size(); i++) {
		std::cout << "-------------TEST N " << i << ", Amount of points in cloud: "<< N_TESTS[i] << "------"<<std::endl;
		std::cout << "Creating cloud of "<<N_TESTS[i]<< " random points" << std::endl;
		std::vector<Punto<long long>> random_cloud = randomPoints(N_TESTS[i], N_TESTS[i] * 40);

		Timer timer;
		
		timer.startTimer();
		Poligono<long long> gs_result = grahamScan(random_cloud);
		timer.stop();

		TIME_RESULTS_GS_RANDOM.push_back(timer.getDuration());
		std::cout << "Graham Scan duration: " << timer.getDuration() << std::endl;
		std::cout << "Amount of points in convex hull: " << gs_result.get_vertices().size() << std::endl;

		timer.startTimer();
		Poligono<long long> gf_result = giftWrapping(random_cloud);
		timer.stop();

		TIME_RESULTS_GW_RANDOM.push_back(timer.getDuration());
		std::cout << "Gift Wrapping duration: " << timer.getDuration() << std::endl;
		std::cout << "Amount of points in convex hull: " << gf_result.get_vertices().size() << std::endl;
		
		std::cout << "--Different convex hull points percentage tests --" << std::endl;
		for (int j = 0; j < PCTG_TESTS.size(); j++) {
			std::cout << "Creating cloud of " << N_TESTS[i] << " random points with " << PCTG_TESTS[j] << "% of points on the CH." << std::endl;
			std::vector<Punto<long long>> semi_random_cloud = semiRandomPoints(N_TESTS[i] ,PCTG_TESTS[j], N_TESTS[i]*1000);

			timer.startTimer();
			Poligono<long long> gs_result_src = grahamScan(semi_random_cloud);
			timer.stop();

			TIME_RESULTS_GS_SEMI_RANDOM[i].push_back(timer.getDuration());
			std::cout << "Graham Scan. Duration: " << timer.getDuration() << std::endl;
			std::cout << "Amount of points in convex hull: " << gs_result_src.get_vertices().size() << std::endl;

			timer.startTimer();
			Poligono<long long> gf_result_src = giftWrapping(semi_random_cloud);
			timer.stop();

			TIME_RESULTS_GW_SEMI_RANDOM[i].push_back(timer.getDuration());
			std::cout << "Gift Wrapping. Duration: " << timer.getDuration() << std::endl;
			std::cout << "Amount of points in convex hull: " << gf_result_src.get_vertices().size() << std::endl;
		}
	}
	//write results to file
	std::ofstream file;
	file.open("results.txt");
	file << "Graham Scan Random Clouds" << std::endl;
	for (int i = 0; i < TIME_RESULTS_GS_RANDOM.size(); i++) {
		file << TIME_RESULTS_GS_RANDOM[i] << std::endl;
	}
	file << "Gift Wrapping Random Clouds" << std::endl;
	for (int i = 0; i < TIME_RESULTS_GW_RANDOM.size(); i++) {
		file << TIME_RESULTS_GW_RANDOM[i] << std::endl;
	}
	file << "Graham Scan Semi Random Clouds" << std::endl;
	for (int i = 0; i < TIME_RESULTS_GS_SEMI_RANDOM.size(); i++) {
		for (int j = 0; j < TIME_RESULTS_GS_SEMI_RANDOM[i].size(); j++) {
			file << TIME_RESULTS_GS_SEMI_RANDOM[i][j] << std::endl;
		}
	}
	file << "Gift Wrapping Semi Random Clouds" << std::endl;
	for (int i = 0; i < TIME_RESULTS_GW_SEMI_RANDOM.size(); i++) {
		for (int j = 0; j < TIME_RESULTS_GW_SEMI_RANDOM[i].size(); j++) {
			file << TIME_RESULTS_GW_SEMI_RANDOM[i][j] << std::endl;
		}
	}
	file.close();
	return 0;
}