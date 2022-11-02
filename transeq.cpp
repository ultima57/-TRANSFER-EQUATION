#include <iostream>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <fstream>
#include "newton.h"
#define N 300
#define K 300
#define eps 0.00000001
#define pi 3.14159265359
using namespace std;
double newton1(double x, double x0, double x1, double tau, double h);
int main() {
	double tau = 1 / ((double)K), h = 1 / ((double)N);
	cout << "tau=" << tau;
	cout << tau;
	ofstream fout("4p0int.txt");
	double u[N][K];
	double x = 0.001;
	int a = 0;
	for (int i = 0; i < N; i++) {
		u[i][0] = sin(pi * i * h);
		if (a % 3 == 0) {
			fout << i * h << " " << 0 << " " << u[i][0] << "\n";
			cout << a << " ";
		}
		a++;
	}
	for (int i = 0; i < K; i++) {
		u[0][i] = exp(-tau * i) - 1;
		if (a % 3 == 0)
			fout << 0 << " " << i * tau << " " << u[0][i] << "\n";
		a++;
	}
	a = 0;
	int c;

	cout << "1 для В 2 для Г";
	cin >> c;
	if (c == 1) {
		for (int k = 1; k < K; k++) {

			for (int j = 1; j < N; j++) {


				u[i][k] = newton 1(u[i][k - 1], u[i][k - 1], u[j - 1][k], tau, h);
				if ((j % 3 == 0) && (k % 3 == 0))
					fout << j * h << " " << k * tau << " " << u[j][k] << "\n";
			}
		}
	}
	if (c == 2) {
		for (int k = 1; k < K; k++) {
			for (int j = 1; j < N; j++) {
				u[i][k] = newton 2(u[i][k - 1], u[j - 1][k - 1], u[j - 1][k], u[j][k - 1], tau, h);
				if ((j % 3 == 0) && (k % 3 == 0))
					fout << j * h << " " << k * tau << " " << u[j][k] << "\n";
			}
		}
	}
		fout.close();

	}