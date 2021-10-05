#define MCfakes_cxx
#include "MCfakes.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <THStack.h>

void MCfakes::Loop()
{
//   In a ROOT session, you can do:
//      root> .L MCfakes.C
//      root> MCfakes t
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

   Long64_t nbytes = 0, nb = 0;
   
   
   int nbins = 15;
   int min3 = -3;
   int max30 = 10;
   TH1F* MC1_15B;
   TH1F* MC15_2B;
   TH1F* MC2_5B;
   TH1F* MC5B;
   TH1F* MC2_5E;
   TH1F* MC5E;
   TH1F* MCtot;
   TH1F* mumuinv_sig;
   TH1F* mumuinv_bkg;
   TH1F* mbinv_sig;
   TH1F* mbinv_bkg;
   THStack* mumuinv;
   THStack* mbinv;
	
   mumuinv = new THStack("hs1","");
   mbinv = new THStack("hs2","");
   
	  
	
   MC1_15B = new TH1F("MC1_15B","", nbins, min3, max30); 
   MC1_15B->Sumw2();
   MC15_2B = new TH1F("MC15_2B","", nbins, min3, max30); 
   MC15_2B->Sumw2();
   MC2_5B = new TH1F("MC2_5B","", nbins, min3, max30); 
   MC2_5B->Sumw2();
   MC5B = new TH1F("MC5B","", nbins, min3, max30); 
   MC5B->Sumw2();
   MC2_5E = new TH1F("MC2_5E","", nbins, min3, max30); 
   MC2_5E->Sumw2();
   MC5E = new TH1F("MC5E","", nbins, min3, max30); 
   MC5E->Sumw2();
   MCtot = new TH1F("MCtot","", nbins, min3, max30); 
   MCtot->Sumw2();
   mumuinv_sig = new TH1F("mumuinv","", 50, 2.8, 3.4); 
   mumuinv_bkg = new TH1F("mumuinv","", 50, 2.8, 3.4); 
   mbinv_sig = new TH1F("mbinv","", 50, 5, 5.5); 
   mbinv_bkg = new TH1F("mbinv","", 50, 5, 5.5); 
	
	   
   
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
  }
      
      
   
   for (int jEntry=0; jEntry < nentries; ++jEntry) {
	  fChain->GetEntry(jEntry);
	  if(mu1MatchMcFromJPsi==1 && mu2MatchMcFromJPsi==1){
		  mumuinv_sig->Fill(mumuMass);
	  }
	  else{
		  mumuinv_bkg->Fill(mumuMass);
	  }
	  if(bMass < 5.5 && bMass > 5){
	  if(bMatchMc==1){
		  mbinv_sig->Fill(bMass);
	  }
	  else{
		  mbinv_bkg->Fill(bMass);
	  }
	  }
	  if(elePt>1){
		  if(bMass < 5.5 && bMass > 5){
		  if(dR_ele_mu1mu2<0.8){
			MCtot->Fill(eleMvaId);
			if(eleEta<1.479 && eleEta>-1.479){	//barrel
			if(elePt>1 && elePt<1.5){
				MC1_15B->Fill(eleMvaId);
			}
			if(elePt>1.5 && elePt<2){
				MC15_2B->Fill(eleMvaId);
			}
			if(elePt>2 && elePt<5){
				MC2_5B->Fill(eleMvaId);
			}
			if(elePt>5){
				MC5B->Fill(eleMvaId);
			}	
			}
			if(eleEta>1.479 || eleEta<-1.479){	//endcap	
			if(elePt>2 && elePt<5){
				MC2_5E->Fill(eleMvaId);
			}
			if(elePt>5){
				MC5E->Fill(eleMvaId); 
			}	
			}
		}
	}
	}
}
	
	mumuinv_bkg->SetLineColor(kBlue);	 
	mumuinv_bkg->SetFillColor(kBlue);	 
	mumuinv_bkg->SetFillStyle(3004);
	mumuinv_bkg->SetLineWidth(2);
	
	mumuinv_sig->SetLineColor(kRed);	 
	mumuinv_sig->SetFillColor(kRed);	 
	mumuinv_sig->SetFillStyle(3004);
	mumuinv_sig->SetLineWidth(2);
	
	mbinv_bkg->SetLineColor(kBlue);	 
	mbinv_bkg->SetFillColor(kBlue);	 
	mbinv_bkg->SetFillStyle(3004);
	mbinv_bkg->SetLineWidth(2);
	
	mbinv_sig->SetLineColor(kRed);	 
	mbinv_sig->SetFillColor(kRed);	 
	mbinv_sig->SetFillStyle(3004);
	mbinv_sig->SetLineWidth(2);
	
	
	mumuinv->Add(mumuinv_bkg, "HIST");
    mumuinv->Add(mumuinv_sig, "HIST");
    mbinv->Add(mbinv_bkg, "HIST");
    mbinv->Add(mbinv_sig, "HIST");


	TCanvas canv2("canv", "canvas for plotting", 1280, 950);
	auto legend2 = new TLegend(0.1,0.7,0.4,0.9);
	//legend1 -> AddEntry(h1, "Candidates", "f");
	legend2 -> AddEntry(mumuinv_bkg, "Background", "f");
	legend2 -> AddEntry(mbinv_sig, "B->J/#psi(#mu^{+}#mu^{-})K", "f");
	mumuinv->Draw("NOSTACK");
	//gPad->SetLogy();
	mumuinv->GetYaxis()->SetMaxDigits(4);
	mumuinv->GetXaxis()->SetLimits(2.8, 3.4);
	mumuinv->GetXaxis()->SetTitle("Reconstructed mass [GeV]");
	mumuinv->GetYaxis()->SetTitle("Events/0.018");
	mumuinv->GetXaxis()->SetTitleSize(0.035);
    mumuinv->GetYaxis()->SetTitleSize(0.035);
    mumuinv->GetXaxis()->SetLabelSize(0.035);
    mumuinv->GetYaxis()->SetLabelSize(0.035);
	legend2->Draw();
	//canv2.SaveAs("grafici2/massaJ.pdf");
	
	
	TCanvas canv1("canv", "canvas for plotting", 1280, 950);
	auto legend1 = new TLegend(0.1,0.7,0.4,0.9);
	//legend1 -> AddEntry(h1, "Candidates", "f");
	legend1 -> AddEntry(mbinv_bkg, "Background", "f");
	legend1 -> AddEntry(mbinv_sig, "B->J/#psi(#mu^{+}#mu^{-})K", "f");
	mbinv->Draw("NOSTACK");
	//gPad->SetLogy();
	mbinv->GetYaxis()->SetMaxDigits(4);
	mbinv->GetXaxis()->SetLimits(5, 5.5);
	mbinv->GetXaxis()->SetTitle("Reconstructed mass [GeV]");
	mbinv->GetYaxis()->SetTitle("Events/0.01");
	mbinv->GetXaxis()->SetTitleSize(0.035);
    mbinv->GetYaxis()->SetTitleSize(0.035);
    mbinv->GetXaxis()->SetLabelSize(0.035);
    mbinv->GetYaxis()->SetLabelSize(0.035);
	legend1->Draw();
	canv1.SaveAs("grafici2/massaB.pdf");
	
    
	TFile* fout2 = new TFile("isto_MCfakes.root","RECREATE");
	fout2->cd();
	//bckg->Write();
	MC1_15B->Write();
    MC15_2B->Write();
    MC2_5B->Write();
    MC5B->Write();
    MC2_5E->Write();
    MC5E->Write();
    MCtot->Write();
	fout2->Write();
	fout2->Close();



}
