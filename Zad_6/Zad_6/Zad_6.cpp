#include "pch.h"

using namespace std;


class Matrix
{
public:

	int i;
	int j;
	float **matrix_values;

	Matrix(int x, int y);
	Matrix(string);

	float changeCellValue(int x, int y, float newValue);
	string returnCell(int x, int y);
	string returnRow(int y);
	string returnColumn(int x);
	string returnMatrix();

	void addNumber(int number);
	void transpose();
	void saveToFile(string);
};

Matrix::Matrix(int x, int y)	//tworzenie macierzy o podanych rozmiarach i wpisanie do komórek wartości domyślnej 0
{
	i = x;
	j = y;

	matrix_values = new float*[i];

	for (int a = 0; a < i; a++)
	{
		matrix_values[a] = new float[j];
	}

	for (int a = 0; a < i; a++)
	{
		for (int b = 0; b < j; b++)
		{
			matrix_values[a][b] = 0;
		}
	}
}

float Matrix::changeCellValue(int x, int y, float newValue)		//zmiana wartości dowolnej komórki
{
	matrix_values[x][y] = newValue;

	return newValue;
}

string Matrix::returnCell(int x, int y)		//zwrócenie dla podanej komórki
{
	string cell_string = to_string(matrix_values[x][y]);
	return cell_string;
}

string Matrix::returnRow(int x)		//zwrócenie dla podanego wiersza
{
	string line;
	for (int a = 0; a < j; a++)
	{
		line += returnCell(x, a);
		line += "    ";
	}
	return line;
}

string Matrix::returnColumn(int y)	//zwrócenie dla podanej kolumny
{
	string column;
	for (int a = 0; a < i; a++)
	{
		column += returnCell(a, y);
		column += '\n';
	}
	return column;
}

string Matrix::returnMatrix()		//zwrócenie macierzy
{
	string matrix;
	for (int a = 0; a < i; a++)
	{
		matrix += returnRow(a);
		matrix += '\n';
	}
	return matrix;
}

void Matrix::addNumber(int number)		//dodanie liczby do elementów macierzy
{
	for (int a = 0; a < i; a++)
	{
		for (int b = 0; b < j; b++)
		{
			matrix_values[a][b] += number;
		}
	}
}

void Matrix::transpose()		//zamiana na macierz transponowaną
{
	Matrix *temp = new Matrix(j, i);
	for (int a = 0; a < j; a++)
	{
		for (int b = 0; b < i; b++)
		{
			temp->matrix_values[a][b] = matrix_values[b][a];
		}
	}
	i = temp->i;
	j = temp->j;
	matrix_values = temp->matrix_values;
	delete temp;
}

Matrix::Matrix(string file_name)		
{
	ifstream file;
	string line;
	int rows = 0;

	file.open(file_name.c_str(), ios::in);            // zliczenie wierszy z pliku
	while (!file.eof())
	{
		getline(file, line);
		rows++;
	}
	file.close();

	vector <float> v1;     // wektor przechowujacy l. rzeczywiste z jednego wiersza
	string temp = "";
	float value;
	float **temp_values;
	temp_values = new float*[rows];
	int help = 0;                            

	file.open(file_name.c_str(), ios::in);
	while (!file.eof())
	{
		getline(file, line);
		for (int m = 0; line[m] != ';'; m++)
		{
			if (line[m] != ' ') temp += line[m];
			else
			{
				istringstream iss(temp);
				iss >> value;
				v1.push_back(value);
				temp = "";
			}
		}

		i = rows;

		if (help == 0)
		{
			j = v1.size();
			for (int a = 0; a < i; a++)
			{
				temp_values[a] = new float[j];
			}
		}
		for (int a = 0; a < j; a++)
		{
			temp_values[help][a] = v1[a];
		}
		v1.clear();
		help++;
	}
	file.close();

	matrix_values = new float*[i];
	for (int a = 0; a < i; a++)
	{
		matrix_values[a] = new float[j];
	}

	for (int a = 0; a < i; a++)
	{
		for (int b = 0; b < j; b++)
		{
			matrix_values[a][b] = temp_values[a][b];
		}
	}
	delete temp_values;
}

void Matrix::saveToFile(string save_to_file)
{
	ofstream file1(save_to_file.c_str());

	for (int a = 0; a < i; a++)
	{
		for (int b = 0; b < j; b++)
		{
			file1 << matrix_values[a][b];
			if (b < j - 1) file1 << " ";
		}
		file1 << " ;"; if (a < i - 1) file1 << endl;
	}

}

int main()
{

	Matrix *matrix1 = new Matrix("test.txt");
	string name;


	matrix1->changeCellValue(0, 0, 7);
	matrix1->changeCellValue(1, 1, 7);
	matrix1->changeCellValue(2, 2, 7);

	cout << matrix1->returnCell(0, 0) <<  endl;
	cout << matrix1->returnColumn(0) <<  endl;
	cout << matrix1->returnRow(2) <<  endl;
	cout << matrix1->returnMatrix() <<  endl;

	time_t t = time(0);
	struct tm now; 
	localtime_s(&now, &t);
	string time;
	ostringstream ss;
	ss << now.tm_hour << now.tm_min << now.tm_sec;
	time = ss.str();

	string save_to_file = "macierz1_";
	save_to_file += time + ".txt";

	matrix1->saveToFile(save_to_file);

	Matrix *matrix2 = new Matrix(save_to_file);

	matrix2->transpose();

	save_to_file = "macierz2_";
	save_to_file += time + ".txt";
	matrix2->saveToFile(save_to_file);

	Matrix *matrix3 = new Matrix(save_to_file);

	matrix3->addNumber(7);

	save_to_file = "macierz3_";
	save_to_file += time + ".txt";
	matrix3->saveToFile(save_to_file);

	return 0;
}