#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void sort(float x[], int N){
	for(int i = 1; i < N; i++){
		for(int j = i; j > 0; j--){
			if(x[j] > x[j-1]){
				float temp = x[j];
				x[j] = x[j-1];
				x[j-1] = temp;
			}else{
				break;
			} 
		}
	}
}

int main(){
	
	//Write your code here
	ifstream input_text("score3.txt");
	ofstream output_text("result.txt");
	string string_input;
	float temp[20];
	int i=0;
	while(getline(input_text,string_input)){
		temp[i]=atof(string_input.c_str());
		i++;
	}
	sort(temp,20);
	int j;
	int show=0;
	int same=0;
	for(int j=0;j<20;j++){
		if (temp[j]==temp[j-1]) {
			show=j-same;
			same++;
			}
		else {
			same=0;
			show=j+1;}
		output_text<<show<<":"<<temp[j]<<endl;
	}
	return 0;
}

