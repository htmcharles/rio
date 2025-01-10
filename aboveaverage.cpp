#include <iostream>
#include <iomanip>

using namespace std;


int main (){
	int cases;
	cin  >> cases;
	
	
	for (int i=0;i<cases;i++){
		int people;
		cin >> people;
		double sum =0;
		double marks[people];
		for (int j=0;j<people;j++){
			cin >> marks[j];
			sum += marks[j];
		}
		double avarage = sum /people;
		double count =0;
		
		for (int k=0;k<people;k++){
			if (marks[k]>avarage){
				count++;
			}
		}
		double result = (count/people)*100;
		
		cout << fixed <<setprecision(3) <<result << endl;
	}
	
	
	return 0;
}
