#define SIGfakes_cxx
#include "SIGfakes.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TLegend.h"
#include "TRatioPlot.h"

void SIGfakes::Loop()
{
//   In a ROOT session, you can do:
//      root> .L SIGfakes.C
//      root> SIGfakes t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

 
   int nbins = 15;
   int min3 = -3;
   int max30 = 10;
   TH1F* sig1_15B;
   TH1F* sig15_2B;
   TH1F* sig2_5B;
   TH1F* sig5B;
   TH1F* sig2_5E;
   TH1F* sig5E;
   TH1F* sigtot;
	
   sig1_15B = new TH1F("sig1_15B","", nbins, min3, max30); 
   sig1_15B->Sumw2();
   sig15_2B = new TH1F("sig15_2B","", nbins, min3, max30); 
   sig15_2B->Sumw2();
   sig2_5B = new TH1F("sig2_5B","", nbins, min3, max30); 
   sig2_5B->Sumw2();
   sig5B = new TH1F("sig5B","", nbins, min3, max30); 
   sig5B->Sumw2();
   sig2_5E = new TH1F("sig2_5E","", nbins, min3, max30); 
   sig2_5E->Sumw2();
   sig5E = new TH1F("sig5E","", nbins, min3, max30); 
   sig5E->Sumw2();
   sigtot = new TH1F("sigtot","", nbins, min3, max30); 
   sigtot->Sumw2();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
   }
   
    for (int jEntry=0; jEntry < nentries; ++jEntry) {
	  fChain->GetEntry(jEntry);
	  if(bMass < 5.5 && bMass > 5){
		  if(elePt>1){
		  if(dR_ele_mu1mu2<0.8){
			sigtot->Fill(eleMvaId);
			if(eleEta<1.479 && eleEta>-1.479){	//barrel
			if(elePt>1 && elePt<1.5){
				sig1_15B->Fill(eleMvaId);
			}
			if(elePt>1.5 && elePt<2){
				sig15_2B->Fill(eleMvaId);
			}
			if(elePt>2 && elePt<5){
				sig2_5B->Fill(eleMvaId);
			}
			if(elePt>5){
				sig5B->Fill(eleMvaId);
			}	
			}
			if(eleEta>1.479 || eleEta<-1.479){	//endcap	
			if(elePt>2 && elePt<5){
				sig2_5E->Fill(eleMvaId);
			}
			if(elePt>5){
				sig5E->Fill(eleMvaId); 
			}	
			}
		}
	}
	}
}
	
	
  sig5B->Scale(1/sig5B->Integral("width"));
  sig2_5B->Scale(1/sig2_5B->Integral("width"));
  sig15_2B->Scale(1/sig15_2B->Integral("width"));
  sig1_15B->Scale(1/sig1_15B->Integral("width"));
  sig2_5E->Scale(1/sig2_5E->Integral("width"));
  sig5E->Scale(1/sig5E->Integral("width")); 
  sigtot->Scale(1/sigtot->Integral("width")); 
  
  	
  TFile* f = TFile::Open("isto_MCfakes.root");
	
  TH1F* MC2_5E = (TH1F*)f->Get("MC2_5E");
  MC2_5E->Scale(1/MC2_5E->Integral("width"));
 
  
  auto c1 = new TCanvas("c1", "A ratio example");
  auto legend222 = new TLegend(0.71,0.755,0.898,0.925);
  gStyle->SetErrorX(0);
  legend222 -> AddEntry(MC2_5E, "MC", "el");
  legend222 -> AddEntry(sig2_5E, "Data", "ep");
  gStyle->SetOptStat(0);
  sig2_5E->GetYaxis()->SetRangeUser(0., 0.35);
  sig2_5E->SetLineColor(kBlack);	 
  sig2_5E->SetMarkerColor(kBlack);	 
  sig2_5E->SetMarkerStyle(8);
  sig2_5E->SetLineWidth(1);
  sig2_5E->SetTitle("Endcap  2 GeV < p_{t} < 5 GeV");
  sig2_5E->SetTitleSize(0.04);
  MC2_5E->SetLineColor(kRed);	 
  MC2_5E->SetMarkerColor(kRed);	 
  MC2_5E->SetMarkerStyle(1);
  MC2_5E->SetLineWidth(1); 
  sig2_5E->GetXaxis()->SetTitle("probeMvaId");
  sig2_5E->GetYaxis()->SetTitle("A.U.");
  sig2_5E->GetXaxis()->SetTitleSize(0.04);
  sig2_5E->GetYaxis()->SetTitleSize(0.04);
  sig2_5E->GetXaxis()->SetLabelSize(0.04);
  sig2_5E->GetYaxis()->SetLabelSize(0.04);
  legend222->Draw();
  auto rp = new TRatioPlot(sig2_5E, MC2_5E, "pois");
  c1->SetTicks(0, 1);
  rp->SetH2DrawOpt("eHIST");
  rp->SetH1DrawOpt("ep");
  rp->Draw();
  //rp->GetUpperPad()->cd();
  //sig2_5E->Draw("PE SAME");   
  //MC2_5E->Draw("LE SAME");   
  legend222->Draw();
  rp->GetLowYaxis()->SetNdivisions(505);
  std::vector<double> lines = {1};
  rp->SetGridlines(lines);
  rp->GetLowerRefYaxis()->SetTitle("data/MC");
  rp->GetLowerRefGraph()->SetMinimum(0);
  rp->GetLowerRefGraph()->SetMaximum(3);
  rp->GetLowerRefGraph()->GetXaxis()->SetTitleSize(0.04);
  rp->GetLowerRefGraph()->GetYaxis()->SetTitleSize(0.04);
  rp->GetLowerRefGraph()->GetXaxis()->SetLabelSize(0.04);
  rp->GetLowerRefGraph()->GetYaxis()->SetLabelSize(0.04);
  c1->SaveAs("grafici3/f_ratioplot2_5E.png");
}
