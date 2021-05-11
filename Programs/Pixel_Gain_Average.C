#include <vector>
#include <string>
#include <TCanvas.h>
#include <TNamed.h>
#include <TGraph.h>
#include <fstream>

void Pixel_Gain_Average() {

char L, A; //characters to be read in from the data file
double Sk, Sp, Idb1, Idb2, Skb, Gain, UniPi_Gain, extra, LANumb, Average, pixel_sum, SerialNumb; //double variables, most of them are dummy variables to facilitate the data read
vector <double> UniPi_Gain_list_OldH12700, UniPi_Gain_list_NewH12700, UniPi_Gain_list_H8500, Pixel_Sum_list_OldH12700, Pixel_Sum_list_NewH12700, Pixel_Sum_list_H8500, Average_list_OldH12700, Average_list_NewH12700, Average_list_H8500; //large vectors that will store an assortment of things across the RICH 1 and RICH 2 components
vector <double> UniPi = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64}; //Number of Pixels

FILE * fp = fopen("H8500.txt", "r"); //Open the txt file that contains RICH 1 H8500 data

int j, k; //counters for loop

for (k=0; k<82; k++) { //reads all rows of the table, k changes depending on size of table
fscanf(fp, "%c %c %lf %lf %lf %lf %lf %lf %lf", &L, &A, &SerialNumb, &Sk, &Sp, &Idb1, &Idb2, &Skb, &Gain); //scans the document and stores dummy variables

for (j=0; j<64; j++) { //reads the 64 data points for the gain
fscanf(fp, "%lf", &UniPi_Gain); //reads 1 data point
UniPi_Gain_list_H8500.push_back(UniPi_Gain); //push the gain values into a vector for easy plotting
}//End inner for loop

for (int t=0; t<64; t++) {
fscanf(fp, "%lf", &extra); //as a result of how fscanf works, it scans an additional 64 data point duplicates. this loop throws those points away so they don't mix with actual data
}//end extra loop
}//End outer for loop

fclose(fp);//close the RICH 1 H8500 .txt

FILE * fp2 = fopen("OldH12700.txt", "r"); //open the txt file that contains the RICH 1 H12700 data

for (k=0; k<350; k++) { //reads all rows of the table, k changes depending on size of table
fscanf(fp2, "%c %c %lf %lf %lf %lf %lf %lf %lf", &L, &A, &SerialNumb, &Sk, &Sp, &Idb1, &Idb2, &Skb, &Gain); //scans document and fills dummy variables

for (j=0; j<64; j++) { //reads the 64 data points for the gain
fscanf(fp2, "%lf", &UniPi_Gain); //reads 1 data point
UniPi_Gain_list_OldH12700.push_back(UniPi_Gain); //push the gain values into a vector for easy plotting
}//End inner for loop

for (int t=0; t<64; t++) {
fscanf(fp2, "%lf", &extra); //scans the duplicate entries and fills them to a dummy variable
}//end extra loop
}//End outer for loop

fclose(fp2); //close the RICH 1 H12700 .txt

FILE * fp3 = fopen("GainTableCopy.txt", "r"); //open the RICH 2 H12700 .txt

for (k=0; k<180; k++) { //read all rows of the data table
fscanf(fp3, "%c %c %lf %lf %lf %lf %lf %lf %lf", &L, &A, &SerialNumb, &Sk, &Sp, &Idb1, &Idb2, &Skb, &Gain); //scans document and fills dummy variables

for (j=0; j<64; j++) { //reads the 64 data points for the gain
fscanf(fp3, "%lf", &UniPi_Gain); //reads 1 data point
UniPi_Gain_list_NewH12700.push_back(UniPi_Gain); //push the gain values into a vector for easy plotting
}//End inner for loop

for (int t=0; t<64; t++) {
fscanf(fp3, "%lf", &extra); //scans the duplicate entries and fills them to a dummy variable
}//end extra loop
}//End outer for loop

fclose(fp3); //close the RICH 2 H12700 .txt

int p=0; //initialize p, will keep track of sets of 64 data point

for (int r=0; r<64; r++) { //loop over pixel numbers

for (int q=0; q<350; q++) { //loop over RICH 1 H12700s
pixel_sum=pixel_sum+UniPi_Gain_list_OldH12700[r+p]; //calculate the sum of pixel entries
p=p+64; //incrememnt P to the next SN
}//loop for adding all Uni_Pi values of a specific Uni_Pi across all SN's

Pixel_Sum_list_OldH12700.push_back(pixel_sum); //storing the sum
pixel_sum=0; //re-initialize for the next part of the loop
p=0; //re-initialize for the next part of the loop
}//end outer loop

