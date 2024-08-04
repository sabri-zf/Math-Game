
#include <iostream>
#include<string>

using namespace std;

enum ElvelQuiss { eyes = 1, Mid = 2, Hard = 3, Mix = 4 };
enum EOpration { Add = 1, substract = 2, Multple = 3, divid = 4, eMix = 5 };

struct stQuiss 
{

	short NumberOFquestion = 0;
	ElvelQuiss LevelQuestion;
	EOpration typeOpration;

	short NumberOfTrueAnswer = 0;
	short NumberOfwornigAnswer = 0;

	short scoreGame = 0;

	bool Ispass = false;

};

short RendomNumber(int From, int To) {
	int Value = rand() % ((To - From + 1) + From);
	return Value;
}

void HelloScreen() {

	cout << "\n\n\t\t Hello Wlecome To GAME Math \n";

}

short HowMuchNeedquestion()
{
	short QuissNum = 0;

	do {
		cout << "Enter How Much Need question : ";
		cin >> QuissNum;
	} while (!(QuissNum >= 1 || QuissNum <= 10));

	return QuissNum;

}

short EnterNumber() {
	short value = 0;

	cin >> value;

	return value;
}

ElvelQuiss ShooesLevel() {

	cout << "\nPlease Enter Level  [ 1 Eyes]  [ 2 Mid]  [ 3 Hard]  [ 4 Mix] ";
	return (ElvelQuiss)EnterNumber();

}

EOpration ShooesOpration() {
	cout << "\nPlease Enter Level  [ 1 Add]  [ 2 Sub]   [ 3 Mult]   [ 4 Divd]    [ 5Mix]";
	return (EOpration)EnterNumber();
}

char GetRendomOpration() {
	char ReandomOprt[4] = { '+','-','*','/' };

	return ReandomOprt[RendomNumber(0, 3)];
}

int AnsOfRendomOpration(int A, int B, char Type) {

	switch (Type)
	{
	case '+':
		return A + B;
	case'-':
		return A - B;
	case '*':
		return A * B;
	case '/':
		return A / B;
	}

	return 0;
}
void PrintCalcuation(int A, int B, char Opration) {
	cout << "\t" << A << endl;
	cout << "\t" << B <<" " << Opration << endl;
	cout << "_______________" << endl;
}
bool MixCalc(int ValueA, int ValueB) {

	char typeOpration = GetRendomOpration();
	int Result = 0;
	int TrueAnswer = AnsOfRendomOpration(ValueA,ValueB,typeOpration);
	PrintCalcuation(ValueA, ValueB, typeOpration);

	cout << "The Result Is  = ";
	cin >> Result;

	if (Result != TrueAnswer) {
		system("color 4F");
		cout << "Wornnig  Ansower :( \n";
		cout << "The Right Answer Is = " << TrueAnswer << endl;
		return false;
	}

	system("color 2F");
	cout << "Corract Answer :D\n";

	return true;
}

bool AddationCalc(int ValueA, int ValueB) {

	int Result = 0;
	int TrueAnswer = (ValueA + ValueB);
	PrintCalcuation(ValueA , ValueB,'+');

	cout << "The Result Is  = ";
	cin >> Result;

	if (Result != TrueAnswer) {
		system("color 4F");
		cout << "Wornnig  Ansower :( \n";
		cout << "The Right Answer Is = " << TrueAnswer << endl;
		return false;
	}

	system("color 2F");
	cout << "Corract Answer :D\n";
	 
	return true;
}

bool SubstractionCalc(int ValueA, int ValueB) {

	int Result = 0;
	int TrueAnswer = (ValueA - ValueB);
	PrintCalcuation(ValueA, ValueB, '-');

	cout << "The Result Is  = ";
	cin >> Result;

	if (Result != TrueAnswer) {
		system("color 4F");
		cout << "Wornnig  Ansower :( \n";
		cout << "The Right Answer Is = " << TrueAnswer << endl;
		return false;
	}

	system("color 2F");
	cout << "Corract Answer :D\n";
	return true;
}

bool MultiplactionCalc(int ValueA, int ValueB) {

	int Result = 0;
	int TrueAnswer = (ValueA * ValueB);
	PrintCalcuation(ValueA, ValueB, 'X');

	cout << "The Result Is  = ";
	cin >> Result;

	if (Result != TrueAnswer) {
		system("color 4F");
		cout << "Wornnig  Ansower :( \n";
		cout << "The Right Answer Is = " << TrueAnswer << endl;
		return false;
	}

	system("color 2F");
	cout << "Corract Answer :D\n";

	return true;
}

