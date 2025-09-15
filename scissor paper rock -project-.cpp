#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

enum enGame { Stone = 1, Paper = 2, Scissor = 3 };
enum enWhoWin { Player = 1, Computer = 2, Draw = 3 };

int RandomNum(int from, int to) {
	return rand() % (to - from + 1) + from;
}

enGame ComputerRound(enGame& Computer) {
	Computer = (enGame)RandomNum(1, 3);
	return Computer;
}

enGame PlayerRound(enGame& Player) {
	int choice;
	cout << "\n\nYour Choice | 1:Stone | 2:Paper | 3:Scissor | ? : ";
	cin >> choice;
	Player = (enGame)choice;
	return Player;
}

enWhoWin WhoWin(enGame Player, enGame Computer, int& PW, int& CW, int& D) {
	if (Computer == enGame::Paper && Player == enGame::Paper) { D++; return enWhoWin::Draw; }
	if (Computer == enGame::Paper && Player == enGame::Scissor) { PW++; return enWhoWin::Player; }
	if (Computer == enGame::Paper && Player == enGame::Stone) { CW++; return enWhoWin::Computer; }
	if (Computer == enGame::Scissor && Player == enGame::Paper) { CW++; return enWhoWin::Computer; }
	if (Computer == enGame::Scissor && Player == enGame::Scissor) { D++; return enWhoWin::Draw; }
	if (Computer == enGame::Scissor && Player == enGame::Stone) { PW++; return enWhoWin::Player; }
	if (Computer == enGame::Stone && Player == enGame::Paper) { PW++; return enWhoWin::Player; }
	if (Computer == enGame::Stone && Player == enGame::Scissor) { CW++; return enWhoWin::Computer; }
	if (Computer == enGame::Stone && Player == enGame::Stone) { D++;  return enWhoWin::Draw; }
	return enWhoWin::Draw;
}
string GetChoiceName(enGame c) {
	switch (c)
	{
	case enGame::Stone: return "Stone";
		break;
	case enGame::Paper: return "Paper";
		break;
	case enGame::Scissor: return "Scissor";
		break;
	}
	return "Unknown";
}
string GetResult(enWhoWin w) {
	switch (w)
	{
	case enWhoWin::Player: return"Player";
		break;
	case enWhoWin::Computer: return"Computer";
		break;
	case enWhoWin::Draw: return "Draw";
		break;
	}
	return "Unknown";
}
void ShowResult(enWhoWin W, enGame Player, enGame Computer, int Round) {
	if (W == enWhoWin::Computer)
	{
		cout << "\a";
		system("color 4f");
		cout << "\n";
		cout << "--------------------Round[" << Round + 1 << "]-----------------------\n"
			<< "Player choice is : " << GetChoiceName(Player) << "\n"
			<< "Computer choise is : " << GetChoiceName(Computer) << "\n"
			<< "Round winner is : [" << GetResult(W) << "]\n"
			<< "--------------------------------------------------------------------\n";
	}
	else if (W == enWhoWin::Draw)
	{
		system("color 6f");
		cout << "\n";
		cout << "--------------------Round[" << Round + 1 << "]-----------------------\n"
			<< "Player choice is : " << GetChoiceName(Player) << "\n"
			<< "Computer choise is : " << GetChoiceName(Computer) << "\n"
			<< "Round winner is : [" << GetResult(W) << "]\n"
			<< "--------------------------------------------------------------------\n";
	}
	else
	{
		system("color af");
		cout << "\n";
		cout << "--------------------Round[" << Round + 1 << "]-----------------------\n"
			<< "Player choice is : " << GetChoiceName(Player) << "\n"
			<< "Computer choise is : " << GetChoiceName(Computer) << "\n"
			<< "Round winner is : [" << GetResult(W) << "]\n"
			<< "--------------------------------------------------------------------\n";
	}
}
enWhoWin FinalWinner(int pw, int cw, int d) {
	if (pw > cw)
	{
		return enWhoWin::Player;
	}
	else if (cw > pw)
	{
		return enWhoWin::Computer;
	}
	else
	{
		return enWhoWin::Draw;
	}

}
void ShowFinalResult(int pw, int cw, int d, int r) {
	enWhoWin Final = FinalWinner(pw, cw, d);
	string W = GetResult(Final);
	cout << "\t\t---------------------------GAME OVER---------------------------\n"
		<< "\t\t--------------------------GAME RESULT--------------------------\n"
		<< "\t\tRounds : " << r << endl
		<< "\t\tPlayer Win : " << pw << endl
		<< "\t\tComputer win : " << cw << endl
		<< "\t\tDraw time : " << d << endl
		<< "\t\tFinal Winner : " << W << endl
		<< "\t\t----------------------------------------------------------------\n";
}
void HowManyRounds() {
	int Rounds, PW = 0, CW = 0, D = 0;
	enGame Player, Computer;
	enWhoWin w;
	cout << "How Many Rounds 1 to 10 ? : ";
	cin >> Rounds;
	int R = 0;
	while (Rounds > R) {

		system("color 0f");
		Player = PlayerRound(Player);
		Computer = ComputerRound(Computer);
		w = WhoWin(Player, Computer, PW, CW, D);
		ShowResult(w, Player, Computer, R);
		system("pause");
		R++;

	}
	ShowFinalResult(PW, CW, D, R);
}

void StartGame() {
	char y;
	do
	{
		system("cls");
		HowManyRounds();
		cout << "\t\tDo You Want To Play Again ? [Y/N] : ";
		cin >> y;
	} while ((y == 'y') || (y == 'Y'));
}
int main()
{
	srand((unsigned)time(NULL));
	StartGame();
}

