


Why you cannot use macro in TTree Draw with more than 10 arguments?
TFormula Analyse issue



To test:

    root -l testBase.cxx
    
    -> test.cxx 9 variables
    -> testBad.cxx   11 variables
    
Does not work:

    CMSSW_8_0_26_patch1/ ---> cmsenv
    6.06/01

Does work:

    CMSSW_10_2_0/ ---> cmsenv
    6.12/07
    
    
    