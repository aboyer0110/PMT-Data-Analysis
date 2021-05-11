#include <vector>
#include <string>
#include <TCanvas.h>
#include <TNamed.h>
#include <TGraph.h>
#include <fstream>
#include <cstring>

void serial_number_setup() {

char L, A; //dummy characters to be read from .txt files
double Sk, Sp, Idb1, Idb2, Skb, Gain, Rel_Gain, extra, LANumb; //dummy variables to be used in reading .txt files
vector <double> Sk_list, Sp_list, Idb1_list, Idb2_list, Skb_list, Gain_list, Rel_Gain_list; //Vectors that will be used to store data values

FILE * fp = fopen("Analysis.txt", "r"); //enter the .txt file containing desired data. Use search & replace function to space out the letters in the Serial Numbers. 

int j, k; //counters for loop

ofstream myfile;
ofstream myfile2;
myfile.open("SN_6_Parameters.txt");
myfile2.open("SN_Gains.txt");

for (k=0; k<321; k++) { //reads all rows of the table
fscanf(fp, "%c %c %lf %lf %lf %lf %lf %lf %lf", &L, &A, &LANumb, &Sk, &Sp, &Idb1, &Idb2, &Skb, &Gain); //This line reads in successive data entries from the text file. Each %lf reads a long float value and stores it to the corresponding variables denoted (addressed with an &).
myfile << L << L << A << LANumb << ".tsdat" << "\n"; //these lines read in the PMT serial number, printing it as LLA####, the extra L is to ensure that the title is properly read into the compliment program pmt_characterization.C to save data to the right files.
myfile2 << L << L << A << LANumb << ".audat" << "\n";

for (j=0; j<64; j++) { //reads the 64 data points for the relative gain
fscanf(fp, "%lf", &Rel_Gain);
Rel_Gain_list.push_back(Rel_Gain);
}//End inner for loop

for (int t=0; t<64; t++) {
fscanf(fp, "%lf", &extra); //As a result of how fscanf works, the last value in a given data line is duplicated 64 times. This dummy variable takes that duplication and ignores it, preventing it from getting mxied in the actual data
}//end extra loop

}//End outer for loop

} 
