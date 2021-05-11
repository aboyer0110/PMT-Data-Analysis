#include <vector>
#include <string>
#include <TCanvas.h>
#include <TNamed.h>
#include <TGraph.h>
#include <fstream>
#include <numeric>


void Rel_Gain_Histo() {

char L, A; //characters to be read in from the .txt data files
double Sk, Sp, Idb1, Idb2, Skb, Gain, UniPi_Gain, extra, SerialNumb, Product; //double variables, most of them are dummy variables to facilitate the reading of data
FILE * fp = fopen("H12700.txt", "r"); //open the RICH 1 H12700 .txt
FILE * fp2 = fopen("GainTableCopy.txt", "r"); //open the RICH 2 H12700 .txt
FILE * fp3 = fopen("H8500.txt", "r"); //open the RICH 1 H8500 .txt

int j, k; //counters for loot

TH1F *h1 = new TH1F("Relative Gain Histo","Relative Gain Distribution", 25, 0, 100); //instantiate a histogram for the RICH 1 H12700s
TH1F *h2 = new TH1F("Relative Gain Histo","Relative Gain Distribution", 25, 0, 100); //instantiate a histogram for the RICH 2 H12700s
TH1F *h3 = new TH1F("Relative Gain Histo","Relative Gain Distribution", 25, 0, 100); //instantiate a histogram for the RICH 1 H8500s
gStyle->SetOptStat(1000000001); //removes the "entries" statistics from the statistics box, since would've been misrepresented

for (k=0; k<530; k++) { //reads all rows of the table
fscanf(fp, "%c %c %lf %lf %lf %lf %lf %lf %lf", &L, &A, &SerialNumb, &Sk, &Sp, &Idb1, &Idb2, &Skb, &Gain); //scans the document and fills dummy variables with information


for (j=0; j<64; j++) { //reads the 64 data points for the gain
fscanf(fp, "%lf", &UniPi_Gain); //reads 1 data point
h1->Fill(UniPi_Gain); //fills the histogram with the relative gains of RICH 1 H12700s
}//End inner for loop

for (int t=0; t<64; t++) {
fscanf(fp, "%lf", &extra); //As a result of how fscanf works, the last value in a given data line was previously duplicated 64 times. This dummy variable takes that duplication and ignores it, preventing it from getting mxied in the actual data
}//end extra loop

}//End outer for loop

fclose(fp); //close RICH 1 H12700 .txt

for (k=0; k<180; k++) { //reads all rows of the table
fscanf(fp2, "%c %c %lf %lf %lf %lf %lf %lf %lf", &L, &A, &SerialNumb, &Sk, &Sp, &Idb1, &Idb2, &Skb, &Gain); //scans the document and fills dummy variables with information

for (j=0; j<64; j++) { //reads the 64 data points for the gain
fscanf(fp2, "%lf", &UniPi_Gain); //reads 1 data point
h2->Fill(UniPi_Gain); //fills histogram with relative gains of RICH 2 H12700s
}//End inner for loop

for (int t=0; t<64; t++) {
fscanf(fp2, "%lf", &extra); //As a result of how fscanf works, the last value in a given data line was previously duplicated 64 times. This dummy variable takes that duplication and ignores it, preventing it from getting mxied in the actual data
}//end extra loop

}//End outer for loop

fclose(fp2); //close RICH 2 H12700 .txt */

for (k=0; k<82; k++) { //reads all rows of the table
fscanf(fp3, "%c %c %lf %lf %lf %lf %lf %lf %lf", &L, &A, &SerialNumb, &Sk, &Sp, &Idb1, &Idb2, &Skb, &Gain); //scans the document and fills dummy variables with information

for (j=0; j<64; j++) { //reads the 64 data points for the gain
fscanf(fp3, "%lf", &UniPi_Gain); //reads in 1 data point
h3->Fill(UniPi_Gain); //fills histogram with relative gains of RICH 1 H8500s
}//End inner for loop 

for (int t=0; t<64; t++) {
fscanf(fp3, "%lf", &extra); //As a result of how fscanf works, the last value in a given data line was previously duplicated 64 times. This dummy variable takes that duplication and ignores it, preventing it from getting mxied in the actual data
}//end extra loop

}//End outer for loop

fclose(fp3); //close RICH 1 H8500 .txt

h1->GetXaxis()->SetTitle("Relative Gain"); //title the first histogram's axis
TCanvas* c2 = new TCanvas("c2","Aiden2",1600,1100); //New canvas for the histograms
h1->SetLineColor(1); //color RICH 1 H12700s grey/black
h2->SetLineColor(2); //color RICH 2 H12700s red
h3->SetLineColor(4); //color RICH 1 H8500s blue
h1->Draw(); //draw the RICH 1 H12700 histo
h2->Draw("Same"); //draw the RICH 2 H12700 histo on the same pad
h3->Draw("Same"); //draw the RICH 1 H8500 histo on the same pad
auto legend = new TLegend(0.78,.79,0.98,0.90);
gStyle->SetLegendTextSize(0.020);
legend->AddEntry(h1,"RICH 1 & 2 H12700s (Avg: 77.41)","l");
legend->AddEntry(h2,"RICH 2 H12700s (Avg: 78.75)","l");
legend->AddEntry(h3,"RICH 1 H8500s (Avg: 73.32)","l");
legend->Draw();
c2->Print("Relative Gain Histo Distribution.pdf"); //save canvas as a pdf

}//end main
