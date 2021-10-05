//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Sep 17 22:21:03 2021 by ROOT version 6.14/02
// from TTree fitter_tree/reduced tree for T&P
// found on file: FormattedLowPt_Fakes_March21_NoRegr_Parking2018ALL.root
//////////////////////////////////////////////////////////

#ifndef SIGfakes_h
#define SIGfakes_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class SIGfakes {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           hlt_9;
   Int_t           numvtx;
   Float_t         bMass;
   Float_t         bPt;
   Float_t         bCos2D;
   Float_t         bSvprob;
   Float_t         bXysig;
   Int_t           bMatchMc;
   Float_t         mumuMass;
   Float_t         dR_ele_mu1;
   Float_t         dR_ele_mu2;
   Float_t         dR_ele_k;
   Float_t         dR_ele_mu1mu2;
   Float_t         kPt;
   Float_t         kEta;
   Float_t         kPhi;
   Float_t         mu1Pt;
   Float_t         mu1Eta;
   Float_t         mu1Phi;
   Int_t           mu1IsTriggering;
   Int_t           mu1MatchMcFromJPsi;
   Float_t         mu2Pt;
   Float_t         mu2Eta;
   Float_t         mu2Phi;
   Int_t           mu2IsTriggering;
   Int_t           mu2MatchMcFromJPsi;
   Float_t         elePt;
   Float_t         eleEta;
   Float_t         elePhi;
   Int_t           eleIsPF;
   Int_t           eleIsPFOverlap;
   Int_t           eleIsLowPt;
   Float_t         eleMvaId;
   Float_t         elePfmvaId;
   Int_t           eleConvVeto;
   Float_t         eleTrkRelIso;
   Float_t         elePFRelIso;
   Float_t         eleFBrem;
   Float_t         eleDxySig;
   Float_t         eleDzSig;
   Float_t         weight;
   Float_t         probeCloseToElePt;
   Float_t         probeCloseToEleEta;
   Float_t         probeCloseToElePhi;

   // List of branches
   TBranch        *b_hlt_9;   //!
   TBranch        *b_numvtx;   //!
   TBranch        *b_bMass;   //!
   TBranch        *b_bPt;   //!
   TBranch        *b_bCos2D;   //!
   TBranch        *b_bSvprob;   //!
   TBranch        *b_bXysig;   //!
   TBranch        *b_bMatchMc;   //!
   TBranch        *b_mumuMass;   //!
   TBranch        *b_dR_ele_mu1;   //!
   TBranch        *b_dR_ele_mu2;   //!
   TBranch        *b_dR_ele_k;   //!
   TBranch        *b_dR_ele_mu1mu2;   //!
   TBranch        *b_kPt;   //!
   TBranch        *b_kEta;   //!
   TBranch        *b_kPhi;   //!
   TBranch        *b_mu1Pt;   //!
   TBranch        *b_mu1Eta;   //!
   TBranch        *b_mu1Phi;   //!
   TBranch        *b_mu1IsTriggering;   //!
   TBranch        *b_mu1MatchMcFromJPsi;   //!
   TBranch        *b_mu2Pt;   //!
   TBranch        *b_mu2Eta;   //!
   TBranch        *b_mu2Phi;   //!
   TBranch        *b_mu2IsTriggering;   //!
   TBranch        *b_mu2MatchMcFromJPsi;   //!
   TBranch        *b_elePt;   //!
   TBranch        *b_eleEta;   //!
   TBranch        *b_elePhi;   //!
   TBranch        *b_eleIsPF;   //!
   TBranch        *b_eleIsPFOverlap;   //!
   TBranch        *b_eleIsLowPt;   //!
   TBranch        *b_eleMvaId;   //!
   TBranch        *b_elePfmvaId;   //!
   TBranch        *b_eleConvVeto;   //!
   TBranch        *b_eleTrkRelIso;   //!
   TBranch        *b_elePFRelIso;   //!
   TBranch        *b_eleFBrem;   //!
   TBranch        *b_eleDxySig;   //!
   TBranch        *b_eleDzSig;   //!
   TBranch        *b_weight;   //!
   TBranch        *b_probeCloseToElePt;   //!
   TBranch        *b_probeCloseToEleEta;   //!
   TBranch        *b_probeCloseToElePhi;   //!

   SIGfakes(TTree *tree=0);
   virtual ~SIGfakes();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef SIGfakes_cxx
SIGfakes::SIGfakes(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("FormattedLowPt_Fakes_March21_NoRegr_Parking2018ALL.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("FormattedLowPt_Fakes_March21_NoRegr_Parking2018ALL.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("FormattedLowPt_Fakes_March21_NoRegr_Parking2018ALL.root:/tnpAna");
      dir->GetObject("fitter_tree",tree);

   }
   Init(tree);
}

