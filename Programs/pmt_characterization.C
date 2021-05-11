#include <vector>
#include <string>
#include <TCanvas.h>
#include <TNamed.h>
#include <TGraph.h>
#include <fstream>
#include <cstring>

void pmt_characterization() {

char L, A; //dummy characters to be read from .txt files
double Sk, Sp, Idb1, Idb2, Skb, Gain, Rel_Gain, extra, LANumb; //dummy variables to be used in reading .txt files
vector <double> Sk_list, Sp_list, Idb1_list, Idb2_list, Skb_list, Gain_list, Rel_Gain_list; //Vectors that will be used to store data values

FILE * fp = fopen("Analysis.txt", "r"); //enter the .txt file containing desired data. Use search & replace function to space out the letters in the Serial Numbers. 

int j, k; //counters for loop

for (k=0; k<321; k++) { //reads all rows of the table
fscanf(fp, "%c %c %lf %lf %lf %lf %lf %lf %lf", &L, &A, &LANumb, &Sk, &Sp, &Idb1, &Idb2, &Skb, &Gain); //This line reads in successive data entries from the text file. Each %lf reads a long float value and stores it to the corresponding variables denoted (addressed with an &).
Sk_list.push_back(Sk);
Sp_list.push_back(Sp);
Idb1_list.push_back(Idb1);
Idb2_list.push_back(Idb2);
Skb_list.push_back(Skb);
Gain_list.push_back(Gain);

for (j=0; j<64; j++) { //reads the 64 data points for the relative gain
fscanf(fp, "%lf", &Rel_Gain);
Rel_Gain_list.push_back(Rel_Gain);
}//End inner for loop

for (int t=0; t<64; t++) {
fscanf(fp, "%lf", &extra); //As a result of how fscanf works, the last value in a given data line is duplicated 64 times. This dummy variable takes that duplication and ignores it, preventing it from getting mxied in the actual data
}//end extra loop

}//End outer for loop

fclose(fp);//close the data file

std::cout << "Length of Rel_Gain_list: " << Rel_Gain_list.size() << '\n'; //check to ensure all data is accounted for

std::string LA; //declare LA string that will be used to title the data files
FILE * fp2 = fopen("SN_6_Parameters.txt", "r"); //open a separate file containing the serial numbers appearing in the order listed in the data table.

for (int i=0; i<321; i++) { //loop over all PMTs
fscanf(fp2, "%s", &LA); //scan the SN .txt file and address entries to the string LA
ofstream myfile; //open a file stream
myfile.open(LA.c_str()); //create a new data file with the name of the LA string

cout << Sk_list[i] << " " << Sp_list[i] << " " << Idb1_list[i] << " " << Idb2_list[i] << " " << Skb_list[i] << " " << Gain_list[i] << endl; //prints to command prompt, as a check
myfile <<  Sk_list[i] << "\n" << Sp_list[i] << "\n" << Idb1_list[i] << "\n" << Idb2_list[i] << "\n" << Skb_list[i] << "\n" << Gain_list[i]; //prints entries to the aforementioned new data file
}//end file creation for the 6 parameters

fclose(fp2); //close the SN txt for .tsdat extension

FILE * fp3 = fopen("SN_Gains.txt", "r"); //open the SN .txt for the rel_gains, have the .audat extension

int q=0; //index for relative gain vector

for (int i=0; i<321; i++) {//loop across all PMTs
fscanf(fp3, "%s", &LA); //read in the SN with the appropriate file extension
ofstream myfile; //open file stream again
myfile.open(LA.c_str()); //create a new data file with the name of the LA string

for(int p=0; p<64; p++) { //loop across 64 PMTs
myfile << Rel_Gain_list[q] << "\n"; //print PMT entries to the data file
q++; //increment for q, different from p such that it can exceed values of 64.

} 
}//end file creation for relative gains

fclose(fp3);


}
