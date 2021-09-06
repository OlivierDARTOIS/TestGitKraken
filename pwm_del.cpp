#include <iostream>
#include <wiringPi.h>

using namespace std;

const int BROCHE_DEL = 18;

int main()
{
	int pause = 100;

	cout << "--- Debut prog" << endl;
	cout << "Duree en ms de la pause : ";
	cin >> pause;
	wiringPiSetupGpio();
	pinMode(BROCHE_DEL, PWM_OUTPUT);

	int pas=1;
	int i=0;
	while (true)
	{
		pwmWrite(BROCHE_DEL, i);
		delay(pause);
		i+= pas;
		if (i == 1024) pas =-1;
		if (i == 0)    pas = 1;
	}

	return 0;
}

