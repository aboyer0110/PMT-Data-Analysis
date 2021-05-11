#include <vector>
#include <string>
#include <TCanvas.h>
#include <TNamed.h>
#include <TGraph.h>
#include <fstream>
#include <cstring>

void LA_Analysis_2x2() {

char L, A; //dummy characters to be read from .txt files
double Sk, Sp, Idb1, Idb2, Skb, Gain, UniPi_Gain, extra, LANumb; //dummy variables to be used in reading .txt files
vector <double> UniPi_Gain_list, Serial_Number_list; //large vector that will store all of the gain values for the Pixels.
vector <double> UniPi = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64}; //Number of Pixels

FILE * fp = fopen("H12700.txt", "r"); //enter the .txt file containing desired data. Use search & replace function to space out the letters in the Serial Numbers. 

int j, k; //counters for loop

for (k=0; k<530; k++) { //reads all rows of the table, k denotes the rows
fscanf(fp, "%c %c %lf %lf %lf %lf %lf %lf %lf", &L, &A, &LANumb, &Sk, &Sp, &Idb1, &Idb2, &Skb, &Gain); //This line reads in successive data entries from the text file. Each %lf reads a long float value and stores it to the corresponding variables denoted with &.

for (j=0; j<64; j++) { //reads the 64 data points for the gain
fscanf(fp, "%lf", &UniPi_Gain);
UniPi_Gain_list.push_back(UniPi_Gain); //push the gain values into a vector for easy graphing
}//End inner for loop

for (int t=0; t<64; t++) {
fscanf(fp, "%lf", &extra); //As a result of how fscanf works, the last value in a given data line was previously duplicated 64 times. This dummy variable takes that duplication and ignores it, preventing it from getting mxied in the actual data
}//end extra loop

}//End outer for loop

fclose(fp);//close the data file

int p=0; //keeps track of sets of 64 in the graph loop

TCanvas* c1 = new TCanvas("c1","Aiden",1600,1600); //instantiate a canvas to allow for the saving of the graph as a pdf
c1->Divide(2,2); //divide the canvas to save page length
c1->Print("RICH H12700s MAPMTs.pdf["); //prints the "opening" of the pdf. allows multiple pages to be printed

int m=1; //counter for canvas divisions

std::string LA; //declare the string to be used for graph titles
FILE * fp2 = fopen("H12700SN.txt", "r"); //open .txt file that only contains the Serial Numbers for the respective data sets. Use search & replace to add an L at the beginning of each serial number to allow the entries to be read

for(int r=0; r<530; r++) { //change the index maximum based on the number of MAPMTs being analyzed
fscanf(fp2, "%s", &LA); //reads the SN .txt file for a Serial Number
TGraph* gr1 = new TGraph(UniPi.size(), &UniPi[0], &UniPi_Gain_list[p]); //instantiate class TGraph, with 64 points, x=UniPI and y=UniPi_Gain
c1->cd(m); //must come before drawing the actual plot & axes; places current plot in the proper canvas division
gr1->SetTitle(LA.c_str()); //converts the read-in string to a constant to allow the arguments of SetTItle to work
gr1->SetMarkerStyle(7); //sets marker type
gr1->SetMarkerSize(2); //sets marker color
gr1->GetXaxis()->SetTitle("Pixel"); //title x-axis
gr1->GetXaxis()->SetTitleSize(0.05); //size the X-axis title
gr1->GetYaxis()->SetTitle("Relative PMT Gain"); //title Y-axis
gr1->GetYaxis()->SetTitleSize(0.060); //size the Y-axis title
gr1->GetYaxis()->SetTitleOffset(0.65); //offset the Y-axis title
gr1->GetXaxis()->SetRangeUser(0,64); //caps the X-axis size
gr1->SetMinimum(30); //sets the minimum possible Y-axis value
gr1->SetMaximum(105); //sets the maximum possible Y-axis value
gr1->Draw("APL"); //draw the plot using the draw function with settings A, P, and L
p=p+64; //increment the counter to graph the next data set

if (m==4) { //if we've reached the last canvas division
m=1; //reset the counter
c1->Print("RICH H12700s MAPMTs.pdf"); //print the canvas to the pdf
c1->Clear(); //clear the canvas; this is for the end of the data set in case it isn't divisble by 4
c1->Divide(2,2); //reset the division
}//end if

else //if not on the last division
m++; //increment the division counter

} //end graphing loop

c1->Print("RICH H12700s MAPMTs.pdf"); //print the canvas, if necessary
c1->Print("RICH H12700s MAPMTs.pdf]"); //close canvas


}//end main
