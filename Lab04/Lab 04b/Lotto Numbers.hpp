#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void LottoNumbers()
{
	int* lottoNumbers = nullptr;
	int lottoBalls = 0;

	cout << "How many balls are in this lottery?" << endl;
	cin >> lottoBalls;
	lottoNumbers = new int[lottoBalls];

	cout << "Lottery numbers are: \n";

	for (int i = 0; i < lottoBalls; i++)
	{
		lottoNumbers[i] = rand() % 100;

		cout << lottoNumbers[i] << "\t";
	}

	cout << endl << endl;

	delete lottoNumbers;
	lottoNumbers = nullptr;

}
