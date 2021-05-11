#include <vector>
#include <string>
#include <TCanvas.h>
#include <TNamed.h>
#include <TGraph.h>
#include <fstream>
#include <numeric>


void Gain_Product_Histo() {

char L, A; //characters to be read in from the .txt files
double Sk, Sp, Idb1, Idb2, Skb, Gain, UniPi_Gain, extra, SerialNumb, Product; //double variables, most are dummy variables to allow the proper reading of data
FILE * fp = fopen("H12700.txt", "r"); //open the RICH 1 H12700 .txt file
FILE * fp2 = fopen("GainTableCopy.txt", "r"); //open the RICH 2 H12700 .txt file
FILE * fp3 = fopen("H8500.txt", "r"); //open the RICH 1 H8500 .txt file

int j, k; //counters for loop

TH1F *h1 = new TH1F("Individual Pixel Gain","Individual Pixel Gain", 25, 0, 6); //instantiate a histogram for the RICH 1 H12700 data
TH1F *h2 = new TH1F("Individual Pixel Gain","Individual Pixel Gain", 25, 0, 6); //instantiate a histogram for the RICH 2 H12700 data
TH1F *h3 = new TH1F("Individual Pixel Gain","Individual Pixel Gain", 25, 0, 6); //instantiate a histogram for the RICH 1 H8500 data
gStyle->SetOptStat(1000000001); //option that disables the "entries" display for the histogram as they would be inaccurately displayed

for (k=0; k<530; k++) { //reads all rows of the table
fscanf(fp, "%c %c %lf %lf %lf %lf %lf %lf %lf", &L, &A, &SerialNumb, &Sk, &Sp, &Idb1, &Idb2, &Skb, &Gain); //scans the documents and fills dummy variables with information

for (j=0; j<64; j++) { //reads the 64 data points for the gain
fscanf(fp, "%lf", &UniPi_Gain); //reads in 1 data point
Product=(Gain*UniPi_Gain)/100; //calculates a gain factor, which is a percentage
h1->Fill(Product); //fills a histogram with these calculated gain factors for the RICH 1 H12700s
}//End inner for loop

for (int t=0; t<64; t++) {
fscanf(fp, "%lf", &extra); //As a result of how fscanf works, the last value in a given data line was previously duplicated 64 times. This dummy variable takes that duplication and ignores it, preventing it from getting mixed in the actual data
}//end extra loop

}//End outer for loop

fclose(fp); //close the RICH 1 H12700 .txt file

for (k=0; k<180; k++) { //reads all rows of the table
fscanf(fp2, "%c %c %lf %lf %lf %lf %lf %lf %lf", &L, &A, &SerialNumb, &Sk, &Sp, &Idb1, &Idb2, &Skb, &Gain); //scans the document and fills dummy variables with information

for (j=0; j<64; j++) { //reads the 64 data points for the gain
fscanf(fp2, "%lf", &UniPi_Gain); //reads in 1 data point 
Product=(Gain*UniPi_Gain)/100; //calculates a gain factor, which is a percentage
h2->Fill(Product); //fills a histogram with these calculated gain factors for the RICH 2 H12700s
}//End inner for loop

for (int t=0; t<64; t++) {
fscanf(fp2, "%lf", &extra); //As a result of how fscanf works, the last value in a given data line was previously duplicated 64 times. This dummy variable takes that duplication and ignores it, preventing it from getting mxied in the actual data
}//end extra loop

}//End outer for loop

fclose(fp2); //close the RICH 2 H12700 .txt file */

for (k=0; k<82; k++) { //reads all rows of the table
fscanf(fp3, "%c %c %lf %lf %lf %lf %lf %lf %lf", &L, &A, &SerialNumb, &Sk, &Sp, &Idb1, &Idb2, &Skb, &Gain); //scans the document and fills dummy variables with information

for (j=0; j<64; j++) { //reads the 64 data points for the gain
fscanf(fp3, "%lf", &UniPi_Gain); //reads in 1 data point
Product=(Gain*UniPi_Gain)/100; //calculates a gain factor, which is a percentage
h3->Fill(Product); //fills a histogram with these calculated gain factors for the RICH 1 H8500s
}//End inner for loop

for (int t=0; t<64; t++) {
fscanf(fp3, "%lf", &extra); //As a result of how fscanf works, the last value in a given data line was previously duplicated 64 times. This dummy variable takes that duplication and ignores it, preventing it from getting mxied in the actual data
}//end extra loop

}//End outer for loop

h1->GetXaxis()->SetTitle("Individual Pixel Gain (10^6)"); //title the first histogram x-axis
h1->GetYaxis()->SetTitle("Frequency of Ocurrence"); //title the first histogram y-axis
TCanvas* c2 = new TCanvas("c2","Aiden2",1600,1100); //New canvas for the histograms
h1->SetLineColor(1); //color the first histogram grey/black
h2->SetLineColor(2); //color the second histogram red
h3->SetLineColor(4); //color the third histogram blue
h1->Draw(); //draw the first histogram
h2->Draw("Same"); //draw the second histogram on the same pad
h3->Draw("Same"); //draw the third histogram on the same pad
auto legend = new TLegend(0.78,.79,0.98,0.90);
gStyle->SetLegendTextSize(0.020);
legend->AddEntry(h1,"RICH 1 & 2 H12700s (Avg: 1.842)","l");
legend->AddEntry(h2,"RICH 2 H12700s (Avg: 1.901)","l");
legend->AddEntry(h3,"RICH 1 H8500s (Avg: 2.164)","l");
legend->Draw();
c2->Print("Individual Pixel Gain Histo.pdf"); //print the canvas to a pdf

}//end main
