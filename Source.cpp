#include <iostream>
#include <string>
using namespace std;

void exit() {
	int zero;
	cout << "\nTo exit please press 0 and hit enter" << endl;
	cin >> zero;
	if (zero == 0) {
		system("CLS");
	}
}

class FullName
{
private:
	string FirstName, MiddleName, LastName;
public:
	/*FullName() {

	}*/
	FullName(string FN = "first_name_here", string MN = "middle_name_here", string LN = "last_name_here")
	{
		FirstName = FN;
		MiddleName = MN;
		LastName = LN;
	}
	~FullName()
	{
		//delete FirstName, MiddleName, LastName;
		//cout << "Object is destructed" << endl;
	}

	void setFirstName(string FirstName) {
		this->FirstName = FirstName;
	}
	string getFirstName() {
		return FirstName;
	}
	void setMiddleName(string MiddleName) {
		this->MiddleName = MiddleName;
	}
	string getMiddleName() {
		return MiddleName;
	}
	void setLastName(string LastName) {
		this->LastName = LastName;
	}
	string getLastName() {
		return LastName;
	}

	void display() {
		cout << FirstName << " " << MiddleName << " " << LastName << endl;
	}

};

class Player
{
private:
	string Player_ID;
	FullName PlayerName;
	int Matches_Played, Goals_Scored;

public:
	/*Player() {
		Player_ID = "id";
		PlayerName = a;
		Matches_Played = 0;
		Goals_Scored = 0;
	}*/
	Player(FullName Play_name, string Play_ID = "id", int numb_match = 0, int goals = 0)
	{
		Player_ID = Play_ID;
		PlayerName = Play_name;
		Matches_Played = numb_match;
		Goals_Scored = goals;
	}
	~Player()
	{
		//cout << "Object is destructed." << endl;
	}
	void setPlayer_ID(string id) {
		Player_ID = id;
	}
	string getPlayer_ID() {
		return Player_ID;
	}

	void setMatches_Played(int m) {
		Matches_Played = m;
	}
	int getMatches_Played() {
		return Matches_Played;
	}
	void setGoals_Scored(int goal) {
		Goals_Scored = goal;
	}
	int getGoals_Scored() {
		return Goals_Scored;
	}
	void setPlayer_name(FullName fname) {
		PlayerName = fname;
	}
	void getPlayer_Name() {
		//cout << PlayerName.getFirstName() << PlayerName.getMiddleName() << PlayerName.getLastName() << endl;
		PlayerName.display();
	}
	friend void Increase_goal(Player* pl);
};
void Increase_goal(Player* pl) {
	pl->Goals_Scored += 1;
}




int main()
{

	//FullName* f = new FullName();
	FullName f;
	Player* p = new Player(f);
	label2:
	cout << "1. Set the Full name of the player." << endl;
	cout << "2.>>> Get the Full name of the player." << endl;
	cout << "3. Set ID of the player." << endl;
	cout << "4.>>> Get ID of the player." << endl;
	cout << "5. Set the number of matches played." << endl;
	cout << "6.>>> Get the number of matches played." << endl;
	cout << "7. Set the number of goals scored." << endl;
	cout << "8.>>> Get the number of goals scored." << endl;
	cout << "9. Increase number of goals by 1" << endl;
	cout << "10. Delete the player" << endl;
	cout << "11. QUIT." << endl;
	
	

	int option, num_matches, goals;
	string name, middle_name, last_name, player_id;
	cin >> option;
	system("CLS");
	switch (option)
	{
	case 1:
		/*string name, middle_name, last_name;
		cout << "Please enter the fullname of the player(name/middle_name/last_name)" << endl;
		cin >> name >> middle_name >> last_name;
		FullName* f = new FullName(name, middle_name, last_name);
		Player* p = new Player(*f);*/
		cout << "Please enter the fullname of the player(name/middle_name/last_name)" << endl;
		cin >> name >> middle_name >> last_name;
		f.setFirstName(name);
		f.setMiddleName(middle_name);
		f.setLastName(last_name);
		system("CLS");
		break;
	case 2:
		cout << "Player's full name is: ";
		p->setPlayer_name(f);
		p->getPlayer_Name();
		/*f->display();
		break;*/
		exit();
		break;
	case 3:
		cout << "Please enter the ID of the player: ";
		cin >> player_id;
		p->setPlayer_ID(player_id);
		system("CLS");
		break;
	case 4:
		cout << "Player's ID is: ";
		cout << p->getPlayer_ID() << endl;
		exit();
		break;
	case 5:
		cout << "Please enter number of matches player played: ";
		cin >> num_matches;
		p->setMatches_Played(num_matches);
		system("CLS");
		break;
	case 6:
		cout << "Number of matches player played: ";
		cout << p->getMatches_Played() << endl;
		exit();
		break;
	case 7:
		cout << "Please enter the number of goals player scored: ";
		cin >> goals;
		p->setGoals_Scored(goals);
		system("CLS");
		break;
	case 8:
		cout << "Number of goals player scored: ";
		cout << p->getGoals_Scored() << endl;
		exit();
		break;
	case 9:
		Increase_goal(p);
		cout << "Incresed succesfully" << endl;
		exit();
		break;
	case 10:
		delete p;
		cout << "Deleted succesfully" << endl;
		exit();
		break;
	case 11:
		goto label1;
		break;
	}
	goto label2;




	label1:
	system("pause");
	return 0;
}