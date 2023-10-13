#include "sierrachart.h"
SCDLLName("VG - Study Input Change on Symbol Change")

/* 
Author: https://github.com/vanillagreen
Big thanks to Luda on Trader Network Lounge Discord
*/

SCSFExport scsf_StudyInputChangeSymChange(SCStudyInterfaceRef sc)
{
    // Define study inputs
    SCInputRef Input_LargeVolumeStudyID = sc.Input[0];
    SCInputRef Input_LargeVolumeStudyInputID = sc.Input[1];
    SCInputRef Input_One = sc.Input[2];
    SCInputRef Input_One_Value = sc.Input[3];
    SCInputRef Input_Two = sc.Input[4];
    SCInputRef Input_Two_Value = sc.Input[5];
    SCInputRef Input_Three = sc.Input[6];
    SCInputRef Input_Three_Value = sc.Input[7];
    SCInputRef Input_Four = sc.Input[8];
    SCInputRef Input_Four_Value = sc.Input[9];
    SCInputRef Input_Five = sc.Input[10];
    SCInputRef Input_Five_Value = sc.Input[11];
    
    
    if (sc.SetDefaults)
    {
        // Set default settings
        sc.GraphRegion = 0;
        sc.GraphName = "Study Input Change on Symbol Change";
        sc.StudyDescription = "Adjusts the input of another study based on the symbol.";
        sc.AutoLoop = 0;  // Disable AutoLoop

        // Initialize study inputs
        Input_LargeVolumeStudyID.Name = "Large Volume Study ID";
        Input_LargeVolumeStudyID.SetInt(5);

        Input_LargeVolumeStudyInputID.Name = "Large Volume Study Input ID";
        Input_LargeVolumeStudyInputID.SetInt(1);

        Input_One.Name= "Symbol 1";
        Input_One.SetString("AAPL_MBO");
        Input_One_Value.Name = "Symbol 1 Value";
        Input_One_Value.SetFloat(2500.0);

        Input_Two.Name= "Symbol 2";
        Input_Two.SetString("TSLA_MBO");
        Input_Two_Value.Name = "Symbol 2 Value";
        Input_Two_Value.SetFloat(2000.0);

        Input_Three.Name= "Symbol 3";
        Input_Three.SetString("ES-202312-CME");
        Input_Three_Value.Name = "Symbol 3 Value";
        Input_Three_Value.SetFloat(5.0);

        Input_Four.Name= "Symbol 4";
        Input_Four.SetString("NQ-202312-CME");
        Input_Four_Value.Name = "Symbol 4 Value";
        Input_Four_Value.SetFloat(5.0);

        Input_Five.Name= "Symbol 4";
        Input_Five.SetString("MNQ-202312-CME-USD");
        Input_Five_Value.Name = "Symbol 5 Value";
        Input_Five_Value.SetFloat(15.0);

        return;
    }

    // Only run this code on a full recalculation (e.g., symbol switch event)
    if (!sc.IsFullRecalculation)
    {
        return;
    }

    // Get the Large Volume Study ID
    int largeVolumeStudyID = Input_LargeVolumeStudyID.GetInt();

    // Adjust the input of the Large Volume Study based on the symbol
    if (sc.Symbol == Input_One.GetString())
    {
        sc.SetChartStudyInputInt(sc.ChartNumber, largeVolumeStudyID, Input_LargeVolumeStudyInputID.GetInt() - 1, Input_One_Value.GetInt());
    }
    else if (sc.Symbol == Input_Two.GetString())
    {
        sc.SetChartStudyInputInt(sc.ChartNumber, largeVolumeStudyID, Input_LargeVolumeStudyInputID.GetInt() - 1, Input_Two_Value.GetInt());
    }
    else if (sc.Symbol == Input_Three.GetString())
    {
        sc.SetChartStudyInputInt(sc.ChartNumber, largeVolumeStudyID, Input_LargeVolumeStudyInputID.GetInt() - 1, Input_Three_Value.GetInt());
    }
    else if (sc.Symbol == Input_Four.GetString())
    {
        sc.SetChartStudyInputInt(sc.ChartNumber, largeVolumeStudyID, Input_LargeVolumeStudyInputID.GetInt() - 1, Input_Four_Value.GetInt());
    }
    else if (sc.Symbol == Input_Five.GetString())
    {
        sc.SetChartStudyInputInt(sc.ChartNumber, largeVolumeStudyID, Input_LargeVolumeStudyInputID.GetInt() - 1, Input_Five_Value.GetInt());
    }

}
