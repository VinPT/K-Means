#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <set>
#include <stdio.h>
#include <cmath>
using std::cout;
using std::endl;
	
void kMeans(int k, std::vector<std::vector<int> > &data);
void import(std::vector<std::vector<int> > &data);

int main()
{

	std::vector<std::vector<int> > data;

	import(data);

	kMeans(2, data);
}

void import(std::vector<std::vector<int> > &data){
	std::vector<int> vTemp;
	char num[5];	

	vTemp.assign(783,-1);
/////////////////////////////////////////////////////////////////////	
	std::ifstream inputFile("data");
	
	if (inputFile){
		while(!inputFile.eof()){
			for (int i = 0; 783 > i; i++){
				inputFile.getline(num, 256,','); 
				vTemp[i] = atoi(num);
			}
			data.push_back(vTemp);
	
		}

		cout << "The data is "<<data.size()<<" lines long"<<endl;
	}
	else{
		cout << "Falure to open input file."<< endl;
	}


	inputFile.close();
	return;
}
/////////////////////////////////////////////////////////////////////

void kMeans(int k, std::vector<std::vector<int> > &data)
{
	// Initalization.
	std::vector<std::vector<int> > centroids;
	std::vector<std::vector<int> > vals;
	std::vector<int> vTemp;
	int cent =0;
	for (int i = 0; i < k; i++)
	{
		vTemp.push_back(k);
		centroids.push_back(data[rand() % data.size()]);
		vals.push_back(vTemp);
		cout << "save me"<< endl;
	}
	
	// run
	
	
	// Determine closest centroid and assign
	for (unsigned int i = 0; i < data.size(); i++)
	{
		std:: vector<int> result;
		int temp = 0;
		for (int j = 0; j < k; j++)
		{
			for (unsigned int f = 0; f< data[0].size(); f++)
			{			
				temp += pow((data[i][f] - centroids[j][f]), 2);
			}
			result.push_back(temp);

			if (1 <= result.size())
				cent =0;
			else if (result[result.size()-1] < result[result.size()-2])
				cent = result.size()-1;

		}
		vTemp = vals[cent];
		vTemp.push_back(i);
		vals[cent] = vTemp;
	}
	
	// Update centroid
	cout << endl << "    ---Update---"<< endl << endl;
	
	for (int i =0; i<k; i++)
	{
		int size = -1;
		cout <<"Testing position "<< i <<endl;
		vTemp = vals[i];
		size = vTemp.size();
		while(!vTemp.empty())
		{
			int num = vTemp[vTemp.size()-1];
			cout<<"num set: " << num << endl;
			for (unsigned int j = 0; j< data[0].size(); j++)
			{
//				cout<<" accessing data "<< vTemp.size() <<endl;
				data[num][j] += centroids[i][j];
			}

			
			vTemp.pop_back();
		}
		
//		vals[i] = vTemp;
		for (unsigned int j = 0; j< data[0].size(); j++)
		{
			centroids[i][j] = centroids[i][j] /size;
		}
	}
	

	// find the resultant sum of square error;
	cout << "        ---SSE---" << endl << endl;
	for (int i = 0; i < k; i++)
	{
		//sumSquareError(centroids);
		int size = -1;
		int result = -1;
		cout <<" SSE"<<endl;
		vTemp = vals[i];
		size = vTemp.size();
		while(!vTemp.empty())
		{
			int num = vTemp[vTemp.size()-1];
			cout<<"num set: " << num << endl;
			for (unsigned int j = 0; j< data[0].size(); j++)
			{
				result += pow((data[num][j] - centroids[i][j]), 2);
			}
			vTemp.pop_back();
		}

			result = result/size; 

			cout << "The result for centroid " << i << " is "<< result<< endl;
	}
	return;
}
	
