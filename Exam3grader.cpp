#include <string>
#include <iostream>
#include <algorithm>
//char to int (cti)
using namespace std;
int cti(char a) {
	int int_a;
    if ((a  < '0')||(a  > '9' )){
		throw std::invalid_argument("Invalid Argument");
	}
	int_a = (int)a - '0';
    return int_a;
}

int ScoreCipher_and_print(string longO, bool ORIGINAL){
		int orig;
    	int Ao = 0;
		int Co = 0;
		int To = 0;
		int Io = 0;
		int Do = 0;
		int Po = 0;
		int Mo = 0;
		int Ro = 0;
		Ao = cti(longO[0]);
		Co = cti(longO[1]);
		To = cti(longO[2])*10 + cti(longO[3]);
		Io = cti(longO[4])*10 + cti(longO[5]);
		Do = cti(longO[6])*10 + cti(longO[7]);
		Po = cti(longO[8])*10 + cti(longO[9]);
		Mo = cti(longO[10])*10 + cti(longO[11]);
		Ro = cti(longO[12])*10 + cti(longO[13]);
		orig = Ao * Co * (To + Io + max(Do,Po) + Mo + Ro);
		cout << endl;
		if (ORIGINAL) {cout << "                        ORIGINAL SCORES" << endl;}
		else{cout << "                        REDEMPTION SCORES" << endl;}
		cout << "approved includes score is:           " << Ao << " out of 1 available." << endl;
		cout << "Compile and warning score is:         " << Co << " out of 1 available." << endl;
		cout << "student coverage score is:            " << To << " out of 10 available." << endl;
		cout << "infrastructure score is:              " << Io << " out of 20 available." << endl;
		cout << "Duplicate score is:                   " << Do << " out of 40 available." << endl;
		cout << "partail creit for Duplicate score is: " << Po << " out of 40 available." << endl;
		cout << "Max length Decreasing score is:       " << Mo << " out of 20 available." << endl;
		cout << "rule of three score is:               " << Ro << " out of 20 available." << endl;
		cout << "Your orginal Exam Score is:           " << orig << " out of 110 avaiable." <<endl;
		return orig;
}

int main(){
    cout << "This Code calculates your Final exam 3 grade for exam three given the long digit of your orginal score and your long digit of your redemption score" << endl;
	// decalartuons of stings
	string longO;
	int orig;// orignal score
	cout << "Enter your ORIGINAL long exam score or your calculated score: ";
	cin >> longO;
	if((longO.length() == 2) or (longO.length() == 3)){
		
		if (longO.length() == 2){orig = cti(longO[0])*10 +cti(longO[1]);}
		else{orig = cti(longO[0])*100 + cti(longO[1])*10 +cti(longO[2]);}
		cout << "Your orginal Exam Score is:           " << orig << " out of 110 avaiable." <<endl;
	}
	else{
		while(longO.length() != 14){
			cout << "enter a Orignal long digit  with length of 14 digits: ";
			cin >> longO;
		}
		// long digit is Acttiiddppmmrr
		orig = ScoreCipher_and_print(longO,true);
	}
	
	
	// REDEMPTION calulations
    string longR;
	cout << "Enter your REDEMPTION long exam score or your calculated score: ";
	cin >> longR;
	int redem;
	if((longR.length() == 2) or (longR.length() == 3)){
		if (longR.length() == 2){redem = cti(longR[0])*10 +cti(longR[1]);}
		else{redem = cti(longR[0])*100 + cti(longR[1])*10 +cti(longR[2]);}
		cout << "Your redemption score is:           " << redem << " out of 110 avaiable." <<endl;
	}
	else{
		while(longR.length() != 14){
			cout << "enter Exam score as a long digit with length of 14 digits: ";
			cin >> longR;
		}
		redem = ScoreCipher_and_print(longR,false);
	}
	double RedemScore = ((double)orig + (double)redem)/2;
	double FinalGrade = max((double)orig,RedemScore);
	cout << endl << endl << endl;
	cout << "Your FINAL EXAM score after redemption is: " << FinalGrade << endl;
	cout << endl;
    return 0;

}

