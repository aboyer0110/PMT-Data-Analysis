#include <vector>
#include <string>
#include <TCanvas.h>
#include <TNamed.h>
#include <TGraph.h>
#include <fstream>
#include <numeric>

void Data_Sheet_Gain_Histo() {

char L, A; //characters to be read in from data files
double Sk, Sp, Idb1, Idb2, Skb, Gain, UniPi_Gain, extra, SerialNumb, Product; //double variables, most of them are dummy variables to facilitate the reading of data
FILE * fp = fopen("H12700.txt", "r"); //open the RICH 1 H12700 .txt file
FILE * fp2 = fopen("GainTableCopy.txt", "r"); //open the RICH 2 H12700 .txt file
FILE * fp3 = fopen("H8500.txt", "r");  //open the RICH 1 H8500 .txt

int j, k; //counters for loop

TH1F *h1 = new TH1F("Data Sheet Gain Histo","Data Sheet Gain Factor", 25, 0, 5.5); //instantiate a histogram for the RICH 1 H12700s
TH1F *h2 = new TH1F("Data Sheet Gain Histo","Data Sheet Gain Factor", 25, 0, 5.5); //instantiate a histogram for the RICH 2 H12700s
TH1F *h3 = new TH1F("Data Sheet Gain Histo","Data Sheet Gain Factor", 25, 0, 5.5); //instantiate a histogram for the RICH 1 H8500s
gStyle->SetOptStat(1000000001); //option that disables the "entries" in the statistics box as they would be inaccurately displayed

for (k=0; k<530; k++) { //reads all rows of the table
fscanf(fp, "%c %c %lf %lf %lf %lf %lf %lf %lf", &L, &A, &SerialNumb, &Sk, &Sp, &Idb1, &Idb2, &Skb, &Gain); //scans the document and fills dummy variables
h1->Fill(Gain); //fill the RICH 1 H12700 histogram with data sheet gain factors


for (j=0; j<64; j++) { //reads the 64 data points for the gain
fscanf(fp, "%lf", &UniPi_Gain); //reads 1 data point
}//End inner for loop

for (int t=0; t<64; t++) {
fscanf(fp, "%lf", &extra); //As a result of how fscanf works, the last value in a given data line was previously duplicated 64 times. This dummy variable takes that duplication and ignores it, preventing it from getting mxied in the actual data
}//end extra loop

}//End outer for loop

fclose(fp); //close the RICH 1 H12700 .txt

for (k=0; k<180; k++) { //reads all rows of the table
fscanf(fp2, "%c %c %lf %lf %lf %lf %lf %lf %lf", &L, &A, &SerialNumb, &Sk, &Sp, &Idb1, &Idb2, &Skb, &Gain); //scans the document and fills dummy variables
h2->Fill(Gain); //fills the RICH 2 H12700 histograms with the data sheet gain factors


for (j=0; j<64; j++) { //reads the 64 data points for the gain
fscanf(fp2, "%lf", &UniPi_Gain); //reads 1 data point
}//End inner for loop

for (int t=0; t<64; t++) {
fscanf(fp2, "%lf", &extra); //As a result of how fscanf works, the last value in a given data line was previously duplicated 64 times. This dummy variable takes that duplication and ignores it, preventing it from getting mxied in the actual data
}//end extra loop

}//End outer for loop

fclose(fp2); //close the RICH 1 H12700 .txt */

for (k=0; k<82; k++) { //reads all rows of the table
fscanf(fp3, "%c %c %lf %lf %lf %lf %lf %lf %lf", &L, &A, &SerialNumb, &Sk, &Sp, &Idb1, &Idb2, &Skb, &Gain); //scans document for dummy variables
h3->Fill(Gain); //fills the RICH 1 H8500 histograms with the data sheet gain factors


for (j=0; j<64; j++) { //reads the 64 data points for the gain
fscanf(fp3, "%lf", &UniPi_Gain); //reads 1 data point
}//End inner for loop

for (int t=0; t<64; t++) {
fscanf(fp3, "%lf", &extra); //As a result of how fscanf works, the last value in a given data line was previously duplicated 64 times. This dummy variable takes that duplication and ignores it, preventing it from getting mxied in the actual data
}//end extra loop

}//End outer for loop

fclose(fp3); //close the RICH 1 H8500 .txt

h1->GetXaxis()->SetTitle("Data Sheet Gain Factor"); //title the first histogram's x-axis
TCanvas* c2 = new TCanvas("c2","Aiden2",1600,1100); //New canvas for the histograms
h1->SetLineColor(1); //color the RICH 1 H12700s histo grey/black
h2->SetLineColor(2); //color the RICH 2 H12700s histo red
h3->SetLineColor(4); //color the RICH 1 H8500s histo blue
h1->Draw(); //draws the RICH 1 H12700s histogram on the canvas
h2->Draw("Same"); //draws the RICH 2 H12700s histo on the same pad
h3->Draw("Same"); //draws the RICH 1 H8500s histo on the same pad
auto legend = new TLegend(0.78,.79,0.98,0.90);
gStyle->SetLegendTextSize(0.020);
legend->AddEntry(h1,"RICH 1 & 2 H12700s (Avg: 2.368)","l");
legend->AddEntry(h2,"RICH 2 H12700s (Avg: 2.409)","l");
legend->AddEntry(h3,"RICH 1 H8500s (Avg: 2.916)","l");
legend->Draw();
c2->Print("Data Sheet Gain Histo Distribution.pdf"); //saves the current canvas as a pdf

}//end main