for (int i=0; i<Pixel_Sum_list_OldH12700.size(); i++) {
Average=Pixel_Sum_list_OldH12700[i]/350; //change division based on number of total MAPMTs, calculates average
Average_list_OldH12700.push_back(Average); //store average for easy plotting
} //end the average loop

for (int r=0; r<64; r++) { //loop over pixel number

for (int q=0; q<180; q++) { //loop over RICH 2 H12700s
pixel_sum=pixel_sum+UniPi_Gain_list_NewH12700[r+p]; //calculate the sum of pixel entries
p=p+64; //incrememnt P to the next SN
}//loop for adding all Uni_Pi values of a specific Uni_Pi across all SN's

Pixel_Sum_list_NewH12700.push_back(pixel_sum); //store the sum
pixel_sum=0; //re-initialize for the next part of the loop
p=0; //re-initialize for the next part of the loop
}//end outer loop

for (int i=0; i<Pixel_Sum_list_NewH12700.size(); i++) {
Average=Pixel_Sum_list_NewH12700[i]/180; //change division based on number of total MAPMTs, calculates average
Average_list_NewH12700.push_back(Average); //stores average for easy plotting
} //end the average loop

for (int r=0; r<64; r++) { //loop over pixel number

for (int q=0; q<82; q++) { //loop over RICH 1 H8500s
pixel_sum=pixel_sum+UniPi_Gain_list_H8500[r+p]; //calculates the sum of pixel entries
p=p+64; //incrememnt P to the next SN
}//loop for adding all Uni_Pi values of a specific Uni_Pi across all SN's

Pixel_Sum_list_H8500.push_back(pixel_sum); //store sum
pixel_sum=0; //re-initialize for the next part of the loop
p=0; //re-initialize for the next part of the loop
}//end outer loop

for (int i=0; i<Pixel_Sum_list_H8500.size(); i++) {
Average=Pixel_Sum_list_H8500[i]/82; //change division based on number of total MAPMTs, calculates average
Average_list_H8500.push_back(Average); //stores average for easy plotting
} //end the average loop

TCanvas* c1 = new TCanvas("c1","Aiden",1600,1100); //instantiate a canvas to allow for the saving of the graph as a pdf

auto mg = new TMultiGraph(); //instantiate multigraph to superimpose the three different plots

TGraph* gr1 = new TGraph(UniPi.size(), &UniPi[0], &Average_list_OldH12700[0]); //instantiate a graph for RICH 1 H12700s
gr1->SetTitle("RICH 1 H12700 MAPMTs"); //title plot, for the legend
gr1->SetMarkerStyle(7); //sets marker type
gr1->SetMarkerSize(4); //sets marker size
gr1->GetXaxis()->SetRangeUser(0,64); //sets X-axis range
mg->Add(gr1); //add current pad to the multigraph

TGraph* gr2 = new TGraph(UniPi.size(), &UniPi[0], &Average_list_NewH12700[0]); //instantiate a graph for the RICH 2 H12700s
gr2->SetTitle("RICH 2 H12700 MAPMTs"); //title plot, for the legend
gr2->SetMarkerStyle(7); //sets marker type
gr2->SetMarkerSize(4); //sets marker size
gr2->SetMarkerColor(2); //sets marker color to red
gr2->SetLineColor(2); //sets line color to red
mg->Add(gr2); //adds current pad to the multigraph

TGraph* gr3 = new TGraph(UniPi.size(), &UniPi[0], &Average_list_H8500[0]); //instantiate a graph for the RICH 1 H8500s
gr3->SetTitle("RICH 1 H8500 MAPMTs"); //title plot, for the legend
gr3->SetMarkerStyle(7); //sets marker type
gr3->SetMarkerSize(4); //sets marker size
gr3->SetMarkerColor(4); //sets marker color to blue
gr3->SetLineColor(4); //sets line color to blue
mg->Add(gr3); //adds current pad to the multigraph

mg->SetTitle("Avg Relative Gain Per Pixel"); //titles the multigraph
mg->GetXaxis()->SetTitle("Pixel"); //titles x-axis
mg->GetXaxis()->SetTitleSize(0.05); //offsets x-axis from default position
mg->GetYaxis()->SetTitle("Avg Relative Gain"); //title y-axis
mg->GetYaxis()->SetTitleSize(0.05); //offsets y-axis from default position
mg->SetMinimum(30); //sets y-axis minimum
mg->SetMaximum(105); //sets y-axis maximum
mg->Draw("APL"); //draw the multigraph with APL options
c1->BuildLegend(); //adds a legend to the graph

c1->Print("Avg Relative Gain Per Pixel.pdf"); //prints canvas to pdf
}//end main
