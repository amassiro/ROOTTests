
#include "test.cxx"
#include "testBad.cxx"


void testBase(){
  
  TTree tree("tree", "tree");
  float a;
  tree.Branch("a1", &a);
  tree.Branch("a2", &a);
  tree.Branch("a3", &a);
  tree.Branch("a4", &a);
  tree.Branch("a5", &a);
  tree.Branch("a6", &a);
  tree.Branch("a7", &a);
  tree.Branch("a8", &a);
  tree.Branch("a9", &a);
  tree.Branch("a10", &a);
  tree.Branch("a11", &a);
  
  for (int i=0; i<100; i++) {
    a = i * 3.14;
    tree.Fill();
  }  
  
  TCanvas* cc1 = new TCanvas ("cc1", "", 800,600);
  tree.Draw("a1");
  
  TCanvas* cc2 = new TCanvas ("cc2", "", 800,600);
  tree.Draw("test(a1,a2,a3,a4,a5,a6,a7,a8,a9)");
  
  TCanvas* cc3 = new TCanvas ("cc3", "", 800,600);
  tree.Draw("testBad(a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11)");

  
}


