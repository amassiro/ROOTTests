
// 
//  g++ -o RDataFrameFilter.exe RDataFrameFilter.cpp `root-config --cflags --glibs`
//  
 

#include <ROOT/RDataFrame.hxx>
#include "TCanvas.h"


int main() {
  
  //
  // Ad hoc tree generation
  //
  
  TTree* tree = new TTree("tree", "tree");
  float a_v[100];
  int b;
  tree->Branch("a_v",a_v, "a_v[100]/F");
  tree->Branch("b",&b, "b/I");
  
  for (int i=0; i<1000; i++){
    for (int j=0; j<100; j++){
      a_v[j] =  j+i;
      b = i%10;
    }
    tree->Fill();
  }
  
  tree->Print();
  
  
  ROOT::RDataFrame dataframe_data (*tree);
  
  
  TCanvas* cc = new TCanvas ("cc", "only b", 800, 600);
  auto histo = dataframe_data.Histo1D("b");
  histo->Draw();
  
  
  TCanvas* cc_simple = new TCanvas ("cc_simple", "simple", 800, 600);
  auto count_simple = dataframe_data.Filter ("b>3").Count();
  std::cout << "count_simple = " << *count_simple << std::endl;
  
  auto simple = dataframe_data.Filter ("b>3");
  std::cout << "count  = " << *(simple.Count()) << std::endl;
  
  auto histo_simple = simple.Histo1D("b");
  histo_simple->Draw();
  

  
  
  
  TCanvas* cc_simple_vect = new TCanvas ("cc_simple_vect", "vect", 800, 600);
  
  
  auto df_vect = dataframe_data.Filter ("a_v[b]>3");
  std::cout << "count 1  = " << *(df_vect.Count()) << std::endl;

  
  auto df_vect_new = dataframe_data.Define ("a_v_b", "a_v[b]"). Filter ("a_v_b>3");
  std::cout << "count 2  = " << *(df_vect_new.Count()) << std::endl;
  
  
}



