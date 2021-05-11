#include <vector>
#include <string>
#include <TCanvas.h>
#include <TNamed.h>
#include <TGraph.h>
#include <fstream>
#include <numeric>


void Cathode_Blue_Sensitivity_Plot() {

char L, A; //characters to be read in from a data file
double Sk, Sp, Idb1, Idb2, Skb, Gain, UniPi_Gain, extra, SerialNumb, Product; //double variables, to be used mostly for dummy variables
FILE * fp = fopen("H12700.txt", "r"); //open the RICH 1 H12700 .txt file
FILE * fp2 = fopen("GainTableCopy.txt", "r"); //open the RICH 2 H12700 .txt file
FILE * fp3 = fopen("H8500.txt", "r"); //open the RICH 1 H8500 .txt file

int j, k; //counters for loop

TH1F *h1 = new TH1F("Blue Sensitivity","Cathode Blue Sensitivity Index", 25, 7, 15); //instantiate a histogram for the RICH 1 H12700s
TH1F *h2 = new TH1F("Blue Sensitivity","Cathode Blue Sensitivity Index", 25, 7, 15); //instantiate a histogram for the RICH 2 H12700s
TH1F *h3 = new TH1F("Blue Sensitivity","Cathode Blue Sensitivity Index", 25, 7, 15); //instantiate a histogram for the RICH 1 H8500s
gStyle->SetOptStat(1000000001); //option that disables the "entries" display, and it would be displayed inaccurately

for (k=0; k<530; k++) { //reads all rows of the table
fscanf(fp, "%c %c %lf %lf %lf %lf %lf %lf %lf", &L, &A, &SerialNumb, &Sk, &Sp, &Idb1, &Idb2, &Skb, &Gain); //scans the document and fills dummy variables
h1->Fill(Skb); //fill the RICH 1 H12700 with the blue sensitivity index


for (j=0; j<64; j++) { //reads the 64 data points for the gain
fscanf(fp, "%lf", &UniPi_Gain); //reads in 1 data point
}//End inner for loop

for (int t=0; t<64; t++) {
fscanf(fp, "%lf", &extra); //As a result of how fscanf works, the last value in a given data line was previously duplicated 64 times. This dummy variable takes that duplication and ignores it, preventing it from getting mxied in the actual data
}//end extra loop

}//End outer for loop

fclose(fp); //close the RICH 1 H12700 .txt

for (k=0; k<180; k++) { //reads all rows of the table
fscanf(fp2, "%c %c %lf %lf %lf %lf %lf %lf %lf", &L, &A, &SerialNumb, &Sk, &Sp, &Idb1, &Idb2, &Skb, &Gain); //scans the document and fills dummy variables
h2->Fill(Skb); //fill the RICH 2 H12700 with the blue sensitivity index


for (j=0; j<64; j++) { //reads the 64 data points for the gain
fscanf(fp2, "%lf", &UniPi_Gain); //reads in 1 data point
}//End inner for loop

for (int t=0; t<64; t++) {
fscanf(fp2, "%lf", &extra); //As a result of how fscanf works, the last value in a given data line was previously duplicated 64 times. This dummy variable takes that duplication and ignores it, preventing it from getting mxied in the actual data
}//end extra loop

}//End outer for loop

fclose(fp2); //close the RICH 2 H12700 .txt */

for (k=0; k<82; k++) { //reads all rows of the table
fscanf(fp3, "%c %c %lf %lf %lf %lf %lf %lf %lf", &L, &A, &SerialNumb, &Sk, &Sp, &Idb1, &Idb2, &Skb, &Gain); //scans the document and fills dummy variables
h3->Fill(Skb); //fills the RICH 1 H8500 histogram with the blue sensitivity index


for (j=0; j<64; j++) { //reads the 64 data points for the gain
fscanf(fp3, "%lf", &UniPi_Gain); //reads in 1 data point
}//End inner for loop

for (int t=0; t<64; t++) {
fscanf(fp3, "%lf", &extra); //As a result of how fscanf works, the last value in a given data line was previously duplicated 64 times. This dummy variable takes that duplication and ignores it, preventing it from getting mxied in the actual data
}//end extra loop

}//End outer for loop

fclose(fp3); //close the RICH 1 H8500 .txt

h1->GetXaxis()->SetTitle("Cathode Blue Sensitivty Index"); //title the RICH 1 H12700 histo x-axis
TCanvas* c2 = new TCanvas("c2","Aiden2",1600,1100); //New canvas for the histograms
h1->SetLineColor(1); //color the RICH 1 H12700 histo grey/black
h2->SetLineColor(2); //color the RICH 2 H12700 histo red
h3->SetLineColor(4); //color the RICH 1 H8500 histo blue
h1->Draw(); //draw the RICH 1 H12700 histo
h2->Draw("Same"); //draw the RICH 2 H12700 histo on the same pad
h3->Draw("Same"); //draw the RICH 3 H12700 histo on the same pad
auto legend = new TLegend(0.78,.79,0.98,0.90);
gStyle->SetLegendTextSize(0.020);
legend->AddEntry(h1,"RICH 1 & 2 H12700s (11.82)","l");
legend->AddEntry(h2,"RICH 2 H12700s (Avg: 11.49)","l");
legend->AddEntry(h3,"RICH 1 H8500s (Avg: 10.01)","l");
legend->Draw();
c2->Print("Cathode Blue Sensitivity Index Distribution.pdf"); //print the canvas to a pdf

}//end main
