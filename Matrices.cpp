#include<iostream>
using namespace std;


class Diagonal {
	private:
		int *A;
		int dim;

	public:
		Diagonal(int dim) {
			this->dim = dim;
			A = new int[dim];
		}


		void set(int i, int j, int x) {
			if(i==j) {
				A[i-1]=x;
			} else {
				cout << "check your dimensions" << endl;
			}
		}
		void get(int i, int j) {
			if(i==j) {
				cout << A[i-1] << endl;
			} else {
				cout << "0" << endl;
			}
		}
		void display() {
			for(int i=0; i<dim; i++) {
				for(int j=0; j<dim; j++) {
					if(i==j) {
						cout << A[i] << " ";
					} else {
						cout << "0 ";
					}
				}
				cout << endl;
			}
		}
		~Diagonal() {
			cout << "Destructing the Diagonal class " << endl;
			delete []A;
		}
};

class Lower {
	private:
		int *A;
		int dim;

	public:
		Lower(int dim) {
			this->dim = dim;
			A = new int[dim*(dim+1)/2];
		}


		void set(int i, int j, int x) {
			if(i>=j) {
				A[i*(i-1)/2 + j-1]=x;
			} 
		}
		void get(int i, int j) {
			if(i>=j) {
				cout << A[i*(i-1)/2 + j-1] << endl;
			} else {
				cout << "0" << endl;
			}
		}
		void display() {
			for(int i=1; i<=dim; i++) {
				for(int j=1; j<=dim; j++) {
					if(i>=j) {
						cout << A[i*(i-1)/2 + j-1] << " ";
					} else {
						cout << "0 ";
					}
				}
				cout << endl;
			}
		}
		~Lower() {
			cout << "Destructing the Lower class " << endl;
			delete []A;
		}
};

class Upper {
	private:
		int *A;
		int dim;

	public:
		Upper(int dim) {
			this->dim = dim;
			A = new int[dim*(dim+1)/2];
		}


		void set(int i, int j, int x) {
			if(j>=i) {
				A[j*(j-1)/2 + i-1]=x;
			} 
		}
		void get(int i, int j) {
			if(j>=i) {
				cout << A[j*(j-1)/2 + i-1] << endl;
			} else {
				cout << "0" << endl;
			}
		}
		void display() {
			for(int i=1; i<=dim; i++) {
				for(int j=1; j<=dim; j++) {
					if(j>=i) {
						cout << A[j*(j-1)/2 + i-1] << " ";
					} else {
						cout << "0 ";
					}
				}
				cout << endl;
			}
		}
		~Upper() {
			cout << "Destructing the Upper class " << endl;
			delete []A;
		}
};


int main() {
	
//	Diagonal m(4);
//	m.set(1,1,4);
//	m.set(2,2,5);
//	m.set(3,3,6);
//	m.set(4,4,7);
//	m.get(2,2);
//	m.display();

//	Lower m(5);
//	int value;
//	for(int i=1; i<=5; i++)
//	{
//		for(int j=1; j<=5;j++)
//		{
//			scanf("%d",  &value);
//			m.set(i,j,value);
//		}
//	}
//	m.get(2,2);
//	m.display();

	Upper m(5);
	int value;
	for(int i=1; i<=5; i++)
	{
		for(int j=1; j<=5;j++)
		{
			scanf("%d",  &value);
			m.set(i,j,value);
		}
	}
	m.get(2,2);
	m.display();

}

