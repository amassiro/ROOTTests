
void test()
{
  THStack *hs = new THStack("hs","Stacked 1D histograms");
  //create three 1-d histograms
  TH1F *h1st = new TH1F("h1st","test hstack",100,-4,4);
  h1st->FillRandom("gaus",20000);
  h1st->SetFillColor(kRed);
  h1st->SetMarkerStyle(21);
  h1st->SetMarkerColor(kRed);
  hs->Add(h1st);
 
  TH1F *h2st = new TH1F("h2st","test hstack",100,-4,4);
  
  TF1 *funz = new TF1("funz","gaus",-4,4);
  funz->SetParameter(0, 1.0);
  funz->SetParameter(1, 1.0);
  funz->SetParameter(2, 0.5);
  h2st->FillRandom("funz",10000);
  h2st->SetFillColor(kBlue);
  h2st->SetMarkerStyle(21);
  h2st->SetMarkerColor(kBlue);
  
  //----
  // change sign for some bins
  
  for (int ibin=0; ibin<h2st->GetNbinsX(); ibin++) {
    if (ibin<(h2st->GetNbinsX()*2/3)) {
      h2st->SetBinContent (ibin+1, -1. * h2st->GetBinContent(ibin+1));
    }
  }
  //----
  
  hs->Add(h2st);
  
  TH1F *h3st = new TH1F("h3st","test hstack",100,-4,4);
  h3st->FillRandom("gaus",10000);
  h3st->SetFillColor(kGreen);
  h3st->SetMarkerStyle(21);
  h3st->SetMarkerColor(kGreen);
  hs->Add(h3st);
  
  TCanvas *cst = new TCanvas("cst","stacked hists",10,10,700,700);
  cst->Divide(2,1);
  // in top left pad, draw the stack with defaults
  cst->cd(1);
  hs->Draw("hist");
  
  // in top right pad, draw the stack in non-stack mode
  // and errors option
  cst->cd(2);
  gPad->SetGrid();
  hs->Draw("nostack,e1p");
 
  
}