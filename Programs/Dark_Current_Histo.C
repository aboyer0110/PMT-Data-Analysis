#include <vector>
#include <string>
#include <TCanvas.h>
#include <TNamed.h>
#include <TGraph.h>
#include <fstream>
#include <numeric>

void Dark_Current_Histo() {

char L, A; //characters to be read from .txt file
double Sk, Sp, Idb1, Idb2, Skb, Gain, UniPi_Gain, extra, SerialNumb, Product; //double variables, most of them used as dummy variables
FILE * fp = fopen("H12700.txt", "r"); //open RICH 1 H12700 .txt file
FILE * fp2 = fopen("GainTableCopy.txt", "r"); //open RICH 2 H12700 .txt file
FILE * fp3 = fopen("H8500.txt", "r"); //open RICH 1 H8500 .txt file

int j, k; //counters for loop

TH1F *h1 = new TH1F("Dark Current","Dark Current (-1000 V)", 25, 0.2, 15); //instantiate RICH 1 H12700 dark current histo for -1000 V
TH1F *h2 = new TH1F("Dark Current","Dark Current (-1100 V)", 25, 0.2, 35); //instantiate RICH 1 H12700 dark current histo for -1100 V
TH1F *h3 = new TH1F("Dark Current","Dark Current (-1000 V)", 25, 0.2, 15); //instantiate RICH 2 H12700 dark current histo for -1000 V
TH1F *h4 = new TH1F("Dark Current","Dark Current (-1100 V)", 25, 0.2, 35); //instantiate RICH 2 H12700 dark current histo for -1100 V
TH1F *h5 = new TH1F("Dark Current","Dark Current (-1000 V)", 25, 0.2, 15); //instantiate RICH 1 H8500 dark current histo for -1000 V
TH1F *h6 = new TH1F("Dark Current","Dark Current (-1100 V)", 25, 0.2, 35); //instantiate RICH 1 H8500 dark current histo for -1100 V
gStyle->SetOptStat(1000000001);

for (k=0; k<530; k++) { //reads all rows of the table
fscanf(fp, "%c %c %lf %lf %lf %lf %lf %lf %lf", &L, &A, &SerialNumb, &Sk, &Sp, &Idb1, &Idb2, &Skb, &Gain); //reads document and fills dummy variables
h1->Fill(Idb1); //fills h1 with dark current data (-1000 V)
h2->Fill(Idb2); //fills h2 with dark current data (-1100 V)

for (j=0; j<64; j++) { //reads the 64 data points for the gain
fscanf(fp, "%lf", &UniPi_Gain); //reads 1 data point
}//End inner for loop

for (int t=0; t<64; t++) {
fscanf(fp, "%lf", &extra); //As a result of how fscanf works, the last value in a given data line was previously duplicated 64 times. This dummy variable takes that duplication and ignores it, preventing it from getting mxied in the actual data
}//end extra loop

}//End outer for loop

fclose(fp); //close the RICH 1 H12700 .txt file

for (k=0; k<180; k++) { //reads all rows of the table
fscanf(fp2, "%c %c %lf %lf %lf %lf %lf %lf %lf", &L, &A, &SerialNumb, &Sk, &Sp, &Idb1, &Idb2, &Skb, &Gain); //reads document and fills dummy variables
h3->Fill(Idb1); //fills h3 with dark current data (-1000 V)
h4->Fill(Idb2); //fills h4 with dark current data (-1100 V)


for (j=0; j<64; j++) { //reads the 64 data points for the gain
fscanf(fp2, "%lf", &UniPi_Gain); //reads 1 data point
}//End inner for loop

for (int t=0; t<64; t++) {
fscanf(fp2, "%lf", &extra); //As a result of how fscanf works, the last value in a given data line was previously duplicated 64 times. This dummy variable takes that duplication and ignores it, preventing it from getting mxied in the actual data
}//end extra loop

}//End outer for loop

fclose(fp2); //close the RICH 2 H12700 .txt file */

for (k=0; k<82; k++) { //reads all rows of the table
fscanf(fp3, "%c %c %lf %lf %lf %lf %lf %lf %lf", &L, &A, &SerialNumb, &Sk, &Sp, &Idb1, &Idb2, &Skb, &Gain); //reads document and fills dummy variable
h5->Fill(Idb1); //fills h5 with dark current data (-1000 V)
h6->Fill(Idb2); //fills h6 with dark current data (-1100 V)

for (j=0; j<64; j++) { //reads the 64 data points for the gain
fscanf(fp3, "%lf", &UniPi_Gain); //reads 1 data point
}//End inner for loop

for (int t=0; t<64; t++) {
fscanf(fp3, "%lf", &extra); //As a result of how fscanf works, the last value in a given data line was previously duplicated 64 times. This dummy variable takes that duplication and ignores it, preventing it from getting mxied in the actual data
}//end extra loop

}//End outer for loop

fclose(fp3); //close the RICH 1 H8500 .txt

h1->GetXaxis()->SetTitle("Dark Current (nA)"); //titles the x-axis for the -1000 V dark current histo
TCanvas* c2 = new TCanvas("c2","Aiden2",1600,1100); //New canvas for the histograms
h1->SetLineColor(1); //color the RICH 1 H12700 histo
h3->SetLineColor(2); //color the RICH 2 H12700 histo
h5->SetLineColor(4); //color the RICH 1 H8500 histo
h1->Draw(); //draw the RICH 1 H12700 dark current histo
h3->Draw("Same"); //draw the RICH 2 H12700 dark current histo on the same pad
h5->Draw("Same"); //draw the RICH 1 H8500 dark current histo on the same pad
auto legend = new TLegend(0.78,.79,0.98,0.90);
gStyle->SetLegendTextSize(0.020);
legend->AddEntry(h1,"RICH 1 H12700s (Avg: 1.243)","l");
legend->AddEntry(h3,"RICH 2 H12700s (Avg: 1.321)","l");
legend->AddEntry(h5,"RICH 1 H8500s (Avg: 1.082)","l");
legend->Draw();
c2->Print("Dark Current Distribution (-1000 V).pdf"); //print the current canvas to pdf

h2->GetXaxis()->SetTitle("Dark Current (nA)"); //titles the x-axis for the -1100 V dark current histo
TCanvas* c3 = new TCanvas("c3","Aiden3",1600,1100); //New canvas for the histograms
h2->SetLineColor(1); //color the RICH 1 H12700 histo
h4->SetLineColor(2); //color the RICH 2 H12700 histo
h6->SetLineColor(4); //color the RICH 1 H8500 histo
h2->Draw(); //draw the RICH 1 H12700 dark current histo
h4->Draw("Same"); //draw the RICH 2 H12700 dark current histo on the same pad 
h6->Draw("Same"); //draw the RICH 1 H8500 dark current histo on the same pad
auto legend2 = new TLegend(0.78,.79,0.98,0.90);
gStyle->SetLegendTextSize(0.020);
legend2->AddEntry(h2,"RICH 1 & 2 H12700s (Avg: 3.718)","l");
legend2->AddEntry(h4,"RICH 2 H12700s (Avg: 3.313)","l");
legend2->AddEntry(h6,"RICH 1 H8500s (Avg: 0)","l");
legend2->Draw();
c3->Print("Dark Current Distribution (-1100 V).pdf"); //prints the canvas to a pdf
}//end main

