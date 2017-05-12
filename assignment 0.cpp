#include <iostream>
#include <math.h>
using namespace std;
//this program solves the entire problem
int main(){
	//input degree of desired fit
	int deg;
	cout << "Degree of polynomial?" << endl;
	cin >> deg;
	deg++; //add 1 to degree for constant term
	//input number of x and y value pairs
	int length;
	cout << "Number of values?" << endl;
	cin >> length;
	double x[length][1];
	//input x values
	cout << "Enter x values" << endl;
	for (int i = 0;i<length;i++) {
		cin >> x[0][i];
	}
	//display x values
	cout << "x values:" << endl;
	for (int j = 0;j<length;j++){
		cout << x[0][j] << ' ';
	}
	cout << endl;
	//input y values
	double y[length][1];
	cout << "Enter y values" << endl;
	for (int i = 0;i<length;i++) {
		cin >> y[0][i];
	}
	//display y values
	cout << "y values:" << endl;
	for (int j = 0;j<length;j++){
		cout << y[0][j] << ' ';
	}
	cout << endl;
	//create Vandermonde matrix
	double V[length][deg];
	for (int i = 0;i<length;i++){
		for (int j = 0;j<deg;j++){
			V[i][j] = pow(x[0][i],j);
		}
	}
	//display Vandermonde matrix
	cout << "Vandermonde matrix (V):" << endl;
	for (int i = 0;i<length;i++){
		for (int j = 0;j<deg;j++){
			cout << V[i][j] << ' ';
		}
		cout << endl;
	}
	//transpose Vandermonde matrix
	int row = length;
	int column = deg;
	double Vt[column][row];
	for (int i = 0;i<column;i++){
		for (int j = 0;j<row;j++){
			Vt[i][j] = V[j][i];
		}
	} 
	//display Vandermonde matrix transpose
	cout << "Vandermonde matrix transpose (Vt):" << endl;
	for (int i = 0;i<deg;i++){
		for (int j = 0;j<length;j++){
			cout << Vt[i][j] << ' ';
		}
		cout << endl;
	}
	//matrix product of Vandermonde matrix and its transpose
	int rowa = deg;
	int columna = length;
	int rowb = length;
	int columnb = deg;
	double product[rowa][columnb];
	for (int i = 0;i<rowa;i++){
		for (int j = 0;j<columnb;j++){
			double sum = 0;
			for (int k = 0;k<columna;k++){
				sum = sum+Vt[i][k]*V[k][j]; //sum products along relevant row and column
			}
			product[i][j] = sum;
		}
	}
	//display matrix product
	cout << "Product of Vt*V:" << endl;
	for (int i = 0;i<deg;i++){
		for (int j = 0;j<deg;j++){
			cout << product[i][j] << ' ';
		}
		cout << endl;
	}
	//invert matrix product
	row = deg;
	column = deg;
	//left side of augmented matrix is product
	double invertProduct[row][row] = {0}; //right side of augmented matrix
	for (int i = 0;i<row;i++){
		invertProduct[i][i] = 1; //initialize identity matrix
	}
	//reduce all terms not along the diagonal to 0
	for (int i = 0;i<column;i++){
		for (int j = 0;j<row;j++){
			if (j!=i){
				double coeff = product[j][i]/product[i][i]; //find coefficient to multiply row by
				for (int k = 0;k<column;k++){
					//apply operation to both left and right side
					product[j][k] = product[j][k]-product[i][k]*coeff; 
					invertProduct[j][k] = invertProduct[j][k]-invertProduct[i][k]*coeff;
				}
			}
		}
	}
	//reduce left side to identity matrix
	for (int i = 0;i<row;i++){
		for (int j = 0;j<column;j++){
			if (i==j){
				double coeff = 1/product[i][j]; //find coefficient to multiply row by
				for (int k = 0;k<column;k++){
					//apply operation to both left and right side
					product[i][k] = product[i][k]*coeff; 
					invertProduct[i][k] = invertProduct[i][k]*coeff;
				}
			}
		}
	}
	//display inverse
	cout << "Inverse of product of Vt*V:" << endl;
	for (int i = 0;i<deg;i++){
		for (int j = 0;j<deg;j++){
			cout << invertProduct[i][j] << ' ';
		}
		cout << endl;
	}
	//execute the formula: c = inv*Vt*y'
	//multiply inverse and Vandermonde transpose
	rowa = deg;
	columna = deg;
	rowb = deg;
	columnb = length;
	double placeholder[rowa][columnb];
	for (int i = 0;i<rowa;i++){
		for (int j = 0;j<columnb;j++){
			double sum = 0;
			for (int k = 0;k<columna;k++){
				sum = sum+invertProduct[i][k]*Vt[k][j]; //sum products along relevant row and column
			}
			placeholder[i][j] = sum;
		}
	}
	//transpose y values
	row = 1;
	column = length;
	double yt[column][row];
	for (int i = 0;i<column;i++){
		for (int j = 0;j<row;j++){
			yt[i][j] = y[j][i];
		}
	} 
	//multiply product from above and transposed y values
	rowa = deg;
	columna = length;
	rowb = length;
	columnb = 1;
	double output[rowa][columnb];
	for (int i = 0;i<rowa;i++){
		for (int j = 0;j<columnb;j++){
			double sum = 0;
			for (int k = 0;k<columna;k++){
				sum = sum+placeholder[i][k]*yt[k][j]; //sum products along relevant row and column
			}
			output[i][j] = sum;
		}
	}
	//output coefficients
	cout << "Polynomial coefficients (lowest to highest degree, top to bottom):" << endl;
	for (int i = 0;i<deg;i++){
		cout << output[i][0] << ' ';
		cout << endl;
	}
	return 0;
}
