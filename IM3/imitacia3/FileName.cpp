#include<iostream>
#include <iomanip>
#include <random>
#include <fstream>

using namespace std;

fstream f;

float* overflow_random(int n, int seed) {
	float* r = new float[n];
	int y;

	for (int i = 0; i < n; i++) {
		y = seed * 1220703125;
		if (y < 0)
			y += 2 * 1073741824;
		r[i] = y * 0.0000000004656613;
		seed = y;
	}
	return r;
}




int main() {
	setlocale(LC_ALL, "Russian");

	f.open("out_file.xls", ios::out);




	const int n = 1000; // ���������� ��������������� �����
	const int seed = 36426;
	float* mas; //������ ��� �������� ��������������� ��������

	//�������� ��� ������ ���� 
	const int num_buckets = 10;
	int buckets[num_buckets] = { 0 };
	int buckets2[num_buckets] = { 0 };

	//���� ����� ����������� ���������	
	mas = overflow_random(n, seed);
	cout << "   C��� ����� ����������� ���������\n";
	f << "C��� ����� ����������� ���������\n";
	for (int i = 0; i < n; i++) {
		if (i % 10 == 0) cout << "\n";
		cout << setw(11) << mas[i] << " ";
		f  << mas[i] << endl;

		//������ ���� �������
		int bucket_num = static_cast<int>(mas[i] * num_buckets);
		buckets[bucket_num]++;
	}
	cout << "\n\n";

	// ������ ����������� ��������
	cout << "�������� �������������: \n";
	for (int i = 0; i < num_buckets; ++i) {
		std::cout << "[" << (i * 0.1) << " - " << ((i + 1) * 0.1) << "): " << std::string(buckets[i], '*') << std::endl;
	}



	
	//������������ ����� 
	cout << "\n\n   ������������ ����� ����������� ���������\n";
	f << "������������ ����� ����������� ���������\n";
	double x;
	srand(seed);
	
	for (int i = 0; i < n; i++) {
		if (i % 10 == 0) cout << "\n";
		x = (double)rand() / (RAND_MAX);
		cout << setw(11) << x << " ";
		f << x << endl;

		//������ ���� �������
		int bucket_num = static_cast<int>(x * num_buckets);
		buckets2[bucket_num]++;
	}
	cout << "\n\n";

	// ������ ����������� ��������
	cout << "�������� �������������: \n";
	for (int i = 0; i < num_buckets; ++i) {
		std::cout << "[" << (i * 0.1) << " - " << ((i + 1) * 0.1) << "): " << std::string(buckets2[i], '*') << std::endl;
	}
	


 	f.close();

	system("pause");
}