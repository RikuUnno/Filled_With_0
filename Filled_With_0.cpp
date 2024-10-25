#include <iostream>
#include <iomanip>

using namespace std;

void Show(int* time, int& seconds, int& minutes, const int ONE_MINUTE );
void FilledWith0(int* time, int& seconds, int& minutes, const int ONE_MINUTE );

void FilledWith0(int *time, int& seconds, int& minutes, const int ONE_MINUTE)
{
	if (*time >= 60)
	{
		minutes = *time / ONE_MINUTE;
		seconds = *time % ONE_MINUTE;
	}
	Show(time, seconds, minutes, ONE_MINUTE);
}

void Show(int *time, int& seconds, int& minutes, const int ONE_MINUTE)
{
	if (*time >= ONE_MINUTE)
	{
		cout << minutes << ':' << flush;
		if (0 <= seconds && seconds < 10 || *time % ONE_MINUTE == 0)
		{
			cout << setw(2) << setfill('0') << flush;
		}
		cout << seconds << "秒" << endl;
	}
	else
	{
		cout << "0:" << flush;
		if (0 <= *time && *time < 10)
		{
			cout << setw(2) << setfill('0') << flush;
		}
		cout << *time << "秒" << endl;
	}
}

int main()
{
	int time = 0;
	int seconds = 0;
	int	minutes = 0;
	const int ONE_MINUTE = 60;

	cout << "秒数を入力してください。" << endl;
	cin >> time;

	cout << endl;

	FilledWith0(&time, seconds, minutes, ONE_MINUTE);
}