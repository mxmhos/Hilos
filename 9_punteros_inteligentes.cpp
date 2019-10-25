#include <memory>
#include <iostream>

#define N 10

using namespace std;

class Punto {

	friend ostream & operator<<(ostream &os, const Punto &p){
		return os << "[x = " << p.x << ", y = " << p.y << "]";
	}

	int x, y;
	

	public:
		Punto(int _x=0,int _y=0):x(_x),y(_y){}	
		int getX(){ return this->x; }
		int getY(){ return this->y; }				
};

void test_ptr_int();
void test_ptr_int_2();

void test_array_int();
//void test_tabla_int();
//void test_tabla_int_2();

void test_ptr_Punto();
void test_array_Puntos();

void test_check_null();



int main(){
	test_check_null();
	test_ptr_int();
	test_ptr_int_2();
	test_array_int();
	//test_tabla_int();
	//test_tabla_int_2();
	test_ptr_Punto();
	test_array_Puntos();
}


void test_check_null(){
	cout << endl << "Check a null" << endl;
	unique_ptr<int> num = nullptr;

	if (num == nullptr)
		cout << "Smart pointer is null" << endl;
	else
		cout << "No es null" << endl;


	auto pp = make_unique<double>(7.99);
	cout << endl << "pp con auto: " << *pp << endl;


}

void test_ptr_int_2(){
	cout << endl << "TEST PUNTERO A INT 2:" << endl;
	int *num = new int(10);

	// Construye a partir de un puntero ya reservado:
	unique_ptr<int> p2(num);

	cout << "p2: " << *p2 << endl;
	*p2 = 1;
	
	cout << "p2 modificado: " << *p2 << endl;

	*num = 2;
	cout << "p2 modificado con *num: " << *p2 << endl;
}

/*
void test_tabla_int_2(){
	cout << endl << "TEST TABLA DE INT V2:" << endl;
		
	// Definicion de la tabla:
	unique_ptr<int*[]> tabla(new int*[5]);
	
	for(int i = 0 ; i < 5 ; i++){
		unique_ptr fila = make_unique<int []>(5);

		for(int j = 0; j < 5 ; j++)
			fila[j]=0;		
				
	
		// Asignar cada fila a cada posicion de la tabla
		tabla[i] = &fila[0];

		// Chequeo de cada fila de la tabla:
		cout << "Chequeo de la FILA: " << i << " de la tabla:" << endl;
		for (int k = 0 ; k < 5 ; k++)
			cout << *tabla[k] << ", ";

		cout << endl;
		
	}
	cout<<endl;

	cout << endl << "Tabla final V2:" << endl;
	for(int i = 0 ; i < 5 ; i++){	
		for(int j = 0 ; j < 5 ; j++)
			cout << tabla[i][j] << " ";
		cout << endl;
	}
}



void test_tabla_int(){
	cout << endl << "TEST TABLA DE INT:" << endl;
	
	
	unique_ptr<int*[]> smp_pi(new int*[5]);
	int counter=0;	
	for(int j=0;j<5;j++){
		unique_ptr<int[]> smp_i(new int[5]);		
		for(int k=0;k<5;k++){
			smp_i[k]=counter+k;		
			cout<<smp_i[k]<<" ";
		}
		counter=counter+5;
		cout<<endl;
		smp_pi[j]=&smp_i[0];
		//smp_pi[j]=smp_i; //this does not compile. why?
	}
	cout<<endl;

	cout << endl << "Tabla final:" << endl;
	for(int j=0;j<5;j++){	
		for(int k=0;k<5;k++)
			cout<<smp_pi[j][k]<<" ";
		cout<<endl;
	}

}
*/

void test_array_int(){
	cout << endl << "TEST ARRAY DE INT:" << endl;
	unique_ptr array = make_unique<int []>(N);

	for (int i = 0 ; i < N ; i++)
		array[i] = i+1;

	for (int i = 0 ; i < N ; i++)
		cout << array[i] << ", ";
	cout << endl;
}


void test_array_Puntos(){
	cout << endl << "TEST ARRAY DE PUNTOS:" << endl;
	unique_ptr array = make_unique<Punto []>(N);

	for (int i = 0 ; i < N ; i++)
		cout << array[i] << endl;
	cout << endl;
}


void test_ptr_Punto(){
	cout << endl << "TEST PUNTERO A OBJETO PUNTO:" << endl;
	unique_ptr<Punto> ppunto = make_unique<Punto>(5,-8);
	cout << "X: " << ppunto->getX() << endl;
	cout << "Y: " << ppunto->getY() << endl;
	
	cout << "Punto: " << *ppunto << endl;
}

void test_ptr_int(){
	cout << endl << "TEST PUNTERO A INT:" << endl;
	unique_ptr<int> num = make_unique<int>();
	cout << "Valor de num: " << *num << endl;

	unique_ptr<int> num2 = make_unique<int>(100);
	cout << "Valor de num2: " << *num2 << endl;

	*num2 = 99;
	cout << "Valor de num2: " << *num2 << endl;
}