bool DivitionCalc(int ValueA, int ValueB) {

	int Result = 0;
	int TrueAnswer =0;

	if (ValueB != 0) {
		TrueAnswer = (ValueA / ValueB);
	}
	
	PrintCalcuation(ValueA, ValueB, '-');

	cout << "The Result Is  = ";
	cin >> Result;

	if (Result != TrueAnswer) {
		system("color 4F");
		cout << "Wornnig  Ansower :( \n";
		cout << "The Right Answer Is = " << TrueAnswer << endl;
		return false;
	}

	system("color 2F");
	cout << "Corract Answer :D\n";
	return true;

}
void CalcuationAndChecking(stQuiss& info,int NumFrom,int NumTo) {

	switch (info.typeOpration)
	{

	case Add:
		if (AddationCalc(RendomNumber(NumFrom, NumTo), RendomNumber(NumFrom, NumTo))) 
		{
			info.NumberOfTrueAnswer++;
			info.scoreGame += 10;
		}
		else {
			info.NumberOfwornigAnswer++;
		}
		break;

	case substract:
		if (SubstractionCalc(RendomNumber(NumFrom, NumTo), RendomNumber(NumFrom, NumTo))) {
			info.NumberOfTrueAnswer++;
			info.scoreGame += 10;
		}
		else
		{
			info.NumberOfwornigAnswer++;
		}
		break;

	case Multple:
		if (MultiplactionCalc(RendomNumber(NumFrom, NumTo), RendomNumber(NumFrom, NumTo))) {
			info.NumberOfTrueAnswer++;
			info.scoreGame += 10;
		}
		else
		{
			info.NumberOfwornigAnswer++;
		}
		break;
	case divid:
		if (DivitionCalc(RendomNumber(NumFrom, NumTo), RendomNumber(NumFrom, NumTo))) {
			info.NumberOfTrueAnswer++;
			info.scoreGame += 10;
		}
		else {
			info.NumberOfwornigAnswer++;
		}
		break;
	case eMix:

		if (MixCalc(RendomNumber(NumFrom, NumTo), RendomNumber(NumFrom, NumTo))) {
			info.NumberOfTrueAnswer++;
			info.scoreGame += 10;
		}
		else
		{
			info.NumberOfwornigAnswer++;
		}
		break;
	}

}

stQuiss LogicOfLevelplay(stQuiss infoOfQuiss) {
	
	switch (infoOfQuiss.LevelQuestion)
	{
	case eyes:
		CalcuationAndChecking(infoOfQuiss, 1, 10);
		break;
	case Mid:
		CalcuationAndChecking(infoOfQuiss, 20, 100);
		break;
	case Hard:
		CalcuationAndChecking(infoOfQuiss, 100, 500);
		break;
	case Mix:
		CalcuationAndChecking(infoOfQuiss, 1, 500);
		break;
	}

	return infoOfQuiss;
}

stQuiss LogicOfGame(short RoundQuestion) {

	stQuiss Quiss;

	Quiss.NumberOFquestion = RoundQuestion;
	Quiss.LevelQuestion = ShooesLevel();
	Quiss.typeOpration = ShooesOpration();

	for (short i = 1; i <=RoundQuestion; i++) {

		Quiss = LogicOfLevelplay(Quiss);

		cout << "\n--------------------------------------------------\n";
	}

	Quiss.Ispass = (Quiss.NumberOfTrueAnswer > Quiss.NumberOfwornigAnswer);
	return Quiss;
}
string IsPass(bool CasePass) {

	if (CasePass) {
		system("color 0F");

		return "Pass :D";
	}

	return "Fail ;)";
}

string LevelQuestion(ElvelQuiss Level) {

	string StrLevel[4] = { "eyes" , "Midum" , "Hard","Mix" };

	return StrLevel[Level - 1];
}
string OprationType(EOpration Type) {

	string TypeOP[5] = { "+", "-","x","/" ,"Mix"};

	return TypeOP[Type - 1];
}

void HaderOfTableScore(stQuiss FinalInfo) {
	cout << "\n\n\t-----------------------------------------------------------------------\n";
	cout << "\t\tResult OF Game The Player Is " << IsPass(FinalInfo.Ispass);
	cout << "\n\t-----------------------------------------------------------------------\n";
}


void FinalGame(stQuiss FinalInfo) {

	 HaderOfTableScore(FinalInfo);

    cout << "\t Total question        : " << FinalInfo.NumberOFquestion << endl;
	cout << "\t Total Correct Answer  : " << FinalInfo.NumberOfTrueAnswer << endl;
	cout << "\t Total Wornnig Answer  : " << FinalInfo.NumberOfwornigAnswer << endl;
	cout << "\t Level Question        : " << LevelQuestion(FinalInfo.LevelQuestion) << endl;
	cout << "\t Type Opration		 : " << OprationType(FinalInfo.typeOpration) << endl;
	cout << "\t Scoree                : " << FinalInfo.scoreGame << endl;
	cout << "\t-----------------------------------------------------------------------\n";

}

void ResetScreen() {

	system("cls");
	system("color 0F");
}
bool PlayAgian(string Message) {
	char ans = 'n';

	cout << "\n\n\t========== Play Agian ==========\n";
	cout << Message << " ";
	cin >> ans;
	cout << "\n\n\t===========================\n";

	return (tolower(ans) == 'y');

}

void MessageGameOver() {

	ResetScreen();

	cout << "\t\t======GAME OVER :E======\n";
	cout << "\tThis is Simple Game OF Math \n";
	cout << "\tThinks For Test Playing This Game : )\n";
}
void startGame() {

	stQuiss quiss;

	do {
		ResetScreen();
		quiss = LogicOfGame(HowMuchNeedquestion());
		FinalGame(quiss);

		
	} while (PlayAgian("Do you want Replay Game ?"));


	MessageGameOver();
}

int main()
{
	//srand((unsigned)time(NULL));
	//startGame();




	return 0;
}