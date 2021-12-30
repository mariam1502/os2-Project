#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
//"First Fit","Best-Fit","Worst-Fit" 
void First_Fit(int a, string b[], int c, string d[])
{
	//a-->total number of blocks
	//b[]-->the size of each block
	//c-->total number of processes
	//d[]-->the size of each process

	cout << "First fit here" << endl;
	int* result = new int[a * c]; //---->>to display think in the form of a table

	cout << "the size of each process:";
	for (int x = 0; x < c; x++)
	{
		cout << d[x] << " ";
	}
	cout << endl;
	cout << "The size of each block: ";

	for (int x = 0; x < a; x++)
	{
		cout << b[x] << " ";
	}

	cout << endl << "OutPut:" << endl;
	bool* checkProcess = new bool[c];
	bool* checkBlock = new bool[a];
	for (int x = 0; x < a; x++)
	{
		checkBlock[x] = false;
		checkProcess[x] = false;

	}
	//cout << "Process size	" << "		|		" << "block size " << endl;
	cout << left << setw(6) << setfill(' ') << "		Process Size";
	cout << left << setw(6) << setfill(' ') << "  Block Size" << endl;


	for (int x = 0; x < a; x++)
	{

		for (int y = 0; y < c; y++)
		{
			if( stoi(b[x]) >= stoi( d[y]) && checkBlock[x] == false && checkProcess[y] == false)
			{

				//cout << "\t  " << d[y] << "			|		" << b[x] << endl;
				cout << left << setw(6) << setfill(' ') << "		"<<d[y];
				cout << left << setw(6) << setfill(' ') << "		"<<b[x];
				cout << endl;

				checkBlock[x] = true;
				checkProcess[y] = true;

			}

		}

	}
	//cout << "block of size			|		process aquires it" << endl;
	cout << left << setw(6) << setfill(' ') << "		Block Size";
	cout << left << setw(6) << setfill(' ') << "  Process Aquires it"<<endl;


	for (int x = 0; x < a; x++)
	{
		if (checkBlock[x] == false )
		{
			//cout << "The block of size " << b[x] << " is empty" << endl;
			// process size ......... block size
			//cout<<"		"<<b[x]<<"		|		"<<"empty"<<endl;
			cout << left << setw(6) << setfill(' ') << "		"<<b[x];
			cout << left << setw(6) << setfill(' ') << "		"<<"empty"<<endl;

			
		}
	}





}

void Best_Fit(int a, string b[], int c, string d[])
{
	cout << "Best fit here" << endl;
	//a-->total number of blocks
//b[]-->the size of each block
//c-->total number of processes
//d[]-->the size of each process
	cout << "the size of each process:";
	for (int x = 0; x < c; x++)
	{
		cout << d[x] << " ";
	}
	cout << endl;
	cout << "The size of each block: ";

	for (int x = 0; x < a; x++)
	{
		cout << b[x] << " ";
	}

	cout << endl << "OutPut:" << endl;

	//sort the block from  the smallest to the biggest
	string temp;

	for (int x = 0; x < a - 1; x++)
	{
		for (int y = 0; y < a - x - 1; y++)
		{
			if (stoi(b[y + 1]) < stoi( b[y]))
			{
				temp = b[y + 1];
				b[y + 1] = b[y];
				b[y] = temp;
			}
		}
	}
	bool* checkBlock2 = new bool[a];
	bool* checkProcess = new bool[c];

	for (int x = 0; x < a; x++)
	{
		checkBlock2[x] = false;
		checkProcess[x] = false;
	}
	//cout << "Process size " << "|" << " block size " << endl;
	cout << left << setw(6) << setfill(' ') << "		Process Size";
	cout << left << setw(6) << setfill(' ') << "  Block Size" << endl;
	for (int x = 0; x < a; x++)
	{
		for (int y = 0; y < c; y++)
		{
			if (stoi(b[x]) >= stoi(d[y]) && checkBlock2[x] == false && checkProcess[y] == false)

			{
				//cout << "\t  " << d[y] << " | " << b[x] << endl;
				cout << left << setw(6) << setfill(' ') << "		" << d[y];
				cout << left << setw(6) << setfill(' ') << "		" << b[x];
				cout << endl;
				checkBlock2[x] = true;
				checkProcess[y] = true;
			}
		}
	}

	//cout << "block of size			|		process aquires it" << endl;
	cout << left << setw(6) << setfill(' ') << "		Block Size";
	cout << left << setw(6) << setfill(' ') << "  Process Aquires it" << endl;

	for (int x = 0; x < a; x++)
	{
		if (checkBlock2[x] == false )
		{
			//cout << "The block of size " << b[x] << " is empty" << endl;
			// process size ......... block size
			//cout << "		" << b[x] << "		|		" << "empty" << endl;
			cout << left << setw(6) << setfill(' ') << "		" << b[x];
			cout << left << setw(6) << setfill(' ') << "		" << "empty" << endl;

		}
	}


}
void Worst_Fit(int a, string b[], int c, string d[])
{
	cout << "Worst fit here" << endl;
	//a-->total number of blocks
//b[]-->the size of each block
//c-->total number of processes
//d[]-->the size of each process
	cout << "the size of each process:";
	for (int x = 0; x < c; x++)
	{
		cout << d[x] << " ";
	}
	cout << endl;
	cout << "The size of each block: ";

	for (int x = 0; x < a; x++)
	{
		cout << b[x] << " ";
	}

	cout << endl << "OutPut:" << endl;

	//sort the block from  the biggest to the smallest
	string temp;
	for (int x = 0; x < a; x++)
	{
		for (int y = 0; y < a - x - 1; y++)
		{
			if (stoi(b[y + 1]) > stoi(b[y]))
			{
				temp = b[y + 1];
				b[y + 1] = b[y];
				b[y] = temp;
			}
		}
	}


	bool* checkBlock2 = new bool[a];
	bool* checkProcess = new bool[c];

	for (int x = 0; x < a; x++)
	{
		checkBlock2[x] = false;
		checkProcess[x] = false;
	}
	//cout << "Process size " << "		|		" << " block size " << endl;
	cout << left << setw(6) << setfill(' ') << "		Process Size";
	cout << left << setw(6) << setfill(' ') << "  Block Size" << endl;
	for (int x = 0; x < a; x++)
	{
		for (int y = 0; y < c; y++)
		{
			if (stoi(b[x]) >= stoi(d[y]) && checkBlock2[x] == false && checkProcess[y] == false)

			{
				//cout << "		|		" << d[y] << " 		|		 " << b[x] << endl;
				cout << left << setw(6) << setfill(' ') << "		" << d[y];
				cout << left << setw(6) << setfill(' ') << "		" << b[x];
				cout << endl;
				checkBlock2[x] = true;
				checkProcess[y] = true;
			}
		}
	}
	//cout << "block of size			|		process aquires it" << endl;
	cout << left << setw(6) << setfill(' ') << "		Block Size";
	cout << left << setw(6) << setfill(' ') << "  Process Aquires it" << endl;

	for (int x = 0; x < a; x++)
	{
		if (checkBlock2[x] == false && checkProcess[x] == false)
		{
			//cout << "The block of size " << b[x] << " is empty" << endl;
			// process size ......... block size
		//	cout << "		" << b[x] << "		|		" << "empty" << endl;
			cout << left << setw(6) << setfill(' ') << "		" << b[x];
			cout << left << setw(6) << setfill(' ') << "		" << "empty" << endl;

		}
	}


}