SIGfakes::~SIGfakes()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t SIGfakes::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t SIGfakes::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void SIGfakes::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("hlt_9", &hlt_9, &b_hlt_9);
   fChain->SetBranchAddress("numvtx", &numvtx, &b_numvtx);
   fChain->SetBranchAddress("bMass", &bMass, &b_bMass);
   fChain->SetBranchAddress("bPt", &bPt, &b_bPt);
   fChain->SetBranchAddress("bCos2D", &bCos2D, &b_bCos2D);
   fChain->SetBranchAddress("bSvprob", &bSvprob, &b_bSvprob);
   fChain->SetBranchAddress("bXysig", &bXysig, &b_bXysig);
   fChain->SetBranchAddress("bMatchMc", &bMatchMc, &b_bMatchMc);
   fChain->SetBranchAddress("mumuMass", &mumuMass, &b_mumuMass);
   fChain->SetBranchAddress("dR_ele_mu1", &dR_ele_mu1, &b_dR_ele_mu1);
   fChain->SetBranchAddress("dR_ele_mu2", &dR_ele_mu2, &b_dR_ele_mu2);
   fChain->SetBranchAddress("dR_ele_k", &dR_ele_k, &b_dR_ele_k);
   fChain->SetBranchAddress("dR_ele_mu1mu2", &dR_ele_mu1mu2, &b_dR_ele_mu1mu2);
   fChain->SetBranchAddress("kPt", &kPt, &b_kPt);
   fChain->SetBranchAddress("kEta", &kEta, &b_kEta);
   fChain->SetBranchAddress("kPhi", &kPhi, &b_kPhi);
   fChain->SetBranchAddress("mu1Pt", &mu1Pt, &b_mu1Pt);
   fChain->SetBranchAddress("mu1Eta", &mu1Eta, &b_mu1Eta);
   fChain->SetBranchAddress("mu1Phi", &mu1Phi, &b_mu1Phi);
   fChain->SetBranchAddress("mu1IsTriggering", &mu1IsTriggering, &b_mu1IsTriggering);
   fChain->SetBranchAddress("mu1MatchMcFromJPsi", &mu1MatchMcFromJPsi, &b_mu1MatchMcFromJPsi);
   fChain->SetBranchAddress("mu2Pt", &mu2Pt, &b_mu2Pt);
   fChain->SetBranchAddress("mu2Eta", &mu2Eta, &b_mu2Eta);
   fChain->SetBranchAddress("mu2Phi", &mu2Phi, &b_mu2Phi);
   fChain->SetBranchAddress("mu2IsTriggering", &mu2IsTriggering, &b_mu2IsTriggering);
   fChain->SetBranchAddress("mu2MatchMcFromJPsi", &mu2MatchMcFromJPsi, &b_mu2MatchMcFromJPsi);
   fChain->SetBranchAddress("elePt", &elePt, &b_elePt);
   fChain->SetBranchAddress("eleEta", &eleEta, &b_eleEta);
   fChain->SetBranchAddress("elePhi", &elePhi, &b_elePhi);
   fChain->SetBranchAddress("eleIsPF", &eleIsPF, &b_eleIsPF);
   fChain->SetBranchAddress("eleIsPFOverlap", &eleIsPFOverlap, &b_eleIsPFOverlap);
   fChain->SetBranchAddress("eleIsLowPt", &eleIsLowPt, &b_eleIsLowPt);
   fChain->SetBranchAddress("eleMvaId", &eleMvaId, &b_eleMvaId);
   fChain->SetBranchAddress("elePfmvaId", &elePfmvaId, &b_elePfmvaId);
   fChain->SetBranchAddress("eleConvVeto", &eleConvVeto, &b_eleConvVeto);
   fChain->SetBranchAddress("eleTrkRelIso", &eleTrkRelIso, &b_eleTrkRelIso);
   fChain->SetBranchAddress("elePFRelIso", &elePFRelIso, &b_elePFRelIso);
   fChain->SetBranchAddress("eleFBrem", &eleFBrem, &b_eleFBrem);
   fChain->SetBranchAddress("eleDxySig", &eleDxySig, &b_eleDxySig);
   fChain->SetBranchAddress("eleDzSig", &eleDzSig, &b_eleDzSig);
   fChain->SetBranchAddress("weight", &weight, &b_weight);
   fChain->SetBranchAddress("probeCloseToElePt", &probeCloseToElePt, &b_probeCloseToElePt);
   fChain->SetBranchAddress("probeCloseToEleEta", &probeCloseToEleEta, &b_probeCloseToEleEta);
   fChain->SetBranchAddress("probeCloseToElePhi", &probeCloseToElePhi, &b_probeCloseToElePhi);
   Notify();
}

Bool_t SIGfakes::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void SIGfakes::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t SIGfakes::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef SIGfakes_cxx
