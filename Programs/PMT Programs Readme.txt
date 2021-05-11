PMT Programs Readme file

Aiden Boyer, Duquesne University, May 10, 2021

Date created: 05/10/2021
Last Updated: 05/10/2021

--------------------------------------------------------------------------------------

Outline

I: Project Description
II: Program Details
III: Concluding Remarks

--------------------------------------------------------------------------------------

Section I: Project Description

This readme file details the various programs included in this project. These were developed by myself during the summer and fall of 2020. These macros read in data tables containing manufacturer data for Hamamatsu Photomultiplier Tubes (PMTs) and plots the distribution of the different fit parameters for the devices.


--------------------------------------------------------------------------------------

Section II: Program Details

The following list includes descriptions for each program and locations where changes are required for use.




1.) Anode_Luminousity_Plot.C - This program reads in PMT data table(s) and plots from them the distribution of the anode luminous sensitivity, which is the anode output current per luminous flux that is incident on a given PMT's anode. In order to function, the following must be changed:

Lines 14-16 must be changed to include the name of the desired data table(s) in .txt. format. Lines can be added or removed as needed.

Lines 25, 42, and 59 must be changed to match the total number of PMTs in the given data sets. See code comments for more detail.




2.) Cathode_Luminousity_Plot.C - This program reads in PMT data table(s) and plots from them the distribution of the cathode luminous sensitivity, which is the photoelectric current produced in the PMT due to an incident light flux on a given PMT's cathode. The following changes must be made:

Lines 14-16 must be changed to include the name of the desired data table(s) in .txt format. Lines can be added or removed as needed.

Lines 25, 42, and 59 must be changed to match the total number of PMTs in the given data sets. See code comments for more detail.




3.) Cathode_Blue_Sensitivity_Plot.C - This program reads in PMT data table(s) and plots from them the distribution of the cathode blue sensitivity index, a quantity that measures the photoelectric current generated from a PMT when a blue filter is superimposed within the same system that measures cathode luminous sensitivity. In order to function, the following must be changed:

Lines 14-16 must be changed to include the name of the desired data table(s) in .txt format. Lines can be added or removed as needed.

Lines 25, 42, and 59 must be changed to match the total number of PMTs in the given data sets. See code comments for more detail.




4.) Dark_Current_Histo.C - This program reads in PMT data table(s) and plots from them the distribution of dark currents, the residual current within the device when it is not actively being used. The dark current is plotted at -1000 V and -1100 V. In order to function, the following must be changed:

Lines 13-15 must be changed to include the name of the desired data table(s) in .txt format. Lines can be added or removed as needed.

Lines 27, 44, and 62 must be changed to match the total number of PMTs in the given data sets. See code comments for more detail.




5.) Data_Sheet_Gain_Histo.C - This program reads in PMT data table(s) and plots from them the distribution of the gain factor for an entire PMT. In order to function, the following must be changed:

Lines 13-15 must be changed to include the name of the desired data table(s) in .txt format. Lines can be added or removed as needed.

Lines 24, 41, and 58 must be changed to match the total number of PMTs in the given data sets. See code comments for more detail.




6.) Gain_Product_Histo.C - This program reads in PMT data table(s) and plots from them the distribution of the gain factor for individual pixels in each PMT. These individual gain factors are a calculated quantity, given by the product of the gain factor with the relative gain of a single pixel, divided by 100. In order to function, the following changes must be made:

Lines 14-16 must be changed to include the name of the desired data table(s) in .txt format. Lines can be added or removed as needed.

Lines 25, 42, and 59 must be changed to match the total number of PMTs in the given data sets. See code comments for more detail. 





7.) LA_Analysis_2x2.C - This program reads in PMT data table(s) and plots from them the distribution of the relative gains for each pixel in a given PMT, and repeats this process for all PMTs in the specified data sets. Unlike prior programs, this one requires the use of a .txt file that includes only the serial numbers of the PMTs to be analyzed, for labelling purposes. This serial number .txt file must have entries formatted in the following style: LLA####, where the extra L is extraneous and is only included so that the entries can be properly read in. In order to function, the following changes must be made:

Line 16 must be changed to include the name of the desired data table(s) in .txt format. Lines can be added or removed as needed.

Line 45 must be changed to include the name of a .txt file including only the serial numbers of all of the PMTs being analyzed. The serial numbers will be needed to differentiate the different plots.

Lines 20, 47 must be changed to match the total number of PMTs in a given data set. See code comments for details.




8.) Pixel_Gain_Average.C - This program reads in PMT data table(s) and plots from them the distribution of average relative gains for each pixel across all PMTs. Each PMT is constructed with 8 rows of 8 pixels for a total of 64 pixels. In order to function, the following changes must be made:

Lines 15, 34, and 51 must be changed to include the name of the desired data table(s) in .txt format. Lines can be added or removed as needed.

Lines 19, 36, 53, 72, 83, 89, 100, 106, and 117 must be changed to match the total number of PMTs in a given data set. See code comments for details.




9.) Rel_Gain_Histo.C - This program reads in PMT data table(s) and plots from them the distribution of relative gains in a histogram format. In order to function, the following changes must be made:

Lines 20-22 must be changed to include the name of the desired data table(s) in .txt format. Lines can be added or removed as needed.

Lines 25, 42, and 58 must be changed to match the total number of PMTs in a given data set. See code comments for details.




10.) serial_number_setup.C - This program reads in PMT data table(s), retrieves the serial numbers for each PMT, and creates two separate files with their serial numbers, one with a .tsdat extension and another with an .audat extension. These files are prepared for use with pmt_characterization, a program which separates the different PMT data into text files so that they can be uploaded to a data base. In order to function, the following changes must be made:

Line 15 must be changed to include the name of the desire data table(s) in .txt format. Lines can be added or removed as needed.

Line 29 must be changed to match the total number of PMTs in a given data set. See code comments for details.




11.) pmt_characterization.C - This program reads in PMT data table(s) and separates it into two files - one file contains exclusively the relative gains of the PMTs (.audat extension) while the other contains the rest of the fit parameters for the PMTs (.tsdat extension). In order to function, the following changes must be made:

Line 15 must be changed to include the name of the desired data table(s) in .txt format. Lines can be aded or removed as needed. 

Lines 19, 46, and 61 must be changed to match the total number of PMTs in a given data set. See code comments for details.

--------------------------------------------------------------------------------------

Section III: Concluding Remarks

These programs were not designed in the most efficient way possible. If you feel there are any additions that can be made to these, feel free to do so with proper crediting of the original source. In the event of any questions of concerns, contact me at boyera1@duq.edu