int main()
{
	//total number if blocks ..block sizes ...number of processes...
	//the size of processes
	char choice = 'y';
	cout << "Welcome to the Proccess Allocation Simulator" << endl;
	cout << "If you want to quit press 'q'" << endl;

	int NumberOfBlocks;//size of array
	cout << "Please enter the total number of you Blocks" << endl;
	cin >> NumberOfBlocks;


	//array block
	string* ArrayOfBlockSizes = new string[NumberOfBlocks];
	cout << "Please enter the Size of your Blocks with spaces in between" << endl;
	for (int x = 0; x < NumberOfBlocks; x++)
	{
		cin >> ArrayOfBlockSizes[x];
	}
	
	int NumberOfProcesses;//size of process array
	cout << "Please enter the total number of your Processes" << endl;
	cin >> NumberOfProcesses;//size of the Array

	//process array
	string* ArrayOfProcessesSizes = new string[NumberOfProcesses];
	cout << "Please enter the Size of your Processes with spaces inbetween" << endl;
	for (int x = 0; x < NumberOfProcesses; x++)
	{
		cin >> ArrayOfProcessesSizes[x];
	}


	while (choice == 'y')
	{
		string Method[] = { "First Fit","Best-Fit","Worst-Fit","Enter new Data" };
		cout << "Please Select the prefered Memory Allocation  Methode" << endl;
		for (int x = 0; x < 4; x++)
		{
			cout << "(" << x + 1 << ")" << Method[x] << endl;
		}
		int MethodSelected;
		cin >> MethodSelected;
		system("CLS");

		if (MethodSelected == 1)
		{
			First_Fit(NumberOfBlocks, ArrayOfBlockSizes, NumberOfProcesses, ArrayOfProcessesSizes);
		}
		else if (MethodSelected == 2)
		{
			Best_Fit(NumberOfBlocks, ArrayOfBlockSizes, NumberOfProcesses, ArrayOfProcessesSizes);
		}
		else if (MethodSelected == 3)
		{
			Worst_Fit(NumberOfBlocks, ArrayOfBlockSizes, NumberOfProcesses, ArrayOfProcessesSizes);
		}
		else if (MethodSelected == 4)
		{
			fill_n(ArrayOfBlockSizes,NumberOfBlocks, 0);
			fill_n(ArrayOfProcessesSizes, NumberOfProcesses, 0);
			cout << "Please enter the total number of you Blocks" << endl;
			cin >> NumberOfBlocks;


			//array block
			//string* ArrayOfBlockSizes = new string[NumberOfBlocks];
			cout << "Please enter the Size of your Blocks with spaces in between" << endl;
			for (int x = 0; x < NumberOfBlocks; x++)
			{
				cin >> ArrayOfBlockSizes[x];
			}

			//int NumberOfProcesses;//size of process array
			cout << "Please enter the total number of your Processes" << endl;
			cin >> NumberOfProcesses;//size of the Array

			//process array
			//string* ArrayOfProcessesSizes = new string[NumberOfProcesses];
			cout << "Please enter the Size of your Processes with spaces inbetween" << endl;
			for (int x = 0; x < NumberOfProcesses; x++)
			{
				cin >> ArrayOfProcessesSizes[x];
			}

		}

		cout << "If you want to quit press 'q' Otherwise press 'y'" << endl;
		cin >> choice;

	}
	
}

